//
//  dataSet.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef dataSet_hpp
#define dataSet_hpp

#include <stdio.h>
#include <vector>
#include <string>

class dataSet {
public:
    dataSet(){} // пустой конструктор на случа   наследования.
    dataSet(std::string dirPath); // конструктор принимает на вход путь к папке с файлами.
    /**
     доступ к вектору с именами файлов.

     @return ссылку на вектор с именами файлов.
     */
    virtual std::vector<std::string>& getFileList();
private:
    /**
     метод проверяет, не находится ли переданное имя в списке мусорных.

     @param name проверяемое имя
     @return 1 Если имя хорошее, 0 если мусор.
     */
    int nameVerification(std::string name);
    std::vector<std::string> fileNames; // найденный список имён файлов в данном коталоге.
    const std::vector<std::string> garbageNames ={".", "..", ".DS_Store"}; // список имён коталога, которые точно не будут именами файлов.
};

#endif /* dataSet_hpp */
