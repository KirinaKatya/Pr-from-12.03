#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("C:/Users/Катя/Desktop/Python/albedo2.jpg");

    if (image.empty()) {
        std::cout << "Not open" << std::endl;
        return -1;
    }

    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    cv::Mat labImage;
    cv::cvtColor(image, labImage, cv::COLOR_BGR2Lab);

    cv::Mat yuvImage;
    cv::cvtColor(image, yuvImage, cv::COLOR_BGR2YUV);

    cv::Mat xyzImage;
    cv::cvtColor(image, xyzImage, cv::COLOR_BGR2XYZ);

    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    cv::imshow("Original Image", image);
    cv::imshow("HSV Image", hsvImage);
    cv::imshow("Lab Image", labImage);
    cv::imshow("YUV Image", yuvImage);
    cv::imshow("XYZ Image", xyzImage);
    cv::imshow("GRAY Image", grayImage);

    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}
