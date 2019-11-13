#include "FuncionariosMenu.h"
#include "../Classes/Aviao.h"

FuncionariosMenu::FuncionariosMenu(enum tipos_funcionarios t) {
    tipo = t;
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
            cout << "AQUI" << endl;
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