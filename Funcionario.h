#ifndef PROJECT1_FUNCIONARIO_H
#define PROJECT1_FUNCIONARIO_H

#include "utils.h"
#include <iostream>
#include <utility>

using namespace std;

class Funcionario{
protected:
    int salario;
public:
    int getSalario() const;
    virtual void print() = 0;
};

class Funcionario_administrativos :public Funcionario{
    string funcao;
    string departamento;
public:
    string getFuncao() const;
    void setFuncao(const string &funcao);
    string getDepartamento() const;
    void setDepartamento(const string &departamento);
};

class Membro_tripulacao :public Funcionario{
    vector<Voo*> voos_alocados;
    vector<Informacao*> info_voos;
};

class Pessoal_de_Base :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    pair<Hora,Hora> horario_de_trabalho;
public:
    const string &getNome() const;

    void setNome(const string &nome);

    const Data &getDataNascimento() const;

    void setDataNascimento(const Data &dataNascimento);

    const string &getCategoria() const;

    void setCategoria(const string &categoria);

    const pair<Hora,Hora> &gethorario_de_trabalho() const;

    void setHorarioDeTrabalho(const pair<Hora,Hora> &horario_de_trabalho);
};

class Piloto :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    vector<string> tipos_aviao; //vetor com tipos de aviao habilitado a pilotar
    vector<Voo*> voos_realizados;
public:
    const string &getNome() const;

    void setNome(const string &nome);

    const Data &getDataNascimento() const;

    void setDataNascimento(const Data &dataNascimento);

    const string &getCategoria() const;

    void setCategoria(const string &categoria);
};

#endif //PROJECT1_FUNCIONARIO_H
