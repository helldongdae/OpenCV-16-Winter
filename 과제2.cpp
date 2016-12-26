#include "cv.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture("freeway.wmv");
	Mat frame, gray, prevgray, diffgray;
	int key;
	int frame_rate = 30;
	capture >> frame;
	cvtColor(frame, prevgray, COLOR_BGR2GRAY);
	while (capture.read(frame)){
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		imshow("SCREEN2", gray);

		absdiff(gray, prevgray, diffgray);
		//threshold(diffgray, diffgray, 100, 255, THRESH_BINARY);
		imshow("diff", diffgray);
		prevgray = gray.clone();

		key = waitKey(frame_rate);
		if (key == 27)
			break;
	}
}
