#include <archivos.h>
#include <utilidades.h>
#include <iostream>
red *archivoRed(){
    string aux;
    string datos;
    red *puntero = new red;
    set<char> arreglo;
    fstream file;
    file.open("adjunta.txt", ios_base::in);
    while(!file.eof()){
        aux += file.get();
    }
    datos = obtenerDatos(aux);
    file.close();
    puntero->setupRed(datos);
    return puntero;
}
