#include <iostream>
#include "menu.h"
#include "funciones.h"
#include "cargaDatos.h"
#include "structs.h"
#include "reportes.h"
using namespace std;

int opcion;
int productosVendidos = 0;
int cantidadRecaudacion = 0;
int contClientes[50];
int totalVentasMarcaFormaPago = 0;

string formaPago;
MedioPago mp[5]; // No es mercado pago :P
PorcentajeMedioPago porcentajesMP[5];
VentasMarcaFormaPago ventasMarcaFormaPago[50];
Marca m[10];
Producto p[20];
RecaudacionProducto rP[20];

void mostrarMenu()
{
    cout << "\n===  MENU PRINCIPAL ===" << endl;
    cout << endl;
    cout << "1. Cargar lote de marcas" << endl;
    cout << "2. Cargar lote de productos" << endl;
    cout << "3. Cargar lote de formas de pago" << endl;
    cout << "4. Cargar lote de ventas" << endl;
    cout << "5. Mostrar reportes" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

bool procesarMenu()
{
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
    switch (opcion)
    {
    case 1:
        cout << "Cargar marcas, solo numeros del 1 al 10\n";
        cargarMarcas(m);
        cargarNombres(m);
        system("cls");
        break;
    case 2:
        cout << "\Cargar Productos\n";
        if (verificarMarcas(m))
        {
            cargarProductos(p, m);

        }
        else{
            cout << "No existen marcas registradas, por favor vuelva al menu a cargarlas." << endl;
            volverAlMenuPrincipal();
        }
        system("cls");
        break;
    case 3:
        cout << "Cargar formas de pago" << endl;
        cargarFormasPago(mp);
        system("cls");
        break;
    case 4:
        if (p[0].codProducto == 0 || m[0].nombreMarca == "" || mp[0].codMedioPago == "") {
            cout << "ERROR: Faltan datos. Asegurese de haber cargado productos, marcas y medios de pago." << endl;
            volverAlMenuPrincipal();
        }
        else {
        cargarLoteVentas(p, m, mp, rP, productosVendidos,contClientes, porcentajesMP, ventasMarcaFormaPago, totalVentasMarcaFormaPago);
        }
        system("cls");
        break;
    case 5:
        if (p[0].codProducto == 0 || m[0].nombreMarca == "" || mp[0].codMedioPago == "" || rP[0].codProducto == 0) {
            cout << "ERROR: Faltan datos. Asegurese de haber cargado productos, marcas y medios de pago ventas." << endl;
            volverAlMenuPrincipal();
        } else {
            mostrarMenuReportes(rP, productosVendidos);
        }
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



void mostrarMenuReportes(RecaudacionProducto recaudacionProducto[], int productosVendidos) {
    int opcion;

    cout << "\n========= MENU DE REPORTES =========" << endl;
    cout << "1. Recaudacion por producto" << endl;
    cout << "2. Porcentaje de ventas por forma de pago" << endl;
    cout << "3. Ventas por marca y forma de pago" << endl;
    cout << "4. Productos sin ventas" << endl;
    cout << "5. Top 10 clientes + Sorteo de cupones" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "Reporte 1: Recaudacion por producto\n";
        reporteRecaudacionPorProducto(recaudacionProducto, productosVendidos);
        volverAlMenuPrincipal();
        break;
    case 2:
        cout << "Reporte 2: Porcentaje de ventas por forma de pago\n";
        porcentajeVentasPorMedioPago(porcentajesMP);
        break;
    case 3:
        cout << "Reporte 3: Ventas por marca y forma de pago (pendiente)\n";
        mostrarVentasPorMarcaYFormaPago(ventasMarcaFormaPago, totalVentasMarcaFormaPago);
        break;
    case 4:
        cout << "Reporte 4: Productos sin ventas\n";
        productosSinVentas(rP, p);
        volverAlMenuPrincipal();
        break;
    case 5:
        cout << "Reporte 5: Top 10 clientes + Sorteo de cupones\n";
        mostrarTop10Clientes(contClientes);
        volverAlMenuPrincipal();
        break;
    case 0:
        cout << "Volviendo al menu principal..." << endl;
        return;
    default:
        cout << "Opcion invalida. Intente nuevamente." << endl;
        break;
    }

    volverAlMenuPrincipal();
    system("cls");
}


