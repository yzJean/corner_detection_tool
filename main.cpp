#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "reader.hpp"



int main(int argc, char* argv[])
{
    cv::String strImgPath = "../Images/*.png";
    //cv::String strImgPath = "../testBoard/*.png";
    Reader *reader = new Reader(strImgPath);
    if (!reader->getImgsFromPath())
    {
        std::cout << "Get images from givne directory failed!" << std::endl;
    }
    reader->read();

    // cv::Mat image;
    // //image = cv::imread("./Images/Img1.png"); // relative path to where to execute the executable
    // image = cv::imread(strImgPath);
    // if (!image.data) 
    // {
    //     std::cout << "image doesn't eixst!" << std::endl;
    //     return 1;
    // }
    // cv::imshow("Start project with opencv", image);
    // cv::waitKey(0);

    if (reader) delete reader;
    return 0;
}