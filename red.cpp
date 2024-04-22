#include "red.h"
#include <iostream>

red::red(){

}

void red::insertar(enrutador* router){
    enrutadores.insert(pair<char, enrutador*>(router->getName(), router));
}

void red::eliminar(char _nombre){
    for(auto itr = enrutadores.rbegin(); itr != enrutadores.rend(); ++itr){
        auto aux = enrutadores[itr ->first]->getFila();
        aux.erase(aux.find(_nombre));
    }
    enrutadores.erase(enrutadores.find(_nombre));
}

void red::impEnrutadores(){
    map<char,enrutador*>::iterator it;

    cout << '\t';
    for(it = enrutadores.begin();it != enrutadores.end();it++) cout << it->first << '\t';
    cout << "\n\n";

    for(it = enrutadores.begin();it != enrutadores.end();it++){
        it->second-> imprimirFila();
        cout << "\n\n";
    }
}

