//
// Created by marcel on 07.12.18.
//

#include "CGeneticAlgorithm.h"
#include <iostream>
#include <string>
#include <random>


CGeneticAlgorithm::CGeneticAlgorithm(int popSize, int crossProb, int mutProb,CKnapsackProblem &problem) {
    if(popSize<=0){
        cout<<"Podana zla wartosc popSize ustawiona domyslna"<<endl;
        this->popSize=5;
    }else{
        this->popSize=popSize;
    }
    if(crossProb<=0){
        cout<<"Podana zla wartosc crossProb ustawiona domyslna"<<endl;
        this->crossProb=5;
    }else{
        this->crossProb=crossProb;
    }
    if(mutProb<=0){
        cout<<"Podana zla wartosc mutProb ustawiona domyslna"<<endl;
        this->mutProb=5;
    }else{
        this->mutProb=mutProb;
    }
    this->problem=&problem;
    this->best=new CIndividual(this->problem);

}

CGeneticAlgorithm::~CGeneticAlgorithm() {
    delete best;
}

void CGeneticAlgorithm::run(int operations) {

    vector<CIndividual *> *population=generatePopulation();

    for(int i=0;i<operations;i++){
        vector<CIndividual *> *newPopulation=new vector<CIndividual *>();

        findTheBestCIndividual(population);

        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<std::mt19937::result_type> dist6(1,100);

        while(newPopulation->size()<popSize){

            CIndividual *firstParent=new CIndividual(findParent(population));
            CIndividual *secondParent=new CIndividual(findParent(population));

            int prawdKrzyz=dist6(rng);
            if(prawdKrzyz<=crossProb){
                vector<CIndividual *> *kids=firstParent->crossOver(*secondParent);
                for(int j=0;j<kids->size();j++){
                    kids->at(j)->mutate(mutProb);
                    CIndividual *kidToAdd=new CIndividual(*kids->at(j));
                    newPopulation->push_back(kidToAdd);
                    delete (*kids)[j];
                }


            }else{
                newPopulation->push_back(firstParent);
                newPopulation->push_back(secondParent);
            }


        //PAMIETAC O USUWANIU POPULACJI (chyba jest ok)
        }
        for(int k=0;k<population->size();k++){
            delete (*population)[k];
        }
        population=newPopulation;

    }
    for(int p=0;p<population->size();p++){
        delete (*population)[p];

    }
    delete population;


}


vector<CIndividual *>* CGeneticAlgorithm::generatePopulation() {
    vector<CIndividual *>* toReturn=new vector<CIndividual *>();
    for(int i=0;i<popSize;i++){
        toReturn->push_back(new CIndividual(problem));
    }

    return toReturn;
}

void CGeneticAlgorithm::findTheBestCIndividual(vector<CIndividual *> *vector) {
    CIndividual *besto=vector->at(0);

    for(int i=1;i<vector->size();i++){
        if(vector->at(i)->countFitness()>besto->countFitness()){
            besto=vector->at(i);
        }
    }

    if(best->countFitness()<besto->countFitness()){
        delete best;
        best=new CIndividual(*besto);

    }
}

CIndividual &CGeneticAlgorithm::findParent(vector<CIndividual *> *vector) {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(0,vector->size()-1);
    int randomIndex1=dist6(rng);
    int randomIndex2=dist6(rng);
    CIndividual *toReturn=(vector->at(randomIndex1)->countFitness()>=vector->at(randomIndex2)->countFitness()) ? vector->at(randomIndex1):vector->at(randomIndex2);
    return *toReturn;

}

void CGeneticAlgorithm::wyswietlNajlepszego() {

    for(int i=0;i<problem->getItemList()->size();i++){
        if(best->getGenotyp().at(i)==1){
            cout<<problem->getItemList()->at(i)->getNazwa()+" ma wagę: ";
            cout<<problem->getItemList()->at(i)->getWaga();
            cout<<" i wartosc: ";
            cout<<+problem->getItemList()->at(i)->getWartosc()<<endl;
        }
    }

}