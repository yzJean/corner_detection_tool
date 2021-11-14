#include <iostream>
#include <vector>
#ifndef OPENCV2_OPENCV_HPP
#define OPENCV2_OPENCV_HPP
#include <opencv2/opencv.hpp>
#endif

//#define DEBUG
#define CHECKERBOARD_ROW (int) 8 //9
#define CHECKERBOARD_COL (int) 6 //7

class Reader 
{
    public: 
        Reader();
        Reader(cv::String &strImgPath);
        ~Reader();
        bool getImgsFromPath();
        void read();
    private:
        std::vector<cv::String> m_vecImgs;
        cv::String m_strImgPath;
        cv::String getImgPath() const;
        void setImgs(std::vector<cv::String> &vecImgs);
        std::vector<cv::String> getImgs() const;
        bool isImgsFilled();
        
};