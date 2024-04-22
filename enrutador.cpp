#include "enrutador.h"
#include <iostream>

enrutador::enrutador(char _nombre){
    nombre = _nombre;
}

char enrutador::getName(){
    return nombre;
}

map<char, int, less<char>> enrutador::getFila(){
    return fila;
}

void enrutador::insertarFila(char _nodo, int valor){
    fila.insert(pair<char, int>(_nodo, valor));
}

void enrutador::imprimirFila()
{
    map<char,int>::iterator it = fila.begin();

    cout << nombre << '\t';
    for(;it!=fila.end();it++) cout << it->second << '\t';

}
