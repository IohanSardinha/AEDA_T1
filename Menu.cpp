#include "Menu.h"

vector<Aeroporto*> aeroportos;

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
            menus_to_call["AcessarAeroportoMenu"]->play();
            break;
        }
        case 3:
        {
            deletarAeroporto();
            break;
        }
    }
}

void MainMenu::criarAeroporto()
{} //falta fazer

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

AcessarAeroportoMenu::AcessarAeroportoMenu() {
    opcoes = {"Alterar gerente", "Alterar localização", "Funcionarios", "Aviões"};
}

void AcessarAeroportoMenu::alterarGerente() {
    //TODO
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
            listarFuncionarios();
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

Funcionario_administrativos* FuncionariosMenu::acharFuncionarioAdministrativo() {
    string in;
    while (1)
    {
        cout << "Nome do funcionario: ";
        cin >> in;
        for (Funcionario_administrativos* funcionario: a->getFuncionariosAdministrativos())
        {
            if (funcionario->getNome() == in)
            {
                return funcionario;
            }
        }
        cout << "Funcionario com parametro requerido nao encontrado, tente novamente" << endl ;
    }
}

Piloto* FuncionariosMenu::acharPiloto() {
    string in;
    while (1)
    {
        cout << "Nome do funcionario: ";
        cin >> in;
        for (Piloto* funcionario: a->getPilotos()) {
            if (funcionario->getNome() == in) {
                return funcionario;
            }
        }
        cout << "Funcionario com parametro requerido nao encontrado, tente novamente" << endl ;
    }
}

Membro_tripulacao* FuncionariosMenu::acharMembroTripulacao(){
    string in;
    while (1)
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
    Funcionario_administrativos novoFuncionario = Funcionario_administrativos(nome,Data(data_nascimentoD,data_nascimentoM,data_nascimentoA),
            pair<Hora,Hora>(Hora(horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1),
                    Hora(horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2)),funcao,departamento);
    a->adicionarFuncionario(&novoFuncionario);
    a->adicionarFuncionarioAdministrativo(&novoFuncionario);
}

void FuncionariosMenu::criarPiloto() {
    string nome;
    int data_nascimentoD,data_nascimentoM,data_nascimentoA;
    string categoria;

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
    cout << "OBS: para adicionar voos e informacoes de voos ao piloto va para editar pilotos" << endl;
    Piloto novoFuncionario = Piloto(0,nome,Data(data_nascimentoD,data_nascimentoM,data_nascimentoA),categoria,{},{});
    a->adicionarFuncionario(&novoFuncionario);
    a->adicionarPiloto(&novoFuncionario);
}

void FuncionariosMenu::criarMembroTripulacao()
{
    vector<Voo*> voos;
    for(Aviao* aviao: a->getAvioes())
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

    Membro_tripulacao novoFuncionario(0,{},{});
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
                novoFuncionario.getVoos().push_back(voo);
                novoFuncionario.getInfos().push_back(voo->getInfo());
            }
        }
    }

    a->adicionarFuncionario(&novoFuncionario);
    a->adicionarMembro(&novoFuncionario);
}

