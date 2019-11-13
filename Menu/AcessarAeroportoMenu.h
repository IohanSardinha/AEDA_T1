#ifndef PROJECT1_ACESSARAEROPORTOMENU_H
#define PROJECT1_ACESSARAEROPORTOMENU_H

#include "Menu.h"

class AcessarAeroportoMenu: public Menu{
    Aeroporto* aeroporto;
public:
    AcessarAeroportoMenu();
    void CallMenu();
    void alterarGerente();
    void alterarLocalizacao();
    void setAeroporto(Aeroporto* a);
    //classe funcionario e classe AVioes
};

#endif //PROJECT1_ACESSARAEROPORTOMENU_H
