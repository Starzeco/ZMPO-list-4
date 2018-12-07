//
// Created by marcel on 06.12.18.
//

#ifndef UNTITLED_CKNAPSACKPROBLEM_H
#define UNTITLED_CKNAPSACKPROBLEM_H
#pragma once
#endif //UNTITLED_CKNAPSACKPROBLEM_H

#include <ostream>
#include <string>
#include <vector>
#include "CItem.h"

using namespace std;

class CKnapsackProblem{


public:
    CKnapsackProblem(vector<CItem*> &list,double rozmiarPlecaka);
    ~CKnapsackProblem();
    double getRozmiarPlecaka();
    vector<CItem *> *getItemList();

    void deCodeGenotype(vector<int> &genotype);




private:
    vector<CItem*> *itemList;
    double rozmiarPlecaka;




};