#include "Menu.h"
#include "../Classes/Aviao.h"
#include "../Classes/Informacao.h"

vector<Aeroporto*> aeroportos;
map<string, Menu*> menus_to_call;

void Menu::print()
{
    cout << string(40,'\n');
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

void Menu::save()
{
    ofstream file;
    file.open("Airport.dt", ofstream::out);
    for(Aeroporto* aeroporto: aeroportos)
    {
        //Localizacao
        file << aeroporto->getLocalizacao().getCidade() << endl;
        file << aeroporto->getLocalizacao().getPais() << endl;
        file << aeroporto->getLocalizacao().getCordenadas().getLatitude() << endl;
        file << aeroporto->getLocalizacao().getCordenadas().getLongitude() << endl;
        file << "--localizacao--" << endl;

        vector<Voo*> voos;
        vector<Informacao*> infos;
        vector<Funcionario*> funcionarios;
       //Voos
       for(Aviao* aviao: aeroporto->getAvioes())
       {
           for(Voo* voo: aviao->getVoos())
           {
               //Voo
               voos.push_back(voo);
               infos.push_back(voo->getInfo());
               file << voo->getData() << endl;
               file << voo->getHora() << endl;
               file << voo->getDestino() << endl;
               file << voo->getInfo()->getHoraPrevista() << endl;
               file << voo->getInfo()->getHoraReal() << endl;
               file << voo->getInfo()->isCancelado() << endl;
           }
       }
       file << "--voos--" << endl;

       //Membros tripulacao
       for(Membro_tripulacao* membroTripulacao: aeroporto->getMembros())
       {
           file << membroTripulacao->getSalario() << endl;
           funcionarios.push_back(membroTripulacao);
           for(Voo* voo: membroTripulacao->getVoos())
           {
               for(int i = 0; i < voos.size(); i++)
               {
                   if(voo == voos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--voos membro--" << endl;
           for(Informacao* info: membroTripulacao->getInfos())
           {
               for(int i = 0; i < infos.size(); i++)
               {
                   if(info == infos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--infos membro--" << endl;
       }
        file << "--membros--" << endl;

       //Avioes
       for(Aviao* aviao: aeroporto->getAvioes())
       {
           file << aviao->getTipo() << endl;
           file << aviao->getCustoOperacao() << endl;
           for(Funcionario* funcionario: aviao->getTripulacao())
           {
               for(int i = 0; i < funcionarios.size(); i++)
               {
                   if(funcionario == funcionarios.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--funcionarios aviao--" << endl;
           for(Voo* voo: aviao->getVoos())
           {
               for(int i = 0; i < voos.size(); i++)
               {
                   if(voo == voos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--voos aviao--" << endl;
       }
        file << "--avioes--" << endl;

       //Pilotos
       for(Piloto* piloto: aeroporto->getPilotos())
       {
           funcionarios.push_back(piloto);
           file << piloto->getSalario() << endl;
           file << piloto->getNome() << endl;
           file << piloto->getDataNascimento() << endl;
           file << piloto->getCategoria() << endl;
           for(Aviao* aviao: piloto->getAvioes())
           {
               for (int i = 0; i < aeroporto->getAvioes().size(); ++i)
               {
                    if(aeroporto->getAvioes().at(i) == aviao)
                    {
                        file << i << endl;
                        break;
                    }
               }
           }
           file << "--avioes piloto--" << endl;
           for(Voo* voo: piloto->getVoos())
           {
               for(int i = 0; i < voos.size(); i++)
               {
                   if(voo == voos.at(i))
                   {
                       file << i << endl;
                       break;
                   }
               }
           }
           file << "--voos piloto--" << endl;
       }
       file << "--piloto--" << endl;

       //Funcionario Administrativo
       for(Funcionario_administrativos* funcionarioAdministrativos: aeroporto->getFuncionariosAdministrativos())
       {
           file << funcionarioAdministrativos->getSalario() << endl;
           file << funcionarioAdministrativos->getNome() << endl;
           file << funcionarioAdministrativos->getDataNascimento() << endl;
           file << funcionarioAdministrativos->getCategoria() << endl;
           file << funcionarioAdministrativos->gethorario_de_trabalho().first << endl;
           file << funcionarioAdministrativos->gethorario_de_trabalho().second << endl;
           file << funcionarioAdministrativos->getFuncao() << endl;
           file << funcionarioAdministrativos->getDepartamento() << endl;
       }
       file << "--funcionario administrativo--" << endl;

       file << "--aeroporto--" << endl;
    }
    file.close();
}