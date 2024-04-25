#include "validacion.h"
#include "utilidades.h"
bool validarOpcion(string entrada, string *opciones, int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones); //Se llama a la funcion stringInArray.
}

bool validarNumero(string entrada){
    string numeros = "0123456789"; //Se inicializa un string que contiene todos los numeros
    if(entrada.size() == 0) return false; //Se verifica que la entrada tenga longitud distinta de 0
    for(int cont = 0; cont < entrada.size(); cont++){
        if(numeros.find(entrada.at(cont)) >= numeros.size()) return false; //Para cada caracter de la entrada se verifica si pertenece al string de numeros, sino se devuelve falso.
    }
    return (stoi(entrada) > 0  && stoi(entrada) <= 100) || stoi(entrada) == 999 ? true: false; //Se devuelve verdadero si la entrada es mayor que cero, de lo contrairo se devuelve falso.
}
