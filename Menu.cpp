#include "Menu.h"

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
            menus_to_call["AvioesMenu"]->play();
        }
    }
}

FuncionariosMenu::FuncionariosMenu() {
    switch (tipo)
    {
        case TODOS:
            opcoes = {"Adicionar funcionario","Deletar funcionario","Ver funcionarios","Editar funcionarios"};
            break;
        case ADMINISTRATIVO:
            opcoes = {"Adicionar funcionario administrativo","Deletar funcionario administrativo","Ver funcionarios administrativos","Editar funcionario administrativo"};
            break;
        case PILOTO:
            opcoes = {"Adicionar piloto","Deletar piloto","Ver pilotos","Editar pilotos"};
            break;
        case MEMBRO_TRIPULACAO:
            opcoes = {"Adicionar membro da tripulacao","Deletar membro da tripulacao","Ver membros da tripulacaos","Editar membro da tripulacao"};
            break;
    }
}

void FuncionariosMenu::CallMenu() {
    string in;
    switch(input)
    {
        case 0:
        {
            switch (tipo)
            {
                case TODOS:
                    cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                    cin >> in;
                    if(in == "Administrativo")
                    {
                        criarFuncionarioAdministrativo();
                    }
                    else if(in == "Piloto")
                    {
                        criarPiloto();
                    }
                    else if(in == "Tripulacao")
                    {
                        criarMembroTripulacao();
                    }
                    break;
                case ADMINISTRATIVO:
                    criarFuncionarioAdministrativo();
                    break;
                case PILOTO:
                    criarPiloto();
                    break;
                case MEMBRO_TRIPULACAO:
                    criarMembroTripulacao();
                    break;
            }
            break;
        }
        case 1:
        {
            switch (tipo)
            {
                case TODOS:
                    cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                    cin >> in;
                    if(in == "Administrativo")
                    {
                        tipo = ADMINISTRATIVO;
                        deletarFuncionarioAdministrativo();
                        tipo = TODOS;
                    }
                    else if(in == "Piloto")
                    {
                        tipo = PILOTO;
                        deletarPiloto();
                        tipo = TODOS;
                    }
                    else if(in == "Tripulacao")
                    {
                        tipo = MEMBRO_TRIPULACAO;
                        deletarMembroTripulacao();
                        tipo = TODOS;
                    }
                    break;
                case ADMINISTRATIVO:
                    deletarFuncionarioAdministrativo();
                    break;
                case PILOTO:
                    deletarPiloto();
                    break;
                case MEMBRO_TRIPULACAO:
                    deletarMembroTripulacao();
                    break;
            }
            break;
        }
        case 2:
        {
            printarFuncionarios();
            break;
        }
        case 3:
        {
            switch (tipo)
            {
                case TODOS:
                    cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                    cin >> in;
                    if(in == "Administrativo")
                    {
                        tipo = ADMINISTRATIVO;
                        editarFuncionarioAdministrativo();
                        tipo = TODOS;
                    }
                    else if(in == "Piloto")
                    {
                        tipo = PILOTO;
                        editarPiloto();
                        tipo = TODOS;
                    }
                    else if(in == "Tripulacao")
                    {
                        tipo = MEMBRO_TRIPULACAO;
                        editarMembroTripulacao();
                        tipo = TODOS;
                    }
                    break;
                case ADMINISTRATIVO:
                    editarFuncionarioAdministrativo();
                    break;
                case PILOTO:
                    editarPiloto();
                    break;
                case MEMBRO_TRIPULACAO:
                    editarMembroTripulacao();
                    break;
            }
            break;
        }
    }
}

