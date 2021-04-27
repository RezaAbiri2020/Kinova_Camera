
Displaying Infrared Frame:
Displaying Infrared and Depth data is not very different from Color data. Infrared frame is a single channel, 8 bits-per-pixel image. Copy the following code snippet into IR_sample.cpp:
------------------------------------------------------------------------------------


the guideline for code lines is availabe in this link:
https://github.com/IntelRealSense/librealsense/blob/master/doc/stepbystep/getting_started_with_openCV.md

compiled/ran in terminal using: 
g++ -std=c++11 IR_sample.cpp -lrealsense2 -lopencv_core -lopencv_imgproc -lopencv_highgui -o ir && ./ir



