/* 
* @file Stack.cpp
* @description veri.txt dosyasından okunan her satırı avl ağaçlarına ve yığıtlara ekleyip gerekli işlemleri gerçekleştirmek
* @course İkinci Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "Stack.hpp"
#include "StackNode.hpp"
using namespace std;

void Stack::push(AVLNode* data) {
    StackNode* newNode = new StackNode(data);
    newNode->next = top;
    top = newNode;
    lastAdded = newNode;
}
bool Stack::isEmpty() {
    return (top == nullptr);
}
AVLNode* Stack::pop() {
    if (isEmpty())
		{
        std::cerr << "Yigit bos!" << std::endl;
        return nullptr;
    }

    StackNode* temp = top;
    AVLNode* poppedData = temp->data;
    top = temp->next;
    delete temp;
    return poppedData;
}
void Stack::clear() {
    while (!isEmpty()) 
    {
      pop();
    }
}
// PrintStack fonksiyonu ekleyin
void Stack::printStack() {
    StackNode* temp = top;
    if (!isEmpty()) {
        while (temp != nullptr) {
            std::cout << temp->data->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    else
    {
       cout << "Yigit bos";
    }
}
void Stack::clearStack() {
    while (!isEmpty()) {
        AVLNode* node = pop();
        delete node; // Düğümü sil
    }
}
void Stack::copyNonEmptyElementsTo(Stack& destination) {
    if (!isEmpty()) {
        StackNode* current = top;

        // İlk elemanı kopyala
        destination.top = new StackNode(new AVLNode(*current->data));
        destination.lastAdded = destination.top;
        current = current->next;

        // Geri kalan elemanları kopyala
        while (current != nullptr) {
            destination.lastAdded->next = new StackNode(new AVLNode(*current->data));
            destination.lastAdded = destination.lastAdded->next;
            current = current->next;
        }
    }
}
