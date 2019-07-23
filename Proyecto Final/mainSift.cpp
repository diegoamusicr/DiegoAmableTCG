#include <iostream>  
#include <cmath>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "cudaImage.h"
#include "cudaSift.h"

int ImproveHomography(SiftData &data, float *homography, int numLoops, float minScore, float maxAmbiguity, float thresh);
void PrintMatchData(SiftData &siftData1, SiftData &siftData2, CudaImage &img);

double ScaleUp(CudaImage &res, CudaImage &src);

int main(int argc, char **argv) 
{    
  cv::Mat limg, rimg;
  cv::imread("../data/img1.jpeg", 0).convertTo(limg, CV_32FC1);
  cv::imread("../data/img2.jpeg", 0).convertTo(rimg, CV_32FC1);

  unsigned int w = limg.cols;
  unsigned int h = limg.rows;
  std::cout << "Image size = (" << w << "," << h << ")" << std::endl;
  
  std::cout << "Initializing data..." << std::endl;
  InitCuda(0); 
  CudaImage img1, img2;
  img1.Allocate(w, h, iAlignUp(w, 128), false, NULL, (float*)limg.data);
  img2.Allocate(w, h, iAlignUp(w, 128), false, NULL, (float*)rimg.data);
  img1.Download();
  img2.Download(); 

  SiftData siftData1, siftData2;
  float initBlur = 1.0f;
  float thresh = 4.5f;
  InitSiftData(siftData1, 32768, true, true);
  InitSiftData(siftData2, 32768, true, true);
  
  float *memoryTmp = AllocSiftTempMemory(w, h, 5);
  for (int i=0;i<1;i++) {
    ExtractSift(siftData1, img1, 5, initBlur, thresh, 0.0f, memoryTmp);
    ExtractSift(siftData2, img2, 5, initBlur, thresh, 0.0f, memoryTmp);
  }
  FreeSiftTempMemory(memoryTmp);
  
  for (int i=0;i<1;i++)
    MatchSiftData(siftData1, siftData2);
  float homography[9];
  int numMatches;
  FindHomography(siftData1, homography, &numMatches, 10000, 0.00f, 0.80f, 5.0);
  int numFit = ImproveHomography(siftData1, homography, 5, 0.00f, 0.80f, 3.0);
  
  std::cout << "Number of original features: " <<  siftData1.numPts << " " << siftData2.numPts << std::endl;
  std::cout << "Number of matching features: " << numFit << " " << numMatches << " " << 100.0f*numFit/std::min(siftData1.numPts, siftData2.numPts) << "% " << initBlur << " " << thresh << std::endl;
  
  PrintMatchData(siftData1, siftData2, img1);
  cv::imwrite("../data/limg_pts.jpg", limg);

  FreeSiftData(siftData1);
  FreeSiftData(siftData2);
}

void PrintMatchData(SiftData &siftData1, SiftData &siftData2, CudaImage &img)
{
  int numPts = siftData1.numPts;
  SiftPoint *sift1 = siftData1.h_data;
  SiftPoint *sift2 = siftData2.h_data;
  float *h_img = img.h_data;
  int w = img.width;
  int h = img.height;
  std::cout << std::setprecision(3);
  for (int j=0;j<numPts;j++) { 
    int k = sift1[j].match;
    if (sift1[j].match_error<5) {
      float dx = sift2[k].xpos - sift1[j].xpos;
      float dy = sift2[k].ypos - sift1[j].ypos;

      int len = (int)(fabs(dx)>fabs(dy) ? fabs(dx) : fabs(dy));
      for (int l=0;l<len;l++) {
      	int x = (int)(sift1[j].xpos + dx*l/len);
      	int y = (int)(sift1[j].ypos + dy*l/len);
      	h_img[y*w+x] = 255.0f;
      }
    }
    int x = (int)(sift1[j].xpos+0.5);
    int y = (int)(sift1[j].ypos+0.5);
    int s = std::min(x, std::min(y, std::min(w-x-2, std::min(h-y-2, (int)(1.41*sift1[j].scale)))));
    int p = y*w + x;
    p += (w+1);
    for (int k=0;k<s;k++) 
      h_img[p-k] = h_img[p+k] = h_img[p-k*w] = h_img[p+k*w] = 0.0f;
    p -= (w+1);
    for (int k=0;k<s;k++) 
      h_img[p-k] = h_img[p+k] = h_img[p-k*w] =h_img[p+k*w] = 255.0f;
  }
  std::cout << std::setprecision(6);
}


