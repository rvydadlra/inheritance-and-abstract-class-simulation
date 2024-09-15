/* 
* @file Test.cpp
* @description veri.txt dosyas�ndan okunan her sat�r� avl a�a�lar�na ve y���tlara ekleyip gerekli i�lemleri ger�ekle�tirmek
* @course �kinci ��retim B grubu
* @assignment 2.�dev
* @date Kodu 24.12.2023
* @author R�veyda Dilara G�lba� ruveyda.gulbas@ogr.sakarya.edu.tr
*/
#include<iostream>
#include <fstream>
#include <sstream>
#include "AVLNode.hpp"
#include "StackNode.hpp"
#include "AVLTree.hpp"
#include "Stack.hpp"
using namespace std;

int findAndRemoveMinFromCopyStacks(Stack* copyStacks, int numCopyStacks)
{
    int minVal = 2147483647; // Ba�lang��ta en b�y�k int de�eri
    int minIndex = -1;    // En k���k de�erin bulundu�u kopya y���n�n indisini sakla

    // Her bir kopya y���n�ndan pop et
    for (int i = 0; i < numCopyStacks; ++i) {
        if (!copyStacks[i].isEmpty()) {
            AVLNode* currentTop = copyStacks[i].top->data;
            if (currentTop->data < minVal) {
                minVal = currentTop->data;
                minIndex = i;
            }
        }
      
    }


    // En k���k de�eri bulundu�u y���ndan ��kar
  // copyStacks[minIndex].printStack();
    return minIndex;
}
// Kopya y���tlar� kar��la�t�rarak en b�y���n� bulan ve ��karan fonksiyon
int findAndRemoveMaxFromCopyStacks(Stack* copyStacks, int numCopyStacks) {
    int maxVal = 2147483648; // Ba�lang��ta en k���k int de�eri
    int maxIndex = -1;    // En b�y�k de�erin bulundu�u kopya y���n�n�n indisini sakla

    // Her bir kopya y���n�ndan pop et
    for (int i = 0; i < numCopyStacks; ++i) {
        if (!copyStacks[i].isEmpty()) {
            AVLNode* currentTop = copyStacks[i].top->data;
            if (currentTop->data > maxVal) {
                maxVal = currentTop->data;
                maxIndex = i;
            }
        }
    }


    // En b�y�k de�eri bulundu�u y���ndan ��kar
  // copyStacks[maxIndex].printStack();
   // cout << "En buyuk deger: " << maxNode->data << " (Kopya yigin: " << maxIndex << ")" << endl;

    return maxIndex;
}
int processCopyStacks(Stack* copyStacks, int numCopyStacks) {
    // Herhangi bir y���n�n bo� olup olmad���n� kontrol et
   
    bool anyStackEmpty = false;
 
   //  Her bir kopya y���n�n�n durumunu kontrol et
    //for (int i = 0; i < numCopyStacks; ++i) 
    //{
    //  
    //    // E�er y���n bo�sa
    //    if (copyStacks[i].isEmpty())
    //    {
    //          cout << "buras�";
    //       // cout << "Yigit " << i << " bosaldigi icin islem durduruldu." << endl;
    //        copyStacks[i].clearStack();
    //        return i;

    //        
    //    }
    //}

    //// En az bir y���n bo�sa, i�lemi durdur
    //if (anyStackEmpty) {
    //    return 0;
    //}

    // Her iki i�lemi de ba�ar�yla ger�ekle�tirmeye �al��
    int minNode = findAndRemoveMinFromCopyStacks(copyStacks, numCopyStacks);

    if (copyStacks[minNode].isEmpty())
    {
      
        anyStackEmpty = true; // En az bir y���n bo�
      //     cout << "Yigit " << minNode << " bosaldigi icin islem durduruldu." << endl;
        copyStacks[minNode].clearStack();
        return minNode;

    }
    if (anyStackEmpty)
    {
        return -1;

    }
 

    int maxNode = findAndRemoveMaxFromCopyStacks(copyStacks, numCopyStacks);
  
    if (copyStacks[maxNode].isEmpty())
    {

        anyStackEmpty = true; // En az bir y���n bo�
      //    cout << "Yigit " << minNode << " bosaldigi icin islem durduruldu." << endl;
        copyStacks[maxNode].clearStack();
        return minNode;

    }
    if (anyStackEmpty)
    {
        return -1;

    }

    // E�er her iki i�lem de ba�ar�s�z de�ilse i�lemleri tekrarla
    if ((minNode != -1) || (maxNode != -1)) {
        processCopyStacks(copyStacks, numCopyStacks);
    }
    return 0;
}
int findEmptyStackIndex(Stack* leafStack, int agacSayisi) {
    for (int i = 0; i < agacSayisi; ++i) {
        if (leafStack[i].isEmpty()) {
            return i;
        }
    }
}
int main() {
    const char* dosyaAdi = "Veri.txt";

    std::ifstream dosya(dosyaAdi);

    if (!dosya) {
        std::cerr << "Dosya acilamadi: " << dosyaAdi << std::endl;
        return 1;
    }

    AVLTree* avlTree;
    Stack* leafStack;
    Stack* copyStack;

    std::string satir;
    int agacSayisi = 0;
    while (getline(dosya, satir)) {
        agacSayisi++;
    }

    dosya.clear();
    dosya.seekg(0, std::ios::beg);

    avlTree = new AVLTree[agacSayisi];
    leafStack = new Stack[agacSayisi * 100];
    copyStack = new Stack[agacSayisi * 100];

    for (int i = 0; i < agacSayisi; ++i) {
        getline(dosya, satir);
        std::istringstream ss(satir);
        int sayi;

        while (ss >> sayi) {
            avlTree[i].root = avlTree[i].insert(avlTree[i].root, sayi);

        }
   
        avlTree[i].addLeavesToStack(avlTree[i].root, leafStack[i]);
        avlTree[i].addLeavesToStack(avlTree[i].root, copyStack[i]);




        int nonLeafSum = avlTree[i].sumNonLeafNodes(avlTree[i].root);
        avlTree[i].printCharCodes();

    }
   int  a = 0;
   int b = 0;
   int c = agacSayisi;
    while(agacSayisi>1)
    {
        a = findAndRemoveMinFromCopyStacks(copyStack, c);
        copyStack[a].pop();
      //  copyStack[a].printStack();
        if (copyStack[a].isEmpty())
        {
            leafStack[a].clear();
            avlTree[a].deleteTree();
            agacSayisi--;
            for (int i = 0; i < c; i++)
            {
                avlTree[i].printCharCodes();

            }
            cout << endl;
            system("cls");

            if (agacSayisi == 1)
            {
               
                for (int i = 0; i < c; i++)
                {
                    avlTree[i].printCharCodes();
                    if (avlTree[i].root != nullptr)
                    {
                        cout <<endl<< "AVL NO: " << i+1;
                    }
                }
                return 0;
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    leafStack[i].copyNonEmptyElementsTo(copyStack[i]);

                }
            }
            continue;
        }

         b = findAndRemoveMaxFromCopyStacks(copyStack, c);
        copyStack[b].pop();
       // copyStack[b].printStack();
        if (copyStack[b].isEmpty())
        {
            avlTree[b].deleteTree();
            leafStack[b].clear();
            agacSayisi--;
            for (int i = 0; i < c; i++)
            {
                
                avlTree[i].printCharCodes();

            }    
            cout << endl;

            system("cls");
            if (agacSayisi == 1)
            {
                for (int i = 0; i < c; i++)
                {
                    avlTree[i].printCharCodes();
                    if (avlTree[i].root != nullptr)
                    {
                        cout <<endl<<"AVL NO: " << i + 1;
                    }
                }
                return 0;
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    leafStack[i].copyNonEmptyElementsTo(copyStack[i]);

                }
            }
        }

    }

 delete[] avlTree;
    delete[] copyStack;
    cout << endl;
    dosya.close();
    return 0;
    return 0;
}