#include <iostream>
#include "Funcionario.h"
#include <string>


using namespace std;

int Funcionario::getSalario() const{
    return salario;
}

Funcionario::Funcionario(int salario) : salario(salario) {}

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

void Funcionario_administrativos::print() {
    cout << "Função: " << funcao << endl;
    cout << "Departamento: " << departamento << endl;
}

Funcionario_administrativos::Funcionario_administrativos(int salario, const string &funcao, const string &departamento)
        : Funcionario(salario), funcao(funcao), departamento(departamento) {}


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

Pessoal_de_Base::Pessoal_de_Base(int salario, const string &nome, const Data &dataNascimento, const string &categoria,const pair<Hora, Hora>&horarioDeTrabalho) :
Funcionario(salario), nome(nome), data_nascimento(dataNascimento),categoria(categoria), horario_de_trabalho(horarioDeTrabalho) {}

void Pessoal_de_Base::print(){
    cout << "Nome: " << nome << endl;
    cout << "Data: " << data_nascimento << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Horario de trabalho: " << horario_de_trabalho << endl;
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

Piloto::Piloto(int salario, const string &nome, const Data &dataNascimento, const string &categoria,
        const vector<string> &tiposAviao, const vector<Voo*> & voosRealizados):
        Funcionario(salario), nome(nome), data_nascimento(dataNascimento), categoria(categoria),
        tipos_aviao(tiposAviao), voos_realizados(voosRealizados) {};

void Piloto::print() {
    cout << "Nome: " << nome << endl;
    cout << "Data: " << data_nascimento << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Avioes pilotados: " << endl;
    for (string tipo: tipos_aviao)
         cout << tipo << endl;
    cout << "Voos realizados: " << endl;
    for (Voo* voos_realiz : voos_realizados)
        cout << voos_realiz << endl;
}

Membro_tripulacao::Membro_tripulacao(int salario, const vector<Voo*> & voosAlocados, const vector<Informacao*> &infoVoos):Funcionario (salario), voos_alocados(voosAlocados), info_voos(infoVoos) {}

void Membro_tripulacao::print() {
    cout << "Voos alocados: " << endl;
    for (Voo* voo : voos_alocados)
        cout << *voo << endl;
    cout << "Informações de voos: " << endl;
    for (Informacao* informacao : info_voos)
        cout << *informacao << endl;
}