#include "ListarAeroportoMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

ListarAeroportoMenu::ListarAeroportoMenu(){
    opcoes = {"Listar por localizacao", "Listar por quantidade de funcionario", "Listar por quantidade de funcionario administrativo",
              "Listar por quantidade de pilotos", "Listar por quantidade de Membro de tripulacao", "Listar por quantidade de avioes",
              "Escolher um aeroporto"};
}

void ListarAeroportoMenu::CallMenu() {
    switch(input){
        case 0:
        {
            porLocalizacao();
            break;
        }
        case 1:
        {
            porQuantidadeFuncionario();
            break;
        }
        case 2:
        {
            porQuantidadeFuncionarioAdministrativo();
            break;
        }
        case 3:
        {
            porQuantidadePilotos();
            break;
        }
        case 4:
        {
            porQuantidadeMembroTripulacao();
            break;
        }
        case 5:
        {
            porQuantidadeAvioes();
            break;
        }
        case 6:
        {
            escolherAeroporto();
            break;
        }
    }
}

void ListarAeroportoMenu::porLocalizacao()
{
    sort(aeroportos.begin(), aeroportos.end(), compLocalizacao);
    for(int i=0; i< aeroportos.size(); i++)
    {
        cout << *aeroportos.at(i);
    }

}

void ListarAeroportoMenu::porQuantidadeFuncionarioAdministrativo()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadeFuncionariosAdministrativos);
    for(int i = 0; aeroportos.size(); i++)
    {
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadeFuncionario()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadefuncionarios);
    for(int i = 0; aeroportos.size(); i++)
    {
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadePilotos()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadePilotos);
    for(int i = 0; aeroportos.size(); i++)
    {
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadeMembroTripulacao()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadeMembroTripulacao);
    for(int i = 0; aeroportos.size(); i++)
    {
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::porQuantidadeAvioes()
{
    sort(aeroportos.begin(), aeroportos.end(), compQuantidadeAvioes);
    for(int i = 0; aeroportos.size(); i++)
    {
        cout << *aeroportos.at(i);
    }
}

void ListarAeroportoMenu::escolherAeroporto()
{
    string p, c;
    cout << "Insira o pais: " << endl;
    cin >> p;
    cout << "Insira a cidade: " << endl;
    cin >> c;
    for(int i = 0; i < aeroportos.size(); i++)
    {
        if (aeroportos.at(i)->getLocalizacao().getPais() == p && aeroportos.at(i)->getLocalizacao().getCidade() == c)
            cout << aeroportos.at(i);
    }
}