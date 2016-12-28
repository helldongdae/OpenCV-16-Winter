#include <opencv2\highgui\highgui.hpp>
#include <opencv\cv.h>
#include <vector>

using namespace std;
using namespace cv;

int main(){
	VideoCapture capture("road.wmv");
	Mat frame, gray, range, finalMat;
	vector<Mat> v;
	Scalar from(0, 0, 50);
	Scalar to(60, 60, 255);
	cout << "1: at 2: iterator 3: bit " << endl;
	int option;
	cin >> option;
	if (option == 1){
		while (capture.read(frame)){
			inRange(frame, from, to, range);
			cvtColor(frame, gray, COLOR_BGR2GRAY);
			split(frame, v);
			for (int i = 0; i < range.rows; i++){
				for (int j = 0; j < range.cols; j++){
					if (range.at<uchar>(i, j) != 255){
						v[0].at<uchar>(i, j) = gray.at<uchar>(i, j);
						v[1].at<uchar>(i, j) = gray.at<uchar>(i, j);
						v[2].at<uchar>(i, j) = gray.at<uchar>(i, j);
					}
				}
			}
			merge(v, finalMat);
			imshow("Screen", finalMat);
			imshow("Screen2", frame);
			waitKey(30);
		}
	}
	else if (option == 2){
		while (capture.read(frame)){
			inRange(frame, from, to, range);
			cvtColor(frame, gray, COLOR_BGR2GRAY);
			split(frame, v);
			Mat_<uchar>::iterator i = range.begin<uchar>();
			Mat_<uchar>::iterator it0 = v[0].begin<uchar>();
			Mat_<uchar>::iterator it1 = v[1].begin<uchar>();
			Mat_<uchar>::iterator it2 = v[2].begin<uchar>();
			Mat_<uchar>::iterator ig = gray.begin<uchar>();
			while (i != range.end<uchar>()){
				if (*i != 255){
					*it0 = *ig;
					*it1 = *ig;
					*it2 = *ig;
				}
				i++; it0++; it1++; it2++; ig++;
			}
			merge(v, finalMat);
			imshow("Screen", finalMat);
			imshow("Screen2", frame);
			waitKey(30);
		}
	}
	else {
		while (capture.read(frame)){
			inRange(frame, from, to, range);
			cvtColor(frame, gray, COLOR_BGR2GRAY);
			split(frame, v);
			vector<Mat> mask(3);
			bitwise_and(v[0], range, mask[0]);
			bitwise_and(v[1], range, mask[1]);
			bitwise_and(v[2], range, mask[2]);
			merge(mask, finalMat);
			cvtColor(gray, gray, COLOR_GRAY2BGR);
			bitwise_or(finalMat, gray, finalMat);
			imshow("Screen", finalMat);
			imshow("Screen2", frame);
			waitKey(30);
		}
	}
}
