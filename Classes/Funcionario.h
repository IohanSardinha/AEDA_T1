#ifndef PROJECT1_FUNCIONARIO_H
#define PROJECT1_FUNCIONARIO_H

#include "../Utils/split.h"
#include "../Utils/Data.h"
#include "../Utils/Hora.h"
#include "../Classes/Voo.h"
#include <iostream>
#include <utility>


using namespace std;

class Aviao;

class Funcionario{
protected:
    int salario;
public:
    Funcionario(int salario);
    int getSalario() const;
    virtual void print() = 0;
};

class Funcionario_administrativos :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    pair<Hora,Hora> horario_de_trabalho;
    string funcao;
    string departamento;
public:
    Funcionario_administrativos(const string& nome,const Data& data_nascimento,const pair<Hora,Hora> horario_de_trabalho,const string &funcao, const string &departamento);
    string getFuncao() const;
    void setFuncao(const string &funcao);
    string getDepartamento() const;
    void setDepartamento(const string &departamento);
    void print();
    const string &getNome() const;
    void setNome(const string &nome);
    const Data &getDataNascimento() const;
    void setDataNascimento(const Data &dataNascimento);
    const string &getCategoria() const;
    void setCategoria(const string &categoria);
    const pair<Hora,Hora> &gethorario_de_trabalho() const;
    void setHorarioDeTrabalho(const pair<Hora,Hora> &horario_de_trabalho);
};

class Membro_tripulacao :public Funcionario{
    vector<Voo*> voos_alocados;
    vector<Informacao*> info_voos;
public:
    Membro_tripulacao(int salario, const vector<Voo*> & voosAlocados, const vector<Informacao*> &infoVoos);
    vector<Voo*> getVoos();
    vector<Informacao*> getInfos();
    void print();
    void adicionarVoo(Voo* v){voos_alocados.push_back(v);}
    void adicionarInfo(Informacao* i){info_voos.push_back(i);}
};

class Piloto :public Funcionario{
    string nome;
    Data data_nascimento;
    string categoria;
    vector<Aviao*> tipos_aviao; //vetor com tipos de aviao habilitado a pilotar
    vector<Voo*> voos_realizados;
public:
    vector<Voo*> getVoos(){ return voos_realizados;};
    vector<Aviao*> getAvioes(){ return tipos_aviao;};
    Piloto(int salario, const string &nome, const Data &dataNascimento, const string &categoria,
           const vector<Aviao*> &tiposAviao, const vector<Voo*> & voosRealizados);

    const string &getNome() const;

    void setNome(const string &nome);

    const Data &getDataNascimento() const;

    void setDataNascimento(const Data &dataNascimento);

    const string &getCategoria() const;

    void setCategoria(const string &categoria);

    void print();
};

#endif //PROJECT1_FUNCIONARIO_H
