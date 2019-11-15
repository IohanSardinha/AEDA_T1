#include <iostream>
#include <vector>
#include "Menu/Menu.h"
#include "Menu/MainMenu.h"
#include "Menu/ListarAeroportoMenu.h"
#include "Menu/AcessarAeroportoMenu.h"
#include "Menu/FuncionariosMenu.h"
#include "Menu/AviaoMenu.h"
#include "Menu/VooMenu.h"
#include "Classes/Informacao.h"
#include "Classes/Aviao.h"

using namespace std;
extern map<string, Menu*> menus_to_call;
extern vector<Aeroporto*> aeroportos;

int main() {

    Voo v(Data(20,11,2019),Hora(10,00,00),"La Pas");
    Informacao i(&v,Hora(10,00,00),Hora(10,10,00),false);
    v.setInfo(&i);
    Membro_tripulacao m(1000,{&v},{&i});
    Funcionario_administrativos f("Gisele",Data(30,01,1990),pair<Hora,Hora>(Hora(8,00,00),Hora(17,0,0)),"Diretora","Financeiro");
    Piloto p(3000,"Sergio",Data(20,06,1958),"principal",{},{});
    Aviao a("Boing 747",500,{&v},{&m},10000);
    Aeroporto ae(&f,Localizacao("Brasil","Rio de Janeiro",GPS(-22.908333,-43.196388)),{&p,&f,&m},{&a},{&p},{&m},{&f});
    aeroportos.push_back(&ae);

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