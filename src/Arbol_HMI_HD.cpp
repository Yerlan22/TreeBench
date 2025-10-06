// Copyright 2023 Antony Picado <antony.picado@ucr.ac.cr>
#include "Arbol_HMI_HD.hpp"

#include <iostream>
#include <queue>

Arbol::Arbol() {
  this->NodoRaiz = nullptr;
  this->numElementos = 0;
}

Arbol::~Arbol() {
  std::queue<Nodo*> queue;
  queue.push(this->NodoRaiz);
  while (!queue.empty()) {
    Nodo* nodoAux = queue.front();
    queue.pop();
    Nodo* nh = nodoAux->siguiente;
    while (nh) {
      queue.push(nh);
      nh = nh->hermanoDer;
    }
    delete nodoAux;
  }
}

void Arbol::vaciar() {
  std::queue<Nodo*> queue;
  queue.push(this->NodoRaiz);
  while (!queue.empty()) {
    Nodo* nodoAux = queue.front();
    queue.pop();
    Nodo* nh = nodoAux->siguiente;
    while (nh) {
      queue.push(nh);
      nh = nh->hermanoDer;
    }
    delete nodoAux;
  }
  this->NodoRaiz = nullptr;
  this->numElementos = 0;
}

bool Arbol::vacio() {
  if (this->NodoRaiz) { return false; }
  return true;
}

Nodo* Arbol::agregarHijo(Nodo* nodo, int64_t elemento, int64_t pos) {
  Nodo* nuevoNodo = nullptr;
  // Si no existe el hijo más izquierdo.
  if (!nodo->siguiente) {
    nuevoNodo = new Nodo(elemento, nodo, nullptr, nullptr);
    nodo->siguiente = nuevoNodo;
  }
  else {
    Nodo* nodoAux = nodo->siguiente;
    int64_t contador = 1;
    while (nodoAux) {
      if (contador >= pos) {
        nuevoNodo = new Nodo(elemento, nodo, nodoAux, nullptr);
        nodo->siguiente = nuevoNodo;
        break;
      } 
      if (!nodoAux->hermanoDer || contador + 1 >= pos) {
        nuevoNodo = new Nodo(elemento, nodo, nodoAux->hermanoDer, nullptr);
        nodoAux->hermanoDer = nuevoNodo;
        break;
      }
      nodoAux = nodoAux->hermanoDer;
      contador++;
    }
  }
  this->numElementos++;
  return nuevoNodo;
}

void Arbol::borrarNodoHoja(Nodo* nodo) {
  if (nodo->padre->siguiente == nodo) {
    nodo->padre->siguiente = nodo->padre->siguiente->hermanoDer;
    delete nodo;
  }
  else {
    Nodo* nodoAux = nodo->padre->siguiente;
    while (nodoAux) {
      if (nodoAux->hermanoDer == nodo) {
        nodoAux->hermanoDer = nodo->hermanoDer;
        delete nodo;
        break;
      }
      nodoAux = nodoAux->hermanoDer;
    }
  }

  this->numElementos--;
}

void Arbol::ponerRaiz(int64_t elemento) {
  Nodo* nuevoNodo = new Nodo(elemento);
  this->NodoRaiz = nuevoNodo;
  this->numElementos = 1;
}

void Arbol::modificarEtiqueta(Nodo* nodo, int64_t elemento) {
  nodo->etiqueta = elemento;
}

Nodo* Arbol::hijoMasIzq(Nodo* nodo) const {
  return nodo->siguiente;
}

Nodo* Arbol::hermanoDer(Nodo* nodo) const {
  return nodo->hermanoDer;
}

Nodo* Arbol::raiz() const {
  return this->NodoRaiz;
}

Nodo* Arbol::padre(Nodo* nodo) const {
  return nodo->padre;
}

Nodo* Arbol::hijo(Nodo* nodo, int64_t pos) {
  Nodo* nodoAux = nodo->siguiente;
  int contador = 1;
  while (nodoAux) {
    if (contador = pos) {
      return nodoAux;
    }
    ++contador;
    nodoAux->hermanoDer;
  }
  return nullptr;
}

int64_t Arbol::etiqueta(Nodo* nodo) const {
  return nodo->etiqueta;
}

int64_t Arbol::numHijos(Nodo* nodo) const {
  int contador = 0;
  if (nodo->siguiente) {
    Nodo* nodoTemp = nodo->siguiente;
    while (nodoTemp) {
      nodoTemp = nodoTemp->hermanoDer;
      ++contador;
    }
  }
  return contador;
}

bool Arbol::esHoja(Nodo* nodo) const {
  if (nodo->siguiente) { return false; }
  return true;
}

int64_t Arbol::numNodos() const {
  return this->numElementos;
}
