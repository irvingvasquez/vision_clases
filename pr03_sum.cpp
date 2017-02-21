#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main( int argc, const char** argv )
{
  // Read images	
  Mat ImGray= imread("../lena.jpg", 0);
  Mat ImGray2 = imread("../monkey.jpg", 0);
  
  int type = ImGray.type();
  
  string r;
  switch (type) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }
  
  cout << "Type:" << r << endl;
  
  Mat sum = Mat(ImGray.size(), type);
  sum = ImGray + ImGray2;
  
  imshow("Suma", sum);
  
  // wait for any key press
  waitKey(0);
  return 0;
}