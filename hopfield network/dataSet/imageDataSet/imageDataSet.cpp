//
//  imageDataSet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "imageDataSet.hpp"

imageDataSet::imageDataSet(std::string dirPath, dataSet ds) {
    setImages.resize(ds.getFileList().size());
    for (int i = 0; i < ds.getFileList().size(); i++) {
        std::string filePath = dirPath + ds.getFileList()[i];
        cv::Mat img = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
        cv::threshold(img, img, 128, 255, cv::THRESH_OTSU);
        cv::resize(img, img, cv::Size(10, 10));
        setImages[i] = img;
    }
}

std::vector<cv::Mat> &imageDataSet::getImageSet() { 
    return setImages;
}

matrix &imageDataSet::getInlineMatrix() { 
    return mat;
}

void imageDataSet::generaitInLineForm() { 
    int ilfIndex = 0;
    matrix ilfMatrix(setImages.size(), setImages[0].rows * setImages[0].cols);
    for (int i = 0; i < setImages.size(); i++) {
        for (int j = 0; j < (setImages[i].rows * setImages[i].cols); j++) {
            if (setImages[i].at<uchar>(j) == 0) ilfMatrix.data()[ilfIndex] == -1;
            else ilfMatrix.data()[ilfIndex] = 1;
            ilfIndex++;
        }
    }
    mat = ilfMatrix;
}



