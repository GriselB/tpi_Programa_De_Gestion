#ifndef REPORTES_H
#define REPORTES_H
using namespace std;

void reporteRecaudacionPorProducto(RecaudacionProducto recaudacionProducto[], int cantidad);
void productosSinVentas(RecaudacionProducto recaudacionProducto[], Producto productos[]);
void mostrarTop10Clientes(int contClientes[]);
void ordenarClientesPorCompras(ClienteInfo clientes[], int cantidad);
void porcentajeVentasPorMedioPago(PorcentajeMedioPago porcentajes[]);
void mostrarVentasPorMarcaYFormaPago(VentasMarcaFormaPago ventas[], int total);


#endif
