#include "red.h"
#include "dijkstra.h"

red::red(){

}

void red::insertar(enrutador* router){
    enrutadores->insert(pair<char, enrutador*>(router->getName(), router));
    this -> setNodos(this->getNodos() + 1);
    delete [] this -> getMatriz();
    delete this -> getCaminos();
    this -> setCaminos(new map<char,map<char, string>*, less<char>>);
    this -> construirMatriz();
    this->setStrNodos(this -> getStrNodos() + router->getName());
    this -> calcularCaminos();
}

void red::eliminar(char _nombre){
    string aux = "";
    for(auto itr = enrutadores->rbegin(); itr != enrutadores->rend(); ++itr){
        auto aux = ((*enrutadores)[itr ->first])->getFila();
        aux->erase(aux->find(_nombre));
    }
    enrutadores->erase(enrutadores->find(_nombre));
    this -> setNodos(this->getNodos() - 1);
    delete [] this -> getMatriz();
    delete this -> getCaminos();
    this -> setCaminos(new map<char,map<char, string>*, less<char>>);
    this -> construirMatriz();
    for(int cont = 0; cont < this->getStrNodos().size(); cont++){
        if(this->getStrNodos().at(cont) != _nombre) aux += this->getStrNodos().at(cont);
    }
    this->setStrNodos(aux);
    this -> calcularCaminos();
}

string red::impEnrutadores(){
    string aux = "";
    map<char,enrutador*>::iterator it;

    aux += '\t';
    for(it = enrutadores->begin();it != enrutadores->end();it++) aux += string(1,it->first) + "\t";
    aux += "\n\n";

    for(it = enrutadores->begin();it != enrutadores->end();it++){
        aux += it->second-> imprimirFila();
        aux += "\n\n";
    }
    return aux;
}

map<char,enrutador*, less<char>> *red::getEnrutadores(){
    return this -> enrutadores;
}

void red::setEnrutadores(map<char,enrutador*, less<char>> *enrutadores){
    this->enrutadores = enrutadores;
}

void red::setNodos(int nodos){
   this -> nodos = nodos;
}

void red::setupRed(string datos){
    string letras = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    int indice;
    string aux;
    set<char> arreglo;
    int costo;
    char nodo;
    char conexion;
    map<char,int, less<char>> *filaAux;
    map<char,enrutador*, less<char>> *enrutadores = new map<char,enrutador*, less<char>>;
    for(int cont = 0; cont < datos.size(); cont++) if(arreglo.find(datos.at(cont)) == arreglo.end() && letras.find(datos.at(cont)) < letras.size()) arreglo.insert(datos.at(cont));
    for(int cont = 0; cont < datos.size(); cont++){
        nodo = datos.at(cont);
        conexion = datos.at(cont + 2);
        indice = datos.substr(cont + 4, datos.size() - cont - 4).find(' ');
        costo = stoi(datos.substr(cont + 4, indice));
        cont += 4 + indice;
        if(enrutadores->find(nodo) == enrutadores->end()){
            enrutadores->insert(pair<char, enrutador*>(nodo,new enrutador(nodo)));
            (*enrutadores)[nodo]->insertarFila(nodo);
        }
        if(enrutadores->find(conexion) == enrutadores->end()){
            enrutadores->insert(pair<char, enrutador*>(conexion,new enrutador(conexion)));
            (*enrutadores)[conexion]->insertarFila(conexion);
        }
        (*enrutadores)[nodo]->insertarFila(conexion, costo);
        (*enrutadores)[conexion]->insertarFila(nodo, costo);
    }
    for(map<char,enrutador*, less<char>>::iterator it = enrutadores->begin();it != enrutadores->end();it++){
        filaAux = it -> second -> getFila();
        for(set<char>::iterator it2 = arreglo.begin(); it2 != arreglo.end(); it2++){
            if(filaAux->find(*it2) == filaAux->end()){
                it->second->insertarFila(*it2, 999);
            }
        }
    }

    for(set<char>::iterator it2 = arreglo.begin(); it2 != arreglo.end(); it2++){
        aux += *it2;
    }
    this ->setStrNodos(aux);
    this->setEnrutadores(enrutadores);
    this->setNodos(arreglo.size());
    this->construirMatriz();
    this->setCaminos(new map<char,map<char, string>*, less<char>>);
    this -> calcularCaminos();
}

void red::setMatriz(int **matriz){
    this -> matriz = matriz;
}
int** red::getMatriz(){
    return this ->matriz;
}

int red::getNodos(){
    return this->nodos;
}

void red::construirMatriz(){
    int fila = 0;
    int columna = 0;
    map<char,int, less<char>> *filaAux;
    int **matriz = new int*[this->getNodos()];
    for(int i = 0; i < this->getNodos();i++) matriz[i] = new int[this->getNodos()];

    for(map<char,enrutador*, less<char>>::iterator it = enrutadores->begin();it != enrutadores->end();it++){
        filaAux = it -> second -> getFila();
        for(map<char,int, less<char>>::iterator it2 = filaAux->begin(); it2 != filaAux->end(); it2++){
            matriz[fila][columna] = it2->second;
            columna++;
        }
        fila++;
        columna = 0;
    }
    this->setMatriz(matriz);
}

void red::setStrNodos(string _strNodos){
    this->strNodos = _strNodos;
}
string red::getStrNodos(){
    return this->strNodos;
}

map<char,map<char, string>*, less<char>> *red::getCaminos(){
    return this->caminos;
}
void red::setCaminos(map<char,map<char, string>*, less<char>> *caminos){
    this -> caminos = caminos;
}

void red::matrizAEnrut(){
    char nodoMayor;
    char nodoInferior;
    int nodos = this -> getNodos();
    int** matriz = this -> getMatriz();
    auto enrutadores = this -> getEnrutadores();

    for(int fila = 0; fila < nodos; fila++){
        nodoMayor = this -> getStrNodos().at(fila);
        for(int columna = 0; columna < nodos; columna++){
            nodoInferior = this -> getStrNodos().at(columna);
            auto filaAux = (*enrutadores)[nodoMayor]->getFila();
            (*filaAux)[nodoInferior] = matriz[fila][columna];
        }
    }
}

void red::calcularCaminos(){
    for(int cont = 0; cont < this->getNodos(); cont++){
        if(isConnected(this->getMatriz()[cont], this->getNodos())){
            dijkstra(cont, this->getNodos(), this->getMatriz(), this);
        }
    }
    this->matrizAEnrut();
}
