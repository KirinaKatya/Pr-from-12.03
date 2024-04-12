#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("C:/Users/Катя/Desktop/Python/image1.png");

    if (image.empty()) {
        std::cout << "Not open" << std::endl;
        return -1;
    }

    cv::imshow("Image", image);

    cv::Mat grayImage, gauss, edges;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    cv::GaussianBlur(grayImage, gauss, cv::Size(5, 5), 0);

    cv::Canny(grayImage, edges, 70, 300);

    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(edges, lines, 1, CV_PI / 180, 100, 1, 20);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(gauss, circles, cv::HOUGH_GRADIENT, 1, grayImage.rows / 15, 55, 40, 0, 0);

    for (size_t i = 0; i < lines.size(); i++) {
        cv::Vec4i l = lines[i];
        cv::line(image, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(255, 200, 0), 3, cv::LINE_AA);
    }

    for (size_t i = 0; i < circles.size(); i++) {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        cv::circle(image, center, radius, cv::Scalar(255, 100, 0), 2, cv::LINE_AA);
    }

    cv::imshow("Result", image);

    cv::waitKey(0);

    cv::destroyAllWindows();

    return 0;
}
