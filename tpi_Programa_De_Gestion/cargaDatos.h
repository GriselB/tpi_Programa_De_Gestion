#ifndef CARGADATOS_H
#define CARGADATOS_H
#include "structs.h"
using namespace std;

void cargarMarcas(Marca marcas[]);
void cargarFormasPago (MedioPago[]);
void cargarProductos(Producto[], Marca marcas[]);
void cargarLoteVentas(Producto productos[], Marca marcas[], MedioPago mp[], RecaudacionProducto recaudacionProducto[], int& productosVendidos,  int contClientes[], PorcentajeMedioPago porcentajeMedioPago[], VentasMarcaFormaPago ventasMarcaFormaPago[], int& totalVentasMarcaFormaPago);
#endif
