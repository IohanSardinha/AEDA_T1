#ifndef PROJECT1_VOO_H
#define PROJECT1_VOO_H

#include "../Utils/split.h"
#include "../Utils/Hora.h"
#include "../Utils/Data.h"

class Informacao;

class Voo{
    Data data;
    Hora hora;
    string destino;
    Informacao* info;
public:
    Voo(Data D, Hora h, string d)
    {
        data = D;
        hora = h;
        destino = d;
    }

    const Data &getData() const {
        return data;
    }

    void setData(const Data &data) {
        Voo::data = data;
    }

    const Hora &getHora() const {
        return hora;
    }

    void setHora(const Hora &hora) {
        Voo::hora = hora;
    }

    const string &getDestino() const {
        return destino;
    }

    void setDestino(const string &destino) {
        Voo::destino = destino;
    }

    Informacao *getInfo() const {
        return info;
    }

    void setInfo(Informacao *info) {
        Voo::info = info;
    }

    friend ostream& operator<<(ostream& os, const Voo& v)
    {
        os << "Destino: " << v.destino << endl;
        os << "Dia: " << v.hora << endl;
        os << v.hora << "horas" << endl;
        return os;
    }
};

#endif //PROJECT1_VOO_H
