#ifndef PROJECT1_FUNCIONARIO_H
#define PROJECT1_FUNCIONARIO_H

#include "utils.h"
#include <iostream>
#include <utility>

using namespace std;

class Funcionario{
protected:
    int salario;
};

class Funcionario_administrativos :public Funcionario{
    string funcao;
    string departamento;

};

class Menbro_tripulacao :public Funcionario{
    vector<Voo*> voos_alocados;
    vector<Informacao*> info_voos;
};

class Pessoal_de_Base :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    pair<Hora,Hora> horario_de_trabalho;
};

class Piloto :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    vector<string> tipos_aviao; //vetor com tipos de aviao habilitado a pilotar
    vector<Voo*> voos_realizados;
     //como o salario depende da categoria, criar um funcao para isso
};

#endif //PROJECT1_FUNCIONARIO_H
