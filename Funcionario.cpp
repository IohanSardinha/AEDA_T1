#include <iostream>
#include "Funcionario.h"
#include <string>


using namespace std;

int Funcionario::getSalario() const{
    return salario;
}

string Funcionario_administrativos::getFuncao() const {
    return funcao;
}

void Funcionario_administrativos::setFuncao(const string &funcao) {
    Funcionario_administrativos::funcao = funcao;
}
string Funcionario_administrativos::getDepartamento() const {
    return departamento;
}

void Funcionario_administrativos::setDepartamento(const string &departamento) {
    Funcionario_administrativos::departamento = departamento;
}


const string &Pessoal_de_Base::getNome() const {
    return nome;
}

void Pessoal_de_Base::setNome(const string &nome) {
    Pessoal_de_Base::nome = nome;
}

const Data &Pessoal_de_Base::getDataNascimento() const {
    return data_nascimento;
}

void Pessoal_de_Base::setDataNascimento(const Data &dataNascimento) {
    data_nascimento = dataNascimento;
}

const string &Pessoal_de_Base::getCategoria() const {
    return categoria;
}

void Pessoal_de_Base::setCategoria(const string &categoria) {
    Pessoal_de_Base::categoria = categoria;
}

const pair<Hora, Hora> &Pessoal_de_Base::gethorario_de_trabalho() const {
    return horario_de_trabalho;
}

void Pessoal_de_Base::setHorarioDeTrabalho(const pair<Hora, Hora> &horarioDeTrabalho) {
    horario_de_trabalho = horarioDeTrabalho;
}


const string &Piloto::getNome() const {
    return nome;
}

void Piloto::setNome(const string &nome) {
    Piloto::nome = nome;
}

const Data &Piloto::getDataNascimento() const {
    return data_nascimento;
}

void Piloto::setDataNascimento(const Data &dataNascimento) {
    data_nascimento = dataNascimento;
}

const string &Piloto::getCategoria() const {
    return categoria;
}

void Piloto::setCategoria(const string &categoria) {
    Piloto::categoria = categoria;
}