void FuncionariosMenu::editarFuncionarioAdministrativo() {
    Funcionario_administrativos* funcionario = acharFuncionarioAdministrativo();
    while (1)
    {
        cout << "Escolha o campo para alterar:" << endl;
        cout << "0 - Nome" << endl;
        cout << "1 - Data de nascimento" << endl;
        cout << "2 - Categoria" << endl;
        cout << "3 - Horario de trabalho" << endl;
        cout << "4 - Funcao" << endl;
        cout << "5 - Departamento" << endl;
        cout << "6 - Sair" << endl;
        cin >> input;

        switch (input)
        {
            case 0:{
                string nome;
                cout << "Digite o novo nome: ";
                cin >> nome;
                funcionario->setNome(nome);
                break;
            }
            case 1: {
                string inp;
                int data_nascimentoD,data_nascimentoM,data_nascimentoA;
                cout << "Digite a nova data de nascimento(DD/MM/AAAA): ";
                vector<string> splitted = split(inp,"/");
                data_nascimentoD = stoi(splitted[0]);
                data_nascimentoM = stoi(splitted[1]);
                data_nascimentoA = stoi(splitted[2]);
                funcionario->setDataNascimento(Data(data_nascimentoD,data_nascimentoM,data_nascimentoA));
                break;
            }
            case 2: {
                string cat;
                cout << "Digite a nova categoria: ";
                cin >> cat;
                funcionario->setCategoria(cat);
                break;
            }
            case 3:
            {
                string in;
                int horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1;
                int horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2;
                cout << "Nova hora que comeca o servico: ";
                cin >> in;
                vector<string> splitted = split(in,":");
                horario_de_trabalhoH1 = stoi(splitted[0]);
                horario_de_trabalhoM1 = stoi(splitted[1]);
                horario_de_trabalhoS1 = stoi(splitted[2]);
                cout << "Nova hora que acaba o servico: ";
                cin >> in;
                splitted = split(in,":");
                horario_de_trabalhoH2 = stoi(splitted[0]);
                horario_de_trabalhoM2 = stoi(splitted[1]);
                horario_de_trabalhoS2 = stoi(splitted[2]);
                funcionario->setHorarioDeTrabalho(pair<Hora,Hora>(Hora(horario_de_trabalhoH1,horario_de_trabalhoM1,horario_de_trabalhoS1),
                                                                  Hora(horario_de_trabalhoH2,horario_de_trabalhoM2,horario_de_trabalhoS2)));
                break;
            }
            case 4: {
                string funcao;
                cout << "Nova funcao: ";
                cin >> funcao;
                funcionario->setFuncao(funcao);
                break;
            }
            case 5: {
                string departamento;
                cout << "Novo departamento: ";
                cin >> departamento;
                funcionario->setDepartamento(departamento);
                break;
            }
            case 6:
                return;
        }
        cout << "Entrada invalida" << endl;
    }

}

void FuncionariosMenu::editarPiloto() {
    Piloto* funcionario = acharPiloto();
    while (1)
    {
        cout << "Escolha o campo para alterar:" << endl;
        cout << "0 - Nome" << endl;
        cout << "1 - Data de nascimento" << endl;
        cout << "2 - Categoria" << endl;
        cout << "3 - Ver voos" << endl;
        cout << "4 - Ver avioes habilitados a dirigir" << endl;
        cout << "5 - Adicionar voo" << endl;
        cout << "6 - Adicionar aviao habilitado a dirigir" << endl;
        cout << "7 - Remover voo" << endl;
        cout << "8 - Remover aviao habilitado a dirigir" << endl;
        cout << "9 - Sair" << endl;
        cin >> input;

        switch (input)
        {
            case 0:{
                string nome;
                cout << "Digite o novo nome: ";
                cin >> nome;
                funcionario->setNome(nome);
                break;
            }
            case 1: {
                string inp;
                int data_nascimentoD,data_nascimentoM,data_nascimentoA;
                cout << "Digite a nova data de nascimento(DD/MM/AAAA): ";
                vector<string> splitted = split(inp,"/");
                data_nascimentoD = stoi(splitted[0]);
                data_nascimentoM = stoi(splitted[1]);
                data_nascimentoA = stoi(splitted[2]);
                funcionario->setDataNascimento(Data(data_nascimentoD,data_nascimentoM,data_nascimentoA));
                break;
            }
            case 2: {
                string cat;
                cout << "Digite a nova categoria: ";
                cin >> cat;
                funcionario->setCategoria(cat);
                break;
            }
            case 3:
            {
                for(Voo* voo: funcionario->getVoos())
                {
                    cout << voo;
                }
                break;
            }
            case 4: {
                for(Aviao* aviao: funcionario->getAvioes())
                {
                    cout << aviao;
                }
                break;
            }
            case 5: {
                vector<Voo*> voos;
                for(Aviao* aviao: a->getAvioes())
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
                string destino;
                cout << "Digite o destino do voo que quer adicionar: ";
                cin >> destino;
                for(Voo* voo : voos)
                {
                    if(destino == voo->getDestino())
                    {
                        bool add = true;
                        for(Voo* v: funcionario->getVoos())
                        {
                            if(v == voo)
                            {
                                cout << "Funcionario ja esta alocado para este voo" << endl;
                                add = false;
                                break;
                            }
                        }
                        if(add)
                            funcionario->getVoos().push_back(voo);
                        break;
                    }
                }
                break;
            }
            case 6: {
                string modelo;
                cout << "Digite o modelo do aviao: ";
                cin >> modelo;
                for(Aviao* aviao: a->getAvioes())
                {
                    if(modelo ==aviao->getTipo())
                    {
                        bool add = true;
                        for(Aviao* av: funcionario->getAvioes())
                        {
                            if(av == aviao)
                            {
                                cout << "Piloto ja dirige este aviao" << endl;
                                add = false;
                                break;
                            }
                        }
                        if(add)
                            funcionario->getAvioes().push_back(aviao);
                        break;
                    }
                }
                break;
            }
            case 7: {
                string destino;
                cout << "Digite o destino do voo que quer remover: ";
                cin >> destino;
                bool found = false;
                for(int i = 0; i < funcionario->getVoos().size(); i++)
                {
                    if(funcionario->getVoos().at(i)->getDestino() == destino)
                    {
                        funcionario->getVoos().erase(funcionario->getVoos().begin()+i);
                        found = true;
                    }
                }
                if(!found)
                {
                    cout << "Voo nao esta alocado para o funcionario" << endl;
                }
                break;
            }
            case 8: {
                string modelo;
                cout << "Digite o modelo do aviao que quer remover: ";
                cin >> modelo;
                bool found = false;
                for(int i = 0; i < funcionario->getAvioes().size(); i++)
                {
                    if(funcionario->getAvioes().at(i)->getTipo() == modelo)
                    {
                        funcionario->getAvioes().erase(funcionario->getAvioes().begin()+i);
                        found = true;
                    }
                }
                if(!found)
                {
                    cout << "Piloto ja nao e habito a pilotar esse aviao" << endl;
                }
                break;
            }
            case 9:
                return;
        }
        cout << "Entrada invalida" << endl;
    }

}

