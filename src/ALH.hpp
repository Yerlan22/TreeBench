// Copyright 2023 Antony Picado <antony.picado@ucr.ac.cr>
#ifndef ALH_HPP
#define ALH_HPP

#include <inttypes.h>

class Nodo;

class subNodo
{
public:
	// Puntero al Nodo.
	Nodo *nodoPtr;
	// Puntero al hermano derecho.
	subNodo *hermanoDer;
	// Contructor sobrecargado.
	subNodo(Nodo *nodo) : nodoPtr(nodo), hermanoDer(nullptr){};
	// Contructor sobrecargado.
	subNodo(Nodo *nodo, subNodo *hermanoDer) : nodoPtr(nodo), hermanoDer(hermanoDer){};
};

class Nodo
{
public:
	// Etiqueta del Nodo.
	int64_t etiqueta;
	// Puntero al siguiente Nodo.
	Nodo *siguiente;
	// Guarda un puntero al hijo del Nodo.
	subNodo *hijo;
	// Cantidad de hijos del Nodo.
	int64_t cantidadHijos;
	// Contructor sobrecargado.
	Nodo() : etiqueta(-1), siguiente(nullptr), hijo(nullptr), cantidadHijos(0) {}
	// Contructor sobrecargado.
	Nodo(const int64_t valor) : etiqueta(valor), siguiente(nullptr), hijo(nullptr), cantidadHijos(0) {}
	// Contructor sobrecargado.
	Nodo(const int64_t valor, Nodo *sig) : etiqueta(valor), siguiente(siguiente), hijo(nullptr), cantidadHijos(0) {}
};

// Clase que representa un árbol n-ario de busqueda implementado mediante una
// lista de hijos.
class Arbol
{
private:
	// Raíz del árbol.
	Nodo *NodoRaiz;
	// Número de elementos del árbol.
	int64_t numElementos;

public:
	// Constructor.
	Arbol();
	// Destructor.
	~Arbol();
	// Vacia el árbol.
	void vaciar();
	// Verifica si el árbol esta vacío.
	bool vacio() const;
	// Agrega un Nodo hijo al árbol.
	Nodo *agregarHijo(Nodo *nodo, int64_t elemento, int64_t pos);
	// Borra el Nodo "nodo" del árbol.
	void borrarNodoHoja(Nodo *nodo);
	// Crea la raíz del árbol.
	void ponerRaiz(int64_t elemento);
	// Modifica la etiqueta del Nodo.
	void modificarEtiqueta(Nodo *nodo, int64_t elemento);
	// Retorna el hijo más izquierdo del Nodo.
	Nodo *hijoMasIzq(Nodo *nodo) const;
	// Retorna el hermano derecho del Nodo.
	Nodo *hermanoDer(Nodo *nodo) const;
	// Retorna la raiz del árbol.
	Nodo *raiz() const;
	// Retorna el padre del Nodo.
	Nodo *padre(Nodo *nodo) const;
	Nodo *hijo(Nodo *nodo, int64_t pos);
	// Retorna la etiqueta del Nodo.
	int64_t etiqueta(Nodo *nodo) const;
	// Retorna el número de hijos del Nodo.
	int64_t numHijos(Nodo *nodo) const;
	// Verifica si el Nodo es una hoja.
	bool esHoja(Nodo *nodo) const;
	// Retorna el número de elementos.
	int64_t numNodos() const;
};

#endif // ALH_HPP