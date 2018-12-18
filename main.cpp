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
    CItem *pupka6=new CItem("linux",15.0,80.0);



    vector<CItem *> *list=new vector<CItem *>();
    list->push_back(pupka);
    list->push_back(pupka1);
    list->push_back(pupka2);
    list->push_back(pupka3);
    list->push_back(pupka4);
    list->push_back(pupka5);
    list->push_back(pupka6);

    CKnapsackProblem *problem=new CKnapsackProblem(*list,15.0);

    CGeneticAlgorithm *alg=new CGeneticAlgorithm(10,40,10,*problem);

    alg->run(10);
    cout<<"HOHOHOHOHOHOOHOH"<<endl;
    alg->wyswietlNajlepszego();

    cout<<""<<endl;



    delete pupka;
    delete pupka1;
    delete pupka2;
    delete pupka3;
    delete pupka4;
    delete pupka5;

    delete list;
    delete problem;//Tego nie trzeba usuwać
    delete alg;

    return 0;
}