/* 
* @file Stack.hpp
* @description veri.txt dosyasından okunan her satırı avl ağaçlarına ve yığıtlara ekleyip gerekli işlemleri gerçekleştirmek
* @course İkinci Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef Stack_HPP
#define Stack_HPP
#include "AVLNode.hpp"
#include "StackNode.hpp"
class Stack {
public:
     StackNode* top;
    StackNode* lastAdded;
    Stack() : top(nullptr), lastAdded(nullptr) {}

    void push(AVLNode* data);
    AVLNode* pop();
    bool isEmpty();

    // Kopya yapıcı fonksiyon
    Stack(const Stack& other);

    // PrintStack fonksiyonu ekleyin
    void printStack();
    void clear();

    
    void clearStack();
    void copyNonEmptyElementsTo(Stack&destination);
   
};
#endif