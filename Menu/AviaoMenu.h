#ifndef PROJECT1_AVIAOMENU_H
#define PROJECT1_AVIAOMENU_H

#include "Menu.h"

class AviaoMenu:public Menu{
    Aeroporto* aeroporto;
public:
    Aviao* escolherAviao();
    AviaoMenu();
    void CallMenu();
    void criarAviao();
    void editarTipo();
    void editarCapacidade();
    Voo* criarVoo();
    Membro_tripulacao* criarMembroTripulacao(vector<Voo*> v);
    void setAeroporto(Aeroporto* a);
    void setAviao(Aviao* a){};
    void listarAvioes();
};

#endif //PROJECT1_AVIAOMENU_H
