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

void cargarProductos(Producto productos[2], Marca marcas[10]){
    int i;

    for (int i=0; i<2; i++) {
        cout<<"ingresar codigo de 3 digitos del producto \n";
        cin >> productos[i].codProducto;

        cout<<"ingresar nombre del producto\n";
        cin >> productos[i].nombreProducto;

        // Si agregamos letras al precio venta entra en loop, hay que ver como lo solucionamos o no ingresemos mal los datos :P

        cout<<"ingresar precio de venta del producto\n";
        cin >> productos[i].precioVenta;

        cout<<"ingresar precio de compra del producto\n";
        cin >> productos[i].precioCompra;

        cout<<"ingresar stock disponible\n";
        cin >> productos[i].stockDisp;

        cout<<"ingresar codigo de marca del producto\n";

        buscarMarcas(marcas);
        cin >> productos[i].codMarca.codMarca;

        }
    }

void cargarFormasPago(MedioPago mp[5])
{
    int i;
    double porcentaje;
    string codMedioPago, esCorrecto;
    int descuentoInteres;

    // Falta la validacion de que no se repitan los medios de pago
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
            cout << "Codigo invalido. Intente de nuevo.\n";
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

                // falta diferenciar si es interes o descuento (si ingresa -10 es descuento, si ingresa 10 es interes)
        cout << "Ingrese el descuento o interes para: " << mp[i].nombreFormaPago << endl;
        cin >> descuentoInteres;

        if (descuentoInteres > 0){
            mp[i].descuento = descuentoInteres;
            mp[i].interes = 0;
        }
        else{
            mp[i].descuento = 0;
            mp[i].interes = descuentoInteres;
        }
}
        system("cls");

        for (i = 0; i < 10; i++) {
        if (mp[i].descuento != 0)
        cout << "Para el medio: " << mp[i].nombreFormaPago << " se selecciono el medio: " << mp[i].descuento << endl;
        else{
        cout << "Para el medio: " << mp[i].nombreFormaPago << " se selecciono el medio: " << mp[i].interes << endl;
        }
        };
}

void cargarLoteVentas(Producto productos[20], Marca marcas[10], MedioPago mp[5], RecaudacionProducto recaudacionProducto[20])
{
    int diasVentas[7];
    int nroCompra;
    string medioPago;
    int codigoProducto;
    int cantidadVendida;
    int codigoCliente;
    int cantidadVentas;
    int productosCargados = 0;

    // Primero cargamos los dias de las ventas
    cargarDiasDeVenta(diasVentas);

    // si no los cargo bien, vuelve a hacerlo
    while (!validarDiasConsecutivos(diasVentas)) {
        cout << "Los dias ingresados no pertenecen a la misma semana. Intente nuevamente.";
        cargarDiasDeVenta(diasVentas);
    }

    for(int i=0; i<7; i++)
    {
        int dia = diasVentas[i];
        cout << "Cargar ventas para el dia " << dia << endl;

        while(true){

        cout << "Ingrese nro de compra (0 para finalizar este dia): ";
        cin >> nroCompra;

        if (nroCompra == 0) break;

        cout << "Ingrese codigo de producto" << endl;
            cin >> codigoProducto;

            int indiceProducto = buscarProductoPorCodigoProducto(productos, codigoProducto);
                while (indiceProducto == -1)
                {
                    cout << "El codigo de producto no existe, intente nuevamente" << endl;
                    cin >> codigoProducto;
                    indiceProducto = buscarProductoPorCodigoProducto(productos, codigoProducto);
                }

            cout << "Ingrese forma de pago" << endl;
            cin >> medioPago;

            int indiceMP = buscarIndiceMedioPago(mp, 5, medioPago);

            while (indiceMP == -1)
                {
                    cout << "El medio de pago no existe, intente nuevamente" << endl;
                    cin >> medioPago;
                    indiceMP =  buscarIndiceMedioPago(mp, 5, medioPago);
                }

            cout << "Ingrese cantidad vendida" << endl;
            cin >> cantidadVendida;

            while (cantidadVendida > productos[indiceProducto].stockDisp) {
                cout << "No hay suficiente stock. Ingrese una cantidad valida: ";
                cin >> cantidadVendida;
            }

            float totalVenta = cantidadVendida * productos[indiceProducto].precioVenta;

            // Agregamos descuento o interes segun el medio de pago que eligio
            if (mp[indiceMP].descuento > 0) {
                    totalVenta *= (1 - mp[indiceMP].descuento / 100.0);
                } else if (mp[indiceMP].interes > 0) {
                    totalVenta *= (1 + mp[indiceMP].interes / 100.0);
                }

            cin >> codigoCliente;

            int indiceRecaudacion = buscarIndiceRecaudacionProducto(recaudacionProducto, codigoProducto, productosCargados);

            //Si no existe, lo agregamos
            if (indiceRecaudacion == -1) {
                recaudacionProducto[productosCargados].codProducto = codigoProducto;
                recaudacionProducto[productosCargados].nombreProducto = productos[indiceProducto].nombreProducto;
                recaudacionProducto[productosCargados].cantidadVendida = cantidadVendida;
                recaudacionProducto[productosCargados].totalRecaudado = cantidadVendida * productos[indiceProducto].precioVenta;
                productos[indiceProducto].stockDisp -= cantidadVendida;
                recaudacionProducto[productosCargados].stockRemanente = productos[indiceProducto].stockDisp;
                productosCargados++;
            // si existe lo modificamos
            } else {
                recaudacionProducto[indiceRecaudacion].cantidadVendida += cantidadVendida;
                recaudacionProducto[indiceRecaudacion].totalRecaudado += cantidadVendida * productos[indiceProducto].precioVenta;
                productos[indiceProducto].stockDisp -= cantidadVendida;
                recaudacionProducto[indiceRecaudacion].stockRemanente = productos[indiceProducto].stockDisp;

            }

            // 2) Porcentaje de ventas por forma de pago -> contador

            // 3) Contador de ventas por marca y forma de pago

            // 4) Productos sin venta sale de recaudacionProducto -> Primero hay que terminar recaudacion producto

            // 5) Contador de clientes, top 10, random 3 ganadores de descuento -> contador


        }



    }
  }

