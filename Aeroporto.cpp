#include "Aeroporto.h"

Aeroporto::Aeroporto(Funcionario* ger, Localizacao loc, vector<Funcionario*> fu, vector<Aviao*> av, vector<Piloto*> pil, vector<Menbro_tripulacao*> mem, vector<Funcionario_administrativos*> f_adm )
{
    gerente = ger;
    localizacao = loc;
    funcionarios = fu;
    avioes = av;
    pilotos = pil;
    membros = mem;
    funcionarios_administrativos = f_adm;
}

Funcionario* Aeroporto::getGerente() const
{
    return gerente;
}

Localizacao Aeroporto::getLocalizacao() const {
    return localizacao;
}

void Aeroporto::adicionarFuncionario(Funcionario* f)
{
    funcionarios.push_back(f);
}

void  Aeroporto::adicionarPiloto(Piloto* p)
{
    pilotos.push_back(p);
}

void  Aeroporto::adicionarAviao(Aviao* a)
{
    avioes.push_back(a);
}

void  Aeroporto::adicionarMembro(Menbro_tripulacao* m)
{
    membros.push_back(m);
}

void  Aeroporto::adicionarFuncionarioAdministrativo(Funcionario_administrativos* f)
{
    funcionarios_administrativos.push_back(f);
}