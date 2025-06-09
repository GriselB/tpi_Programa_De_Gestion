#include <iostream>
#include "cargaDatos.h"

using namespace std;

void cargarMarcas(int vec[], int tamanio) {
    int i;
    for (i=0; i<tamanio; i++) {
       cin >> vec[i];
       while (vec[i] > 10 || vec[i] == 0) {
        cout << "No se puede ingresar numeros mayores a 10 o 0"<<endl;
        cin >> vec[i];
       }}
}
