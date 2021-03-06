//
//  matrix.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <vector>

class matrix {
public:
    matrix() {} // пустой конструктор на случай появления наследников.
    matrix(int rows, int cols); // конструктор заполняет поля класса и задаёт размер поля матрицы.
    /**
     метод риализует доступ к полю матрицы

     @return ссылку на вектор содержащий матрицу.
     */
    std::vector<int>& data(); // реализует прямой доступ к вектору, содержащему матрицу.
    /**
     метод принимает координаты и приобразует их в линейный индекс.

     @param i Номер строки
     @param j номер столбца
     @return ссылка на элемент матрицы
     */
    int& at(int i, int j); // метод реализует доступ к элементу матрицы по координатам.
    /**
     метод возвращает количество строк в матрице.

     @return количество строк в матрице
     */
    int rows(); // метод возвращает количество строк в матрицы.
    /**
     столбцыы

     @return количество столбцов в матрице.
     */
    int cols(); // метод возвращает количество столбцов в матрице.
    /**
     размер

     @return размер вектора линеризованной матрицы.
     */
    int size(); // метод возвращает размер матрицы.
    void generaitInMatrixForm();
    std::vector<std::vector<int>>& getMatrixInMatrixForm();
protected:
    std::vector<int> matrixInLine; // поле хранит в себе линеризованную матрицу.
    int mHaid, mWits, mSize; // поля высоты, ширины и размера матрицы.
    std::vector<std::vector<int>> matrixInMatrixForm;
};

#endif /* matrix_hpp */
