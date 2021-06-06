// include the librealsense C++ header file
#include <librealsense2/rs.hpp>

// include OpenCV header file
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main(int argc, char * argv[]) try
{
    // Declare depth colorizer for pretty visualization of depth data
    rs2::colorizer color_map;

    // Declare RealSense pipeline, encapsulating the actual device and sensors
    rs2::pipeline pipe;
    // Start streaming with default recommended configuration
    pipe.start();

    const auto window_name_depth = "Display_Image_depth";
    namedWindow(window_name_depth, WINDOW_AUTOSIZE);

    const auto window_name_BGR = "Display_Image_BGR";
    namedWindow(window_name_BGR, WINDOW_AUTOSIZE);

    while (waitKey(1) < 0 && getWindowProperty(window_name_depth, WND_PROP_AUTOSIZE) >= 0 && getWindowProperty(window_name_BGR, WND_PROP_AUTOSIZE) >= 0)
    {
        rs2::frameset frames = pipe.wait_for_frames(); // Wait for next set of frames from the camera
        
        // Make sure the frameset is spatialy aligned 
        // (each pixel in depth image corresponds to the same pixel in the color image)
        // rs2:: align align_to
        // rs2:: frameset aligned_set = align_to.process(frames);
        
        rs2::frame color_frame = frames.get_color_frame();
        rs2::frame depth = frames.get_depth_frame().apply_filter(color_map);

        // Query frame size (width and height)
        const int w = depth.as<rs2::video_frame>().get_width();
        const int h = depth.as<rs2::video_frame>().get_height();
        
        // cout << w << endl;
        // cout << depth << endl;
        cout << color_frame << endl; 

        // to show the depth camera run this line: Create OpenCV matrix of size (w,h) from the colorized depth data
        Mat image_depth(Size(w, h), CV_8UC3, (void*)depth.get_data(), Mat::AUTO_STEP);
        
        // to show the RGB camera run this line:
        Mat image_BGR(Size(640, 480), CV_8UC3, (void*)color_frame.get_data(), Mat::AUTO_STEP);
        
        // Update the window with new data
        imshow(window_name_depth, image_depth);
        imshow(window_name_BGR, image_BGR);
        
    }

    return EXIT_SUCCESS;
}
catch (const rs2::error & e)
{
    std::cerr << "RealSense error calling " << e.get_failed_function() << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
    return EXIT_FAILURE;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}

