#ifndef PROJECT1_FUNCIONARIOSMENU_H
#define PROJECT1_FUNCIONARIOSMENU_H

#include "Menu.h"

enum tipos_funcionarios
{
    TODOS,
    ADMINISTRATIVO,
    PILOTO,
    MEMBRO_TRIPULACAO
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
    void setAeroporto(Aeroporto* a){};
};

#endif //PROJECT1_FUNCIONARIOSMENU_H
