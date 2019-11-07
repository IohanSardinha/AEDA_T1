#ifndef PROJECT1_FUNCIONARIO_H
#define PROJECT1_FUNCIONARIO_H
#pragma once
#include <iostream>
#include "utils.h"

using namespace std;

class Funcionario{
    int salario;
};

class Funcionario_administrativos{
    string funcao;
    string departamento;
    int salario;
};

class Menbro_tripulacao{
    vector<Voo*> voos_alocados;
    Informacoes info_voo;
    int salario;
};

class Pessoal_de_Base{
    string nome;
    Data data_nascimento;
    string categoria;
    //Horario fixo de trabalho respectivo*  trabalha de hora x a hora y ou trabalha k horas?
    int salario;
};

class Piloto{
    string nome;
    Data data_nascimento;
    string categoria;
    vector<string> tipos_aviao; //vetor com tipos de aviao habilitado a pilotar
    vector<Voo> voos_realizados;
    int salario; //como o salario depende da categoria, criar um funcao para isso
};



#endif //PROJECT1_FUNCIONARIO_H
