#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <importaciones.h>
#include <set>
class red{
    public:
        red();
        void insertar(enrutador* router);
        void eliminar(char _nombre);
        void impEnrutadores();
        void setupRed(string datos);
        void construirMatriz();
        void matrizAEnrut();
        void calcularCaminos();
        void setStrNodos(string _strNodos);
        void setEnrutadores(map<char,enrutador*, less<char>> *enrutadores);
        void setNodos(int nodos);
        void setMatriz(int **matriz);
        void setCaminos(map<char,map<char, string>*, less<char>> *caminos);
        map<char,map<char, string>*, less<char>> *getCaminos();
        map<char,enrutador*, less<char>> *getEnrutadores();
        int getNodos();
        int** getMatriz();
        string getStrNodos();
    private:
        map<char,enrutador*, less<char>> *enrutadores;
        int nodos;
        string strNodos;
        int **matriz;
        map<char,map<char, string>*, less<char>> *caminos;
};

#endif // RED_H