Funcionario* FuncionariosMenu::acharFuncionario() {
    string in;
    while (1) {
        switch (tipo) {
            case TODOS:
                cout << "Tipo de funcionario(Administrativo, Piloto, Tripulacao): ";
                cin >> in;
                if(in == "Administrativo")
                {
                    cout << "Nome do funcionario: ";
                    cin >> in;
                    for (Funcionario_administrativos* funcionario: a->getFuncionariosAdministrativos()) {
                        if (funcionario->getNome() == in) {
                            return funcionario;
                        }
                    }
                }
                else if(in == "Piloto")
                {
                    cout << "Nome do funcionario: ";
                    cin >> in;
                    for (Piloto* funcionario: a->getPilotos()) {
                        if (funcionario->getNome() == in) {
                            return funcionario;
                        }
                    }
                }
                else if(in == "Tripulacao")
                {
                    cout << "Destino para qual o funcionario vai: ";
                    cin >> in;
                    for(Membro_tripulacao* funcionario: a->getMembros())
                    {
                        for(Voo* voo: funcionario->getVoos())
                        {
                            if(voo->getDestino() == in)
                            {
                                return funcionario;
                            }
                        }
                    }
                }
                break;
            case ADMINISTRATIVO:
                cout << "Nome do funcionario: ";
                cin >> in;
                for (Funcionario_administrativos* funcionario: a->getFuncionariosAdministrativos()) {
                    if (funcionario->getNome() == in) {
                        return funcionario;
                    }
                }
                break;
            case PILOTO:
                cout << "Nome do funcionario: ";
                cin >> in;
                for (Piloto* funcionario: a->getPilotos()) {
                    if (funcionario->getNome() == in) {
                        return funcionario;
                    }
                }
                break;
            case MEMBRO_TRIPULACAO:
                cout << "Destino para qual o funcionario vai: ";
                cin >> in;
                for(Membro_tripulacao* funcionario: a->getMembros())
                {
                    for(Voo* voo: funcionario->getVoos())
                    {
                        if(voo->getDestino() == in)
                        {
                            return funcionario;
                        }
                    }
                }
                break;
        }
        cout << "Funcionario com parametro requerido nao encontrado, tente novamente" << endl ;
    }
}

void FuncionariosMenu::criarFuncionarioAdministrativo() {
    string nome;
    int data_nascimentoD,data_nascimentoM,data_nascimentoA;
    string categoria;
    int horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1;
    int horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2;
    string funcao;
    string departamento;

    string in;
    cout << "Nome:";
    cin >> nome;
    cout << "Data de nascimento (DD/MM/AAAA)";
    cin >> in;
    vector<string> splitted = split(in,"/");
    data_nascimentoD = stoi(splitted[0]);
    data_nascimentoM = stoi(splitted[1]);
    data_nascimentoA = stoi(splitted[2]);
    cout << "Categoria: ";
    cin >> categoria;
    cout << "Hora que comeca o servico: ";
    cin >> in;
    splitted = split(in,":");
    horario_de_trabalhoH1 = stoi(splitted[0]);
    horario_de_trabalhoM1 = stoi(splitted[1]);
    horario_de_trabalhoS1 = stoi(splitted[2]);
    cout << "Hora que acaba o servico: ";
    cin >> in;
    splitted = split(in,":");
    horario_de_trabalhoH2 = stoi(splitted[0]);
    horario_de_trabalhoM2 = stoi(splitted[1]);
    horario_de_trabalhoS2 = stoi(splitted[2]);
    cout << "Funcao: ";
    cin >> funcao;
    cout << "Departamento: ";
    cin >> departamento;
    Funcionario* novoFuncionario =new Funcionario_administrativos(nome,Data(data_nascimentoD,data_nascimentoM,data_nascimentoA),
            pair<Hora,Hora>(Hora(horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1),
                    Hora(horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2)),funcao,departamento);
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
        }
    }
}


//FUNCOES DOS VOOS

VooMenu::VooMenu() {
    opcoes = {"Alterar data", "Alterar hora", "Alterar destino", "Alterar Informação", "Visualizar voo", "Criar voo"};
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
            alterarHora();
            break;
        }
        case 2:
        {
            alterarDestino();
            break;
        }
        case 3:
        {
            alterarInformacao();
            break;
        }
        case 4:
        {
            visualizarVoo();
            break;
        }
        case 5:
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
    Data data;
    Hora hora_prevista, hora_real;
    string destino;
    bool cancelado;
    cout << "Diga a data do novo voo";
}
