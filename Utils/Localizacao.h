#ifndef PROJECT1_LOCALIZACAO_H
#define PROJECT1_LOCALIZACAO_H

#include <iostream>
#include <string>
#include "split.h"
#include "GPS.h"

class Localizacao{
    string pais;
    string cidade;
    GPS cordenadas;
public:
    Localizacao()= default;

    Localizacao(string pais, string cidade, GPS coord)
    {
        cordenadas = coord;
        this->pais = pais;
        this->cidade = cidade;
    }

    const string &getPais() const {
        return pais;
    }

    void setPais(const string &pais) {
        Localizacao::pais = pais;
    }

    const string &getCidade() const {
        return cidade;
    }

    void setCidade(const string &cidade) {
        Localizacao::cidade = cidade;
    }

    const GPS &getCordenadas() const {
        return cordenadas;
    }

    void setCordenadas(const GPS &cordenadas) {
        Localizacao::cordenadas = cordenadas;
    }

    friend ostream& operator<<(ostream& os, const Localizacao& l)
    {
        os << l.cidade << ", " << l.pais << " " <<  l.cordenadas;
        return os;
    }

};

#endif //PROJECT1_LOCALIZACAO_H
