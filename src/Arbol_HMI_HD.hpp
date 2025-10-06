// Copyright 2023 Antony Picado <antony.picado@ucr.ac.cr>
#ifndef Arbol_HMI_HD_HPP
#define Arbol_HMI_HD_HPP

#include <inttypes.h>

class Nodo {
public:
  // Etiqueta del Nodo.
  int64_t etiqueta;
  // Padre  del Nodo.
  Nodo* padre;
  // Hermano derecho del Nodo.
  Nodo* hermanoDer;
  // Hijo más izquierdo del Nodo.
  Nodo* siguiente;
  // Contructor sobrecargado.
  Nodo(const int64_t& etiqueta = 0) : etiqueta(etiqueta), padre(nullptr), hermanoDer(nullptr),
    siguiente(nullptr) {}
  // Contructor sobrecargado.
  Nodo(const int64_t& etiqueta, Nodo* padre, Nodo* hermanoDer, Nodo* siguiente) :
    etiqueta(etiqueta), padre(padre), hermanoDer(hermanoDer), siguiente(siguiente) {}
};

// Clase que representa un árbol n-ario de busqueda implementado mediante la ED 
// Hijo Más Izquierdo - Hermano Derecho.
class Arbol {
private:
  // Raíz del Árbol HMI-HD.
  Nodo* NodoRaiz;
  // número de elementos.
  int64_t numElementos;

public:
  // Constructor.
  Arbol();
  // Destructor.
  ~Arbol();
  // Vacia el árbol.
  void vaciar();
  // Verifica si el árbol esta vacío.
  bool vacio();
  // Agrega un Nodo hijo al árbol.
  Nodo* agregarHijo(Nodo* nodo, int64_t elemento, int64_t pos);
  // Borra el Nodo "nodo" del árbol. 
  void borrarNodoHoja(Nodo* nodo);
  // Crea la raíz del árbol.
  void ponerRaiz(int64_t elemento);
  // Modifica la etiqueta del Nodo.
  void modificarEtiqueta(Nodo* nodo, int64_t elemento);
  // Retorna el hijo más izquierdo del Nodo.
  Nodo* hijoMasIzq(Nodo* nodo) const;
  // Retorna el hermano derecho del Nodo.
  Nodo* hermanoDer(Nodo* nodo) const;
  // Retorna la raiz del árbol.
  Nodo* raiz() const;
  // Retorna el padre del Nodo.
  Nodo* padre(Nodo* nodo) const;
  // Retorna el hijo en la posición i.
  Nodo* hijo(Nodo* nodo, int64_t pos);
  // Retorna la etiqueta del Nodo.
  int64_t etiqueta(Nodo* nodo) const;
  // Retorna el número de hijos del Nodo.
  int64_t numHijos(Nodo* nodo) const;
  // Verifica si el Nodo es una hoja.
  bool esHoja(Nodo* nodo) const;
  // Retorna el número de elementos.
  int64_t numNodos() const;
};

#endif  // Arbol_HPP