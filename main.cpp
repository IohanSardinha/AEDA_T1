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

    menus_to_call.insert(pair<string,Menu*>("MainMenu",new MainMenu));
    menus_to_call.insert(pair<string,Menu*>("ListarAeroportoMenu",new ListarAeroportoMenu));
    menus_to_call.insert(pair<string,Menu*>("AcessarAeroportoMenu",new AcessarAeroportoMenu));
    menus_to_call.insert(pair<string,Menu*>("TodosFuncionariosMenu",new FuncionariosMenu(TODOS)));
    menus_to_call.insert(pair<string,Menu*>("PilotosFuncionariosMenu",new FuncionariosMenu(PILOTO)));
    menus_to_call.insert(pair<string,Menu*>("FuncionariosAdministrativosMenu",new FuncionariosMenu(ADMINISTRATIVO)));
    menus_to_call.insert(pair<string,Menu*>("MembrosTripulacaoFuncionariosMenu",new FuncionariosMenu(MEMBRO_TRIPULACAO)));
    menus_to_call.insert(pair<string,Menu*>("AviaoMenu",new AviaoMenu));
    menus_to_call.insert(pair<string,Menu*>("VooMenu",new VooMenu));

    menus_to_call["MainMenu"]->play();

    return 0;
}