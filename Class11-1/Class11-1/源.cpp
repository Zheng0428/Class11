#include<iostream>
#include<opencv2/opencv.hpp>
#include <opencv2\imgproc\types_c.h>
using namespace cv;
using namespace std;



	VideoCapture capVideo(0);

	int cnt = 0;
	//int bin_width = 3;
	//int bin_height = 50;
	//float histgram[256] = { 0 };
	//
	//cv::Mat histMat;
	cv::Mat bgMat, subMat, bny_subMat;
	int main()
	{
		while (1)
		{
			Mat frame;
			Mat grayMat;
			capVideo >> frame;
			cvtColor(frame, grayMat, COLOR_BGR2GRAY);
			if (cnt == 0) 
			{
				frame.copyTo(bgMat);
			}
			else 
			{
				absdiff(frame, bgMat, subMat);
				threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
				//threshold(subMat, bny_subMat, 0, 255, CV_THRESH_OTSU);
				imshow("b_subMat", bny_subMat);
				imshow("subMat", subMat);
				waitKey(30);
			}
			cnt++;
		}
	}

