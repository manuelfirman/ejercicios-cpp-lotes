#include <iostream>

using namespace std;

/*
Se dispone de un lote de 300 registros (uno por artículo), cada uno de los cuales tiene la
siguiente información:
- Número de artículo (4 dígitos no correlativos).
- Cantidad de unidades en stock.
- Precio Unitario.
El lote está desordenado.
Se dispone de otro lote de registros, cada uno de los cuales corresponde a una venta con la siguiente
información:
- Número de cliente (1 a 300).
- Número de artículo (4 dígitos, no correlativos).
- Cantidad de unidades vendidas.
El último registro de este lote tiene número de cliente cero y no debe procesarse. Desarrollar el
programa que determine e imprima:
a) Un listado de las ventas realizadas, con el siguiente formato:
Listado de ventas
Nro. Cliente    Nro. Artículo   Cantidad Vendida    Importe Total
    99              99                  999             999.99
b) Informar cuál es el número de cliente que más compró en total (en pesos).
c) Informar cada uno de los números de los artículos que no hayan registrado ventas.

NOTA: se utilizan arrays y ciclos de 5 para agilizar la carga y prueba del programa.
*/

int main()
{
    //Vectores
    int vnArticulo[5], vnStock[5], vnCliente[5], vAcuVentasCliente[5];
    float vnPrecio[5];
    bool bandVentaArt[5];
    //Variables
    int inArticulo=0, inVendidos=0, inCliente=0, importeMayorCliente=0, nMayorCliente=0;
    //CARGA de lote
    for(int x=0; x<5; x++){
        cout << "Ingrese el Codigo de Articulo " << x+1 << ": "; cin >> vnArticulo[x];
        cout << "Ingrese el Stock del Articulo " << x+1 << ": "; cin >> vnStock[x];
        cout << "Ingrese el Precio del Articulo " << x+1 << ": "; cin >> vnPrecio[x];
    }
    cout << "------------ Lote cargado exitosamente -------------" << endl;
    //INI
    for(int x=0; x<5; x++){
        vAcuVentasCliente[x]=0;
    }
    for(int x=0; x<5; x++){
        bandVentaArt[x]=false;
    }

    //PROCESO de registro
    cout << "Ingrese el Numero de Cliente: "; cin >> inCliente;
    while(inCliente!=0){
        float cImporte=0;
        cout << "Ingrese el Numero de Articulo: "; cin >> inArticulo;
        cout << "Ingrese las Unidades Vendidas: "; cin >> inVendidos;
        for(int x=0; x<5; x++){
            if(inArticulo==vnArticulo[x]){
                cImporte=vnPrecio[x]*inVendidos;
                bandVentaArt[x]=true;
            }
        }
        for(int x=0; x<5; x++){
            if(inCliente==vnCliente[x]){
                vAcuVentasCliente[x]+=cImporte;
            }
        }


        //OUT POR VENTA
        cout << "--------------------------------------------------------" << endl;
        cout << "CLIENTE        ARTICULO        CANTIDAD        IMPORTE" << endl;
        cout << inCliente << "               " << inArticulo << "              " << inVendidos << "                " << cImporte << endl;
        cout << "--------------------------------------------------------" << endl;
        //ID WHILE
        cout << "Ingrese el Numero de Cliente: "; cin >> inCliente;
    }

    for(int x=0; x<5; x++){
        cout << vAcuVentasCliente << endl;
    }
    //Cliente con mas compras
    for(int x=0; x<5; x++){
        if(vAcuVentasCliente[x]>importeMayorCliente){
            importeMayorCliente=vAcuVentasCliente[x];
            nMayorCliente=x+1;
        }
    }

    cout << "------------------------------------------------------------" << endl << endl;

    //Articulos sin venta
    cout << "Los Articulos que no han registrado ventas son:" << endl;
    for(int x=0; x<5; x++){
        if(!bandVentaArt[x]){
            cout << "Articulo " << x+1 << endl;
        }
    }

    cout << "El cliente que mas compro es el N " << nMayorCliente << " con un importe total de $" << importeMayorCliente << endl;



    return 0;
}
