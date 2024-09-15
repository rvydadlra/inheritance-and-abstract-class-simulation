/* 
* @file StackNode.hpp
* @description veri.txt dosyasından okunan her satırı avl ağaçlarına ve yığıtlara ekleyip gerekli işlemleri gerçekleştirmek
* @course İkinci Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef StackNode_HPP
#define StackNode_HPP
#include "AVLNode.hpp"

class StackNode {
public:
    AVLNode* data;
    StackNode* next;

    StackNode(AVLNode* val) : data(val), next(nullptr) {}
};

#endif