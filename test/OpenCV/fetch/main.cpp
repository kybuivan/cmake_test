#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char* argv[])
{
  cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC3);
  cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
  cv::imshow("Display window", image);
  cv::waitKey(0);
  return 0;
}