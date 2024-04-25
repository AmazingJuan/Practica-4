
using namespace std;
#include <archivos.h>
#include "red.h"
#include "menus.h"
#include "utilidades.h"

int main(){
    string **opcNodos = nullptr;
    string camino = "";
    red *network = nullptr;
    bool bandera = true;
    int decision = 0;
    int decision2 = 0;
    string *opciones = new string[5];
    opciones[0] = "1";
    opciones[1] = "2";
    opciones[2] = "3";
    opciones[3] = "4";
    opciones[4] = "5";

    while(bandera){
        if(network == nullptr){
            decision = menuOpcion(mensajes(1), opciones, 3);
            if(decision == 1){
                network  = archivoRed();
                opcNodos = opcionesNodos(network -> getStrNodos());
            }
            else if(decision == 2){
                network = new red;
                int nodos = menuNumero(mensajes(10), "el numero de enrutadores de la red (maximo 26)");
                if(nodos <= 26){
                    float probabilidad = float(menuNumero(mensajes(10), "la probabilidad que tiene un enrutador de enlazarse con otro (probabilidad del 1 al 100)")) / 100;
                    network -> setupRed(obtenerDatos(randomGrafo(nodos, probabilidad)));
                    opcNodos = opcionesNodos(network -> getStrNodos());
                }
                else{
                    //error
                }
            }
            else bandera = false;
        }
        else{
            decision2 = menuOpcion(mensajes(2), opciones, 5);
            if(decision2 == 1){
                if(network -> getNodos() + 1 <= 26){
                    enrutador *newRouter = new enrutador(network ->getNodos() + 65);
                    for(int cont = 0; cont < network -> getNodos(); cont++){
                        newRouter -> insertarFila(network->getStrNodos().at(cont), menuNumero(mensajes(9) + "El enrutador a crear es: " + string(1, network ->getNodos() + 65) + "\n\n", "el costo para llegar al nodo " + string(1, network->getStrNodos().at(cont)) + " (si no estan conectados escriba 999)"));
                    }
                    newRouter -> insertarFila(newRouter->getName());
                    network->insertar(newRouter);
                    opcNodos = opcionesNodos(network -> getStrNodos());
                }
                else{
                    //error
                }
            }
            else if(decision2 == 2){
                network -> eliminar(64 + menuOpcion(mensajes(4) + opcNodos[0][0], opcNodos[1], network ->getNodos()));
                opcNodos = opcionesNodos(network -> getStrNodos());
            }
            else if(decision2 == 3){
                char origen = menuOpcion(mensajes(5) + opcNodos[0][0], opcNodos[1], network ->getNodos()) + 64;
                char destino = menuOpcion(mensajes(6) + opcNodos[0][0], opcNodos[1], network ->getNodos()) + 64;
                auto caminos = network -> getCaminos();
                if(isConnected(network->getMatriz()[origen - 65], network -> getNodos())){
                    camino = (*(*caminos)[origen])[destino];
                }
                else{
                    camino = "";
                }
                menuOpcion(mensajes(8) + "Ruta: " + getRuta(camino, (network -> getMatriz())[origen-65][destino - 65]) + "\nCosto: " + to_string((network -> getMatriz())[origen-65][destino - 65]) + "\n\n1. Seleccione esta opcion si desea volver al menu principal.\n\n", opciones, 1);
            }
            else if(decision2 == 4){
                menuOpcion(mensajes(7) + network -> impEnrutadores() + "\n1. Seleccione esta opcion si desea volver al menu de la red.\n\n", opciones, 1);
            }
            else{
                delete network;
                network = nullptr;
            }
        }
    }
}
