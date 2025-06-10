#include <iostream>
#include "funciones.h"

using namespace std;

void cargarNombres(string nombre[], int tamanio) {
    int i;
    for (i=0; i<tamanio; i++) {
       cin >> nombre[i];
}
}

void volverAlMenuPrincipal() {
    int volver = -1;
    while (volver != 0) {
        cout << "\nPresione 0 para volver al menu principal: ";
        cin >> volver;
        if (volver != 0) {
            cout << "Opcion invalida. Intente nuevamente.";
        }
    }
}
