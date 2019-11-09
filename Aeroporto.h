#ifndef PROJECT1_AEROPORTO_H
#define PROJECT1_AEROPORTO_H

#include <iostream>
#include "Funcionario.h"
#include "utils.h"

class Aeroporto{
    Funcionario* gerente;
    Localizacao localizacao;
    vector<Funcionario*> funcionarios;
    vector<Aviao*> avioes;
    vector<Piloto*> pilotos;
    vector<Menbro_tripulacao*> membros;
    vector<Funcionario_administrativos*> funcionarios_administrativos;
public:
    Aeroporto(Funcionario* ger, Localizacao loc, vector<Funcionario*> fu, vector<Aviao*> av, vector<Piloto*> pil, vector<Menbro_tripulacao*> mem, vector<Funcionario_administrativos*> f_adm );
    Funcionario* getGerente() const;
    Localizacao getLocalizacao() const;
    void adicionarFuncionario(Funcionario* f);
    void adicionarPiloto(Piloto* p);
    void adicionarAviao(Aviao* a);
    void adicionarMembro(Menbro_tripulacao* m);
    void adicionarFuncionarioAdministrativo(Funcionario_administrativos* f);
    void removerFuncionario(Funcionario* f);
    void removerPiloto(Piloto* p);
    void removerAviao(Aviao* a);
    void removerMembro(Menbro_tripulacao* m);
    void removerFuncionarioAdministrativo(Funcionario_administrativos* f);
};

#endif //PROJECT1_AEROPORTO_H
