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

void Aeroporto::removerFuncionario(Funcionario* f)
{
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios.at(i) == f)
        {
            funcionarios.erase(funcionarios.begin()+i);
            break;
        }
    }
}

void  Aeroporto::removerPiloto(Piloto* p)
{
    for(int i = 0; i < pilotos.size(); i++)
    {
        if(pilotos.at(i) == p)
        {
            pilotos.erase(pilotos.begin()+i);
            break;
        }
    }
}

void  Aeroporto::removerAviao(Aviao* a)
{
    for(int i = 0; i < avioes.size(); i++)
    {
        if(avioes.at(i) == a)
        {
            avioes.erase(avioes.begin()+i);
            break;
        }
    }
}

void  Aeroporto::removerMembro(Menbro_tripulacao* m)
{
    for(int i = 0; i < membros.size(); i++)
    {
        if(membros.at(i) == m)
        {
            membros.erase(membros.begin()+i);
            break;
        }
    }
}

void  Aeroporto::removerFuncionarioAdministrativo(Funcionario_administrativos* f)
{
    for(int i = 0; i < funcionarios_administrativos.size(); i++)
    {
        if(funcionarios_administrativos.at(i) == f)
        {
            funcionarios_administrativos.erase(funcionarios_administrativos.begin()+i);
            break;
        }
    }
}