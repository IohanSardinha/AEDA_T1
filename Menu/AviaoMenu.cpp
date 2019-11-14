#include "AviaoMenu.h"
#include "../Classes/Informacao.h"
#include "../Classes/Aviao.h"

extern map<string, Menu*> menus_to_call;

AviaoMenu::AviaoMenu() {
    opcoes = {"Criar Aviao", "Editar Tipo do Aviao", "Editar Capacidade Aviao", "Editar Voos", "Voltar"};
}

void AviaoMenu::CallMenu() {
    switch(input)
    {
        case 0:
        {
            criarAviao();
            break;
        }
        case 1:{
            editarTipo();
            break;
        }
        case 2:
        {
            editarCapacidade();
            break;
        }
        case 3:
        {
            menus_to_call["VooMenu"]->setAviao(escolherAviao());
            menus_to_call["VooMenu"]->play();
            break;
        }
        case 4:
        {
            menus_to_call["AcessarAeroportoMenu"]->play();
            break;
        }
    }
}

void AviaoMenu::criarAviao() {
    string tipo;
    int capacidade, v, f, custo;
    vector<Voo*> voo;
    vector<Funcionario*> funcionario;
    cout << "Qual o tipo do aviao: " << endl;
    cin >> tipo;
    cout << "Qual a capacidade do aviao: " << endl;
    cin >> capacidade;
    cout << "Quantos voos deseja adicionar? " << endl;
    cin >> v;
    for (v; v != 0; v--)
        voo.push_back(criarVoo());
    cout << "Quantos funcionarios deseja criar? " << endl;
    cin >> f;
    for (f; f!= 0;f--)
        funcionario.push_back(criarMembroTripulacao());
    cout << "Qual o custo da operacao: " << endl;
    cin >> custo;

    Aviao a(tipo, capacidade, voo, funcionario, custo);
    aeroporto->adicionarAviao(&a);

}

Voo* AviaoMenu::criarVoo() {
    int dia, mes, ano;
    int min1, hora1, seg1;
    int min2, hora2, seg2;
    string data, horap, horar;
    string destino;
    string resp;
    bool cancelado;

    cout << "Diga a data do novo voo: (dia/mes/ano) " << endl;
    cin >> data;
    dia = stoi(data.substr(0, data.find_first_of("/")));
    mes = stoi(data.substr(data.find_first_of("/")+1, 2));
    ano = stoi(data.substr(data.find_last_of("/")+1, -1));
    Data data_c(dia, mes, ano);

    cout << "Diga a hora prevista do voo: (hora:min:seg)" << endl;
    cin >> horap;
    hora1 = stoi(horap.substr(0, horap.find_first_of(":")));
    min1 = stoi(horap.substr(horap.find_first_of(":")+1, 2));
    seg1 = stoi(horap.substr(horap.find_last_of(":")+1, -1));
    Hora hora_prevista(hora1, min1, seg1);

    cout << "Diga a hora real do voo: (hora:min:seg) " << endl;
    cin >> horar;
    hora2 = stoi(horar.substr(0, horar.find_first_of(":")));
    min2 = stoi(horar.substr(horar.find_first_of(":")+1, 2));
    seg2 = stoi(horar.substr(horar.find_last_of(":")+1, -1));
    Hora hora_real(hora2, min2, seg2);

    cout << "Diga o destino do voo: " << endl;
    cin >> destino;

    Voo* voo = new Voo(data_c, hora_prevista, destino);

    cout << "O voo foi cancelado: (sim/nao)" << endl;
    cin >> resp;
    if (resp == "sim")
        cancelado = true;
    else
        cancelado = false;

    Informacao info(voo, hora_prevista, hora_real, cancelado);

    return voo;

}

Membro_tripulacao* AviaoMenu::criarMembroTripulacao()
{
    vector<Voo*> voos;
    for(Aviao* aviao: aeroporto->getAvioes())
    {
        for(Voo* voo: aviao->getVoos())
        {
            bool in_voos = false;
            for(Voo* v : voos)
            {
                if(v == voo)
                {
                    in_voos = true;
                    break;
                }
            }
            if(!in_voos)
            {
                voos.push_back(voo);
            }
        }
    }

    Membro_tripulacao* novoFuncionario = new Membro_tripulacao(0,{},{});
    string in;
    while (1)
    {
        cout << "Destino voo o qual o funcionario vai trabalhar(0 para sair): ";
        cin >> in;
        if(in == "0")
        {
            break;
        }
        for(Voo* voo: voos)
        {
            if(voo->getDestino() == in)
            {
                novoFuncionario->getVoos().push_back(voo);
                novoFuncionario->getInfos().push_back(voo->getInfo());
                break;
            }
        }
    }

    return novoFuncionario;
}

Aviao* AviaoMenu::escolherAviao()
{
    int i, capacidade;
    string tipo;
    while (1) {
        cout << "Deseja escolher o aviao por: " << endl;
        cout << "0 - Tipo de aviao" << endl << "1 - Capacidade do aviao" << endl;
        cin >> i;
        switch (i) {
            case 0: {
                cout << "Qual o tipo de aviao que deseja: " << endl;
                cin >> tipo;
                for (int i = 0; i < aeroporto->getAvioes().size(); i++) {
                    if (aeroporto->getAvioes().at(i)->getTipo() == tipo)
                        return aeroporto->getAvioes().at(i);
                }
                break;
            }
            case 1: {
                cout << "Qual a capacidade do aviao que deseja: " << endl;
                cin >> capacidade;
                for (int i = 0; i < aeroporto->getAvioes().size(); i++) {
                    if (aeroporto->getAvioes().at(i)->getCapacidade() == capacidade)
                        return aeroporto->getAvioes().at(i);
                }
                break;
            }
        }
        cout << "Aviao com o campo indicado nao existe" << endl;
    }
}

void AviaoMenu::editarTipo() {
    string tipo;
    Aviao* aviao = escolherAviao();
    cout << "Qual o novo tipo do aviao: " << endl;
    cin >> tipo;
    aviao->setTipo(tipo);
}

void AviaoMenu::editarCapacidade() {
    int capacidade;
    Aviao* aviao = escolherAviao();
    cout << "Qual a nova capacidade do aviao: " << endl;
    cin >> capacidade;
    aviao->setCapacidade(capacidade);
}

void AviaoMenu::setAeroporto(Aeroporto* a)
{
    aeroporto = a;
}
