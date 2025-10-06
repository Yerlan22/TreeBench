#include "Arbol_ArrPadre.hpp"

Arbol::Arbol()
{
  this->numElementos = 0;
  this->raizIndice = nullptr;
}

Arbol::~Arbol()
{
  this->vaciar();
}

void Arbol::vaciar()
{
  this->numElementos = 0;
  raizIndice = nullptr;
}

bool Arbol::vacio()
{
  return this->numElementos == 0;
}

void Arbol::ponerRaiz(int elemento)
{
  this->nodos[numElementos].etiqueta = elemento;
  this->nodos[numElementos].indicePadre = nullptr;
  this->nodos[numElementos].siguiente = nullptr;
  this->nodos[numElementos].hermanoDer = nullptr;
  this->raizIndice = &nodos[numElementos];
  this->numElementos++;
}

Nodo *Arbol::agregarHijo(Nodo *nodo, int elemento, int pos)
{
  if (pos <= 0 || pos > numHijos(nodo) + 1)
  {
    return nullptr;
  }

  Nodo *nuevoHijo = &nodos[numElementos];
  nuevoHijo->etiqueta = elemento;
  nuevoHijo->indicePadre = nodo;
  nuevoHijo->siguiente = nodo;
  nuevoHijo->siguiente = nullptr;
  nuevoHijo->hermanoDer = nullptr;

  if (pos == 1)
  {
    if (nodo)
    {
      nuevoHijo->hermanoDer = nodo->siguiente;
      nodo->siguiente = nuevoHijo;
    }
  }
  else
  {
    Nodo *actual = nodo->siguiente;
    for (int i = 1; i < pos - 1; i++)
    {
      actual = actual->hermanoDer;
    }
    nuevoHijo->hermanoDer = actual->hermanoDer;
    actual->hermanoDer = nuevoHijo;
  }
  numElementos++;
  return nuevoHijo;
}

void Arbol::borrarNodoHoja(Nodo *nodo)
{
  Nodo *indicePadre = nodo->indicePadre;
  if (indicePadre != nullptr)
  {
    if (indicePadre->siguiente == nodo)
    {
      indicePadre->siguiente = nodo->hermanoDer;
    }
    else
    {
      Nodo *aux = indicePadre->siguiente;
      while (aux->hermanoDer != nodo)
      {
        aux = aux->hermanoDer;
      }
      aux->hermanoDer = nodo->hermanoDer;
    }
  }
  else
  {
    this->raizIndice = nodo->hermanoDer;
  }
  nodo->etiqueta = -1;
  nodo->indicePadre = nullptr;
  nodo->siguiente = nullptr;
  nodo->hermanoDer = nullptr;
  this->numElementos--;
}

void Arbol::modificarEtiqueta(Nodo *nodo, int elemento)
{
  if (nodo != nullptr)
  {
    nodo->etiqueta = elemento;
  }
}

Nodo *Arbol::raiz()
{
  return this->raizIndice;
}

Nodo *Arbol::hijo(Nodo *nodo, int elemento)
{
  if (nodo)
  {
    if (nodo->siguiente != nullptr)
    {
      Nodo *actual = nodo->siguiente;
      while (actual != nullptr)
      {
        if (actual->etiqueta == elemento)
        {
          return actual;
        }
        actual = actual->hermanoDer;
      }
    }
  }
  return nullptr;
}

Nodo *Arbol::padre(Nodo *nodo)
{
  if (nodo != nullptr)
  {
    return nodo->indicePadre;
  }
  return nullptr;
}

Nodo *Arbol::hermanoDer(Nodo *nodo)
{
  if (nodo->hermanoDer != nullptr)
  {
    return nodo->hermanoDer;
  }
  return nullptr;
}

Nodo *Arbol::hijoMasIzq(Nodo *nodo)
{
  if (nodo->siguiente != nullptr)
  {
    return nodo->siguiente;
  }
  return nullptr;
}

int Arbol::etiqueta(Nodo *nodo)
{
  return nodo->etiqueta;
}

int Arbol::numHijos(Nodo *nodo)
{
  int contador = 0;
  Nodo *actual = nullptr;
  if (nodo)
  {
    actual = nodo->siguiente;
  }
  while (actual != nullptr)
  {
    contador++;
    actual = actual->hermanoDer;
  }
  return contador;
}

int Arbol::numNodos()
{
  return this->numElementos;
}
