#include <iostream>

using namespace std;
#include <fstream>
#include "red.h"

int main(){
    red network;
    enrutador *router1 = new enrutador('A');
    enrutador *router2 = new enrutador('B');
    router2->insertarFila('B');
    router2->insertarFila('A', 5);
    router1->insertarFila('A');
    router1->insertarFila('B', 5);
    network.insertar(router1);
    network.insertar(router2);
    network.impEnrutadores();
}
