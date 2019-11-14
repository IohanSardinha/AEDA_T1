#include "AcessarAeroportoMenu.h"

extern vector<Aeroporto*> aeroportos;
extern map<string, Menu*> menus_to_call;

AcessarAeroportoMenu::AcessarAeroportoMenu() {
    opcoes = {"Alterar gerente", "Alterar localizacao", "Acessar todos os funcionarios", "Acessar pilotos", "Acessar funcionarios administrativos", "Acessar membros da tripulacao", "Acessar Avioes", "Voltar"};
}

void AcessarAeroportoMenu::alterarGerente() {
    string inp;
    cout << "Novo gerente sera que tipo de funcionario(Administrativo, Piloto, Membro tripulacao):";
    cin.ignore(1024,'\n');
    getline(cin,inp);
    if(inp == "Administrativo")
    {
        while(1)
        {
            cout << "Nome do funcionario que sera o gerente: ";
            getline(cin, inp);
            bool found = false;
            for(Funcionario_administrativos* funcionario : aeroporto->getFuncionariosAdministrativos())
            {
                if(funcionario->getNome() == inp)
                {
                    aeroporto->setGerente(funcionario);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
            cout << "Nome inserido nao corresponde a nenhum funcionario" << endl;
        }
    }
    else if(inp == "Piloto")
    {
        while(1)
        {
            cout << "Nome do piloto que sera o gerente: ";
            getline(cin, inp);
            bool found = false;
            for(Piloto* funcionario : aeroporto->getPilotos())
            {
                if(funcionario->getNome() == inp)
                {
                    aeroporto->setGerente(funcionario);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
            cout << "Nome inserido nao corresponde a nenhum piloto" << endl;
        }
    }
    else
    {
        while(1)
        {
            cout << "Destino de um voo do membro que sera o gerente: ";
            getline(cin, inp);
            bool found = false;
            for(Membro_tripulacao* funcionario : aeroporto->getMembros())
            {
                bool b = false;
                for(Voo* voo: funcionario->getVoos())
                {
                    if(voo->getDestino() == inp)
                    {
                        aeroporto->setGerente(funcionario);
                        found = true;
                        b = true;
                        break;
                    }
                }
                if(b)
                    break;

            }
            if(found)
                break;
            cout << "Nome inserido nao corresponde a nenhum funcionario" << endl;
        }
    }
    menus_to_call["AcessarAeroportoMenu"]->play();
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
            menus_to_call["AviaoMenu"]->setAeroporto(aeroporto);
            menus_to_call["AviaoMenu"]->play();
            break;
        }
        case 7:{
            menus_to_call["MainMenu"]->play();
            break;
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
    menus_to_call["AcessarAeroportoMenu"]->play();
}

void AcessarAeroportoMenu::setAeroporto(Aeroporto* a)
{
    aeroporto = a;
}

