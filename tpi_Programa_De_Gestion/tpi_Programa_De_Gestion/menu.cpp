#include <iostream>
#include "menu.h"
#include "funciones.h"
#include "marcas.h"
using namespace std;

int vecMarcas[10];
string vecNombresMarcas[10];

void mostrarMenu() {
    cout << "MENU PRINCIPAL" << endl;
    cout << "1. Cargar lote de marcas" << endl;
    cout << "2. Cargar lote de productos" << endl;
    cout << "3. Cargar lote de formas de pago" << endl;
    cout << "4. Cargar lote de ventas" << endl;
    cout << "5. Mostrar reportes" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

bool procesarMenu() {
    int opcion;
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Cargar marcas, solo numeros del 1 al 10\n";
            cargarMarcas(vecMarcas,10);
            cout << "Los nombres de las marcas\n";
            cargarNombres(vecNombresMarcas,10);
            break;
        case 2:
            cout << "\Funcion: Cargar productos\n";
            volverAlMenuPrincipal();
            break;
        case 3:
            cout << "\Funcion: Cargar formas de pago\n";
            volverAlMenuPrincipal();
            break;
        case 4:
            cout << "\Funcion: Cargar ventas\n";
            volverAlMenuPrincipal();
            break;
        case 5:
            cout << "\Funcion: Mostrar reportes\n";
            volverAlMenuPrincipal();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            return true;
        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
            volverAlMenuPrincipal();
    }

    return false;
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

