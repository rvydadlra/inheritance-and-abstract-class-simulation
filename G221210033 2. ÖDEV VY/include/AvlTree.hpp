/* 
* @file AVLTree.hpp
* @description veri.txt dosyasından okunan her satırı avl ağaçlarına ve yığıtlara ekleyip gerekli işlemleri gerçekleştirmek
* @course İkinci Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#ifndef AVLTree_HPP
#define AVLTree_HPP
#include "AVLNode.hpp"
#include "Stack.hpp"
class AVLTree {
public:
    AVLNode* root;
    Stack leafStack;  // Yaprakları tutan bağlı liste başlangıcı

    AVLTree() : root(nullptr) {}
    void printAddress();
        
    void postorderPrintWithAddresses(AVLNode* node);
        
    AVLNode* createNode(int data);  // Yeni bir düğüm oluşturan yardımcı fonksiyon
    AVLNode* insert(AVLNode* node, int data);
    int updateHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    void printTree(AVLNode* node);
    void addLeavesToStack(AVLNode* node, Stack& leafStack);
    int sumNonLeafNodes(AVLNode* node);
    void printCharCodes();
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    void deleteTree();
};
#endif