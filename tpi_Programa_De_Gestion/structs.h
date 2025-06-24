#ifndef STRUCTS_H
#define STRUCTS_H

using namespace std;

struct Marca {
    int codMarca;
    string nombreMarca;
};

struct Producto{
    int codProducto;
    string nombreProducto;
    float precioVenta;
    float precioCompra;
    int stockDisp;
    Marca codMarca;
};

struct MedioPago{
    string codMedioPago;
    string nombreFormaPago;
    int interes;
    int descuento;
};

struct RecaudacionProducto{
    int codProducto;
    string nombreProducto;
    double totalRecaudado;
    int cantidadVendida;
    int stockRemanente;
};

#endif