void FuncionariosMenu::editarMembroTripulacao(){
    Membro_tripulacao* funcionario = acharMembroTripulacao();
    while (1)
    {
        cout << "Escolha o campo para alterar:" << endl;
        cout << "0 - Ver voos alocados" << endl;
        cout << "1 - Alocar voo" << endl;
        cout << "2 - Remover voo" << endl;
        cout << "3 - Ver informacoes dos voos" << endl;
        cout << "4 - Sair" << endl;
        cin >> input;

        switch (input)
        {
            case 0:
            {
                for(Voo* voo: funcionario->getVoos())
                {
                    cout << voo;
                }
                break;
            }
            case 1: {
                vector<Voo*> voos;
                for(Aviao* aviao: a->getAvioes())
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
                string destino;
                cout << "Digite o destino do voo que quer adicionar: ";
                cin >> destino;
                for(Voo* voo : voos)
                {
                    if(destino == voo->getDestino())
                    {
                        bool add = true;
                        for(Voo* v: funcionario->getVoos())
                        {
                            if(v == voo)
                            {
                                cout << "Funcionario ja esta alocado para este voo" << endl;
                                add = false;
                                break;
                            }
                        }
                        if(add)
                            funcionario->getVoos().push_back(voo);
                        break;
                    }
                }
                break;
            }
            case 2: {
                string destino;
                cout << "Digite o destino do voo que quer remover: ";
                cin >> destino;
                bool found = false;
                for(int i = 0; i < funcionario->getVoos().size(); i++)
                {
                    if(funcionario->getVoos().at(i)->getDestino() == destino)
                    {
                        funcionario->getVoos().erase(funcionario->getVoos().begin()+i);
                        found = true;
                    }
                }
                if(!found)
                {
                    cout << "Voo nao esta alocado para o funcionario" << endl;
                }
                break;
            }
            case 3:
            {
                for(Informacao* info: funcionario->getInfos())
                {
                    cout << info;
                }
                break;
                break;
            }
            case 9:
                return;
        }
        cout << "Entrada invalida" << endl;
    }

}

