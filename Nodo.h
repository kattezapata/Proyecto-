//
// Created by Alexander on 1/09/2022.
//

#ifndef LISTICAS2_NODO_H
#define LISTICAS2_NODO_H
#include <string>
using namespace std;
#include <iostream>


class Nodo
{
public:
    string evento;
    string cientifico;
    int datos;
    Nodo* PtrPasado;
    Nodo* PtrFuturo;
    static int numNodos;
    static string eventoAnt;
    static int datoA;

    Nodo();

    Nodo( Nodo* n);// crea el nodo y lo enlaza a n

    int datoNodo( );

    Nodo* enlaceNodoPasado( );

    Nodo* enlaceNodoFuturo( );

    void ponerEnlacePasado(Nodo* pasado);

    void ponerEnlaceFuturo(Nodo* futuro);

};



#endif //LISTICAS2_NODO_H
