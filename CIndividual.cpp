//
// Created by marcel on 06.12.18.
//

#include "CIndividual.h"
#include <iostream>
#include <string>
#include <random>


using namespace std;

CIndividual::CIndividual(CKnapsackProblem *problem)  {

    this->problem=problem;
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(0,1);
    for(int i=0;i<problem->getItemList()->size();i++){


        genotyp->push_back(dist6(rng));
    }

}

CIndividual::CIndividual(CIndividual &toCopy) {
    this->problem=toCopy.problem;
    this->genotyp=new vector<int>();
    for(int i=0;i<toCopy.genotyp->size();i++){
        int k=toCopy.getGenotyp().at(i);
        this->genotyp->push_back(k);
    }

}


CIndividual::~CIndividual() {
    delete genotyp;
    //cout<<"Detruktor individuala"<<endl;
}


vector<int> CIndividual::getGenotyp() {
    return *genotyp;
}

void CIndividual::showGenotyp() {

    for(int i=0;i<genotyp->size();i++){
        cout<<genotyp->at(i)<<" , ";


    }
    cout<<""<<endl;
}


double CIndividual::countFitness() {
    double limit=problem->getRozmiarPlecaka();
    double fitness=0;
    double waga=0;

    for(int i=0;i<genotyp->size();i++){
        if(genotyp->at(i)==1){
            fitness+=problem->getItemList()->at(i)->getWartosc();
        }
    }
    for(int i=0;i<genotyp->size();i++){
        if(genotyp->at(i)==1){
            waga+=problem->getItemList()->at(i)->getWaga();
        }
    }
    if(waga>limit){
        fitness=0;
    }

    return fitness;

}

void CIndividual::mutate(int mutacja) {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(1,100);


    for(int i=0;i<genotyp->size();i++){
        int wylosowanaSzansa=dist6(rng);
        if(wylosowanaSzansa<=mutacja){
            if(genotyp->at(i)==1){
                //cout<<"Zaszla mutacja z 1 na 0 na pozycji: ";
               // cout<<i<<endl;                                   //TODO Delete
                genotyp->at(i)=0;
            }else{
               // cout<<"Zaszla mutacja z 0 na 1 na pozycji: ";
               // cout<<i<<endl;                                   //TODO Delete
                genotyp->at(i)=1;
            }
            //countFitness();
        }
    }
}

vector<CIndividual *> *CIndividual::crossOver(CIndividual &other) {
    vector<CIndividual *> *toReturn=new vector<CIndividual *>();

    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist6(1,problem->getItemList()->size()-1);

    int crossPlace=dist6(rng);

    CIndividual *first=new CIndividual(problem);
    CIndividual *second=new CIndividual(problem);

    for(int i=0;i<crossPlace;i++){
        first->genotyp->at(i)=this->genotyp->at(i);
        second->genotyp->at(i)=other.genotyp->at(i);
    }
    for(int i=crossPlace;i<genotyp->size();i++){
        first->genotyp->at(i)=other.genotyp->at(i);
        second->genotyp->at(i)=this->genotyp->at(i);
    }

    toReturn->push_back(first);
    toReturn->push_back(second);

    //cout<<crossPlace<<endl; //TODO DELETE
    return toReturn;

}