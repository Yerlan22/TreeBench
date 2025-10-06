#include <iostream>
#ifndef ARB_ULTPTRP_HPP
#define ARB_ULTPTRP_HPP

// Nodo de arbol
class Nodo
{
public:
  // Etiqueta del nodo
  int etiqueta;
  // Hijo Mas izquierdo de un nodo
  Nodo *siguiente;
  // Hermano Derecho de un nodo
  Nodo *hermanoDer;
  // Padre de un Nodo
  Nodo *Padre;
  // Numero de hijos de un nodo
  int numNodoHijos;
  // Constructor sobrecagado
  Nodo(int etiqueta = 0) : etiqueta(etiqueta), siguiente(nullptr), hermanoDer(nullptr), Padre(nullptr), numNodoHijos(0) {}
  // Constructor sobrecagado
  Nodo(int etiqueta, Nodo *padre, Nodo *hermanoDer, Nodo *HMI) : etiqueta(etiqueta), Padre(padre), hermanoDer(hermanoDer), siguiente(HMI), numNodoHijos(0) {}
};

class Arbol
{
private:
  // Raiz del arbol
  Nodo *arbRaiz = nullptr;
  // Numero de nodos de una Raiz
  int numElem = 0;

public:
  // Inicializa
  Arbol();
  // Destructor
  ~Arbol();
  // Vacia el arbol mediante VacioRecursive
  void vaciar();
  // Verifica si un arbol esta vacio
  bool vacio();
  // Metodo para eliminar todos los nodos del arbol
  void vacioRecursive(Nodo *nodo);
  // Coloca una etiqueta a la raiz
  void ponerRaiz(int elem);
  // Agrega un hijo en la posicion especifica del nodo que el usuario quiera
  Nodo *agregarHijo(Nodo *padre, int elem, int pos);
  // Borra un nodo Hoja
  void borrarNodoHoja(Nodo *hoja);
  // Modifica la etiqueta de un nodo ya creado
  void modificarEtiqueta(Nodo *nodo, int elem);
  // Retorna el nodo Raiz de un arbol
  Nodo *raiz();
  // Retorna el i-esimo hijo de un nodo
  Nodo *hijo(Nodo *np, int numh);
  // Retorna el nodo padre de un nodo
  Nodo *padre(Nodo *nodo);
  // Retorna el hermano derecho de un nodo
  Nodo *hermanoDer(Nodo *nodo);
  // Retorna el hijo mas izquierdo de un nodo
  Nodo *hijoMasIzq(Nodo *nodo);
  // Retorna la etiqueta de un nodo
  int etiqueta(Nodo *nodo);
  // Retorna el numero de hijos de un nodo
  int numHijos(Nodo *nodo);
  // Retorna el numero de nodos que tiene el arbol
  int numNodos();
};

#endif // ARB_ULTPTRP_HPP
