#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <vector>
#include "Aeroporto.h"

using namespace std;

class Menu {
protected:
    vector<string> opcoes;
    int input;
    vector<Menu*> menus_to_call;
public:
    Menu()= default;
    void print();
    void getInput();
    virtual void CallMenu() = 0;
};

class MainMenu :public Menu{
public:
    MainMenu();
    void CallMenu();
};

#endif //PROJECT1_MENU_H
