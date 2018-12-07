//
// Created by marcel on 06.12.18.
//
#pragma once
#ifndef UNTITLED_CINDIVIDUAL_H
#define UNTITLED_CINDIVIDUAL_H

#endif //UNTITLED_CINDIVIDUAL_H

#include <iostream>
#include <string>
#include <vector>
#include "CKnapsackProblem.h"

using namespace std;

class CIndividual{


public:
    CIndividual(CKnapsackProblem *problem);

    CIndividual(CIndividual &toCopy);
    ~CIndividual();

    vector<int> getGenotyp();

    void showGenotyp();

    double countFitness();

    void mutate(int mutationChance);

    vector<CIndividual *> *crossOver(CIndividual &other);

private:
    vector<int> *genotyp=new vector<int>();
    CKnapsackProblem *problem;



};