//
//  imageDataSet.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef imageDataSet_hpp
#define imageDataSet_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "dataSet.hpp"
#include "matrix.hpp"

class imageDataSet: dataSet {
public:
    imageDataSet() {}
    imageDataSet(std::string dirPath, dataSet ds); // конструктор загрузит изображения в вектор изображений.
    /**
     доступ к вектору изображений

     @return ссылку на вектор с изображениями.
     */
    std::vector<cv::Mat>& getImageSet();
    /**
     доступ к матрицы с линеризованным видом.

     @return ссылку на линеризованную матрицу с биполярными значениями.
     */
    matrix& getInlineMatrix();
    /**
     метод создаёт линеризованный вид.
     */
    void generaitInLineForm();
private:
    std::vector<cv::Mat> setImages;
    matrix mat;
};

#endif /* imageDataSet_hpp */
