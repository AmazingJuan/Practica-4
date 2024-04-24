#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <map>
using namespace std;
class enrutador{
    public:
        char nombre;
        enrutador(char _nombre);
        char getName();
        map<char, int, less<char>> *getFila();
        void insertarFila(char _nodo, int valor = 0);
        void imprimirFila();
    private:
        map<char, int, less<char>> *fila;
};

#endif // ENRUTADOR_H
