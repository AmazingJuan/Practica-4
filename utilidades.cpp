#include "utilidades.h"

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n";
}

bool stringInArray(string cadena, string* arreglo, int lenArreglo){
    for(int cont = 0; cont < lenArreglo; cont ++) if(cadena == arreglo[cont]) return true;
    return false;
}
