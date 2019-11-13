#ifndef PROJECT1_DATA_H
#define PROJECT1_DATA_H

#include <iostream>

using namespace std;

class Data{
    int dia,
            mes,
            ano;
public:
    Data()
    {
        dia = 1;
        mes = 1;
        ano = 1970;
    }

    Data(int d, int m, int a)
    {
        if(d > 31 || d < 1)
        {
            throw runtime_error("Day must be between 1 and 31");
        }
        if(m > 12 || d < 1)
        {
            throw runtime_error("Month must be between 1 and 12");
        }
        dia = d;
        mes = m;
        ano = a;
    }

    int getDia() const {
        return dia;
    }

    void setDia(int dia) {
        if(dia > 31)
        {
            throw runtime_error("Day must be between 1 and 31");
        }
        Data::dia = dia;
    }

    int getMes() const {
        return mes;
    }

    void setMes(int mes) {
        if(mes > 12)
        {
            throw runtime_error("Month must be between 1 and 12");
        }
        Data::mes = mes;
    }

    int getAno() const {
        return ano;
    }

    void setAno(int ano) {
        Data::ano = ano;
    }

    friend ostream& operator<<(ostream& os, const Data& dt)
    {
        os << dt.dia << "/" << dt.mes << "/" << dt.ano;
        return os;
    }
};

#endif //PROJECT1_DATA_H
