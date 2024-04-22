#ifndef RED_H
#define RED_H
#include "enrutador.h"
class red{
    public:
        red();
        void insertar(enrutador* router);
        void eliminar(char _nombre);
        void impEnrutadores();
    private:
        map<char,enrutador*, less<char>> enrutadores;
};

#endif // RED_H
