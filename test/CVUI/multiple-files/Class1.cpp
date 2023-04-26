/*
Copyright (c) 2017 Fernando Bevilacqua <dovyski@gmail.com>
Licensed under the MIT license.
*/

#include "cvui.h"
#include "Class1.h"

Class1::Class1() {
	checked = false;
}

void Class1::renderInfo(cv::Mat & frame) {
	cvui::window(frame, 10, 50, 100, 120, "Info");
	// draw an image in size the window
	cv::Mat img = cv::Mat::ones(100, 100, CV_8UC3);
	img = img * 125;
	cvui::image(frame, 10, 70, img);
	cvui::checkbox(frame, 15, 80, "Checked", &checked);
}
