#include <iostream>
#include <string.h> 
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "BMP.h"

using namespace std;
using namespace cv;

int main()
{
	BMP bmp1("test.bmp");

	Mat Image(bmp1.bmp_info_header.height, bmp1.bmp_info_header.width, CV_8UC3, bmp1.data.data());
	imshow("Test", Image);
	waitKey(0);

	return 0;
}