#include <iostream>

using namespace std;

int main()
{
    //Vectores
    int vCodArticulo[5], vAcuVentas[5], vMeses[12], vVentasMes[12];
    float vPrecioUnitario[5];
    //Variables
    int numCliente=0, codArticulo=0, nMes=0, nDia=0, cantidadVendida=0, indiceVector=0, indiceMes=0, acuPromedio=0, cantPromedio=0, conVentas=0;

    //Carga de lote
    for(int x=0; x<5; x++){
        cout << "Ingrese el CODIGO DE ARTICULO: "; cin >> vCodArticulo[x];
        cout << "Ingrese el PRECIO UNITARIO: "; cin >> vPrecioUnitario[x];
    }
    //Inicializacion vectores
        for(int x=0; x<5; x++){
            vAcuVentas[x]=0;
        }
        for(int x=0; x<12; x++){
            vMeses[x]=x+1;
            vVentasMes[x]=0;
        }
    //Feedback lote cargado
    cout << "¡Lote cargado exitosamente!" << endl;

    //ID
    cout << "Ingrese el NUMERO DE CLIENTE: "; cin >> numCliente;

    //Proceso de lote
    while(numCliente!=0){
        cout << "Ingrese el numero de MES: "; cin >> nMes;
        cout << "Ingrese el CODIGO DEL ARTICULO: "; cin >> codArticulo;
        cout << "Ingrese la CANTIDAD VENDIDA: "; cin >> cantidadVendida;
        //contador ventas
        conVentas++;
        //Acumulacion de venta por codigo
        for(int x=0; x<5; x++){
            if(codArticulo==vCodArticulo[x]){
                indiceVector=x;
            }
        }
        vAcuVentas[indiceVector]+=cantidadVendida;
        //Acumulacion ventas por mes
        for(int x=0; x<12; x++){
            if(nMes==vMeses[x]){
                indiceMes=x;
            }
        }
        vVentasMes[indiceMes]+=cantidadVendida;



        cout << "Ingrese el NUMERO DE CLIENTE: "; cin >> numCliente;

    }
    //Separador
    cout << "----------- soy un separador -----------" << endl;
    //Ordenado de mayor a menor
    for(int y=0; y<5; y++){
        for(int x=0; x<4; x++){
                int auxFor=0;
            if(vAcuVentas[x]<vAcuVentas[x+1]){
                //Ventas
                auxFor=vAcuVentas[x+1];
                vAcuVentas[x+1]=vAcuVentas[x];
                vAcuVentas[x]=auxFor;
                //Codigo
                auxFor=vCodArticulo[x+1];
                vCodArticulo[x+1]=vCodArticulo[x];
                vCodArticulo[x]=auxFor;
            }
        }
    }

    //Lectura lote Lista de articulos
    for(int x=0; x<5; x++){
        cout << "COD: " << vCodArticulo[x] << " - Cantidad Vendida: " << vAcuVentas[x] << endl;
    }
    //Separador
    cout << "----------- soy un separador -----------" << endl;
    //Lectura mes sin ventas
    cout << "Los meses sin ventas son:" << endl;
    for(int x=0; x<12; x++){
        if(vVentasMes[x]==0){
           cout << vMeses[x] << "/21" << endl;
        }
    }
    //Separador
    cout << "----------- soy un separador -----------" << endl;
    // Mayor al promedio
    cout << "los codigos de articulo con cantidad de ventas mayor al promedio son:" << endl;
    for(int x=0; x<5; x++){
        acuPromedio+=vAcuVentas[x];
    }
    cantPromedio=acuPromedio/conVentas;
    for(int x=0; x<5; x++){
        if(vAcuVentas[x]>cantPromedio){
            cout << "Codigo " << vCodArticulo[x] << " con " << vAcuVentas[x] << " ventas." << endl;
        }
    }


    return 0;
}
