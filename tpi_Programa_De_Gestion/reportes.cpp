#include <iostream>
#include "structs.h"
using namespace std;

// Ordenamos el reporte de mayor a menor y lo mostramos
void reporteRecaudacionPorProducto(RecaudacionProducto recaudacionProducto[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (recaudacionProducto[i].cantidadVendida < recaudacionProducto[j].cantidadVendida) {
                RecaudacionProducto aux = recaudacionProducto[i];
                recaudacionProducto[i] = recaudacionProducto[j];
                recaudacionProducto[j] = aux;
            }
        }
    }

    cout << "\n=== Reporte 1: Recaudacion por producto (ordenado por cantidad vendida) ===" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "Producto: " << recaudacionProducto[i].nombreProducto << endl;
        cout << "  Código: " << recaudacionProducto[i].codProducto << endl;
        cout << "  Total recaudado: $" << recaudacionProducto[i].totalRecaudado << endl;
        cout << "  Cantidad vendida: " << recaudacionProducto[i].cantidadVendida << endl;
        cout << "  Stock remanente: " << recaudacionProducto[i].stockRemanente << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
}
