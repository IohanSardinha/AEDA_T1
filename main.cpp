#include <iostream>
#include <vector>
#include "utils.h"
#include "Funcionario.h"
#include "Menu.h"
#include "Aeroporto.h"

using namespace std;

int main() {
    Piloto p(300,"Sergio",Data(30,06,199),"Classe A",{},{});
    Aeroporto a(&p,Localizacao("Brasil","Rio de Janeiro",GPS(10,10)),{&p},{},{&p},{},{});
    p.print();
    cout << endl << endl << a;
    return 0;
}