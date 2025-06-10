#include <iostream>
#include "cargaDatos.h"

using namespace std;

//Hay que buscar una validación, porque cuando pide que ingreses un número e ingresas una letra, lo que hace es que queda en un loop infinito del cout
void cargarMarcas(int nombre[], int tamanio) {
    int i;
    for (i=0; i<tamanio; i++) {
       cin >> nombre[i];
       while (nombre[i] > 10 || nombre[i] == 0) {
        cout << "No se puede ingresar numeros mayores a 10 o 0"<<endl;
        cin >> nombre[i];
       }}
}


