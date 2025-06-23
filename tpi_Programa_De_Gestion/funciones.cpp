#include <iostream>
#include "funciones.h"
#include "structs.h"

using namespace std;

void cargarNombres(Marca marcas[]) {
    int i;
    for (i=0; i<10; i++) {
       cin >> marcas[i].nombreMarca;
}
}

void volverAlMenuPrincipal() {
    int volver = -1;
    while (volver != 0) {
        cout << "\nPresione 0 para volver al menu principal: " << endl;
        cin >> volver;
        if (volver != 0) {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }
}

void buscarMarcas(Marca marcas[]) {
    for (int i = 0; i < 10; i++) {
        cout << marcas[i].codMarca << " - " << marcas[i].nombreMarca << endl;
    }
}

bool verificarMarcas(Marca marcas[]) {
    int i;

    for (i = 0; i < 10; i++) {
        if (marcas[i].codMarca != 0) {
            return true;
            break;
        }
    }
        return false;
}

bool buscarProducto(Producto productos[20], int codigoProducto)
{
    int i;

    for(i=0; 1 < 20; i++){
        if (productos[i].codProducto == codigoProducto){
            return true;
            break;
        }
    }
    return false;
}
