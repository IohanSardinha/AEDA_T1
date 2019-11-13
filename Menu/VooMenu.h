#ifndef PROJECT1_VOOMENU_H
#define PROJECT1_VOOMENU_H

#include "Menu.h"

class VooMenu:public Menu{
    Aviao* a;
public:
    VooMenu();
    void visualizarVoo();
    Voo* escolherVoo();
    void alterarData();
    Hora alterarHora();
    void alterarHoraPrevista();
    void alterarHoraReal();
    void alterarDestino();
    void alterarEstado();
    void criarVoo();
    void CallMenu();
    void escolherAviao(); //como vou escolher aviao???
    void setAeroporto(Aeroporto* a){};
};

#endif //PROJECT1_VOOMENU_H
