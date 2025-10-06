// Copyright 2023 Antony Picado <antony.picado@ucr.ac.cr>
#include "ALH.hpp"

#include <queue>

Arbol::Arbol()
{
  this->NodoRaiz = nullptr;
  this->numElementos = 0;
}

Arbol::~Arbol()
{
  Nodo *nodoAux = this->NodoRaiz;
  subNodo *n = nullptr;
  while (nodoAux)
  {
    while (nodoAux->hijo)
    {
      n = nodoAux->hijo;
      if (n->hermanoDer)
      {
        nodoAux->hijo = n->hermanoDer;
      }
      else
      {
        nodoAux->hijo = nullptr;
      }
      delete n;
    }
    Nodo *na = nodoAux;
    nodoAux = nodoAux->siguiente;
    delete na;
  }
}

void Arbol::vaciar()
{
  // Se destruye los nodos del árbol.
  Nodo *nodoAux = this->NodoRaiz;
  subNodo *n = nullptr;
  while (nodoAux)
  {
    while (nodoAux->hijo)
    {
      n = nodoAux->hijo;
      if (n->hermanoDer)
      {
        nodoAux->hijo = n->hermanoDer;
      }
      else
      {
        nodoAux->hijo = nullptr;
      }
      delete n;
    }
    Nodo *na = nodoAux;
    nodoAux = nodoAux->siguiente;
    delete na;
  }
  // Se inicializa el árbol.
  this->numElementos = 0;
  this->NodoRaiz = nullptr;
}

bool Arbol::vacio() const
{
  if (this->NodoRaiz)
  {
    return false;
  }
  return true;
}

Nodo *Arbol::agregarHijo(Nodo *nodo, int64_t elemento, int64_t pos)
{
  Nodo *nuevoNodo = nullptr;

  if (!nodo->siguiente)
  {
    nuevoNodo = new Nodo(elemento);
    nodo->siguiente = nuevoNodo;
    nodo->hijo = new subNodo(nuevoNodo);
  }
  else
  {
    nuevoNodo = new Nodo(elemento, nodo->siguiente);
    nodo->siguiente = nuevoNodo;
    subNodo *nodoAux = nodo->hijo;
    int64_t contador = 1;
    while (nodoAux)
    {
      if (contador >= pos)
      {
        nodo->hijo = new subNodo(nuevoNodo, nodoAux);
        break;
      }
      if (!nodoAux->hermanoDer || contador + 1 >= pos)
      {
        subNodo *nodoSigAux = nodoAux->hermanoDer;
        nodoAux->hermanoDer = new subNodo(nuevoNodo, nodoSigAux);
        break;
      }
      nodoAux = nodoAux->hermanoDer;
      contador++;
    }
  }
  this->numElementos++;
  nodo->cantidadHijos++;
  return nuevoNodo;
}

void Arbol::borrarNodoHoja(Nodo *nodo)
{
  Nodo *padreAux = padre(nodo);
  subNodo *subNodoAux = padreAux->hijo;
  while (subNodoAux)
  {
    // Caso hijo más izquierdo.
    if (subNodoAux->nodoPtr == nodo)
    {
      padreAux->hijo = subNodoAux->hermanoDer;
      delete subNodoAux;
      break;
    }
    if (subNodoAux->hermanoDer->nodoPtr == nodo)
    {
      subNodoAux->hermanoDer = subNodoAux->hermanoDer->hermanoDer;
      delete subNodoAux->hermanoDer;
      break;
    }
    subNodoAux = subNodoAux->hermanoDer;
  }
  Nodo *nodoAux = this->NodoRaiz;
  while (nodoAux)
  {
    // Caso en el que sea la raiz.
    if (nodoAux == nodo)
    {
      delete nodo;
      break;
    }
    if (nodoAux->siguiente == nodo)
    {
      nodoAux->siguiente = nodo->siguiente;
      delete nodo;
      break;
    }
    nodoAux = nodoAux->siguiente;
  }
  this->numElementos--;
  padreAux->cantidadHijos--;
}

void Arbol::ponerRaiz(int64_t elemento)
{
  this->NodoRaiz = new Nodo(elemento);
  this->numElementos = 1;
}

void Arbol::modificarEtiqueta(Nodo *nodo, int64_t elemento)
{
  nodo->etiqueta = elemento;
}

Nodo *Arbol::hijoMasIzq(Nodo *nodo) const
{
  if (nodo->hijo)
  {
    return nodo->hijo->nodoPtr;
  }
  return nullptr;
}

Nodo *Arbol::hermanoDer(Nodo *nodo) const
{

  subNodo *nodoAux = nullptr;
  if (this->padre(nodo))
  {
    nodoAux = this->padre(nodo)->hijo;
  }

  while (nodoAux)
  {
    if (nodoAux->nodoPtr == nodo && nodoAux->hermanoDer)
    {
      return nodoAux->hermanoDer->nodoPtr;
    }
    nodoAux = nodoAux->hermanoDer;
  }
  return nullptr;
}

Nodo *Arbol::raiz() const
{
  return this->NodoRaiz;
}

Nodo *Arbol::padre(Nodo *nodo) const
{
  Nodo *nodoAux = this->NodoRaiz;
  subNodo *subNodoAux = nullptr;
  while (nodoAux)
  {
    subNodoAux = nodoAux->hijo;
    while (subNodoAux)
    {
      if (subNodoAux->nodoPtr == nodo)
      {
        return nodoAux;
      }
      subNodoAux = subNodoAux->hermanoDer;
    }
    nodoAux = nodoAux->siguiente;
  }
  return nullptr;
}

Nodo *Arbol::hijo(Nodo *nodo, int64_t pos)
{
  subNodo *nodoAux = nodo->hijo;
  int contador = 1;
  while (nodoAux)
  {
    if (contador = pos)
    {
      return nodoAux->nodoPtr;
    }
    ++contador;
    nodoAux = nodoAux->hermanoDer;
  }
  return nullptr;
}

int64_t Arbol::etiqueta(Nodo *nodo) const
{
  return nodo->etiqueta;
}

int64_t Arbol::numHijos(Nodo *nodo) const
{
  return nodo->cantidadHijos;
}

bool Arbol::esHoja(Nodo *nodo) const
{
  if (nodo->hijo)
  {
    return true;
  }
  return false;
}

int64_t Arbol::numNodos() const
{
  return this->numElementos;
}
