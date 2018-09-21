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
    auto folder = opendir(dirPath.data());
    struct dirent *entry;
    while ((entry = readdir(folder)) != NULL) {
        if (nameVerification(entry->d_name) == 1) {
            fileNames.push_back(entry->d_name);
        }
    }
}

int dataSet::nameVerification(std::string name) {
    int i = 0, result = 1;
    while ((i < garbageNames.size()) && (result == 1)) {
        result = name == garbageNames[i]? 0: 1;
        i++;
    }
    return result;
}

std::vector<std::string> &dataSet::getFileList() { 
    return fileNames;
}


