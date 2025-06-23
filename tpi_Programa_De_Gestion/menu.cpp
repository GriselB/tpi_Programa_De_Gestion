#include <iostream>
#include "menu.h"
#include "funciones.h"
#include "cargaDatos.h"
#include "structs.h"

using namespace std;

int opcion;

MedioPago mp[5]; // No es mercado pago :P
Marca m[10];
Producto p[20]; // Reemplazamos los vectores structs que contiene las propiedades en structs.h
recaudacionProducto recaudacionProducto[20];


void mostrarMenu() {
    cout << "-- MENU PRINCIPAL --" << endl;
    cout << endl;
    cout << "1. Cargar lote de marcas" << endl;
    cout << "2. Cargar lote de productos" << endl;
    cout << "3. Cargar lote de formas de pago" << endl;
    cout << "4. Cargar lote de ventas" << endl;
    cout << "5. Mostrar reportes" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

bool procesarMenu() {
    cin >> opcion;
    while(opcion != 1 &&
          opcion != 2 &&
          opcion != 3 &&
          opcion != 4 &&
          opcion != 5 &&
          opcion != 0 )
    {
        system("cls");
        mostrarMenu();
        cin >> opcion;
    }
    system("cls");
    switch (opcion) {
        case 1:
            cout << "Cargar marcas, solo numeros del 1 al 10\n";
            cargarMarcas(m);
            cout << "Los nombres de las marcas\n";
            cargarNombres(m);
            system("cls");
            break;
        case 2:
            cout << "\Funcion: Cargar Productos\n";
                if (!verificarMarcas(m)) {
                    cout << "No existen marcas registradas, por favor vuelva al menu a cargarlas." << endl;
                    volverAlMenuPrincipal();
                }
            cargarProductos(p, m, recaudacionProducto);
            system("cls");
            break;
        case 3:
            cout << "\Funcion: Cargar formas de pago\n";
            cargarFormasPago(mp);
            system("cls");
            break;
        case 4:
            cout << "\Funcion: Cargar ventas\n";
            volverAlMenuPrincipal();
            system("cls");
            break;
        case 5:
            cout << "\Funcion: Mostrar reportes\n";
            volverAlMenuPrincipal();
            system("cls");
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            return true;
        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
            volverAlMenuPrincipal();
            system("cls");
    }

    return false;
}


