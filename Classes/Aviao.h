#ifndef PROJECT1_AVIAO_H
#define PROJECT1_AVIAO_H

#include <iostream>
#include <string>
#include "../Classes/Voo.h"

class Aviao{
    string tipo;
    int capacidade;
    //Escalonamento
    vector<Voo*> voos;
    vector<Funcionario*> tripulacao; //2 pilotos e 2 membros de cabine, talvez valha mais criar a classe tripulacao
    int custo_operacao;
public:
    Aviao(string tipo, int capacidade, vector<Voo*> voos, vector<Funcionario*> funcionarios, int custo_operacao)
    {
        this->tipo = tipo;
        this->capacidade = capacidade;
        this->voos = voos;
        this->tripulacao = funcionarios;
        this->custo_operacao = custo_operacao;
    }

    Aviao(string tipo, int capacidade, vector<Voo*> voos, Funcionario* piloto1, Funcionario* piloto2,Funcionario* membro_cabine1,Funcionario* membro_cabine2,vector<Funcionario*> mais_tripulacao, int custo_operacao)
    {
        tripulacao.push_back(piloto1);
        tripulacao.push_back(piloto2);
        tripulacao.push_back(membro_cabine1);
        tripulacao.push_back(membro_cabine2);
        tripulacao.insert(tripulacao.end(),mais_tripulacao.begin(),mais_tripulacao.end());
        this->tipo = tipo;
        this->capacidade = capacidade;
        this->voos = voos;
        this->tripulacao = tripulacao;
        this->custo_operacao = custo_operacao;
    }

    vector<Funcionario*> getTripulacao() const{ return tripulacao;}

    void adicionarTripulacao(Funcionario* funcionario)
    {
        tripulacao.push_back(funcionario);
    }

    void adicionarVoo(Voo* voo)
    {
        voos.push_back(voo);
    }

    void removerTripulacao(Funcionario* funcionario)
    {
        for(int i = 0; i < tripulacao.size(); i++)
        {
            if(tripulacao.at(i) == funcionario)
            {
                tripulacao.erase(tripulacao.begin()+i);
                break;
            }
        }
    }

    void removerVoo(Voo* voo)
    {
        for(int i = 0; i < voos.size(); i++)
        {
            if(voos.at(i) == voo)
            {
                voos.erase(voos.begin()+i);
                break;
            }
        }
    }

    const string &getTipo() const {
        return tipo;
    }

    void setTipo(const string &tipo) {
        Aviao::tipo = tipo;
    }

    int getCapacidade() const {
        return capacidade;
    }

    void setCapacidade(int capacidade) {
        Aviao::capacidade = capacidade;
    }

    vector<Voo*> getVoos() const{
        return voos;
    }

    void setVoos(const vector<Voo*> voos) {
        Aviao::voos = voos;
    }

    int getCustoOperacao() const {
        return custo_operacao;
    }

    void setCustoOperacao(int custoOperacao) {
        custo_operacao = custoOperacao;
    }

    friend ostream& operator<<(ostream& os, const Aviao& a);
};

#endif //PROJECT1_AVIAO_H
