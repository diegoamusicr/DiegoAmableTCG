#include <stdio.h>
#include <iostream>
#include <string>
#include <cuda.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace std;
using namespace cv;

__global__
void TMKernel(unsigned char * src, int width_src,
			  unsigned char * templ, int width_templ, int height_templ,
			  float * result, int width_result, int height_result)
{
	int Col = blockIdx.x * blockDim.x + threadIdx.x;
	int Row = blockIdx.y * blockDim.y + threadIdx.y;

	if (Col >= width_result || Row >= height_result) return;

	float pixelVal = 0.0;
	float pixelTempSq = 0.0;
	float pixelSrcSq = 0.0;

	for (int templRow = 0; templRow < height_templ; templRow++)
	{
		for (int templCol = 0; templCol < width_templ; templCol++)
		{
			int curRow = Row + templRow;
			int curCol = Col + templCol;

			pixelVal += templ[templRow * width_templ + templCol] * 
						src[curRow * width_src + curCol];
			pixelTempSq += powf(templ[templRow * width_templ + templCol], 2);
			pixelSrcSq += powf(src[curRow * width_src + curCol], 2);
		}
	}

	result[Row * width_result + Col] = pixelVal / sqrtf(pixelTempSq * pixelSrcSq);
}

void TemplateMatchingWrapper(Mat &src, Mat &templ, Mat &result)
{
	unsigned char * dataImgSrc;
	unsigned char * dataImgTmpl;
	float * dataImgResult;

	int width_src = src.size().width;
	int height_src = src.size().height;

	int width_templ = templ.size().width;
	int height_templ = templ.size().height;

	int width_result = width_src - width_templ + 1;
	int height_result = height_src - height_templ + 1;

	int src_size = width_src * height_src * sizeof(unsigned char);
	int templ_size = width_templ * height_templ * sizeof(unsigned char);
	int result_size = width_result * height_result * sizeof(float);

	dataImgSrc = src.data;
	dataImgTmpl = templ.data;
	dataImgResult = (float *) malloc(result_size);

	unsigned char *d_Src, *d_Templ;
	float *d_Result;

	cudaMalloc((void **) &d_Src, src_size);
	cudaMalloc((void **) &d_Templ, templ_size);
	cudaMalloc((void **) &d_Result, result_size);

	cudaMemcpy(d_Src, dataImgSrc, src_size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_Templ, dataImgTmpl, templ_size, cudaMemcpyHostToDevice);

	dim3 dimGrid(ceil(width_result/32.0), ceil(height_result/32.0), 1);
	dim3 dimBlock(32, 32, 1);
	TMKernel<<<dimGrid, dimBlock>>>(d_Src, width_src, 
									d_Templ, width_templ, height_templ, 
									d_Result, width_result, height_result);

	cudaMemcpy(dataImgResult, d_Result, result_size, cudaMemcpyDeviceToHost);

	cudaFree(d_Src); cudaFree(d_Templ); cudaFree(d_Result);

	result = Mat(height_result, width_result, CV_32FC1, dataImgResult);
}


int main()
{

	Mat img = imread("Technophilia.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat templ = imread("template.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat result;

	TemplateMatchingWrapper(img, templ, result);

	double minVal; double maxVal; Point minLoc; Point maxLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

	rectangle(img, maxLoc, Point(maxLoc.x + templ.cols, maxLoc.y + templ.rows), Scalar::all(0), 1);
	imshow("Template Matching Result", result);
	imshow("Template Matching Found", img);
	waitKey(0);
	destroyAllWindows();

	return 0;
}