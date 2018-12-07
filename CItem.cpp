//
// Created by marcel on 06.12.18.
//

#include <iostream>
#include <string>
#include "CItem.h"

CItem::CItem(string nazwa, double waga, double wartosc) {
    this->nazwa=nazwa;
    if(waga<=0){
        cout<<"Podana zla waga, ustawiona domyslna"<<endl;
        this->waga=5;
    }else{
        this->waga=waga;
    }
    if(wartosc<=0){
        cout<<"Podana zla wartosc, ustawiona domyslna"<<endl;
        this->wartosc=5;
    }else{
        this->wartosc=wartosc;
    }

}

CItem::~CItem() {
    cout<<"Destruktor Item'u"<<endl;
}

string CItem::toString() {
    cout<<nazwa+" ma wartosc: ";
    cout<<wartosc;
    cout<<" i wage: ";
    cout<<waga;
}

string CItem::getNazwa() {
    return nazwa;
}

double CItem::getWaga() {
    return waga;
}


double CItem::getWartosc() {
    return wartosc;
}