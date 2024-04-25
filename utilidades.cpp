#include "utilidades.h"

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n";
}

bool stringInArray(string cadena, string* arreglo, int lenArreglo){
    for(int cont = 0; cont < lenArreglo; cont ++) if(cadena == arreglo[cont]) return true;
    return false;
}

string randomGrafo(int nodos, float probabilidad){
    char nodo1;
    char nodo2;
    srand(time(0));
    string aux = "";
    for (int i = 0; i < nodos; ++i) {
        for (int j = i + 1; j < nodos; ++j) {
            float randNum = (float)rand() / RAND_MAX;
            if (randNum < probabilidad) {
                nodo1 = char('A' + i);
                nodo2 = char('A' + j);
                int cost = rand() % 100 + 1; // Generar un costo aleatorio entre 1 y 100
                aux += string(1, nodo1) + " " + string(1, nodo2) + " " + to_string(cost) + '\n';
            }
        }
    }
    return aux;
}

string obtenerDatos(string raw){
    char aux;
    string datos = "";
    string numeros = "1234567890";
    string letras = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    for(int cont = 0; cont < raw.size(); cont++){
        aux = raw.at(cont);
        if(numeros.find(aux) > numeros.size() && letras.find(aux) > letras.size() && aux != ' ') datos += ' ';
        else datos += aux;
    }
    return datos;
}

string **opcionesNodos(string nodos){
    auto opciones = new string*[2];
    opciones[0] = new string[1];
    opciones[0][0] = "";
    opciones[1] = new string[nodos.size()];
    int cont = 0;
    for(; cont < nodos.size(); cont++){
        opciones[0][0] += to_string(cont + 1) + ". " + nodos.at(cont) + '\n';
        opciones[1][cont] = to_string(cont + 1);
    }
    opciones[0][0] += '\n';
    return opciones;
}

