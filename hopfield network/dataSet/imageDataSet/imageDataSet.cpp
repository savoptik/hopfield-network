//
//  imageDataSet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "imageDataSet.hpp"

imageDataSet::imageDataSet(std::string dirPath, dataSet ds) {
    // задаём размер вектора.
    setImages.resize(ds.getFileList().size());
    // обходим список
    for (int i = 0; i < ds.getFileList().size(); i++) {
        // собираем путь к файлу
        std::string filePath = dirPath + ds.getFileList()[i];
        // загружаем изображение
        cv::Mat img = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
        // бинаризуем изображение.
        cv::threshold(img, img, 128, 255, cv::THRESH_OTSU);
        // уменьшаем масштаб
        cv::resize(img, img, cv::Size(10, 10));
        // забираем изображение.
        setImages[i] = img;
    }
}

std::vector<cv::Mat> &imageDataSet::getImageSet() {
    // возвращаем ссылку.
    return setImages;
}

matrix &imageDataSet::getInlineMatrix() {
    // возвращаем ссылку
    return xMat;
}

void imageDataSet::generaitInLineForm() {
    // линейный индекс в матрице
    int ilfIndex = 0;
    // создаём матрицу и задаём высоту равную числу объектов в выборке и ширину равную размеру изображений
    matrix ilfMatrix(static_cast<int>(setImages.size()), setImages[0].rows * setImages[0].cols);
    // идём по списку изображений
    for (int i = 0; i < setImages.size(); i++) {
        // идём вдоль линеризованного изображения
        for (int j = 0; j < (setImages[i].rows * setImages[i].cols); j++) {
            // если значение равно нулю, записываем -1
            if (setImages[i].at<uchar>(j) == 0) ilfMatrix.data()[ilfIndex] = -1;
            // иначе записываем 1
            else ilfMatrix.data()[ilfIndex] = 1;
            // наращиваем общий индекс
            ilfIndex++;
        }
    }
    xMat = ilfMatrix; // записываем полученную матрицу в поле класса
}
