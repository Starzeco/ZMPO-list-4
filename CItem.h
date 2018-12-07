//
// Created by marcel on 06.12.18.
//

#include <string>
#pragma once
#ifndef UNTITLED_CITEM_H
#define UNTITLED_CITEM_H

#endif //UNTITLED_CITEM_H
using namespace std;


class CItem{


public:
    CItem(string nazwa,double waga,double wartosc);
    ~CItem();
    double getWaga();
    double getWartosc();
    string getNazwa();
    string toString();



private:
    string nazwa;
    double waga;
    double wartosc;




};