#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;

/** @function main */
int main( int argc, char** argv )
{

  Mat src, src_gray;
  Mat grad;
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  int k = 3; // kernel size
  
  int c;

  /// Load an image
  src = imread("../ferrarib.jpg");

  if( !src.data )
  { return -1; }

  GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );

  /// Convert it to gray
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// Create window
  namedWindow("Original", CV_WINDOW_AUTOSIZE );

  /// Generate grad_x and grad_y
  Mat grad_x, grad_y;

  /// Gradient X
  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_x, ddepth, 1, 0, k, scale, delta, BORDER_DEFAULT );
  imshow("Sobel right", grad_x*255);
  
  /// Gradient Y
  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_y, ddepth, 0, 1, k, scale, delta, BORDER_DEFAULT );
  imshow("Sobel Up", grad_y*255);

  imshow("Original", src);
  
  Mat Gx_f, Gy_f;
  grad_x.convertTo(Gx_f, CV_32FC1);
  grad_y.convertTo(Gy_f, CV_32FC1);
  
  Mat mag = Mat(Gx_f.size(), Gx_f.type());
  Mat mag_show;
  magnitude(Gx_f, Gy_f, mag);
  
  convertScaleAbs(mag, mag_show);

  imshow("Magnitude", mag_show);
  
  waitKey(0);

  return 0;
  }