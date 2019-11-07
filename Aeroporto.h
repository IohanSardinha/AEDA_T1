#ifndef PROJECT1_AEROPORTO_H
#define PROJECT1_AEROPORTO_H

#include <iostream>
#include "Funcionario.h"
#include "utils.h"

class Aeroportos{
    Funcionario* gerente;
    Localizacao loc;
    vector<Funcionario*> func;
    vector<Aviao*> avioes;
    vector<Piloto*> pilotos;
    vector<Menbro_tripulacao*> membros;
    vector<Funcionario_administrativos*> func_admin;
};

#endif //PROJECT1_AEROPORTO_H
