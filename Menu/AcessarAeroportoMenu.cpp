#include "AcessarAeroportoMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

AcessarAeroportoMenu::AcessarAeroportoMenu() {
    opcoes = {"Alterar gerente", "Alterar localizacao", "Acessar todos os funcionarios", "Acessar pilotos", "Acessar funcionarios administrativos", "Acessar membros da tripulacao", "Avioes"};
}

void AcessarAeroportoMenu::alterarGerente() {
    //TODO
}

void AcessarAeroportoMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            alterarGerente();
            break;
        }
        case 1:
        {
            alterarLocalizacao();
            break;
        }
        case 2:
        {
            menus_to_call["TodosFuncionariosMenu"]->setAeroporto(aeroporto);
            menus_to_call["TodosFuncionariosMenu"]->play();
            break;
        }
        case 3:
        {
            menus_to_call["PilotosFuncionariosMenu"]->setAeroporto(aeroporto);
            menus_to_call["PilotosFuncionariosMenu"]->play();
            break;
        }
        case 4:
        {
            menus_to_call["FuncionariosAdministrativosMenu"]->setAeroporto(aeroporto);
            menus_to_call["FuncionariosAdministrativosMenu"]->play();
            break;
        }
        case 5:
        {
            menus_to_call["MembrosTripulacaoFuncionariosMenu"]->setAeroporto(aeroporto);
            menus_to_call["MembrosTripulacaoFuncionariosMenu"]->play();
            break;
        }
        case 6:
        {
            menus_to_call["AvioesMenu"]->setAeroporto(aeroporto);
            menus_to_call["AvioesMenu"]->play();
        }
    }
}

void AcessarAeroportoMenu::alterarLocalizacao() {
    string pais, cidade;
    float latitude, longitude;
    cin.ignore(1024, '\n');
    cout << "Qual o pais da nova localizacao: ";
    getline(cin, pais);
    cout << "Qual a cidade da nova localizacao: " << endl;
    getline(cin, cidade);
    cout << "Qual a latitude da nova localizacao: " << endl;
    cin >> latitude;
    cout << "Qual a nova longitude da nova localizacao: " << endl;
    cin >> longitude;
    GPS gps(latitude, longitude);
    aeroporto->setLocalizacao(pais, cidade, gps);
    menus_to_call["MainMenu"]->play();
}

void AcessarAeroportoMenu::setAeroporto(Aeroporto* a)
{
    aeroporto = a;
}