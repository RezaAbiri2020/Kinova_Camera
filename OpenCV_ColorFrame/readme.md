
Displaying Color Frame:
In this demo, you will acquire color frame from the RealSense camera and display it using OpenCV. Before you start, make sure you have librealsense and OpenCV installed and working properly on your system. Using the editor of your choice create BGR_sample.cpp and copy-paste the following code-snippet:

----------------------------------------------------------------------------

the issue related to shared lib solved by this:
https://github.com/cggos/DIPDemoQt/issues/1


the guideline for code lines is availabe in this link:
https://github.com/IntelRealSense/librealsense/blob/master/doc/stepbystep/getting_started_with_openCV.md

compiled/ran in terminal using: 
g++ -std=c++11 BGR_sample.cpp -lrealsense2 -lopencv_core -lopencv_highgui -o BGR && ./BGR