void FuncionariosMenu::deletarFuncionarioAdministrativo() {
    string nome;
    cout << "Nome do funcionario a ser removido: ";
    cin >> nome;
    int i,j = 0;
    Funcionario* funcionario;
    for(; i<a->getFuncionariosAdministrativos().size(); i++)
    {
        if(a->getFuncionariosAdministrativos().at(i)->getNome() == nome)
        {
            funcionario = a->getFuncionariosAdministrativos().at(i);
            break;
        }
    }
    for(; j < a->getFuncionarios().size(); j++)
    {
        if(a->getFuncionarios().at(j) == funcionario)
        {
            break;
        }
    }
    a->getFuncionariosAdministrativos().erase(a->getFuncionariosAdministrativos().begin()+i);
    a->getFuncionarios().erase(a->getFuncionarios().begin()+j);
    delete(funcionario);
}

void FuncionariosMenu::deletarPiloto(){
    string nome;
    cout << "Nome do funcionario a ser removido: ";
    cin >> nome;
    int i,j = 0;
    Funcionario* funcionario;
    for(; i<a->getPilotos().size(); i++)
    {
        if(a->getPilotos().at(i)->getNome() == nome)
        {
            funcionario = a->getPilotos().at(i);
            break;
        }
    }
    for(; j < a->getFuncionarios().size(); j++)
    {
        if(a->getFuncionarios().at(j) == funcionario)
        {
            break;
        }
    }
    a->getPilotos().erase(a->getPilotos().begin()+i);
    a->getFuncionarios().erase(a->getFuncionarios().begin()+j);
    delete(funcionario);
}

void FuncionariosMenu::deletarMembroTripulacao(){

    for(int i = 0; i < a->getMembros().size(); i++)
    {
        cout << "Mebro " << i << ":" << endl;
        a->getMembros().at(i)->print();
    }
    cout << "Qual o membro que deseja remover?: ";
    int i,j;
    Funcionario* funcionario = a->getMembros().at(i);
    cin >> i;
    for(; j < a->getFuncionarios().size(); j++)
    {
        if(funcionario == a->getFuncionarios().at(j))
        {
            break;
        }
    }
    a->getMembros().erase(a->getMembros().begin()+i);
    a->getFuncionarios().erase(a->getFuncionarios().begin()+j);
    delete(funcionario);
}

void FuncionariosMenu::listarFuncionarios() {
    switch (tipo)
    {
        case TODOS:
            for(Funcionario* funcionario: a->getFuncionarios())
            {
                funcionario->print();
            }
            break;
        case ADMINISTRATIVO:
            for(Funcionario* funcionario: a->getFuncionariosAdministrativos())
            {
                funcionario->print();
            }
            break;
        case PILOTO:
            for(Funcionario* funcionario: a->getPilotos())
            {
                funcionario->print();
            }
            break;
        case MEMBRO_TRIPULACAO:
            for(Funcionario* funcionario: a->getMembros())
            {
                funcionario->print();
            }
            break;
    }
}

void AcessarAeroportoMenu::alterarLocalizacao() {
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
}

AviaoMenu::AviaoMenu() {
    opcoes = {"Criar Aviao", "Editar Tipo do Aviao", "Editar Capacidade Aviao", "Editar Voos"};
}

void AcessarAeroportoMenu::escolherAeroporto()
{
    string p, c;
    cout << "Insira o pais: " << endl;
    cin >> p;
    cout << "Insira a cidade: " << endl;
    cin >> c;
    for(int i = 0; i < aeroportos.size(); i++) {
        if (aeroportos.at(i)->getLocalizacao().getPais() == p && aeroportos.at(i)->getLocalizacao().getCidade() == c)
        {
            aeroporto = aeroportos.at(i);
            break;
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

void AviaoMenu::criarAviao() {
    string tipo;
    int capacidade, v, f, custo;
    vector<Voo*> voo;
    vector<Funcionario*> funcionario;
    cout << "Qual o tipo do avião: " << endl;
    cin >> tipo;
    cout << "Qual a capacidade do avião: " << endl;
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
        cout << "0 - Tipo de avião" << endl << "1 - Capacidade do avião" << endl;
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


//FUNCOES DOS VOOS

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
    cout << "Informação: " << voo->getInfo() << endl;
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

//menus_to_call["AviaoMenu"]->a = aviao;