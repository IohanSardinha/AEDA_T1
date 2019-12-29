#ifndef PROJECT1_EMPRESAMENU_H
#define PROJECT1_EMPRESAMENU_H

#include "Menu.h"


class EmpresaMenu:public Menu{
    Aeroporto* aeroporto;
    Aviao* aviao;
public:
    Empresa escolherEmpresa();
    void CallMenu();
    EmpresaMenu();
    void criarEmpresa();
    void deletarEmpresa();
    void editarEmpresa();
    void listarEmpresas();
    void usarEmpresa();
    Aviao* escolherAviao();
    void setAeroporto(Aeroporto* a);
    void setAviao(Aviao *a);
    void teste();
};



#endif //PROJECT1_EMPRESAMENU_H
