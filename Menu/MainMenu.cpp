#include "MainMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

MainMenu::MainMenu() {
    opcoes = {"Criar aeroporto","Listar aeroportos","Acessar aeroporto", "Remover Aeroporto"};
}

void MainMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            criarAeroporto();
            break;
        }
        case 1:
        {
            menus_to_call["ListarAeroportoMenu"]->play();
            break;
        }
        case 2:
        {
            menus_to_call["AcessarAeroportoMenu"]->setAeroporto(escolherAeroporto());
            menus_to_call["AcessarAeroportoMenu"]->play();
            break;
        }
        case 3:
        {
            deletarAeroporto();
            break;
        }
    }
}

void MainMenu::criarAeroporto()
{} //falta fazer

void MainMenu::deletarAeroporto()
{
    Aeroporto* a1;
    string p, c;
    cout << "Insira o pais: " << endl;
    cin >> p;
    cout << "Insira a cidade: " << endl;
    cin >> c;
    for(int i =0; i < aeroportos.size(); i++)
    {
        if (aeroportos.at(i)->getLocalizacao().getPais() == p && aeroportos.at(i)->getLocalizacao().getCidade() == c)
        {
            aeroportos.erase(aeroportos.begin()+i);
            break;
        }
    }
}

Aeroporto* MainMenu::escolherAeroporto()
{
    string p, c;
    cout << "Insira o pais: " << endl;
    cin >> p;
    cout << "Insira a cidade: " << endl;
    cin >> c;
    cin.ignore(1024,'\n');
    for(int i = 0; i < aeroportos.size(); i++) {
        if (aeroportos.at(i)->getLocalizacao().getPais() == p && aeroportos.at(i)->getLocalizacao().getCidade() == c)
        {
            return aeroportos.at(i);
        }
    }
}