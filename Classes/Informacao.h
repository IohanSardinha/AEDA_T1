#ifndef PROJECT1_INFORMACAO_H
#define PROJECT1_INFORMACAO_H

#include "../Classes/Voo.h"

class Informacao{
    Voo* voo;
    Hora hora_prevista;
    Hora hora_real;
    bool cancelado;
public:
    Informacao(Voo* v, Hora hp, Hora hr, bool canc)
    {
        voo = v;
        hora_prevista = hp;
        hora_real = hr;
        cancelado = canc;
    }

    Voo* getVoo() const {
        return voo;
    }

    void setVoo(Voo *voo) {
        Informacao::voo = voo;
    }

    const Hora &getHoraPrevista() const {
        return hora_prevista;
    }

    void setHoraPrevista(const Hora &horaPrevista) {
        hora_prevista = horaPrevista;
    }

    const Hora &getHoraReal() const {
        return hora_real;
    }

    void setHoraReal(const Hora &horaReal) {
        hora_real = horaReal;
    }

    bool isCancelado() const {
        return cancelado;
    }

    void setCancelado(bool cancelado) {
        Informacao::cancelado = cancelado;
    }

    friend ostream& operator<<(ostream& os, const Informacao& i)
    {
        os << "Voo:" << endl;
        os << i.getVoo() << endl;
        os << "Horario previsto: " << i.getHoraPrevista() << endl;
        os << "Horario real: " << i.getHoraReal() << endl;
        os << (i.cancelado ? "Cancelado" : "A tempo") << endl;
        return os;
    }

};


#endif //PROJECT1_INFORMACAO_H
