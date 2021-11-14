#include "reader.hpp"

#ifndef OPENCV2_OPENCV_HPP
#define OPENCV2_OPENCV_HPP
#include <opencv2/opencv.hpp>
#endif
#include <opencv2/core/types.hpp>

Reader::Reader()
{
    std::cout << "Reader is created." << std::endl;
}

Reader::Reader(cv::String &strImgPath)
{
    m_strImgPath = strImgPath;
    std::cout << "Loading images from " << m_strImgPath << std::endl;
}

Reader::~Reader()
{
    std::cout << "Reader is destoried." << std::endl;
}

cv::String Reader::getImgPath() const
{
    return m_strImgPath;
}
bool Reader::getImgsFromPath()
{
    std::string path = getImgPath();
    std::vector<cv::String> vecImgs;
    cv::glob(getImgPath(), vecImgs);
    setImgs(vecImgs);
    return isImgsFilled();
}
void Reader::setImgs(std::vector<cv::String> &vecImgs)
{
    m_vecImgs.clear();
    m_vecImgs = vecImgs;
}
std::vector<cv::String> Reader::getImgs() const
{
    return m_vecImgs;
}
bool Reader::isImgsFilled()
{
    #ifdef DEBUG
        std::cout << "(Debug) Verifying image..." << std::endl;
        cv::Mat image = cv::imread(getImgs()[0]);
        if (!image.data) 
        {
            std::cout << "(Debug) image doesn't eixst!" << std::endl;
            return 1;
        }
        cv::imshow("(Debug) Start project with opencv", image);
        cv::waitKey(0);
    #endif
    return !getImgs().empty();
}

void Reader::read()
{
    std::vector<cv::String> vecImgs = getImgs();
    cv::Mat frame, grayImg;
    std::vector<cv::Point2f> vecCornerPts{};
    bool bSucceed = false;
    for (int i = 0; i < vecImgs.size(); i++)
    {
        frame = cv::imread(vecImgs[i]);
        if (!frame.data)
        {
            std::cout << vecImgs[i] << " doesn't eixst!" << std::endl;
            return;
        }
        cv::cvtColor(frame, grayImg, cv::COLOR_BGR2GRAY);
        // std::string strImgName = "gray image" + std::to_string(i + 1);
        // cv::imshow(strImgName, grayImg);
        // cv::waitKey(0);
        // bSucceed = cv::findChessboardCorners(grayImg, cv::Size(CHECKERBOARD_COL, CHECKERBOARD_ROW),
        //                                     vecCornerPts, cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FAST_CHECK | cv::CALIB_CB_NORMALIZE_IMAGE);
        bSucceed = cv::findChessboardCorners(grayImg, cv::Size(CHECKERBOARD_COL, CHECKERBOARD_ROW),
                                            vecCornerPts);
        if (bSucceed)
        {   
            cv::TermCriteria criteria(cv::TermCriteria::EPS | cv::TermCriteria::MAX_ITER, 30, 0.001);
            cv::cornerSubPix(grayImg, vecCornerPts, cv::Size(11, 11), cv::Size(-1, -1), criteria);
            cv::drawChessboardCorners(frame, cv::Size(CHECKERBOARD_COL, CHECKERBOARD_ROW),
                                    vecCornerPts, bSucceed);
        }
        else
        {
            std::cout << "Chessboard corners found fail at " << i + 1 << "th image." << std::endl;
        }
        cv::imshow("image", frame);
        cv::waitKey(0);
    }
    cv::destroyAllWindows();

}