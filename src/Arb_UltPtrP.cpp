#include "Arb_UltPtrP.hpp"

using namespace std;

Arbol::Arbol()
{
  this->numElem = 0;
  this->arbRaiz = nullptr;
}
Arbol::~Arbol()
{
  vaciar();
}

void Arbol::vaciar()
{
  vacioRecursive(this->arbRaiz);
  this->numElem = 0;
  this->arbRaiz = nullptr;
}

void Arbol::vacioRecursive(Nodo *nodo)
{
  if (nodo)
  {
    if (nodo->siguiente)
    {
      vacioRecursive(nodo->siguiente);
    }
    if (nodo->hermanoDer)
    {
      vacioRecursive(nodo->hermanoDer);
    }
    delete nodo;
    nodo = nullptr;
  }
}

bool Arbol::vacio()
{
  bool vacio = true;
  if (this->arbRaiz != nullptr)
  {
    vacio = false;
  }
  return vacio;
}

void Arbol::ponerRaiz(int elem)
{
  Nodo *nuevoNodo = new Nodo(elem);
  this->arbRaiz = nuevoNodo;
  this->numElem = 1;
}

Nodo *Arbol::agregarHijo(Nodo *padre, int elem, int pos)
{
  Nodo *nuevoNodo = new Nodo(elem);

  if (!padre->siguiente)
  {
    padre->siguiente = nuevoNodo;
  }
  else if (pos == 1)
  {
    nuevoNodo->hermanoDer = padre->siguiente;
    padre->siguiente = nuevoNodo;
  }
  else
  {
    Nodo *nodoAux = padre->siguiente;
    int contador = 1;

    while (nodoAux->hermanoDer && contador < pos - 1)
    {
      nodoAux = nodoAux->hermanoDer;
      contador++;
    }

    nuevoNodo->hermanoDer = nodoAux->hermanoDer;
    nodoAux->hermanoDer = nuevoNodo;
  }

  nuevoNodo->Padre = padre;
  padre->numNodoHijos++;
  numElem++;
  return nuevoNodo;
}

void Arbol::borrarNodoHoja(Nodo *hoja)
{
  Nodo *padre = this->padre(hoja);
  // Quiero borrar, HMI
  if (padre->siguiente == hoja)
  {
    if (hoja->hermanoDer != nullptr)
    {
      padre->siguiente = hoja->hermanoDer;
    }
    delete hoja;
  }
  // Quiero Borrar, Ultimo Hijo.
  else if (hoja->hermanoDer == nullptr)
  {
    // Si la funcion falla, la causa es laa liberacion de aux.
    Nodo *aux = padre->siguiente;
    while (aux->hermanoDer->hermanoDer != nullptr)
    {
      aux = aux->hermanoDer;
    }
    aux->Padre = padre;
    delete hoja;
  }
  // Quiero borrar nodo cualquiera
  else
  {
    Nodo *aux = padre->siguiente;
    while (aux->hermanoDer != hoja)
    {
      aux = aux->hermanoDer;
    }
    aux->hermanoDer = hoja->hermanoDer;
  }
  padre->numNodoHijos--;
  this->numElem--;
}

void Arbol::modificarEtiqueta(Nodo *nodo, int elem)
{
  nodo->etiqueta = elem;
}

Nodo *Arbol::raiz()
{
  return this->arbRaiz;
}

Nodo *Arbol::hijo(Nodo *padre, int numh)
{
  Nodo *nodoAux = padre->siguiente;

  int64_t contador = 1;

  while (nodoAux)
  {
    if (contador == numh)
    {
      return nodoAux;
    }
    ++contador;
    nodoAux = nodoAux->hermanoDer;
  }
  return nullptr;
}

Nodo *Arbol::padre(Nodo *nodo)
{
  Nodo *aux = nodo;
  while (aux->hermanoDer)
  {
    aux = aux->hermanoDer;
  }
  return aux->Padre;
}

Nodo *Arbol::hermanoDer(Nodo *nodo)
{
  return nodo->hermanoDer;
}

Nodo *Arbol::hijoMasIzq(Nodo *nodo)
{
  return nodo->siguiente;
}

int Arbol::etiqueta(Nodo *nodo)
{
  return nodo->etiqueta;
}

int Arbol::numHijos(Nodo *nodo)
{
  return nodo->numNodoHijos;
}

int Arbol::numNodos()
{
  return this->numElem;
}

