#include <iostream>
#include <vector>
#include "Menu/Menu.h"
#include "Menu/MainMenu.h"
#include "Menu/ListarAeroportoMenu.h"
#include "Menu/AcessarAeroportoMenu.h"
#include "Menu/FuncionariosMenu.h"
#include "Menu/AviaoMenu.h"
#include "Menu/VooMenu.h"

using namespace std;
extern map<string, Menu*> menus_to_call;
extern vector<Aeroporto*> aeroportos;

int main() {
    Piloto p(0,"Sergio",Data(20,06,1958),"principal",{},{});
    Aeroporto a(&p,Localizacao("Brasil","Rio de Janeiro",GPS(10,10)),{&p},{},{&p},{},{});
    aeroportos.push_back(&a);

    MainMenu mainMenu;
    menus_to_call.insert(pair<string,Menu*>("MainMenu",&mainMenu));

    ListarAeroportoMenu listarAeroportoMenu;
    menus_to_call.insert(pair<string,Menu*>("ListarAeroportoMenu",&listarAeroportoMenu));

    AcessarAeroportoMenu acessarAeroportoMenu;
    menus_to_call.insert(pair<string,Menu*>("AcessarAeroportoMenu",&acessarAeroportoMenu));

    FuncionariosMenu todosOsFuncionariosMenu(TODOS);
    menus_to_call.insert(pair<string,Menu*>("TodosFuncionariosMenu",&todosOsFuncionariosMenu));

    FuncionariosMenu pilotosFuncionariosMenu(PILOTO);
    menus_to_call.insert(pair<string,Menu*>("PilotosFuncionariosMenu",&pilotosFuncionariosMenu));

    FuncionariosMenu funcionariosAdministrativosMenu(ADMINISTRATIVO);
    menus_to_call.insert(pair<string,Menu*>("FuncionariosAdministrativosMenu",&funcionariosAdministrativosMenu));

    FuncionariosMenu membrosTripulacaoFuncionariosMenu(MEMBRO_TRIPULACAO);
    menus_to_call.insert(pair<string,Menu*>("MembrosTripulacaoFuncionariosMenu",&membrosTripulacaoFuncionariosMenu));

    AviaoMenu aviaoMenu;
    menus_to_call.insert(pair<string,Menu*>("AviaoMenu",&aviaoMenu));

    VooMenu vooMenu;
    menus_to_call.insert(pair<string,Menu*>("VooMenu",&vooMenu));

    mainMenu.play();

    return 0;
}