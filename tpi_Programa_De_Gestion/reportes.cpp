#include <iostream>
#include <cstdlib>    // para rand
#include <ctime>      // para time
#include "structs.h"
#include "funciones.h"
using namespace std;

// Ordenamos el reporte de mayor a menor y lo mostramos
void reporteRecaudacionPorProducto(RecaudacionProducto recaudacionProducto[], int cantidad) {
    for (int i = 0; i<cantidad - 1; i++) {
        for (int j = i + 1; j<cantidad; j++) {
            if (recaudacionProducto[i].cantidadVendida < recaudacionProducto[j].cantidadVendida) {
                RecaudacionProducto aux = recaudacionProducto[i];
                recaudacionProducto[i] = recaudacionProducto[j];
                recaudacionProducto[j] = aux;
            }
        }
    }

    cout << "\n=== Reporte 1: Recaudacion por producto (ordenado por cantidad vendida) ===" << endl;

    for (int i = 0; i<cantidad; i++) {
        cout << " Producto: " << recaudacionProducto[i].nombreProducto << endl;
        cout << "  Código: " << recaudacionProducto[i].codProducto << endl;
        cout << "  Total recaudado: $" << recaudacionProducto[i].totalRecaudado << endl;
        cout << "  Cantidad vendida: " << recaudacionProducto[i].cantidadVendida << endl;
        cout << "  Stock remanente: " << recaudacionProducto[i].stockRemanente << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}

void productosSinVentas(RecaudacionProducto recaudacionProducto[], Producto productos[])
{
    cout << "\n=== Los productos que no registraron ventas son ===" << endl;
    int productosConVenta = contarProductosConVentas(recaudacionProducto);

    for (int i = 0; i < 20; i++) {
        if (productos[i].codProducto == 0) continue;
        bool sinVentas = true;

        for (int j = 0; j < productosConVenta; j++) {
            if (productos[i].codProducto == recaudacionProducto[j].codProducto) {
                sinVentas = false;
                break;
            }
        }

        if (sinVentas) {
            cout << "  Producto: " << productos[i].nombreProducto
                 << " | Codigo: " << productos[i].codProducto << endl;
        }
    }
}
void ordenarClientesPorCompras(ClienteInfo clientes[], int cantidad) {
    for (int i=0; i<cantidad - 1; i++) {
        for (int j=0; j<cantidad - i - 1; j++) {
            if (clientes[j].cantidadCompras < clientes[j + 1].cantidadCompras) {
                ClienteInfo temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }
}

void mostrarTop10Clientes(int contClientes[]) {
    ClienteInfo clientes[50];


    for (int i=0; i<50; i++) {
        clientes[i].codigoCliente = i + 1;
        clientes[i].cantidadCompras = contClientes[i];
    }

    ordenarClientesPorCompras(clientes, 50);

    cout << "\n=== TOP 10 CLIENTES CON MAS COMPRAS ===";
    for (int i=0; i<10; i++) {
        cout << "Cliente #" << clientes[i].codigoCliente
             << " - Compras: " << clientes[i].cantidadCompras << endl;
    }

    // Sorteo aleatorio de 3 ganadores entre el Top 10
    srand(time(0));
    int ganadores[3];
    int cantidadGanadores = 0;

    while (cantidadGanadores<3) {
        int indice = rand() % 10;
        bool repetido = false;

        for (int j = 0; j < cantidadGanadores; j++) {
            if (ganadores[j] == indice) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            ganadores[cantidadGanadores] = indice;
            cantidadGanadores++;
        }
    }

    cout << "\n=== CLIENTES GANADORES DEL CUPON DE DESCUENTO ===";
    for (int i=0; i<3; i++) {
        int indiceGanador = ganadores[i];
        cout << "Cliente #" << clientes[indiceGanador].codigoCliente
             << " - Compras: " << clientes[indiceGanador].cantidadCompras << endl;
    }
}
