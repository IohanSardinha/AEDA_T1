#ifndef PROJECT1_HORA_H
#define PROJECT1_HORA_H

#include <iostream>

using namespace std;

class Hora{
    int hora,
            minuto,
            segundo;
public:
    Hora()
    {
        hora = 0;
        minuto = 0;
        segundo = 0;
    }
    Hora(int h, int m, int s)
    {
        if(h > 24 || h < 0)
        {
            throw runtime_error("Hour must be between 0 and 24");
        }
        if(m > 59 || m < 0)
        {
            throw runtime_error("Minutes must be between 0 and 59");
        }
        if(s > 59 || s < 0)
        {
            throw runtime_error("Seconds must be between 0 and 59");
        }

    }
    int getHora() const {
        return hora;
    }

    void setHora(int hora) {
        Hora::hora = hora;
    }

    int getMinuto() const {
        return minuto;
    }

    void setMinuto(int minuto) {
        Hora::minuto = minuto;
    }

    int getSegundo() const {
        return segundo;
    }

    void setSegundo(int segundo) {
        Hora::segundo = segundo;
    }

    friend ostream& operator<<(ostream& os, const Hora& hr)
    {
        os << hr.hora << ":" << hr.minuto << ":" << hr.segundo;
        return os;
    }
};

#endif //PROJECT1_HORA_H
