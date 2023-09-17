//
// Created by Alexander on 1/09/2022.
//

#include "Nodo.h"
#include <random>
#include <string>
using namespace std;
#include <iostream>
int Nodo::numNodos = 0;
string Nodo::eventoAnt = "C";
int Nodo::datoA = 0;
#include <cmath>

int calcularMCD(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

bool sonCoprimos(int num1, int num2) {
  int mcd = calcularMCD(num1, num2);
  return mcd == 1;
}

bool esPrimo(int numero) {
  if (numero <= 1) {
    return false;
  }

  for (int i = 2; i * i <= numero; i++) {
    if (numero % i == 0) {
      return false;
    }
  }

  return true;
}

Nodo::Nodo() {

  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(1, 100);
  int numAleatorio = distribution(generator);
  this->datos = numAleatorio;
  this->PtrFuturo = nullptr;
  this->PtrPasado = nullptr;
  int f = Nodo::numNodos;
  // cout << f << endl;
  // cout << Nodo::eventoAnt << endl;

  if (Nodo::eventoAnt == "A" or Nodo::eventoAnt == "C") {
    while (!esPrimo(numAleatorio)) {
      numAleatorio = distribution(generator);
      this->datos = numAleatorio;
    }
  }
  if (Nodo::eventoAnt == "B") {
    while (!sonCoprimos(numAleatorio, datoA)) {
      numAleatorio = distribution(generator);
      this->datos = numAleatorio;
    }
  } // Funciona: Los eventos A y B son numeros primos y el evento C es un numero
    // coprimo con el dato de A

  // if (esPrimo(numAleatorio)){
  if (f == 0 or Nodo::eventoAnt == "C") {
    this->evento = "A";
    datoA = this->datos;
  } else if (Nodo::eventoAnt == "A") {
    this->evento = "B";
  }
  //}
  else {
    this->evento = "C";
  }

  uniform_int_distribution<int> distribution2(1, 2);
  int CientificoAleatorio = distribution2(generator);
  if (CientificoAleatorio == 1) {
    this->cientifico = "E";
  }
  if (CientificoAleatorio == 2) {
    this->cientifico = "R";
  }
  if (this->evento == "A") {
    this->cientifico = "E";
  }
  int j=0;
  if(this->evento=="B"){
    j=1;
  }
  if(this->evento=="C"){
    j=2;
  }
  
  cout << "Se ha producido un evento de Tipo " << this->evento << ": "
       << this->datos << endl;

  if (this->evento == "C") {
    if (esPrimo(this->datos)) {
      cout << "Se ha viajado en el tiempo y se han comprartido datos" << endl;
    } else {
      cout << "Se ha viajado en el tiempo y No se han comprartido datos"
           << endl;
    }
  }

  
  cout << "|" << this->datos << "|" << this->cientifico << "|"
       << this->evento << "|->";
    //temp = temp->PtrPasado;
    
  cout << ""<< endl;

  

  Nodo::eventoAnt = this->evento;

  Nodo::numNodos++;
}

Nodo::Nodo(Nodo *n) {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(1, 100);
  int numAleatorio = distribution(generator);
  this->datos = numAleatorio;
  this->evento = evento;
  this->PtrPasado = nullptr; // 0 es el puntero NULL en C++
  this->PtrFuturo = n;
  uniform_int_distribution<int> distribution2(1, 2);
  int CientificoAleatorio = distribution2(generator);
  if (CientificoAleatorio == 1) {
    this->cientifico = "E";
  }
  if (CientificoAleatorio == 2) {
    this->cientifico = "R";
  }
  Nodo::numNodos++;
}
int Nodo::datoNodo() { return this->datos; }
Nodo *Nodo::enlaceNodoPasado() { return this->PtrPasado; }
Nodo *Nodo::enlaceNodoFuturo() { return this->PtrFuturo; }
void Nodo::ponerEnlacePasado(Nodo *pasado) { this->PtrPasado = pasado; }
void Nodo::ponerEnlaceFuturo(Nodo *futuro) { this->PtrFuturo = futuro; }
