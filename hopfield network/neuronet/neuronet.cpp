//
//  neuronet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "neuronet.hpp"

neuronet::neuronet(matrix& xMat, wMatrix& wMat, distortedSignal& dSignal) {
    // затаскиваем в себя значения
    xm = xMat;
    wm = wMat;
    ds = dSignal;
}

void neuronet::prod(std::vector<int>& y_prev, std::vector<double>& y_t) {
    // выделяем память
    y_t.resize(y_prev.size());
    // обходим матрицу
    for (int i = 0; i < wm.rows(); i++) {
        for (int j = 0; j < wm.cols(); j++) {
                y_t[i] += wm.at(i, j) * y_prev[j]; // вычисляем значения вектора
        }
    }
}

int neuronet::ToObtainThePercentageOfMatches(std::vector<int>& y_prev, std::vector<int>& y_t) {
    int coincidences = 0;
    for (int i = 0; i < y_prev.size(); i++) { // проходим вдоль векторов
        coincidences = y_t[i] == y_prev[i]? coincidences+1: coincidences; // считаем совпадения
    }
    int res = coincidences * 100 / y_t.size();
//    std::cout << "Процент совпадений " << res << std::endl;
    return res; // возвращаем в процентах
}

void neuronet::copyLToR(std::vector<int> &v1, std::vector<int> &v2) { 
    if (v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i++) {
            v2[i] = v1[i];
        }
    }
}

void neuronet::activation(std::vector<double>& vec, std::vector<int>& outVec) {
    outVec.resize(vec.size());
    for (int i = 0; i < vec.size(); i++) { // обходим вектор
        if (vec[i] > 0) { // если значение положительно?
            outVec[i] = 1; // записываем единицу
        } else if (vec[i] < 0) { // если отрицательное
            outVec[i] = -1; // записываем -1
    }
}
}
    
void neuronet::ranNV() {
    std::vector<int> y_t;
    y_t.resize(ds.data().size());
    std::vector<int> y_prev = ds.data();
    std::vector<double> timeVec;
    timeVec.resize(y_t.size());
    int nI = 0;    copyLToR(y_prev, y_t);
    do {
        copyLToR(y_t, y_prev);
        prod(y_prev, timeVec);
        activation(timeVec, y_t);
        nI++;
    } while (ToObtainThePercentageOfMatches(y_prev, y_t) <= 99);
    std::cout << "количество итераций " << nI << std::endl;
    resultVector = y_t;
}

void neuronet::exportresult(std::string dirPath) { 
    cv::Mat img(100, 100, CV_8UC1);
    // заполняем матрицу изображения
    for (int i = 0; i < img.rows * img.cols; i++) {
        if (resultVector[i] > 0) {
            img.at<uchar>(i) = 1;
        } else if (resultVector[i] < 0) {
            img.at<uchar>(i) = 255;
        } else {
            img.at<uchar>(i) = 128;
        }
    }
    dirPath = dirPath + "result.jpg"; // дополняем полученный путь именем файла
    cv::imwrite(dirPath, img); // пишем файл на диск
}

void neuronet::outWM(int i, int j) { 
    for (int r = 0; r < i; r++) {
        for (int c = 0; c < j; c++) {
            std::cout << wm.at(r, c) << " ";
        }
        std::cout << std::endl;
    }
}

int neuronet::ToDetermineTheNumberOfClassImage() { 
    int ind = -1, matchPercentage = 0;
    xm.generaitInMatrixForm();
    for (int i = 0; i < xm.rows(); i++) {
        int p = ToObtainThePercentageOfMatches(resultVector, xm.getMatrixInMatrixForm()[i]);
        if (p > matchPercentage) {
            matchPercentage = p;
            ind = i;
        }
    }
    return ind;
}


