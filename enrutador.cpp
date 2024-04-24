#include "enrutador.h"
#include <iostream>

enrutador::enrutador(char _nombre){
    this->nombre = _nombre;
    this ->fila = new map<char, int, less<char>>;
}

char enrutador::getName(){
    return this->nombre;
}

map<char, int, less<char>> *enrutador::getFila(){
    return this->fila;
}

void enrutador::insertarFila(char _nodo, int valor){
    this->fila->insert(pair<char, int>(_nodo, valor));
}

void enrutador::imprimirFila()
{
    map<char,int>::iterator it = this->fila->begin();

    cout << this->nombre << '\t';
    for(;it!=fila->end();it++) cout << it->second << '\t';

}
