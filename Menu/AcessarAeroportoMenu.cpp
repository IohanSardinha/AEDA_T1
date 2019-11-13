#include "AcessarAeroportoMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

AcessarAeroportoMenu::AcessarAeroportoMenu() {
    opcoes = {"Alterar gerente", "Alterar localizacao", "Funcionarios", "Avioes"};
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
            menus_to_call["FuncionariosMenu"]->play();
            break;
        }
        case 3:
        {
            menus_to_call["AvioesMenu"]->play();
        }
    }
}

void AcessarAeroportoMenu::alterarLocalizacao() {
    string pais, cidade;
    float latitude, longitude;
    cout << "Qual o país da nova localizacao: " << endl;
    cin >> pais;
    cout << "Qual a cidade da nova localizacao: " << endl;
    cin >> cidade;
    cout << "Qual a latitude da nova localizacao: " << endl;
    cin >> latitude;
    cout << "Qual a nova longitude da nova localizacao: " << endl;
    cin >> longitude;
    GPS gps(latitude, longitude);
    Localizacao localizacao(pais, cidade, gps);
}

void AcessarAeroportoMenu::escolherAeroporto()
{
    string p, c;
    cout << "Insira o pais: " << endl;
    cin >> p;
    cout << "Insira a cidade: " << endl;
    cin >> c;
    for(int i = 0; i < aeroportos.size(); i++) {
        if (aeroportos.at(i)->getLocalizacao().getPais() == p && aeroportos.at(i)->getLocalizacao().getCidade() == c)
        {
            aeroporto = aeroportos.at(i);
            break;
        }
    }
}