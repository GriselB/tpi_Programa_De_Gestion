#include <iostream>
#include "cargaDatos.h"
#include "funciones.h"
using namespace std;

    //Hay que buscar una validación, porque cuando pide que ingreses un número e ingresas una letra, lo que hace es que queda en un loop infinito del cout
    void cargarMarcas(int nombre[], int tamanio) {
        int i;
        for (i=0; i< tamanio; i++) {
           cin >> nombre[i];
           while (nombre[i] > 10 || nombre[i] == 0) {
            cout << "No se puede ingresar numeros mayores a 10 o 0"<<endl;
            cin >> nombre[i];
           }}
    }

void cargarFormasPago (string nombre[], string medioPago[])
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

        for (i=0; i < 10; i++){
        cout << nombre[i] << endl;
        cout << "Selecciona: ";
        cin  >> codMedioPago;

        while (codMedioPago != "EF"
            && codMedioPago != "MP"
            && codMedioPago != "TR"
            && codMedioPago != "TC"
            && codMedioPago != "CT")
        {
            cout << "Código invalido. Intente de nuevo.\n";
            cin  >> codMedioPago;
        }
            if (codMedioPago == "EF") {
                    medioPago[i] = "Efectivo";
                } else if (codMedioPago == "MP") {
                    medioPago[i] = "Mercado Pago";
                } else if (codMedioPago == "TR") {
                    medioPago[i] = "Transferencia";
                } else if (codMedioPago == "TC") {
                    medioPago[i] = "Tarjeta de credito";
                } else if (codMedioPago == "CT") {
                    medioPago[i] = "Criptomoneda";
                } else {
                    medioPago[i] = "Código inválido";
                }
        }
        system("cls");

        for (i = 0; i < 10; i++) {
        cout << "Para la marca: " << nombre[i] << " se selecciono el medio: " << medioPago[i] << endl;
        };
}


