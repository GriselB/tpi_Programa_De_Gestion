#include <iostream>
#include "menu.h"
using namespace std;

int main() {
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        salir = procesarMenu();
    }

    return 0;
}
