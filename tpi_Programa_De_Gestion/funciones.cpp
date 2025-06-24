#include <iostream>
#include "funciones.h"
#include "structs.h"

using namespace std;

void cargarNombres(Marca marcas[])
{
    int i;
    for (i=0; i<10; i++)
    {
        cin >> marcas[i].nombreMarca;
    }
}

void volverAlMenuPrincipal()
{
    int volver = -1;
    while (volver != 0)
    {
        cout << "\nPresione 0 para volver al menu principal: " << endl;
        cin >> volver;
        if (volver != 0)
        {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }
}

void buscarMarcas(Marca marcas[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << marcas[i].codMarca << " - " << marcas[i].nombreMarca << endl;
    }
}

bool verificarMarcas(Marca marcas[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (marcas[i].codMarca != 0)
        {
            return true;
            break;
        }
    }
    return false;
}

bool esCodigoValido(string codigo) {
    return (
        codigo == "EF" || codigo == "ef" ||
        codigo == "MP" || codigo == "mp" ||
        codigo == "TR" || codigo == "tr" ||
        codigo == "TC" || codigo == "tc" ||
        codigo == "CT" || codigo == "ct"
    );
}

bool medioDePagoRepetido(MedioPago mp[], int cantidad, string codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (mp[i].codMedioPago == codigo) {
            return true;
        }
    }
    return false;
}


int buscarProductoPorCodigoProducto(Producto productos[], int codProducto) {
// buscamos la posicion en la que se encuentra el producto
    for (int i = 0; i < 20; i++) {
        if (productos[i].codProducto == codProducto) {
            return i;
        }
    }
    return -1; // si no lo encuentra devuelve -1
}

void cargarDiasDeVenta(int diasVentas[7]) {
    int dia;
    for (int i = 0; i < 7; i++) {
        cout << "Ingrese el numero del dia de la semana (1 al 30): ";
        cin >> dia;
        while (dia < 1 || dia > 30) {
            cout << "Dia invalido, ingrese un dia del 1 al 30: ";
            cin >> dia;
        }
        diasVentas[i] = dia;
    }
}

// Buscamos el minimo en este caso para saber que los proximos dias se encuentren en la misma semana y sea correlativo (por ejemplo, si pongo dia 1, no puedo poner dia 30)
int obtenerMinimo(int dias[7]) {
    int minimo = dias[0];
    for (int i = 1; i < 7; i++) {
        if (dias[i] < minimo)
            minimo = dias[i];
    }
    return minimo;
}

// Nos fijamos que sean dias consecutivos
bool validarDiasConsecutivos(int dias[7]) {
    int minDia = obtenerMinimo(dias);
    for (int i = 0; i < 7; i++) {
        if (dias[i] < minDia || dias[i] > minDia + 6)
            return false;
    }
    return true;
}

// Buscamos si ya existe el producto en el struct
int buscarIndiceRecaudacionProducto(RecaudacionProducto recaudacionProducto[], int codProducto, int cantidadActual) {
    for (int i = 0; i < cantidadActual; i++) {
        if (recaudacionProducto[i].codProducto == codProducto) {
            return i;
        }
    }
    return -1;
}

// Para saber cuanto interes o descuento tiene el cliente
int buscarIndiceMedioPago(MedioPago mp[], int cantidadMedios, string codigo) {
    for (int i = 0; i < cantidadMedios; i++) {
        if (mp[i].codMedioPago == codigo) {
            return i;
        }
    }
    return -1;
}
