#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "structs.h"
using namespace std;

void cargarNombres(Marca marcas[]);
void buscarMarcas(Marca marcas[]);
int buscarIndiceMarca(Marca marcas[], int cantidad, int codigo);
bool verificarMarcas(Marca marcas[]);
void cargarDiasDeVenta(int diasVentas[]);
int obtenerMinimo(int dias[]);
bool validarDiasConsecutivos(int dias[]);
int buscarProductoPorCodigoProducto(Producto productos[], int codProducto);
int buscarIndiceRecaudacionProducto(RecaudacionProducto recaudacionProducto[], int codProducto, int cantidadActual);
int buscarIndiceMedioPago(MedioPago mp[], int cantidadMedios, string codigo);
bool esCodigoValido(string codigo);
bool medioDePagoRepetido(MedioPago mp[], int cantidad, string codigo);
int contarProductosConVentas(RecaudacionProducto recaudacionProducto[]);
void inicializarPorcentajesMedioPago(MedioPago mp[], PorcentajeMedioPago porcentajes[]);
int buscarIndiceVentasMarcaFormaPago(VentasMarcaFormaPago ventas[], int total, int codMarca, string codMedioPago);

#endif


