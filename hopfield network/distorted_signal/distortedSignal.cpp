//
//  distortedSignal.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "distortedSignal.hpp"
#include <opencv2/opencv.hpp>
#include <random>
#include <ctime>

distortedSignal::distortedSignal(std::string filePath) { 
    cv::Mat img = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
    cv::threshold(img, img, 128, 255, cv::THRESH_OTSU);
    cv::resize(img, img, cv::Size(10, 10));
    int size = img.rows * img.cols;
    matrixInLineInBipolarForm.resize(size);
    for (int i = 0; i < size; i++) {
        if (img.at<uchar>(i) == 0) {
            matrixInLineInBipolarForm[i] = -1;
        } else {
            matrixInLineInBipolarForm[i] = 1;
        }
    }
}

void distortedSignal::toDistortTheSignal() { 
    int distans = static_cast<int>(matrixInLineInBipolarForm.size()/10);
    std::mt19937 gen(static_cast<int>(time(0)));
    std::uniform_int_distribution<> uid(0, distans);
    for (int i = 0; i < matrixInLineInBipolarForm.size(); i+=distans) {
        int  ind = i + uid(gen);
        matrixInLineInBipolarForm[ind] = 1;
    }
    for (int i = 0; i < matrixInLineInBipolarForm.size(); i+=distans) {
        int  ind = i + uid(gen);
        matrixInLineInBipolarForm[ind] = -1;
    }
}

distortedSignal::~distortedSignal() { 
    matrixInLineInBipolarForm.clear();
    matrixInLineInBipolarForm.~vector();
}