string mensajes(int parametro){
    switch(parametro){
        case 1:
            return "  ____    _                                         _       _         \n |  _ \\  (_)                                       (_)     | |        \n | |_) |  _    ___   _ __   __   __   ___   _ __    _    __| |   ___  \n |  _ <  | |  / _ \\ | '_ \\  \\ \\ / /  / _ \\ | '_ \\  | |  / _` |  / _ \\ \n | |_) | | | |  __/ | | | |  \\ V /  |  __/ | | | | | | | (_| | | (_) |\n |____/  |_|  \\___| |_| |_|   \\_/    \\___| |_| |_| |_|  \\__,_|  \\___/ \n                                                                    \nBienvenido a TP LINK, usted tiene las siguientes opciones:\n\n1. Acceder a una red mediante el archivo de nodos.\n2. Generar una red aleatoria.\n3. Salir del programa.\n\n";
        case 2:
            return "  _____               _ \n |  __ \\             | |\n | |__) |   ___    __| |\n |  _  /   / _ \\  / _` |\n | | \\ \\  |  __/ | (_| |\n |_|  \\_\\  \\___|  \\__,_|\n                         \nSe ha ingresado a la red correctamente, usted posee las siguientes opciones:\n\n1. Agregar un enrutador a la red.\n2. Eliminar un enrutador de la red.\n3. Mostrar ruta y costo para enviar un paquete de un enrutador a otro.\n4. Mostrar mapa de redes.\n5. Volver al menu principal.\n\n";;
        case 3:
            return "                                                        \n     /\\                                                 \n    /  \\      __ _   _ __    ___    __ _    __ _   _ __ \n   / /\\ \\    / _` | | '__|  / _ \\  / _` |  / _` | | '__|\n  / ____ \\  | (_| | | |    |  __/ | (_| | | (_| | | |   \n /_/    \\_\\  \\__, | |_|     \\___|  \\__, |  \\__,_| |_|   \n              __/ |                 __/ |               \n             |___/                 |___/                \n";
        case 4:
            return "  ______   _   _               _                        \n |  ____| | | (_)             (_)                       \n | |__    | |  _   _ __ ___    _   _ __     __ _   _ __ \n |  __|   | | | | | '_ ` _ \\  | | | '_ \\   / _` | | '__|\n | |____  | | | | | | | | | | | | | | | | | (_| | | |   \n |______| |_| |_| |_| |_| |_| |_| |_| |_|  \\__,_| |_|   \n                                                        \nIngrese el nodo que desea eliminar:\n\n";
        case 5:
            return "  ____           _                        \n / __ \\         (_)                       \n| |  | |  _ __   _    __ _    ___   _ __  \n| |  | | | '__| | |  / _` |  / _ \\ | '_ \\ \n| |__| | | |    | | | (_| | |  __/ | | | |\n \\____/  |_|    |_|  \\__, |  \\___| |_| |_|\n                      __/ |               \n                     |___/                \nIngrese el nodo de origen:\n\n";
        case 6:
            return "  _____                 _     _                 \n |  __ \\               | |   (_)                \n | |  | |   ___   ___  | |_   _   _ __     ___  \n | |  | |  / _ \\ / __| | __| | | | '_ \\   / _ \\ \n | |__| | |  __/ \\__ \\ | |_  | | | | | | | (_) |\n |_____/   \\___| |___/  \\__| |_| |_| |_|  \\___/ \n                                                 \nIngrese el nodo de destino:\n\n";
        case 7:
            return "  __  __                         \n |  \\/  |                        \n | \\  / |   __ _   _ __     __ _ \n | |\\/| |  / _` | | '_ \\   / _` |\n | |  | | | (_| | | |_) | | (_| |\n |_|  |_|  \\__,_| | .__/   \\__,_|\n                  | |            \n                  |_|            \nHe aqui la matriz de adyacencia de la red actual:\n\n\n";
        case 8:
            return "  _____                         _   _                 _         \n |  __ \\                       | | | |               | |        \n | |__) |   ___   ___   _   _  | | | |_    __ _    __| |   ___  \n |  _  /   / _ \\ / __| | | | | | | | __|  / _` |  / _` |  / _ \\ \n | | \\ \\  |  __/ \\__ \\ | |_| | | | | |_  | (_| | | (_| | | (_) |\n |_|  \\_\\  \\___| |___/  \\__,_| |_|  \\__|  \\__,_|  \\__,_|  \\___/ \n                                                                \nHe aqui el resultado esperado:\n\n";
        case 9:
            return "  _____                 _           \n / ____|               | |          \n| |        ___    ___  | |_    ___  \n| |       / _ \\  / __| | __|  / _ \\ \n| |____  | (_) | \\__ \\ | |_  | (_) |\n \\_____|  \\___/  |___/  \\__|  \\___/ \n                                     \n";
        case 10:
            return " _   _               _               \n| \\ | |             | |              \n|  \\| |   ___     __| |   ___    ___ \n| . ` |  / _ \\   / _` |  / _ \\  / __|\n| |\\  | | (_) | | (_| | | (_) | \\__ \\\n|_| \\_|  \\___/   \\__,_|  \\___/  |___/\n                                      \n";
        case 11:
            return "  _____                   _               _       _   _   _       _               _ \n |  __ \\                 | |             | |     (_) | | (_)     | |             | |\n | |__) |   _ __    ___  | |__     __ _  | |__    _  | |  _    __| |   __ _    __| |\n |  ___/   | '__|  / _ \\ | '_ \\   / _` | | '_ \\  | | | | | |  / _` |  / _` |  / _` |\n | |       | |    | (_) || |_) | | (_| | | |_) | | | | | | | | (_| | | (_| | | (_| |\n |_|       |_|     \\___/ |_.__/   \\__,_| |_.__/  |_| |_| |_|  \\__,_|  \\__,_|  \\__,_|\n                                                                                    \n";
        }
}

string getRuta(string camino, int costo){
    string aux = "";
    int cont = 0;
    if(costo != 999){
        if(costo == 0){
            aux = "No tiene que moverse para llegar a este nodo";
        }
        else{
            for(;cont < camino.size(); cont++){
                aux += camino.at(cont);
                if(cont + 1 < camino.size()) aux += " -> ";
            }
        }
    }
    else{
        aux = "No se puede llegar al nodo bajo ninguna circunstancia";
    }
    return aux;
}

bool isConnected(int*fila, int size){
    for(int cont = 0; cont < size;cont++){
        if(fila[cont] != 999 && fila[cont] != 0) return true;
    }
    return false;
}
