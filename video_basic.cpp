#include "cv.hpp"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture("freeway.wmv");
	Mat frame, gray;
	int key;
	int frame_rate = 30;
	while (capture.read(frame)){
		imshow("SCREEN", frame);
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		imshow("SCREEN2", gray);
		key = waitKey(frame_rate);
		if (key == 32){
			if (frame_rate == 30)
				frame_rate = 0;
			else
				frame_rate = 30;
		}
		else if (key == 27)
			break;
	}
}
