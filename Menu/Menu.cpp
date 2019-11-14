#include "Menu.h"

vector<Aeroporto*> aeroportos;
map<string, Menu*> menus_to_call;

void Menu::print()
{
    //system("cls");
    cout << "-------------------------------------" << endl;
    for(int i = 0; i < opcoes.size(); i++)
    {
        cout << i  << "  -  "<< opcoes.at(i) << endl;
    }

    cout << "-------------------------------------" << endl;
}

void Menu::play() {
    print();
    getInput();
    CallMenu();
}

void Menu::getInput() {
    while (1)
    {
        cout << "Selecione uma opcao: ";
        cin >> input;
        if (!cin.fail() && input < opcoes.size()) {
            break;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "Entrada invalida" << endl;
    }
}