#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../Classes/Aeroporto.h"
#include "../Utils/sorts.h"

using namespace std;

enum tipos_funcionarios
{
    TODOS,
    ADMINISTRATIVO,
    PILOTO,
    MEMBRO_TRIPULACAO
};

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
};

class MainMenu :public Menu{
public:
    MainMenu();
    void criarAeroporto(); //falta implementar
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
    enum tipos_funcionarios tipo;
    Aeroporto* a;

public:
    FuncionariosMenu(enum tipos_funcionarios t);
    void CallMenu();
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
    Funcionario_administrativos* acharFuncionarioAdministrativo();
    Piloto* acharPiloto();
    Membro_tripulacao* acharMembroTripulacao();
};

class AviaoMenu:public Menu{
    Aeroporto* aeroporto;
public:
    Aviao* escolherAviao();
    AviaoMenu();
    void CallMenu();
    void criarAviao();
    void editarTipo();
    void editarCapacidade();
    Voo* criarVoo();
    Membro_tripulacao* criarMembroTripulacao();
};

class VooMenu:public Menu{
    Aviao* a;
public:
    VooMenu();
    void visualizarVoo();
    Voo* escolherVoo();
    void alterarData();
    Hora alterarHora();
    void alterarHoraPrevista();
    void alterarHoraReal();
    void alterarDestino();
    void alterarEstado();
    void criarVoo();
    void CallMenu();
    void escolherAviao(); //como vou escolher aviao???
};



#endif //PROJECT1_MENU_H
