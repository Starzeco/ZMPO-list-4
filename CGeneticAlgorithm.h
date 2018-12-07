//
// Created by marcel on 07.12.18.
//

#ifndef UNTITLED_CGENETICALGORITHM_H
#define UNTITLED_CGENETICALGORITHM_H

#endif //UNTITLED_CGENETICALGORITHM_H

#include <iostream>
#include <string>
#include <random>
#include "CIndividual.h"

using namespace std;

class CGeneticAlgorithm{


public:
    CGeneticAlgorithm(int popSize,int crossProb,int mutProb,CKnapsackProblem &problem);
    ~CGeneticAlgorithm();
    void run(int operations);

    vector<CIndividual *> *generatePopulation();

    void findTheBestCIndividual(vector<CIndividual *> *vector);
    CIndividual &findParent(vector<CIndividual *> *vector);

    void wyswietlNajlepszego();
private:

    int popSize;
    int crossProb;
    int mutProb;
    CIndividual *best;
    CKnapsackProblem *problem;




};