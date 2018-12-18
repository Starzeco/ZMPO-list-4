//
// Created by marcel on 06.12.18.
//

#include "CKnapsackProblem.h"
#include <string>
#include <iostream>

using  namespace std;

CKnapsackProblem::CKnapsackProblem(vector<CItem *> &list, double rozmiarPlecaka) {
    if(rozmiarPlecaka<=0){
        cout<<"Podana zla wartosc rozmiaru plecaka, ustawiona domyslna"<<endl;
        this->rozmiarPlecaka=5;
    }else{
        this->rozmiarPlecaka=rozmiarPlecaka;
    }
    itemList=&list;
}


CKnapsackProblem::~CKnapsackProblem() {


}

void CKnapsackProblem::deCodeGenotype(vector<int> &genotype) {

    for(int i=0;i<genotype.size();i++){
        if(genotype.at(i)==1){
            (*itemList)[i]->toString();

           cout<<""<<endl;
        }
    }
}

vector<CItem *> *CKnapsackProblem::getItemList() {
    return itemList;
}

double CKnapsackProblem::getRozmiarPlecaka() {
    return rozmiarPlecaka;
}