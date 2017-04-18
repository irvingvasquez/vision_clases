#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"

using namespace cv;

int main( int argc, const char** argv )
{
  // Read images	
  Mat gray= imread("../lena.jpg", 0);
  
  Ptr<ORB> orb_detector = ORB::create();  
  std::vector<KeyPoint> kp;
  
  orb_detector->detect(gray, kp);
  
  Mat out;
  drawKeypoints(gray, kp, out, Scalar::all(255));
  
  imshow("Lena Keypoints", out);
  
  // wait for any key press
  waitKey(0);
  return 0;
}