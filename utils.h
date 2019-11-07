#ifndef PROJECT1_UTILS_H
#define PROJECT1_UTILS_H

#include <iostream>

using namespace std;

class GPS{
    float latitude,
          longitude;
};

class Data{
    int dia,
        mes,
        ano;
};

class Hora{
    int hora,
        minuto,
        segundo;
};

class Localizacao{
    string pais;
    string cidade;
    GPS cordenadas;
};

#endif //PROJECT1_UTILS_H
