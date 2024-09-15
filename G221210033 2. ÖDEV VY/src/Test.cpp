/* 
* @file Test.cpp
* @description veri.txt dosyasýndan okunan her satýrý avl aðaçlarýna ve yýðýtlara ekleyip gerekli iþlemleri gerçekleþtirmek
* @course Ýkinci Öðretim B grubu
* @assignment 2.Ödev
* @date Kodu 24.12.2023
* @author Rüveyda Dilara Gülbaþ ruveyda.gulbas@ogr.sakarya.edu.tr
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
    int minVal = 2147483647; // Baþlangýçta en büyük int deðeri
    int minIndex = -1;    // En küçük deðerin bulunduðu kopya yýðýnýn indisini sakla

    // Her bir kopya yýðýnýndan pop et
    for (int i = 0; i < numCopyStacks; ++i) {
        if (!copyStacks[i].isEmpty()) {
            AVLNode* currentTop = copyStacks[i].top->data;
            if (currentTop->data < minVal) {
                minVal = currentTop->data;
                minIndex = i;
            }
        }
      
    }


    // En küçük deðeri bulunduðu yýðýndan çýkar
  // copyStacks[minIndex].printStack();
    return minIndex;
}
// Kopya yýðýtlarý karþýlaþtýrarak en büyüðünü bulan ve çýkaran fonksiyon
int findAndRemoveMaxFromCopyStacks(Stack* copyStacks, int numCopyStacks) {
    int maxVal = 2147483648; // Baþlangýçta en küçük int deðeri
    int maxIndex = -1;    // En büyük deðerin bulunduðu kopya yýðýnýnýn indisini sakla

    // Her bir kopya yýðýnýndan pop et
    for (int i = 0; i < numCopyStacks; ++i) {
        if (!copyStacks[i].isEmpty()) {
            AVLNode* currentTop = copyStacks[i].top->data;
            if (currentTop->data > maxVal) {
                maxVal = currentTop->data;
                maxIndex = i;
            }
        }
    }


    // En büyük deðeri bulunduðu yýðýndan çýkar
  // copyStacks[maxIndex].printStack();
   // cout << "En buyuk deger: " << maxNode->data << " (Kopya yigin: " << maxIndex << ")" << endl;

    return maxIndex;
}
int processCopyStacks(Stack* copyStacks, int numCopyStacks) {
    // Herhangi bir yýðýnýn boþ olup olmadýðýný kontrol et
   
    bool anyStackEmpty = false;
 
   //  Her bir kopya yýðýnýnýn durumunu kontrol et
    //for (int i = 0; i < numCopyStacks; ++i) 
    //{
    //  
    //    // Eðer yýðýn boþsa
    //    if (copyStacks[i].isEmpty())
    //    {
    //          cout << "burasý";
    //       // cout << "Yigit " << i << " bosaldigi icin islem durduruldu." << endl;
    //        copyStacks[i].clearStack();
    //        return i;

    //        
    //    }
    //}

    //// En az bir yýðýn boþsa, iþlemi durdur
    //if (anyStackEmpty) {
    //    return 0;
    //}

    // Her iki iþlemi de baþarýyla gerçekleþtirmeye çalýþ
    int minNode = findAndRemoveMinFromCopyStacks(copyStacks, numCopyStacks);

    if (copyStacks[minNode].isEmpty())
    {
      
        anyStackEmpty = true; // En az bir yýðýn boþ
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

        anyStackEmpty = true; // En az bir yýðýn boþ
      //    cout << "Yigit " << minNode << " bosaldigi icin islem durduruldu." << endl;
        copyStacks[maxNode].clearStack();
        return minNode;

    }
    if (anyStackEmpty)
    {
        return -1;

    }

    // Eðer her iki iþlem de baþarýsýz deðilse iþlemleri tekrarla
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