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
    int porcDescuentoInteres;
};

struct Venta{
    int nCompra;
    Producto codProducto;
    MedioPago formaPago;
    int ctidadVendida;
    int codCliente;
    int diaVenta;
};

struct recaudacionProducto{
    int codProducto;
    string nombreProducto;
    double totalRecaudado;
    int cantidadVendida;
    int stockRemanante;
};

#endif


