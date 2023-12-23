/* Usage Command : g++ getImages.cpp -o getImages -I/usr/include -I/usr/include/opencv4 -I/usr/include/libusb-1.0 -lfreenect -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lboost_filesystem -lboost_system
*/

#include "/usr/include/libfreenect.hpp"
#include <opencv2/opencv.hpp>
#include <boost/filesystem.hpp>

class MyFreenectDevice : public Freenect::FreenectDevice {
public:
    MyFreenectDevice(freenect_context* ctx, int index) : Freenect::FreenectDevice(ctx, index) {}

    void VideoCallback(void* rgb, uint32_t timestamp) {
    // Process the RGB frame (use OpenCV for simplicity)
        cv::Mat bgrMat(480, 640, CV_8UC3, rgb);

        // Convert BGR to RGB
        cv::Mat rgbMat;
        cv::cvtColor(bgrMat, rgbMat, cv::COLOR_BGR2RGB);

        cv::imshow("Kinect RGB", rgbMat);

        // Example: Save image when 's' is pressed
        int key = cv::waitKey(1);
        if (key == 's' || key == 'S') {
            saveImage(rgbMat);
        }
}

    void saveImage(const cv::Mat& image) {
        std::string folder_path = "images";
        boost::filesystem::create_directory(folder_path);

        // Generate a unique filename based on the current timestamp
        std::string filename = folder_path + "/img_" + std::to_string(time(0)) + ".png";

        // Save the image
        cv::imwrite(filename, image);
        std::cout << "Image saved: " << filename << std::endl;
    }
};

int main() {
    Freenect::Freenect freenect;
    MyFreenectDevice& device = freenect.createDevice<MyFreenectDevice>(0);

    device.startVideo();

    // Your main program loop
    while (true) {
        // Perform any processing or wait for user input
        // Note: The video frames will be processed in the VideoCallback function
    }

    device.stopVideo();

    return 0;
}
