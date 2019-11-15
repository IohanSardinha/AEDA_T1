#include "AviaoMenu.h"
#include "../Classes/Informacao.h"
#include "../Classes/Aviao.h"

extern map<string, Menu*> menus_to_call;

AviaoMenu::AviaoMenu() {
    opcoes = {"Criar Aviao", "Editar Tipo do Aviao", "Editar Capacidade Aviao", "Editar Voos","Ver avioes", "Voltar"};
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
            listarAvioes();
            break;
        }
        case 5:
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
    cin.ignore(1024, '\n');
    getline(cin, tipo);
    cout << "Qual a capacidade do aviao: " << endl;
    cin >> capacidade;
    cout << "Quantos voos deseja adicionar? " << endl;
    cin >> v;
    for (; v > 0; v--)
        voo.push_back(criarVoo());
    cout << "Quantos funcionarios deseja criar? " << endl;
    cin >> f;
    for (; f> 0;f--)
    {
        Membro_tripulacao* membroTripulacao = criarMembroTripulacao(voo);
        funcionario.push_back(membroTripulacao);
        aeroporto->adicionarMembro(membroTripulacao);
    }
    cout << "Qual o custo da operacao: " << endl;
    cin >> custo;

    Aviao* a = new Aviao(tipo, capacidade, voo, funcionario, custo);
    aeroporto->adicionarAviao(a);
    menus_to_call["AviaoMenu"]->play();
}

void AviaoMenu::listarAvioes() {
    for(Aviao* aviao: aeroporto->getAvioes())
    {
        cout << *aviao;
    }
    cin.ignore(1024,'\n');
    wait();
    menus_to_call["AviaoMenu"]->play();
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
    vector<string> splitted = split(data,"/");
    dia = stoi(splitted[0]);
    mes =  stoi(splitted[1]);
    ano =  stoi(splitted[2]);
    Data data_c(dia, mes, ano);

    cout << "Diga a hora prevista do voo: (hora:min:seg)" << endl;
    cin >> horap;
    splitted = split(horap,":");
    hora1 = stoi(splitted[0]);
    min1 = stoi(splitted[1]);
    seg1 = stoi(splitted[2]);
    Hora hora_prevista(hora1, min1, seg1);

    cout << "Diga a hora real do voo: (hora:min:seg) " << endl;
    cin >> horar;
    splitted = split(horar,":");
    hora2 = stoi(splitted[0]);
    min2 = stoi(splitted[1]);
    seg2 = stoi(splitted[2]);
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

    Informacao* info = new Informacao(voo, hora_prevista, hora_real, cancelado);
    voo->setInfo(info);

    return voo;

}

Membro_tripulacao* AviaoMenu::criarMembroTripulacao(vector<Voo*> voos)
{
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

    cout << "Destino voo o qual o funcionario vai trabalhar: ";
    cin >> in;
    for(Voo* voo: voos)
    {
        if(voo->getDestino() == in)
        {
            novoFuncionario->adicionarVoo(voo);
            novoFuncionario->adicionarInfo(voo->getInfo());
            break;
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
                cin.ignore(1024, '\n');
                getline(cin, tipo);
                for (int j = 0; j < aeroporto->getAvioes().size(); j++) {
                    if (aeroporto->getAvioes().at(j)->getTipo() == tipo)
                        return aeroporto->getAvioes().at(j);
                }
                break;
            }
            case 1: {
                cout << "Qual a capacidade do aviao que deseja: " << endl;
                cin >> capacidade;
                for (int j = 0; j < aeroporto->getAvioes().size(); j++) {
                    if (aeroporto->getAvioes().at(j)->getCapacidade() == capacidade)
                        return aeroporto->getAvioes().at(j);
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
    getline(cin, tipo);
    aviao->setTipo(tipo);
    menus_to_call["AviaoMenu"]->play();
}

void AviaoMenu::editarCapacidade() {
    int capacidade;
    Aviao* aviao = escolherAviao();
    cout << "Qual a nova capacidade do aviao: " << endl;
    cin >> capacidade;
    aviao->setCapacidade(capacidade);
    menus_to_call["AviaoMenu"]->play();
}

void AviaoMenu::setAeroporto(Aeroporto* a)
{
    aeroporto = a;
}
