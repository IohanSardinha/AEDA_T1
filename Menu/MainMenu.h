#ifndef PROJECT1_MAINMENU_H
#define PROJECT1_MAINMENU_H

#include "Menu.h"

class MainMenu :public Menu{
public:
    MainMenu();
    void criarAeroporto(); //falta implementar
    void deletarAeroporto();
    void CallMenu();
    Aeroporto* escolherAeroporto();
    void setAeroporto(Aeroporto* a){};
    void setAviao(Aviao* a){};
};

#endif //PROJECT1_MAINMENU_H
