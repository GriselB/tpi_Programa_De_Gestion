#ifndef CARGADATOS_H
#define CARGADATOS_H
#include "structs.h"

using namespace std;

void cargarMarcas(Marca marcas[]);
void cargarFormasPago (MedioPago[]);
void cargarProductos(Producto[], Marca marcas[], recaudacionProducto recaudacionProducto[]);
void cargarVentas(Producto productos[], Marca marcas[], MedioPago mp[]);

#endif
