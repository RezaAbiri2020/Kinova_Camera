
This example shows how to use Intel RealSense cameras with existing Deep Neural Network algorithms. The demo is derived from MobileNet Single-Shot Detector example provided with opencv. We modify it to work with Intel RealSense cameras and take advantage of depth data (in a very basic way).

The demo will load existing Caffe model (see another tutorial here) and use it to classify objects within the RGB image. Once object is detected, the demo will calculate approximate distance to the object using the depth data:


------------------------------------------------------------------------------------


# check here for necessary libraries:
/usr/local/lib

compiled/ran in terminal using: 
g++ -std=c++11 rs-dnn.cpp -lrealsense2 -lopencv_core -lopencv_highgui -lopencv_dnn -lopencv_imgproc -o rs-dnn && ./rs-dnn



