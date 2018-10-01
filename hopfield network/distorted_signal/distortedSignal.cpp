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
    // загружаем изображение
    cv::Mat img = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
    cv::threshold(img, img, 128, 255, cv::THRESH_OTSU); // выполняем бинаризацию
    cv::resize(img, img, cv::Size(100, 100)); // уменьшаем масштаб изображения
    int size = img.rows * img.cols; // вычисляем размер
    matrixInLineInBipolarForm.resize(size); // выделяем память
    // выполняем биполяризацию
    for (int i = 0; i < size; i++) {
        if (img.at<uchar>(i) == 255) {
            matrixInLineInBipolarForm[i] = -1;
        } else {
            matrixInLineInBipolarForm[i] = 1;
        }
    }
}

void distortedSignal::toDistortTheSignal() { // искажение изображения
    int distans = static_cast<int>(matrixInLineInBipolarForm.size()/20); // шаг
    std::mt19937 gen(static_cast<int>(time(0))); // генератор случайных чисел с ядром случайности
    std::uniform_int_distribution<> uid(0, distans); // задаём промежуток.
    for (int i = 0; i < matrixInLineInBipolarForm.size(); i+=distans) { // идём вдоль вектора
        int  ind = i + uid(gen); // в случайных местах
        matrixInLineInBipolarForm[ind] = 1; //  вставляем единицы
    }
    for (int i = 0; i < matrixInLineInBipolarForm.size(); i+=distans) { // сново проходим по массиву
        int  ind = i + uid(gen); // и в случайных местах
        matrixInLineInBipolarForm[ind] = -1; // вставляем -1
    }
}

std::vector<int> &distortedSignal::data() { 
    return matrixInLineInBipolarForm;
}
