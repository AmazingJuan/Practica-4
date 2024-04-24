#include "menus.h"
#include "validacion.h"
#include "utilidades.h"

int menuOpcion(string mensaje, string* opciones, int lenOpcion){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de escoger o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al escoger la opcion.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario

        //De la linea 22 a 23 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escoger una opcion valida.
        if(!error) cout << "Escoja la opcion que desee: ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar la opcion por favor: ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(validarOpcion(entrada, opciones, lenOpcion)){ //Valida la entrada del usuario haciendo uso de la funcion validarOpcion.
            return stoi(entrada); //Devuelve la entrada del usuario convertida a entero.
        }
        else error = true; //Si la opcion no es valida se activa el booleano error.
    }
}

int menuNumero(string mensaje, string tipoEntrada){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de escoger o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al escoger la opcion.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        limpiarPantalla(); //Se limpia la pantalla.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario
        //De la linea 50 a 52 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escoger una opcion valida.
        if(!error) cout << "Ingrese " + tipoEntrada + ": ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar " + tipoEntrada + ": ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(validarNumero(entrada)){ //Se valida que la entrada sea un numero positivo.
            return stoi(entrada); //Se devuelve al entrada que el usuario ingreso, como entero.
        }
        else error = true; //Si la entrada no es valida se activa el booleano error.
    }
}
