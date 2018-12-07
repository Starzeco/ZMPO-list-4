#include <iostream>
#include "CIndividual.h"
#include "CGeneticAlgorithm.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    CItem *pupka=new CItem("pupka",3.0,10.0);
    CItem *pupka1=new CItem("hejka",8.0,7.0);
    CItem *pupka2=new CItem("dom",2.0,4.0);
    CItem *pupka3=new CItem("trololo",9.0,2.0);
    CItem *pupka4=new CItem("koko",1.0,4.0);
    CItem *pupka5=new CItem ("lili",7.0,10.0);




    vector<CItem *> *list=new vector<CItem *>();
    list->push_back(pupka);
    list->push_back(pupka1);
    list->push_back(pupka2);
    list->push_back(pupka3);
    list->push_back(pupka4);
    list->push_back(pupka5);

    CKnapsackProblem *problem=new CKnapsackProblem(*list,15.0);

    CGeneticAlgorithm *alg=new CGeneticAlgorithm(10,40,10,*problem);

    alg->run(1000);
    cout<<"HOHOHOHOHOHOOHOH"<<endl;
    alg->wyswietlNajlepszego();

    cout<<""<<endl;
  /*  CIndividual *p=new CIndividual(problem);
    p->showGenotyp();

    cout<<""<<endl;
    cout<<p->countFitness();
    cout<<""<<endl;

    //p->mutate();          Teraz trzeba przekazywac szanse na mutacje
    cout<<""<<endl;
    p->showGenotyp();
    cout<<""<<endl;
    cout<<p->countFitness();
    cout<<""<<endl;

    CIndividual *p2=new CIndividual(*p);

    p2->showGenotyp();
    //p2->mutate();             Teraz trzeba przekazywac szanse na mutacje
    //cout<<"HOHOHOHOHHHOHO"<<endl;

   /* vector<CIndividual *> *c=p->crossOver(*p2);
    for(int i=0;i<2;i++){
        c->at(i)->showGenotyp();
    } */


    delete pupka;
    delete pupka1;
    delete pupka2;
    delete pupka3;
    delete pupka4;
    delete pupka5;

    delete list;
    delete problem;
    delete alg;
   // delete p;
   // delete p2;
    return 0;
}