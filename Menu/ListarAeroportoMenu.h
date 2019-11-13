#ifndef PROJECT1_LISTARAEROPORTOMENU_H
#define PROJECT1_LISTARAEROPORTOMENU_H

#include "MainMenu.h"

class ListarAeroportoMenu: public Menu{
public:
    ListarAeroportoMenu();
    void porLocalizacao();
    void porQuantidadeFuncionarioAdministrativo();
    void porQuantidadeFuncionario();
    void porQuantidadePilotos();
    void porQuantidadeMembroTripulacao();
    void porQuantidadeAvioes();
    void escolherAeroporto();
    void CallMenu();
    void setAeroporto(Aeroporto* a){};
    void setAviao(Aviao* a){};
};
#endif //PROJECT1_LISTARAEROPORTOMENU_H
