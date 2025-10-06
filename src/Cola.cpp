#include "Cola.hpp"

Cola::Cola() {
  this->frente = nullptr;
  this->atras = nullptr;
}

Cola::~Cola() {
  while (!this->Vacia()) {
    Nodo* temp = this->frente;
    this->frente = this->frente->siguiente;
    delete temp;
  }
}

void Cola::Vaciar() {
  while (!this->Vacia()) {
  this->Sacar();
  }
}

bool Cola::Vacia() {
  return this->frente == nullptr;
}

void Cola::Agregar(int e) {
  Nodo* nuevoNodo = new Nodo();
  nuevoNodo->etiqueta = e;
  nuevoNodo->siguiente = nullptr;
  if (this->Vacia()) {
    this->frente = this->atras = nuevoNodo;
  }
  else {
    this->atras->siguiente = nuevoNodo;
    this->atras = nuevoNodo;
  }
}

void Cola::Sacar() {
  if (this->Vacia()) {
    return;
  }
  Nodo* temp = this->frente;
  this->frente = this->frente->siguiente;
  if (this->Vacia()) {
    this->atras = nullptr;
  }
  delete temp;
}

int Cola::Frente() {
  return this->frente->etiqueta;
}