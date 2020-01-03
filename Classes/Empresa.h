#ifndef PROJECT1_EMPRESAS_H
#define PROJECT1_EMPRESAS_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;
///Empresa de Manutençãde aviões
class Empresa{
    ///Identificação unica da empresa
    int id;
    ///numero de manutenccoes ja feitas
    int disponibilidade;
    ///numero de horas que falta para que esteja disponivel
    int manutencoes;
public:
    ///Construtor da Empresa
    Empresa(int id, int disponibilidade, int manutencoes);
    ///Getter do ID
    int getId() const;
    ///Getter da disponibilidade
    int getDisponibilidade() const;
    ///Setter da disponibilidade
    void setDisponibilidade(int n);
    ///Setter da manutenção
    void setManutencao(int n);
    ///Getter da Manutenção
    int getManutencao();
    ///Sobrecarga do operador < para implementação da lista de prioridade
    bool operator< (Empresa e) const;
    ///Sobrecarga do operador << para printar a empresa
    friend ostream& operator<<(ostream& os, Empresa e);
};

class EmpresaJaExiste{
    int id;
public:
    EmpresaJaExiste(int i){id = i;}
};




#endif //PROJECT1_EMPRESAS_H
