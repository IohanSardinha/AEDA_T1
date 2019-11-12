#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <vector>
#include <map>
#include "Aeroporto.h"

vector<Aeroporto*> aeroportos;

using namespace std;


class Menu {
protected:
    vector<string> opcoes;
    int input;
    map<string, Menu*> menus_to_call;
public:
    Menu()= default;
    void print();
    void play();
    void getInput();
    virtual void CallMenu() = 0;
};

class MainMenu :public Menu{
public:
    MainMenu();
    void criarAeroporto(); //falta implementars
    void deletarAeroporto();
    void CallMenu();
};

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

};

class AcessarAeroportoMenu: public Menu{
    Aeroporto* aeroporto;
public:
    AcessarAeroportoMenu();
    void escolherAeroporto();
    void CallMenu();
    void alterarGerente();
    void alterarLocalizacao();
    //classe funcionario e classe AVioes
};

class FuncionariosMenu:public Menu{
    string tipo;
public:
    FuncionariosMenu();
    void criarFuncionarioAdministrativo();
    void criarPiloto();
    void criarMembroTripulacao();
    void editarFuncionarioAdministrativo();
    void editarPiloto();
    void editarMembroTripulacao();
    void deletarFuncionarioAdministrativo();
    void deletarPiloto();
    void deletarMembroTripulacao();
    void listarFuncionarios();
};

class AviaoMenu:public Menu{
public:
    AviaoMenu();
    void CallMenu();
    void criarAviao();
    void editarTipo();
    void editarCapacidade();

};

class VooMenu:public Menu{
public:
    VooMenu();
    void visualizarVoo();
    void alterarData();
    void alterarHora();
    void alterarDestino();
    void alterarInformacao();
    void criarVoo();
    void CallMenu();
};



#endif //PROJECT1_MENU_H
