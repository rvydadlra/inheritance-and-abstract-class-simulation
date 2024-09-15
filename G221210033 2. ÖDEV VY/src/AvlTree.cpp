/* 
* @file AVLNode.cpp
* @description veri.txt dosyasından okunan her satırı avl ağaçlarına ve yığıtlara ekleyip gerekli işlemleri gerçekleştirmek
* @course İkinci Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaş ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include <iostream>
using namespace std;
#include "AVLTree.hpp"
#include "AVLNode.hpp"
AVLNode* AVLTree::createNode(int data) {
    return new AVLNode(data);
}

int AVLTree::updateHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = (node->left != nullptr) ? node->left->height : 0;
    int rightHeight = (node->right != nullptr) ? node->right->height : 0;

    return 1 + std::max(leftHeight, rightHeight);
}
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = updateHeight(y);
    x->height = updateHeight(x);

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = updateHeight(x);
    y->height = updateHeight(y);

    return y;
}

int AVLTree::getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = (node->left != nullptr) ? node->left->height : 0;
    int rightHeight = (node->right != nullptr) ? node->right->height : 0;

    return leftHeight - rightHeight;
}
AVLNode* AVLTree::insert(AVLNode* node, int data) {
    if (node == nullptr) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    else {
        return node;
    }

    node->height = updateHeight(node);

    int balance = getBalanceFactor(node);

    if (balance > 1 && data < node->left->data) {
        return rotateRight(node);
    }

    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}
void AVLTree::printTree(AVLNode* node) {
    if (node != nullptr) {
        printTree(node->left);
        printTree(node->right);
        std::cout << node->data << " ";
    }
}

void AVLTree::addLeavesToStack(AVLNode* node, Stack& leafStack) {
    if (node != nullptr) {
        addLeavesToStack(node->left, leafStack);
        addLeavesToStack(node->right, leafStack);

        if (node->left == nullptr && node->right == nullptr) {
            leafStack.push(node);
        }
    }
}

int AVLTree::sumNonLeafNodes(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return 0;
    }

    return node->data + sumNonLeafNodes(node->left) + sumNonLeafNodes(node->right);
}

void AVLTree::printCharCodes() {
    int nonLeafSum = sumNonLeafNodes(root);
    if(nonLeafSum==0)
    {
        return;
    }
    char asciiChar = nonLeafSum % (90 - 65 + 1) + 65;

   // std::cout << "Yaprak Olmayan Dugumlerin Toplaminin ASCII Karakteri: ";
    cout << asciiChar;
}
void deleteAVLTree(AVLNode* node) {
    if (node != nullptr) {
        deleteAVLTree(node->left);
        deleteAVLTree(node->right);
        delete node;
    }
}

// AVLTree sınıfına eklenen fonksiyon
void AVLTree::deleteTree() {
    deleteAVLTree(root);
    root = nullptr;  // Ağaç boş olduğunda kökü nullptr yapmak iyi bir uygulama
}