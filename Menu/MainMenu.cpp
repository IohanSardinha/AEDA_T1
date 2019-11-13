#include "MainMenu.h"
#include "../Classes/Aviao.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

MainMenu::MainMenu() {
    opcoes = {"Criar aeroporto","Listar aeroportos","Acessar aeroporto", "Remover Aeroporto", "Sair"};
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
        case 4:
        {
            return;
        }
    }
}

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
    while (1)
    {
        string p, c;
        cout << "Pais no qual o aeroporto esta localizado: ";
        cin.ignore(1024, '\n');
        getline(cin, p);
        cout << "Cidade do aeroporto: ";
        getline(cin, c);
        for (int i = 0; i < aeroportos.size(); i++) {
            if (aeroportos.at(i)->getLocalizacao().getPais() == p &&
                aeroportos.at(i)->getLocalizacao().getCidade() == c) {
                return aeroportos.at(i);
            }
        }
        cout << "Parametros dados nao indicam nenhum aeroporto" << endl;
    }
}

Localizacao* MainMenu::inserirLocalizacao()
{
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
    return &localizacao;
}

void MainMenu::criarAeroporto()
{
    //Localizacao
    string cidade,pais;
    cout << "Pais do novo aeroporto: ";
    cin.ignore(1024,'\n');
    getline(cin,pais);
    cout << "Cidade do novo aeroporto: ";
    getline(cin,cidade);
        //GPS
        float lat,lang;
        cout << "Latitude do novo aeroporto: ";
        cin >> lat;
        cout << "Longitude do novo aeroporto: ";
        cin >> lang;

    Localizacao localizacao(pais,cidade,GPS(lat,lang));
    aeroportos.push_back(new Aeroporto(NULL,localizacao,{},{},{},{},{}));
    cout << "Para adicionar funcionarios e avioes ao aeroporto va para:"<< endl;
    cout << "2 - Acessar aeroporto" << endl << endl;
    menus_to_call["MainMenu"]->play();
}