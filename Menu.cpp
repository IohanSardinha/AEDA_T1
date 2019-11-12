#include "Menu.h"
#include <string>

void Menu::print()
{
    cout << "--------------------------------" << endl;
    for(int i = 0; i < opcoes.size(); i++)
    {
        cout << opcoes.at(i) << "  -  " << i << endl;
    }

    cout << "--------------------------------" << endl;
}

void Menu::play() {
    print();
    getInput();
    CallMenu();
}

void Menu::getInput() {
    string string_input;
    cout << "Selecione uma opcao: ";
    cin >> string_input;
    do
    {
        try
        {
            input = stoi(string_input);
            if(input < 0 || input > opcoes.size())
            {
                cout << "Erro: " << string_input << " nao e uma opcao valida" << endl;
                continue;
            }
            break;
        }
        catch(exception e)
        {
            cout << "Erro: " << string_input << " nao e uma opcao valida" << endl;
        }
    }while(1);
}

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
            break;
        }
        case 3:
        {
            break;
        }
    }
}

ListarAeroportoMenu::ListarAeroportoMenu(){
    opcoes = {"Listar por localização", "Listar por quantidade de funcionario", "Listar por quantidade de funcionario administrativo",
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

AcessarAeroportoMenu::AcessarAeroportoMenu() {
    opcoes = {"Alterar gerente", "Alterar localização", "Funcionarios", "Aviões"};
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
            escolherAviao();
            menus_to_call["AvioesMenu"]->play();
        }
    }
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
            menus_to_call["VooMenu"]->play();
            break;
        }
    }
}


//FUNCOES DOS VOOS

VooMenu::VooMenu() {
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
    mes = stoi(data.substr(data.find_first_of("/"), data.find_last_of("/")));
    ano = stoi(data.substr(data.find_last_of("/"), data.size()));
    Data data_c(dia, mes, ano);

    cout << "Diga a hora prevista do voo: (hora:min:seg)" << endl;
    cin >> horap;
    hora1 = stoi(horap.substr(0, horap.find_first_of(":")));
    min1 = stoi(horap.substr(horap.find_first_of(":"), horap.find_last_of(":")));
    seg1 = stoi(horap.substr(horap.find_last_of(":"), horap.size()));
    Hora hora_prevista(hora1, min1, seg1);

    cout << "Diga a hora real do voo: (hora:min:seg) " << endl;
    cin >> horar;
    hora2 = stoi(horar.substr(0, horar.find_first_of(":")));
    min2 = stoi(horar.substr(horar.find_first_of(":"), horar.find_last_of(":")));
    seg2 = stoi(horar.substr(horar.find_last_of(":"), horar.size()));
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

Voo* VooMenu::escolherVoo()
{
    string destino, data;
    int op;
    int ano, mes, dia;
    cout << "Como desejar escolher o Voo? "<<endl;
    cout << "0 - destino" << endl << "1 - data" << endl;
    cin >> op;
    switch (op)
    {
        case 0:
        {
            cout << "Qual o destino do voo que deseja?" << endl;
            cin >> destino;

            for (int i = 0; i < a->getVoos().size(); i++)
            {
                if (a->getVoos().at(i)->getDestino() == destino)
                    return a->getVoos().at(i);

            }
        }
        case 1:
        {
            cout << "Qual a data do voo que deseja? (ano/mes/dia)" << endl;
            cin >> data;
            dia = stoi(data.substr(0, data.find_first_of("/")));
            mes = stoi(data.substr(data.find_first_of("/"), data.find_last_of("/")));
            ano = stoi(data.substr(data.find_last_of("/"), data.size()));
            Data data_c(dia, mes, ano);
            for (int i = 0; i < a->getVoos().size(); i++)
            {
                if (a->getVoos().at(i)->getData().getDia() == dia && a->getVoos().at(i)->getData().getMes() == mes && a->getVoos().at(i)->getData().getAno() == ano)
                    return a->getVoos().at(i);

            }
        }
    }

    //fazer para data e hora se tivermos tempo
}

void VooMenu::visualizarVoo() {
    Voo* voo = escolherVoo();
    cout << "Data: " << voo->getData() << endl;
    cout << "Hora: " << voo->getHora() << endl;
    cout << "Destino: " << voo->getDestino() << endl;
    cout << "Informação: " << voo->getInfo() << endl;
}

void VooMenu::alterarData() {
    string data;
    int ano, mes, dia;
    Voo* voo = escolherVoo();
    cout << "Diga a nova data: (dia/mes/ano) " << endl;
    cin >> data;
    dia = stoi(data.substr(0, data.find_first_of("/")));
    mes = stoi(data.substr(data.find_first_of("/"), data.find_last_of("/")));
    ano = stoi(data.substr(data.find_last_of("/"), data.size()));
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
    min = stoi(horap.substr(horap.find_first_of(":"), horap.find_last_of(":")));
    seg = stoi(horap.substr(horap.find_last_of(":"), horap.size()));
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

//menus_to_call["AviaoMenu"]->a = aviao;