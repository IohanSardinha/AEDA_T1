#include <iostream>
#include "utils.h"
#include "Funcionario.h"
#include "Menu.h"

using namespace std;

int main() {
    MainMenu main_menu;
    main_menu.print();
    main_menu.getInput();
    return 0;
}