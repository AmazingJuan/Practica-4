#include <archivos.h>
#include <iostream>
red *archivoRed(){
    string numeros = "1234567890";
    string letras = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

    char aux;
    string datos;
    red *puntero = new red;
    set<char> arreglo;
    fstream file;
    file.open("adjunta.txt", ios_base::in);
    while(!file.eof()){
        aux = file.get();
        if(numeros.find(aux) > numeros.size() && letras.find(aux) > letras.size() && aux != ' ') datos += ' ';
        else datos += aux;
    }
    file.close();
    puntero->setupRed(datos);
    return puntero;
}
