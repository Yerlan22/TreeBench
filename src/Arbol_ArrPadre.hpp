#ifndef ARBOL_ARRPADRE_HPP
#define ARBOL_ARRPADRE_HPP

const int MAX_NODOS = 100;

class Nodo
{
public:
  // Etiqueta del Nodo.
  int etiqueta;
  // Indice del Nodo Padre.
  Nodo *indicePadre;
  // Indice hijo más izquierdo.
  Nodo *siguiente;
  // Indice hermano derecho.
  Nodo *hermanoDer;
};

class Arbol
{
private:
  // Numero de elementos en el arbol
  int numElementos;
  // Indice de la raiz en el arreglo de nodos
  Nodo *raizIndice;

public:
  // Arreglo de nodos para almacenar
  // los elementos del arbol
  Nodo nodos[MAX_NODOS];
  // Crear
  Arbol();
  // Destruir
  ~Arbol();
  // Vacia el arbol y lo inicializa.
  void vaciar();
  // Comprueba si el arbol esta vacio
  bool vacio();
  // Pone el elemento dado como la raiz del arbol
  void ponerRaiz(int elemento);
  // Agrega un hijo con el elemento en el nodo padre dado
  // devuelve el nodo* al hijo
  Nodo *agregarHijo(Nodo *nodo, int elemento, int pos);
  // Borra un nodo hoja especificado del arbol
  void borrarNodoHoja(Nodo *nodo);
  // Modifica la etiqueta del nodo dado
  void modificarEtiqueta(Nodo *nodo, int elemento);
  // Devuelve un puntero a la raiz del arbol
  Nodo *raiz();
  // Devuelve un puntero al hijo del nodo padre dado.
  Nodo *hijo(Nodo *nodo, int elemento);
  // Devuelve un puntero al padre del nodo dado
  Nodo *padre(Nodo *nodo);
  // Devuelve un puntero al hermano derecho del nodo
  // especificado
  Nodo *hermanoDer(Nodo *nodo);
  // Devuelve un puntero al hijo mas izquierdo del nodo
  // especificado
  Nodo *hijoMasIzq(Nodo *nodo);
  // Devuelve la etiqueta del nodo dado
  int etiqueta(Nodo *nodo);
  // Devuelve el numero de hijos del nodo dado
  int numHijos(Nodo *nodo);
  // Devuelve el numero de elementos en el arbol.
  int numNodos();
};

#endif // ARBOL_ARRPADRE_HPP
