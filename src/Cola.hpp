#ifndef COLA_HPP
#define COLA_HPP

#include "ALH.hpp"
//#include "Arb_UltPtrP.hpp"
//#include "Arbol_ArrPadre.hpp"
//#include "Arbol_HMI_HD.hpp"

#include <iostream>


class Cola {
private:
  // Nodo del frente.
  Nodo* frente;
  // Nodo de atras.
  Nodo* atras;
public:
  // Constructor.
  Cola();
  // Destructor.
  ~Cola();
  // Vacia vacia e inicializa la cola.
  void Vaciar();
  // Retorna verdadero si la cola esta vacia.
  bool Vacia();
  // Agrega un elemento a la cola.
  void Agregar(int e);
  // Saca un elemento de la cola y lo retorna.
  void Sacar();
  // Retorna la elemento del nodo frente.
  int Frente();
};

#endif // COLA_HPP