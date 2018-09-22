//
//  distortedSignal.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef distortedSignal_hpp
#define distortedSignal_hpp

#include <stdio.h>
#include <vector>
#include <string>

class distortedSignal {
public:
    distortedSignal() {}
    distortedSignal(std::string filePath); // конструктор загружает изображение по полученному пути и преобразует его в биполярный вектор.
    /**
     доступ к биполярному вектору.

     @return ссылку на биполярный вектор
     */
    std::vector<int>& data();
    /**
     метод искажает сигнал добавляя 1 и -1 через случайные промежутки.
     */
    void toDistortTheSignal(); // метод искажает сигнал.
    ~distortedSignal();
private:
    std::vector<int> matrixInLineInBipolarForm;
};

#endif /* distortedSignal_hpp */
