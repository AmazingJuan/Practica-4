#include <iostream>

using namespace std;
#include <fstream>
#include <archivos.h>
#include "red.h"
#include "menus.h"
#include "dijkstra.h"

int main(){
    red *red = archivoRed();
    red->impEnrutadores();
    red->eliminar('A');
    red->impEnrutadores();
    bool bandera = true;
    int decision = 0;
    string *opciones = new string[4];
    opciones[0] = "1";
    opciones[1] = "2";
    opciones[2] = "3";
    opciones[3] = "4";

    while(bandera){
        decision = menuOpcion("mensajito troll", opciones, 3);
        if(decision == 1){
            //hacer tales
        }
        else if(decision == 2){
            //hacer otor tales
        }
        else bandera = false;
    }
}
