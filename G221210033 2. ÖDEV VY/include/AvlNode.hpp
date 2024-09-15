/* 
* @file AvlNode.hpp
* @description veri.txt dosyasından okunan her satırı avl ağaçlarına ve yığıtlara ekleyip gerekli işlemleri gerçekleştirmek
* @course İkinci Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef AvlNode_HPP
#define AvlNode_HPP

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

#endif