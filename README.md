# XBOX-360-Kinect-Camera-Calibration

## Overview

This project provides a C++ and Python implementation for calibrating the Xbox 360 Kinect Camera using the libfreenect package and OpenCV. The calibration process involves capturing images of a chessboard pattern and computing calibration and distortion matrices.

## Video

Watch the calibration process in action by referring to the provided video files located in the videos folder. The video provides a visual representation of the Kinect camera calibration using the described code.



## Requirements
* Libfreenect
``` $ sudo apt-get install libfreenect-dev ```

* OpenCV (version 4)

``` $ sudo apt-get install libopencv-dev ```

* libusb-1.0
  ``` bash  $ sudo apt-get install libusb-1.0-0-dev ```
  
* Boost C++ Libraries

``` $ sudo apt-get install libboost-all-dev ```

## Usage

* Compile getImages.cpp using the following command:


``` $ g++ getImages.cpp -o getImages -I/usr/include -I/usr/include/opencv4 -I/usr/include/libusb-1.0 -lfreenect -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lboost_filesystem -lboost_system ```

* Run the compiled executable:

``` $ ./getImages ```

* Press 's' to save an image when the Kinect RGB frame is displayed.

* Run calibration.py to calibrate the Kinect camera:

``` $ python3 calibration.py ```

The script will detect chessboard corners, perform camera calibration, and save the calibration result.

## Calibration Result

The calibration result, including the camera matrix and distortion coefficients, is saved in the current directory as calibration.pkl, cameraMatrix.pkl, and dist.pkl.

## Notes

* Make sure the Kinect camera is connected and functioning correctly before running the code.
* Adjust the chessboardSize variable in calibration.py based on the actual number of inner squares in your calibration pattern.
* The script assumes a square chessboard pattern with a specified size of chessboard squares in millimeters (size_of_chessboard_squares_mm).
* You can pick your Chessboard image from [here](https://markhedleyjones.com/projects/calibration-checkerboard-collection)

## Credits

Special thanks to the following sources for valuable insights and guidance:

[Kinect Study by Xianghua Zhou](https://cs.gmu.edu/~xzhou10/doc/kinect-study.pdf)
[ROS Noetic Kinect Xbox 360 by Rospibot](https://rospibot.azw.pt/ros-noetic-kinect-xbox-360/)
[Nicolai Nielsen's YouTube Channel](https://www.youtube.com/@NicolaiAI)
[Markhedleyjones.com](https://markhedleyjones.com/projects/calibration-checkerboard-collection)
