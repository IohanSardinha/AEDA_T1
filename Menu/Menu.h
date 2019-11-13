#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../Classes/Aeroporto.h"
#include "../Utils/sorts.h"

using namespace std;

class Menu {
protected:
    vector<string> opcoes;
    int input;
public:
    Menu()= default;
    void print();
    void play();
    void getInput();
    virtual void CallMenu() = 0;
    virtual void setAeroporto(Aeroporto* a) = 0;
    virtual void setAviao(Aviao* a) = 0;
};

#endif //PROJECT1_MENU_H
