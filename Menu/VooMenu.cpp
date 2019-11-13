#include "VooMenu.h"

VooMenu::VooMenu(){
    opcoes = {"Alterar data", "Alterar hora prevista", "Alterar hora real", "Alterar destino", "Alterar estado voo", "Visualizar voo", "Criar voo"};
}

void VooMenu::CallMenu() {
    switch (input)
    {
        case 0:
        {
            alterarData();
            break;
        }
        case 1:
        {
            alterarHoraPrevista();
            break;
        }
        case 2:
        {
            alterarHoraReal();
            break;
        }
        case 3:
        {
            alterarDestino();
            break;
        }
        case 4:
        {
            alterarEstado();
            break;
        }
        case 5:
        {
            visualizarVoo();
            break;
        }
        case 6:
        {
            criarVoo();
            break;
        }
    }
}

void VooMenu::criarVoo() {
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

    Voo voo(data_c, hora_prevista, destino);

    cout << "O voo foi cancelado: (sim/nao)" << endl;
    cin >> resp;
    if (resp == "sim")
        cancelado = true;
    else
        cancelado = false;

    Informacao info(&voo, hora_prevista, hora_real, cancelado);

    a->adicionarVoo(&voo);

}

Voo* VooMenu::escolherVoo() {
    string destino, data;
    int op;
    int ano, mes, dia;
    while (1) {
        cout << "Como desejar escolher o Voo? " << endl;
        cout << "0 - destino" << endl << "1 - data" << endl;
        cin >> op;
        switch (op) {
            case 0: {
                cout << "Qual o destino do voo que deseja?" << endl;
                cin >> destino;

                for (int i = 0; i < a->getVoos().size(); i++) {
                    if (a->getVoos().at(i)->getDestino() == destino)
                        return a->getVoos().at(i);

                }
            }
            case 1: {
                cout << "Qual a data do voo que deseja? (ano/mes/dia)" << endl;
                cin >> data;
                dia = stoi(data.substr(0, data.find_first_of("/")));
                mes = stoi(data.substr(data.find_first_of("/") + 1, 2));
                ano = stoi(data.substr(data.find_last_of("/") + 1, -1));
                Data data_c(dia, mes, ano);
                for (int i = 0; i < a->getVoos().size(); i++) {
                    if (a->getVoos().at(i)->getData().getDia() == dia &&
                        a->getVoos().at(i)->getData().getMes() == mes && a->getVoos().at(i)->getData().getAno() == ano)
                        return a->getVoos().at(i);

                }
            }
        }
        cout << "Voo com o campo indicado nao encontrado" << endl;
    }
    //fazer para data e hora se tivermos tempo
}


void VooMenu::visualizarVoo() {
    Voo* voo = escolherVoo();
    cout << "Data: " << voo->getData() << endl;
    cout << "Hora: " << voo->getHora() << endl;
    cout << "Destino: " << voo->getDestino() << endl;
    cout << "Informacao: " << voo->getInfo() << endl;
}

void VooMenu::alterarData() {
    string data;
    int ano, mes, dia;
    Voo* voo = escolherVoo();
    cout << "Diga a nova data: (dia/mes/ano) " << endl;
    cin >> data;
    dia = stoi(data.substr(0, data.find_first_of("/")));
    mes = stoi(data.substr(data.find_first_of("/")+1, 2));
    ano = stoi(data.substr(data.find_last_of("/")+1, -1));
    Data data_c(dia, mes, ano);
    voo->setData(data_c);
}

Hora VooMenu::alterarHora() {
    Voo* voo = escolherVoo();
    int hora, min, seg;
    string horap;
    cout << "Diga a nova hora: " << endl;
    cin >> horap;
    hora = stoi(horap.substr(0, horap.find_first_of(":")));
    min = stoi(horap.substr(horap.find_first_of(":")+1, 2));
    seg = stoi(horap.substr(horap.find_last_of(":")+1, -1));
    Hora horas(hora, min, seg);
    return horas;
}

void VooMenu::alterarHoraPrevista() {
    Voo* voo = escolherVoo();
    voo->setHora(alterarHora());
    voo->getInfo()->setHoraPrevista(alterarHora());
}

void VooMenu::alterarHoraReal() {
    Voo* voo = escolherVoo();
    voo->getInfo()->setHoraReal(alterarHora());
}

void VooMenu::alterarEstado() {
    Voo* voo = escolherVoo();
    string booleano;
    cout << "O voo foi cancelado? (sim/nao)" << endl;
    cin >> booleano;
    if (booleano == "sim")
        voo->getInfo()->setCancelado(true);
    else
        voo->getInfo()->setCancelado(false);

}

void VooMenu::alterarDestino() {
    Voo* voo = escolherVoo();
    string destino;
    cout << "Qual o nome destino: " << endl;
    cin >> destino;
    voo->setDestino(destino);
}
