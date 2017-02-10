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
  Mat ImCropped;
  
  // x ,y 
  Rect window(0, 0, ImGray.cols, 0.5*ImGray.rows);
  
  ImCropped = ImGray(window);
  
  // Write images
  imwrite("lena_gray_cropped.jpg", ImCropped);
    
  // show images
  imshow("Lena Gray", ImGray);
  imshow("Lena Gray cropped", ImCropped);
  
  // wait for any key press
  waitKey(0);
  return 0;
}