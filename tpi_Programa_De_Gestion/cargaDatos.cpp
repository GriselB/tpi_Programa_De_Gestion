#include <iostream>
#include "cargaDatos.h"
#include "funciones.h"
#include "structs.h"
using namespace std;

void cargarMarcas(Marca marcas[10]) {
int i;
int cod;
bool repetido;

    while (i < 10) {

        cin >> cod;

        while (cod < 0 || cod > 10) {
            cout << "---------------------------------------------" << endl;
            cout << "ERROR: No se puede ingresar numeros mayores a 10 o 0. Intente otro: \n" << endl;
            cin >> cod;
            cout << "---------------------------------------------" << endl;
        }

        repetido = false;

        for (int j = 0; j < i; j++) {
            if (marcas[j].codMarca == cod) {
                repetido = true;
                break;
            }
        }

        if (repetido) {
            cout << "---------------------------------------------" << endl;
            cout << "ERROR: El codigo de marca ya fue ingresado. Intente otro: \n";
            cout << "---------------------------------------------" << endl;
        } else {
            marcas[i].codMarca = cod;
            i++;
        }
    }
}

void cargarProductos(Producto productos[2], Marca marcas[10]){
    int i;

    for (int i=0; i<2; i++) {
        cout<<"ingresar codigo de 3 digitos del producto \n";
        cin >> productos[i].codProducto;
        while (productos[i].codProducto < 1 || productos[i].codProducto > 999)
        {
            cout << "---------------------------------------------" << endl;
            cout<<"ERROR: Solo se aceptan numeros del 1 al 999. Intente otro.\n";
            cin >> productos[i].codProducto;
            cout << "---------------------------------------------" << endl;
        }

        cout<<"ingresar nombre del producto\n";
        cin >> productos[i].nombreProducto;

        // Si agregamos letras al precio venta entra en loop, hay que ver como lo solucionamos o no ingresemos mal los datos :P

        cout<<"ingresar precio de venta del producto\n";
        cin >> productos[i].precioVenta;

        cout<<"ingresar precio de compra del producto\n";
        cin >> productos[i].precioCompra;

        cout<<"ingresar stock disponible\n";
        cin >> productos[i].stockDisp;

        cout<<"ingresar el numero de marca del producto\n";

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
            cout << "Seleccione medio de pago: ";
            cin >> mp[i].codMedioPago;

            while (!esCodigoValido(mp[i].codMedioPago)) {
            cout << "---------------------------------------------" << endl;
            cout << "ERROR: Codigo invalido. Intente de nuevo: \n";
            cin >> mp[i].codMedioPago;
            cout << "---------------------------------------------" << endl;
            }

            bool repetido = medioDePagoRepetido(mp, i, mp[i].codMedioPago);

            while (repetido) {
                cout << "---------------------------------------------" << endl;
                cout << "ERROR: El codigo ya fue ingresado. Intente de nuevo: \n ";
                cin >> mp[i].codMedioPago;
                cout << "---------------------------------------------" << endl;

                while (!esCodigoValido(mp[i].codMedioPago)) {
                    cout << "---------------------------------------------" << endl;
                    cout << "ERROR: Codigo invalido. Intente de nuevo.\n";
                    cin >> mp[i].codMedioPago;
                    cout << "---------------------------------------------" << endl;
                }

                repetido = medioDePagoRepetido(mp, i, mp[i].codMedioPago);
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

            cout << "Ingrese el descuento o interes (Negativo para descuento, positivo para interes)" << endl;
            cin >> descuentoInteres;

            while (descuentoInteres < -100){
                cout << "---------------------------------------------" << endl;
                cout << "ERROR: El descuento no puede exceder el 100% Intente de nuevo.\n" << endl;
                cin >> descuentoInteres;
                cout << "---------------------------------------------" << endl;
            }

            if (descuentoInteres < 0) {
                mp[i].descuento = -descuentoInteres;
                mp[i].interes = 0;
            } else {
                mp[i].descuento = 0;
                mp[i].interes = descuentoInteres;
            }
        }
        for (i = 0; i < 5; i++) {
            if (mp[i].descuento != 0)
                cout << "Para el medio: " << mp[i].nombreFormaPago << " se selecciono el medio: " << mp[i].descuento << endl;
            else{
                cout << "Para el medio: " << mp[i].nombreFormaPago << " se selecciono el medio: " << mp[i].interes << endl;
            }
        }
}

void cargarLoteVentas(Producto productos[20], Marca marcas[10], MedioPago mp[5], RecaudacionProducto recaudacionProducto[20], int& productosVendidos, int contClientes[])
{
    int diasVentas[7];
    int nroCompra;
    string medioPago;
    int codigoProducto;
    int cantidadVendida;
    int codigoCliente;
    int cantidadVentas;

    // Primero cargamos los dias de las ventas
    cargarDiasDeVenta(diasVentas);

    // si no los cargo bien, vuelve a hacerlo
    while (!validarDiasConsecutivos(diasVentas)) {
        cout << "---------------------------------------------" << endl;
        cout << "ERROR: Los dias ingresados no pertenecen a la misma semana. Intente de nuevo: \n";
        cout << "---------------------------------------------" << endl;
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
                    cout << "---------------------------------------------" << endl;
                    cout << "ERROR: El codigo de producto no existe. Intente de nuevo.\n" << endl;
                    cin >> codigoProducto;
                    cout << "---------------------------------------------" << endl;
                    indiceProducto = buscarProductoPorCodigoProducto(productos, codigoProducto);
                }

            cout << "Ingrese forma de pago" << endl;
            cin >> medioPago;

            int indiceMP = buscarIndiceMedioPago(mp, 5, medioPago);

            while (indiceMP == -1)
                {
                    cout << "---------------------------------------------" << endl;
                    cout << "ERROR: El medio de pago no existe. Intente de nuevo.\n" << endl;
                    cin >> medioPago;
                    cout << "---------------------------------------------" << endl;
                    indiceMP =  buscarIndiceMedioPago(mp, 5, medioPago);
                }

            cout << "Ingrese cantidad vendida" << endl;
            cin >> cantidadVendida;

            while (cantidadVendida > productos[indiceProducto].stockDisp) {
                cout << "---------------------------------------------" << endl;
                cout << "ERROR: No hay suficiente stock. Intente de nuevo: \n ";
                cin >> cantidadVendida;
                cout << "---------------------------------------------" << endl;
            }

            float totalVenta = cantidadVendida * productos[indiceProducto].precioVenta;

            // Agregamos descuento o interes segun el medio de pago que eligio
            if (mp[indiceMP].descuento > 0) {
                totalVenta *= (1 - mp[indiceMP].descuento / 100.0);
            } else if (mp[indiceMP].interes > 0) {
                totalVenta *= (1 + mp[indiceMP].interes / 100.0);
            }

            cout << "Ingrese codigo de cliente" << endl;
            cin >> codigoCliente;

            while (codigoCliente < 1 || codigoCliente > 50) { //aca agregue para que el usuario ingrese un codigo de cliente entre el 1 y el 50 como dicta el enunciado
                cout << "---------------------------------------------" << endl;
                cout << "ERROR: Codigo invalido. Ingrese un codigo entre 1 y 50. Intente de nuevo: \n ";
                cin >> codigoCliente;
                cout << "---------------------------------------------" << endl;
            }

            // Aumentar el contador del cliente correspondiente
            contClientes[codigoCliente - 1]++;


            int indiceRecaudacion = buscarIndiceRecaudacionProducto(recaudacionProducto, codigoProducto, productosVendidos);

            //Si no existe, lo agregamos
            if (indiceRecaudacion == -1) {
                recaudacionProducto[productosVendidos].codProducto = codigoProducto;
                recaudacionProducto[productosVendidos].nombreProducto = productos[indiceProducto].nombreProducto;
                recaudacionProducto[productosVendidos].cantidadVendida = cantidadVendida;
                recaudacionProducto[productosVendidos].totalRecaudado = totalVenta;
                productos[indiceProducto].stockDisp -= cantidadVendida;
                recaudacionProducto[productosVendidos].stockRemanente = productos[indiceProducto].stockDisp;
                productosVendidos++;
            // si existe lo modificamos
            } else {
                recaudacionProducto[indiceRecaudacion].cantidadVendida += cantidadVendida;
                recaudacionProducto[indiceRecaudacion].totalRecaudado += totalVenta;
                productos[indiceProducto].stockDisp -= cantidadVendida;
                recaudacionProducto[indiceRecaudacion].stockRemanente = productos[indiceProducto].stockDisp;

            }
        cout << "---------------------------------------------" << endl;
        }
    }
  }

