#include <iostream>
#include "cargaDatos.h"
#include "funciones.h"
#include "structs.h"

using namespace std;

void cargarMarcas(Marca marcas[10]) {
int i;
    for (i=0; i<10; i++) {
        cin >> marcas[i].codMarca;
        while (marcas[i].codMarca > 10 || marcas[i].codMarca == 0) {
        cout << "No se puede ingresar numeros mayores a 10 o 0"<<endl;
        cin >> marcas[i].codMarca;
        }}
    }

void cargarProductos(Producto productos[20], Marca marcas[10], recaudacionProducto recaudacionProducto[20]){
    int i;

    for (int i=0; i<20; i++) {
        cout<<"ingresar codigo de 3 digitos del producto \n";
        cin >> productos[i].codProducto;
        recaudacionProducto[i].codProducto = productos[i].codProducto;

        cout<<"ingresar nombre del producto\n";
        cin >> productos[i].nombreProducto;
        recaudacionProducto[i].nombreProducto = productos[i].nombreProducto;

        cout<<"ingresar precio de venta del producto\n";
        cin >> productos[i].precioVenta;

        // Si agregamos letras al precio venta entra en loop, hay que ver como lo solucionamos

        cout<<"ingresar precio de compra del producto\n";
        cin >> productos[i].precioCompra;

        cout<<"ingresar stock disponible\n";
        cin >> productos[i].stockDisp;
        recaudacionProducto[i].stockRemanante = productos[i].stockDisp;

        cout<<"ingresar codigo de marca del producto\n";

        buscarMarcas(marcas);

        }
    }


void cargarFormasPago(MedioPago mp[5])
{
    int i;
    double porcentaje;
    string codMedioPago, esCorrecto;

        cout << "Ingrese los codigos del medio de pago: " << endl;
            cout << "EF: Efectivo"<< endl;
            cout << "MP: Mercado Pago" << endl;
            cout << "TR: Transferencia" << endl;
            cout << "TC: Tarjeta de credito" << endl;
            cout << "CT: Criptomoneda" << endl;

        for (i=0; i < 5; i++){
        cout << "Selecciona: ";
        cin >> mp[i].codMedioPago;

        while (mp[i].codMedioPago != "EF"
            && mp[i].codMedioPago != "MP"
            && mp[i].codMedioPago != "TR"
            && mp[i].codMedioPago != "TC"
            && mp[i].codMedioPago != "CT")
        {
            cout << "Código invalido. Intente de nuevo.\n";
            cin >> mp[i].codMedioPago;
        }
            if (mp[i].codMedioPago == "EF") {
                    mp[i].nombreFormaPago = "Efectivo";
                } else if (mp[i].codMedioPago == "MP") {
                    mp[i].nombreFormaPago = "Mercado Pago";
                } else if (mp[i].codMedioPago == "TR") {
                    mp[i].nombreFormaPago = "Transferencia";
                } else if (mp[i].codMedioPago == "TC") {
                    mp[i].nombreFormaPago = "Tarjeta de credito";
                } else if (mp[i].codMedioPago == "CT") {
                    mp[i].nombreFormaPago = "Criptomoneda";
                }

        cout << "Ingrese el descuento o interes para: " << mp[i].nombreFormaPago << endl;
        cin >> mp[i].porcDescuentoInteres;
}
        system("cls");

        for (i = 0; i < 10; i++) {
        cout << "Para el medio: " << mp[i].nombreFormaPago << " se selecciono el medio: " << mp[i].porcDescuentoInteres << endl;
        };
}

void cargarVentas(Producto productos[20], Marca marcas[10], MedioPago mp[5], recaudacionProducto[20])
{
    int i = 0;
    int diaVenta;
    int nroCompra;
    string formaPago;
    int codigoProducto;
    int cantidadVendida;
    int codigoCliente;

    cout << "Ingrese dia de la semana" << endl;
    cin >> diaVenta;

    while (diaVenta < 1 || diaVenta > 30)
    {
        cout << "Dia invalido, ingrese un dia del 1 al 30" << endl;
        cin >> diaVenta;
    }



        for (i=0; i<7; i++)
        {
        cout << "Ingrese nro de compra" << endl;
        cin >> nroCompra;

        cout << "Ingrese codigo de producto" << endl;
        cin >> codigoProducto;

            while (!buscarProducto(productos, codigoProducto))
            {
                cout << "El codigo de producto no existe, intente nuevamente" << endl;
                cin >> codigoProducto;
            }

        cout << "Ingrese forma de pago" << endl;
        cin >> formaPago;

        cout << "Ingrese cantidad vendida" << endl;
        cin >> cantidadVendida;

            if (codigoProducto == recaudacionProducto.codProducto)
            {
                while (recaudacionProducto.cantidadVendida > productos.stockDisp)
                {
                    cout << "No hay suficiente stock disponible, ingrese nuevamente" << endl;
                    cin >> cantidadVendida;
                }

                recaudacionProducto.cantidadVendida = recaudacionProducto.cantidadVendida + cantidadVendida;
                recaudacionProducto.stockRemanante = recaudacionProducto.stockRemanante - cantidadVendida;
                recaudacionProducto.totalRecaudado = recaudacionProducto.totalRecaudado + (cantidadVendida * productos.precioVenta);

            }

        cout << "Ingrese el codigo del cliente" << endl;
        cin >> codigoCliente;
        }

}



