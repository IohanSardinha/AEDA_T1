#ifndef PROJECT1_UTILS_H
#define PROJECT1_UTILS_H
#pragma once
#include <iostream>
#include <vector>
#include "Funcionario.h"

using namespace std;

class GPS{
    float latitude,
          longitude;
};

class Data{
    int dia,
        mes,
        ano;
};

class Hora{
    int hora,
        minuto,
        segundo;
};

class Localizacao{
    string pais;
    string cidade;
    GPS cordenadas;
};

class Voo{
    Data data;
    Hora hora;
    string destino;
};

class Informacoes{
    Voo voo;
    Hora hora_prevista;
    Hora hora_real;
    bool cancelado;
};

class Aviao{
    string tipo;
    int capacidade;
    //Escalonamento
    vector<Voo*> voos;
    vector<Funcionario*> tripulacao; //2 pilotos e 2 membros de cabine, talvez valha mais criar a classe tripulacao
    int custo_operacao;
};

#endif //PROJECT1_UTILS_H
