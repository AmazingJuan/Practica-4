#ifndef UTILIDADES_H
#define UTILIDADES_H
#include "importaciones.h"
void limpiarPantalla();
bool stringInArray(string cadena, string* arreglo, int lenArreglo);
string randomGrafo(int nodos, float probabilidad);
string obtenerDatos(string raw);
string **opcionesNodos(string nodos);
string mensajes(int parametro);
string getRuta(string camino, int costo);
bool isConnected(int*fila, int size);
#endif // UTILIDADES_H
