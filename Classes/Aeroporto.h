#ifndef PROJECT1_AEROPORTO_H
#define PROJECT1_AEROPORTO_H

#include <iostream>
#include "Funcionario.h"
#include "../Utils/Localizacao.h"

class Aeroporto{
    Funcionario* gerente;
    Localizacao localizacao;
    vector<Funcionario*> funcionarios;
    vector<Aviao*> avioes;
    vector<Piloto*> pilotos;
    vector<Membro_tripulacao*> membros;
    vector<Funcionario_administrativos*> funcionarios_administrativos;

public:
    Aeroporto(Funcionario* ger, Localizacao loc, vector<Funcionario*> fu, vector<Aviao*> av, vector<Piloto*> pil, vector<Membro_tripulacao*> mem, vector<Funcionario_administrativos*> f_adm );
    Funcionario* getGerente() const;
    Localizacao getLocalizacao() const;
    void setLocalizacao(string p, string c, GPS g);
    void adicionarFuncionario(Funcionario* f);
    void adicionarPiloto(Piloto* p);
    void adicionarAviao(Aviao* a);
    void adicionarMembro(Membro_tripulacao* m);
    void adicionarFuncionarioAdministrativo(Funcionario_administrativos* f);
    void removerFuncionario(Funcionario* f);
    void removerPiloto(Piloto* p);
    void removerAviao(Aviao* a);
    void removerMembro(Membro_tripulacao* m);
    void removerFuncionarioAdministrativo(Funcionario_administrativos* f);
    friend ostream& operator<<(ostream& os, const Aeroporto& a);
    vector<Funcionario*> & getFuncionarios();
    vector<Aviao*> & getAvioes();
    vector<Piloto*> & getPilotos();
    vector<Membro_tripulacao*> & getMembros();
    vector<Funcionario_administrativos*> & getFuncionariosAdministrativos();

};

#endif //PROJECT1_AEROPORTO_H