//
//  main.cpp
//  UP
//
//  Created by mak on 16.05.2023.
//

/*1. Создать файл F1,содержащий заданное число матриц размером 2х2.
 Элементы матриц - целые числа в диапазоне 1…10,получить от датчика случайных чисел RANDOM.
 Из файла F1 получить файл F2 записей, каждая из которых содержит матрицу файла F1, ее наименьший и наибольший элементы и определитель.*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int min(int n1,int n2,int n3,int n4){
   
    int x = (n1 < n2) ? n1 : n2;
    int y = (n3 < n4) ? n3 : n4;
    return (x < y) ? x : y;
}
int max(int n1,int n2,int n3,int n4){
   
    int x = (n1 > n2) ? n1 : n2;
    int y = (n3 > n4) ? n3 : n4;
    return (x > y) ? x : y;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    //srand(time(NULL));
    srand((unsigned int) time(NULL));

    
    //Создать файл F1,содержащий заданное число матриц размером 2х2.Элементы матриц - целые числа в диапазоне 1…10,получить от датчика случайных чисел RANDOM.
    ofstream F1 ("F1.txt");
    int R =rand()%100;
    for (int i = 0; i < R; i++){
        for(int I=0; I < 2; I++){
            for(int J=0; J < 2; J++){
                int NUM = rand()%9 + 1;
                F1 << NUM<<"\t";
            }
            F1 << "\n";
        }
        F1 << "\n\n\n\n\n\n\n";
    }
    F1.close();
    
    ifstream f1("F1.txt");
    ofstream F2("F2.txt");
    for (int i = 0; i < R; i++){
        int n1,n2,n3,n4;
        f1 >> n1 >> n2 >> n3 >> n4;
        cout << n1 << "\t"<< n2 << "\n"<< n3 << "\t"<< n4 << "\n\n\n";
        cout << "min -> " << min(n1,n2,n3,n4) << "\n";
        cout << "max -> " << max(n1,n2,n3,n4) << "\n";
        cout << "det -> " << n1 * n4 - n2 * n3 << "\n\n\n";
        
        
        F2 << n1 << "\t"<< n2 << "\n"<< n3 << "\t"<< n4 << "\n\n\n";
        F2 << "min -> " << min(n1,n2,n3,n4) << "\n";
        F2 << "max -> " << max(n1,n2,n3,n4) << "\n";
        F2 << "det -> " << n1 * n4 - n2 * n3 << "\n\n\n";
    }
    
    
    f1.close();
    F2.close();
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
