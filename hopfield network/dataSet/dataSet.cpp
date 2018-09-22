//
//  dataSet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "dataSet.hpp"
#include <dirent.h>
#include <iostream>

dataSet::dataSet(std::string dirPath) {
    // открываем поток папки.
    auto folder = opendir(dirPath.data());
    struct dirent *entry;
    // перебираем имена папок
    while ((entry = readdir(folder)) != NULL) {
        // проверяем, не мусор ли мы отловили?
        if (nameVerification(entry->d_name) == 1) {
            // записываем имя в список.
            fileNames.push_back(entry->d_name);
        }
    }
}

int dataSet::nameVerification(std::string name) {
    int i = 0, result = 1;
    // перебираем имена, выходем как только перебирём все или найдём совпадения.
    while ((i < garbageNames.size()) && (result == 1)) {
        result = name == garbageNames[i]? 0: 1;
        i++;
    }
    return result;
}

std::vector<std::string> &dataSet::getFileList() {
    // возвращаем ссылку
    return fileNames;
}
