// Algoritmo de busqueda para el arbol lista de hijos.
// #define ALG_BUSQUEDA_ALH
// Algoritmo de busqueda para el arbol hijo más izquierdo-hermano derecho.
// #define ALG_BUSQUEDA_AHMI_HD
// Algoritmo de busqueda para el arbol ultimo ptr al padre.
// #define ALG_BUSQUEDA_AUPP
// Algoritmo de busqueda para el arbol arreglo con señalador al padre.
#define ALG_BUSQUEDA_AARP
#define _DEFAULT_SOURCE

#include "Cola.hpp"
// #include "ALH.hpp"
// #include "Arb_UltPtrP.hpp"
// #include "Arbol_HMI_HD.hpp"
#include "Arbol_ArrPadre.hpp"

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <chrono>
#include <time.h>

// Muestra las opciones principales.
void mostrarOpciones();
// Muestra las opciones para el árbol.
void mostrarOpcionesArbol();
// Muestra las opciones para el cálculo de tiempo de ejecución.
void mostrarOpcionesTiempoEjecucion();
// Muestra las opciones para la Cola.
void mostrarOpcionesCola();
// LLama a los OB de la Cola.
void ColaOperadorBasico(size_t opcion, bool &repetir, Cola *cola);
// Llama a los OB y algoritmos de los árboles.
void ArbolOperadorBasico(size_t opcion, bool &repetir, Arbol *arbol, Arbol *arbolCopia, Nodo *nodo);
// Llama a los OB y algoritmos de los árboles y cálcula su tiempo de duración.
void opcionesTiempoEjecucion(size_t opcion, bool &repetir, Arbol *arbol, Arbol *arbolCopia, Nodo *nodo);
// Permite al usuario ingresar una etiqueta.
int64_t ingresarEtiqueta();
// Busca un nodo en base a la etiqueta que ingresa el usuario.
Nodo *buscarNodo(Arbol *arbol, int64_t etiqueta);
// Algoritmo que busca si existen etiquetas repetidas en un árbol.
bool etiquetaRep(Arbol *arb);
// Algoritmo que copia un árbol.
void copiarArb(Arbol *arbUno, Arbol *arbDos);
// Algoritmo que verifica si dos árboles son iguales.
bool arbIguales(Arbol *arbUno, Arbol *arbDos);
// Algoritmo que obtiene la profundidad de un Nodo.
int obtenerProfundidadNodo(Nodo *nodo, Arbol *arb);
// Algoritmo que obtiene la altura de un árbol.
int alturaNodo(Nodo *nodo, Arbol *arb);
// Algoritmo que verifica si una etiqueta esta o no en un árbol.
bool estaEtiqueta(int etiqueta, Nodo *nodo, Arbol *arbol);
// Algoritmo que enlista a los hermanos de un nodo.
std::vector<int> listaDeHermanos(Nodo *nodo, Arbol *arbol);
// Algoritmo que enlista a las etiquetas de los nodos de un nivel de un árbol.
std::vector<int> listaDeEtiquetas(int64_t numNivel, Arbol *arbol);
// Algoritmo que retorna el número de niveles de un arbol.
int64_t numNiveles(Arbol *arbol);
// Algoritmo que crea un árbol con n nodos.
Nodo *crearArbol(Arbol *arbol, std::vector<int> lista, int numElem);

int main()
{
  Cola *cola = new Cola();
  Arbol *arbol = new Arbol();
  Arbol *arbolCopia = new Arbol();

  Nodo *nodoAux = nullptr;
  mostrarOpciones();
  int64_t opcion = 0;
  std::cin >> opcion;
  bool repetir = true;
  if (opcion == 1)
  {
    while (repetir)
    {
      mostrarOpcionesCola();
      std::cin >> opcion;
      ColaOperadorBasico(opcion, repetir, cola);
    }
  }
  else if (opcion == 2)
  {
    while (repetir)
    {
      mostrarOpcionesArbol();
      std::cin >> opcion;
      ArbolOperadorBasico(opcion, repetir, arbol, arbolCopia, nodoAux);
    }
  }
  else if (opcion == 3)
  {
    while (repetir)
    {
      mostrarOpcionesTiempoEjecucion();
      std::cin >> opcion;
      opcionesTiempoEjecucion(opcion, repetir, arbol, arbolCopia, nodoAux);
    }
  }
  return EXIT_SUCCESS;
}

void mostrarOpcionesTiempoEjecucion()
{
  std::cout << "----------------------" << std::endl;
  std::cout << "Tempo de ejecución:" << std::endl;
  std::cout << "1.  vaciar()" << std::endl;
  std::cout << "2.  padre()" << std::endl;
  std::cout << "3.  listaDeEtiquetas()" << std::endl;
  std::cout << "4.  numNiveles()" << std::endl;
  std::cout << "5.  copiarArbol()" << std::endl;
  std::cout << "6.  arbIguales()" << std::endl;
  std::cout << "0.  salir()" << std::endl;
  std::cout << "----------------------" << std::endl;
}

void mostrarOpcionesArbol()
{
  std::cout << "----------------------" << std::endl;
  std::cout << "1.  Vaciar()" << std::endl;
  std::cout << "2.  Vacio()" << std::endl;
  std::cout << "3.  AgregarHijo()" << std::endl;
  std::cout << "4.  BorrarNodoHoja()" << std::endl;
  std::cout << "5.  PonerRaíz()" << std::endl;
  std::cout << "6.  ModificarEtiqueta()" << std::endl;
  std::cout << "7.  HijoMásIzq()" << std::endl;
  std::cout << "8.  HermanoDer()" << std::endl;
  std::cout << "9.  Raíz()" << std::endl;
  std::cout << "10. Padre()" << std::endl;
  std::cout << "11. Etiqueta()" << std::endl;
  std::cout << "12. NumHijos()" << std::endl;
  std::cout << "13. Hijo()" << std::endl;
  std::cout << "14. NumNodos()" << std::endl;
  std::cout << "15. listaDeHermanos()" << std::endl;
  std::cout << "16. listaDeEtiquetas()" << std::endl;
  std::cout << "17. numNiveles()" << std::endl;
  std::cout << "18. etiquetaRepetida()" << std::endl;
  std::cout << "19. copiarArbol()" << std::endl;
  std::cout << "20. arbIguales()" << std::endl;
  std::cout << "21. obtenerProfundidadNodo()" << std::endl;
  std::cout << "22. alturaNodo()" << std::endl;
  std::cout << "23. estaEtiqueta()" << std::endl;
  std::cout << "0.  salir()" << std::endl;
  std::cout << "----------------------" << std::endl;
}

void mostrarOpcionesCola()
{
  std::cout << "----------------------" << std::endl;
  std::cout << "1. Vaciar()" << std::endl;
  std::cout << "2. Vacio()" << std::endl;
  std::cout << "3. Agregar()" << std::endl;
  std::cout << "4. Sacar()" << std::endl;
  std::cout << "5. Frente()" << std::endl;
  std::cout << "0. salir()" << std::endl;
  std::cout << "----------------------" << std::endl;
}

void mostrarOpciones()
{
  std::cout << "1. Cola" << std::endl;
  std::cout << "2. Arbol" << std::endl;
  std::cout << "3. Tiempos de ejecución" << std::endl;
  std::cout << "0. salir" << std::endl;
}

void opcionesTiempoEjecucion(size_t opcion, bool &repetir, Arbol *arbol, Arbol *arbolCopia, Nodo *nodo)
{

  using namespace std::chrono;

  std::cout << "Ïngrese el número de elementos del árbol" << std::endl;
  int num = 0;
  std::cin >> num;
  // Se crea una lista con n elementos.
  std::vector<int> lista;
  for (int i = 1; i <= num; ++i)
  {
    lista.push_back(i);
  }
  // Se crea el árbol en base a los elementos de la lista.
  std::cout << "Ingrese el número de hijos por nodo" << std::endl;
  std::cin >> num;
  Nodo *n = crearArbol(arbol, lista, num);
  if (opcion == 0)
  {
    repetir = false;
  }
  else
  {
    std::cout << "El tiempo en nanosegundos es:" << std::endl;
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    if (opcion == 1)
    {
      t1 = high_resolution_clock::now();
      arbol->vaciar();
      t2 = high_resolution_clock::now();
    }
    else if (opcion == 2)
    {
      t1 = high_resolution_clock::now();
      arbol->padre(n);
      t2 = high_resolution_clock::now();
    }
    else if (opcion == 3)
    {
      t1 = high_resolution_clock::now();
      listaDeHermanos(arbol->hijoMasIzq(arbol->raiz()), arbol);
      t2 = high_resolution_clock::now();
    }
    else if (opcion == 4)
    {
      t1 = high_resolution_clock::now();
      numNiveles(arbol);
      t2 = high_resolution_clock::now();
    }
    else if (opcion == 5)
    {
      t1 = high_resolution_clock::now();
      copiarArb(arbol, arbolCopia);
      t2 = high_resolution_clock::now();
    }
    else if (opcion == 6)
    {
      crearArbol(arbolCopia, lista, num);
      t1 = high_resolution_clock::now();
      arbIguales(arbol, arbolCopia);
      t2 = high_resolution_clock::now();
    }
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << time_span.count() << std::endl;
    if (!arbol->vacio())
    {
      arbol->vaciar();
    }
    if (!arbolCopia->vacio())
    {
      arbolCopia->vaciar();
    }
  }
}

void ColaOperadorBasico(size_t opcion, bool &repetir, Cola *cola)
{
  if (opcion == 0)
  {
    repetir = false;
  }
  else if (opcion == 1)
  {
    cola->Vaciar();
  }
  else if (opcion == 2)
  {
    cola->Vacia() ? std::cout << "La cola esta vacia" << std::endl
                  : std::cout << "La cola no esta vacia" << std::endl;
  }
  else if (opcion == 3)
  {
    cola->Agregar(ingresarEtiqueta());
  }
  else if (opcion == 4)
  {
    cola->Sacar();
  }
  else if (opcion == 5)
  {
    std::cout << cola->Frente() << std::endl;
  }
  else
  {
    std::cout << "Opción invalida" << std::endl;
  }
}

int obtenerProfundidadNodo(Nodo *nodo, Arbol *arb)
{
  if (nodo == nullptr)
  {
    return -1;
  }
  std::queue<Nodo *> cola;
  cola.push(arb->raiz());
  int profundidad = 0;
  while (!cola.empty())
  {
    int nodos = cola.size();
    for (int i = 0; i < nodos; i++)
    {
      Nodo *actual = cola.front();
      cola.pop();

      if (actual == nodo)
      {
        return profundidad;
      }
      Nodo *hijo = arb->hijoMasIzq(actual);

      while (hijo != nullptr)
      {
        cola.push(hijo);
        hijo = arb->hermanoDer(hijo);
      }
    }
    profundidad = profundidad + 1;
  }
  return -1;
}

void ArbolOperadorBasico(size_t opcion, bool &repetir, Arbol *arbol, Arbol *arbolCopia, Nodo *nodo)
{
  // llama a los O.B de las ED
  if (opcion == 0)
  {
    repetir = false;
  }
  else if (opcion == 1)
  {
    arbol->vaciar();
  }
  else if (opcion == 2)
  {
    if (arbol->vacio())
    {
      std::cout << "El arbol esta vacio" << std::endl;
    }
    else
    {
      std::cout << "El arbol no esta vacio" << std::endl;
    }
  }
  else if (opcion == 3)
  {
    int64_t etiqueta = ingresarEtiqueta();
    int64_t nuevaEtiqueta = 0;
    std::cout << "Ingrese la nueva etiqueta" << std::endl;
    std::cin >> nuevaEtiqueta;

    int64_t pos = 0;
    std::cout << "Ingrese la posicion de la nueva etiqueta" << std::endl;
    std::cin >> pos;

    arbol->agregarHijo(buscarNodo(arbol, etiqueta), nuevaEtiqueta, pos);
  }
  else if (opcion == 4)
  {
    arbol->borrarNodoHoja(buscarNodo(arbol, ingresarEtiqueta()));
  }
  else if (opcion == 5)
  {
    arbol->ponerRaiz(ingresarEtiqueta());
  }
  else if (opcion == 6)
  {
    int64_t etiqueta = ingresarEtiqueta();
    int64_t nuevaEtiqueta = 0;
    std::cout << "Ingrese la nueva etiqueta" << std::endl;
    std::cin >> nuevaEtiqueta;
    arbol->modificarEtiqueta(buscarNodo(arbol, etiqueta), nuevaEtiqueta);
  }
  else if (opcion == 7)
  {
    std::cout << arbol->hijoMasIzq(buscarNodo(arbol, ingresarEtiqueta()))->etiqueta << std::endl;
  }
  else if (opcion == 8)
  {
    std::cout << arbol->hermanoDer(buscarNodo(arbol, ingresarEtiqueta()))->etiqueta << std::endl;
  }
  else if (opcion == 9)
  {
    std::cout << arbol->raiz()->etiqueta << std::endl;
  }
  else if (opcion == 10)
  {
    std::cout << arbol->padre(buscarNodo(arbol, ingresarEtiqueta()))->etiqueta << std::endl;
  }
  else if (opcion == 11)
  {
    std::cout << arbol->etiqueta(buscarNodo(arbol, ingresarEtiqueta())) << std::endl;
  }
  else if (opcion == 12)
  {
    std::cout << arbol->numHijos(buscarNodo(arbol, ingresarEtiqueta())) << std::endl;
  }
  else if (opcion == 13)
  {
    int etiqueta = ingresarEtiqueta();
    int pos = 0;
    std::cout << "Ingrese la posición del hijo" << std::endl;
    std::cin >> pos;
    std::cout << arbol->hijo(buscarNodo(arbol, etiqueta), pos)->etiqueta << std::endl;
  }
  else if (opcion == 14)
  {
    std::cout << arbol->numNodos() << std::endl;
  }
  else if (opcion == 15)
  {
    for (int index = 0; index < listaDeHermanos(buscarNodo(arbol, ingresarEtiqueta()), arbol).size(); ++index)
    {
      std::cout << listaDeHermanos(buscarNodo(arbol, ingresarEtiqueta()), arbol)[index] << std::endl;
    }
  }
  else if (opcion == 16)
  {
    int nivel = 0;
    std::cout << "Ingrese el nivel del árbol" << std::endl;
    std::cin >> nivel;
    for (int index = 0; index < listaDeEtiquetas(nivel, arbol).size(); ++index)
    {
      std::cout << listaDeEtiquetas(nivel, arbol)[index] << std::endl;
    }
  }
  else if (opcion == 17)
  {
    std::cout << numNiveles(arbol) << std::endl;
  }
  else if (opcion == 18)
  {
    etiquetaRep(arbol) ? std::cout << "La etiqueta esta repetida" << std::endl
                       : std::cout << "La etiqueta no esta repetida" << std::endl;
  }
  else if (opcion == 19)
  {
    copiarArb(arbol, arbolCopia);
  }
  else if (opcion == 20)
  {
    arbIguales(arbol, arbolCopia) ? std::cout << "Los arboles son iguales"
                                              << std::endl
                                  : std::cout << "Los arboles no son iguales" << std::endl;
  }
  else if (opcion == 21)
  {
    std::cout << obtenerProfundidadNodo(buscarNodo(arbol, ingresarEtiqueta()), arbol) << std::endl;
  }
  else if (opcion == 22)
  {
    std::cout << alturaNodo(buscarNodo(arbol, ingresarEtiqueta()), arbol)
              << std::endl;
  }
  else if (opcion == 22)
  {
    estaEtiqueta(ingresarEtiqueta(), arbol->raiz(), arbol) ? std::cout
                                                                 << "La etiqueta si se encuentra en el arbol" << std::endl
                                                           : std::cout << "La etiqueta no se encuentra en el árbol" << std::endl;
  }
  else
  {
    std::cout << "Opción invalida" << std::endl;
  }
}

int64_t ingresarEtiqueta()
{
  std::cout << "Ingrese la etiqueta" << std::endl;
  int64_t etiqueta = 0;
  std::cin >> etiqueta;
  return etiqueta;
}

void numNivelesR(Nodo *nodo, int nivel, int64_t &resultado, Arbol *arbol)
{
  Nodo *n1 = nodo->siguiente;
  nivel++;
  int result = nivel;
  while (n1)
  {
    numNivelesR(n1, nivel, resultado, arbol);
    n1 = arbol->hermanoDer(n1);
  }
  if (nivel >= resultado)
  {
    resultado = nivel;
  }
}

int64_t numNiveles(Arbol *arbol)
{
  int64_t resultado = 0;
  if (!arbol->vacio())
  {
    numNivelesR(arbol->raiz(), 0, resultado, arbol);
  }
  return resultado;
}

std::vector<int> listaDeEtiquetas(int64_t numNivel, Arbol *arbol)
{
  std::vector<int> etiquetas;
  std::queue<Nodo *> Cola;
  Cola.push(arbol->raiz());
  int contador = 0;
  if (numNivel == 0)
  {
    etiquetas.push_back(arbol->raiz()->etiqueta);
    return etiquetas;
  }
  while (!Cola.empty())
  {
    Nodo *n = Cola.front();
    Cola.pop();
    Nodo *n1 = n->siguiente;
    ++contador;
    while (n1)
    {
      Cola.push(n1);
      if (contador == numNivel)
      {
        etiquetas.push_back(n1->etiqueta);
      }
      n1 = arbol->hermanoDer(n1);
    }
  }
  return etiquetas;
}

std::vector<int> listaDeHermanos(Nodo *nodo, Arbol *arbol)
{
  std::vector<int> hermanos;
  Nodo *nodoAux = arbol->hermanoDer(nodo);
  while (nodoAux)
  {
    hermanos.push_back(nodoAux->etiqueta);
    nodoAux = arbol->hermanoDer(nodoAux);
  }
  return hermanos;
}

bool estaEtiqueta(int etiqueta, Nodo *nodo, Arbol *arb)
{
  if (nodo == nullptr)
  {
    return false;
  }
  if (arb->etiqueta(nodo) == etiqueta)
  {
    return true;
  }
  Nodo *hijo = arb->hijoMasIzq(nodo);
  while (hijo != nullptr)
  {
    if (estaEtiqueta(etiqueta, hijo, arb))
    {
      return true;
    }
    hijo = arb->hermanoDer(hijo);
  }
  return false;
}

int alturaNodo(Nodo *nodo, Arbol *arb)
{
  if (nodo == nullptr)
  {
    return -1;
  }
  if (arb->hijoMasIzq(nodo) == nullptr)
  {
    return 0;
  }
  int altura = 0;
  Nodo *hijo = arb->hijoMasIzq(nodo);
  while (hijo != nullptr)
  {
    int alturaHijo = alturaNodo(hijo, arb);
    if (alturaHijo + 1 > altura)
    {
      altura = alturaHijo + 1;
    }
    hijo = arb->hermanoDer(hijo);
  }
  return altura;
}

bool arbIguales(Arbol *arbUno, Arbol *arbDos)
{
  bool iguales = true;
  if (arbUno->numNodos() != arbDos->numNodos())
  {
    return false;
  }
  else if (arbUno->raiz()->etiqueta != arbDos->raiz()->etiqueta)
  {
    return false;
  }
  else
  {
    std::queue<Nodo *> cArbUno, cArbDos;
    cArbUno.push(arbUno->raiz());
    cArbDos.push(arbDos->raiz());
    while (!cArbUno.empty() && iguales)
    {
      // Tipo nodo?
      Nodo *nodUno = cArbUno.front();
      cArbUno.pop();
      Nodo *nodDos = cArbDos.front();
      cArbDos.pop();
      if (arbUno->numHijos(nodUno) != arbDos->numHijos(nodDos))
      {
        iguales = false;
      }
      else
      {
        Nodo *nodHijoUno = arbUno->hijoMasIzq(nodUno);
        Nodo *nodHijoDos = arbDos->hijoMasIzq(nodDos);
        while (nodHijoUno != nullptr && iguales)
        {
          if (arbUno->etiqueta(nodHijoUno) != arbDos->etiqueta(nodHijoDos))
          {
            iguales = false;
          }
          else
          {
            cArbUno.push(nodHijoUno);
            cArbDos.push(nodHijoDos);
            nodHijoUno = arbUno->hermanoDer(nodHijoUno);
            nodHijoDos = arbDos->hermanoDer(nodHijoDos);
          }
        }
      }
    }
  }
  return iguales;
}

void copiarArb(Arbol *arbUno, Arbol *arbDos)
{
  if (arbUno->numNodos() != 0)
  {
    std::queue<Nodo *> cArbUno, cArbDos;
    arbDos->ponerRaiz(arbUno->raiz()->etiqueta);
    cArbUno.push(arbUno->raiz());
    cArbDos.push(arbDos->raiz());
    while (!cArbUno.empty())
    {
      Nodo *nodUno, *nodDos, *nodHijoUno;
      nodUno = cArbUno.front();
      cArbUno.pop();
      nodDos = cArbDos.front();
      cArbDos.pop();
      nodHijoUno = arbUno->hijoMasIzq(nodUno);
      while (nodHijoUno != nullptr)
      {
        arbDos->agregarHijo(nodDos, arbUno->etiqueta(nodHijoUno), arbDos->numHijos(nodDos) + 1);
        Nodo *nodHijoDos = arbDos->hijo(nodDos, arbDos->numHijos(nodDos));
        cArbUno.push(nodHijoUno);
        cArbDos.push(nodHijoDos);
        nodHijoUno = arbUno->hermanoDer(nodHijoUno);
      }
    }
  }
}

bool etiquetaRep(Arbol *arb)
{
  bool repetido = false;
  std::vector<int> etiquetas;
  int ultLleno = 0;
  if (!arb->vacio())
  {
    std::queue<Nodo *> cArb;
    cArb.push(arb->raiz());
    while (!cArb.empty())
    {
      Nodo *nod = cArb.front();
      cArb.pop();
      int cont = 0;
      etiquetas.push_back(arb->etiqueta(nod));
      ultLleno++;
      int visto = 0;
      while (cont < ultLleno && !repetido)
      {
        if (etiquetas[cont] == arb->etiqueta(nod))
        {
          visto++;
          if (visto >= 2)
          {
            repetido = true;
          }
        }
        cont++;
      }
      Nodo *nodHijo = arb->hijoMasIzq(nod);
      while (nodHijo != nullptr)
      {
        cArb.push(nodHijo);
        nodHijo = arb->hermanoDer(nodHijo);
      }
    }
  }
  return repetido;
}

Nodo *crearArbol(Arbol *arbol, std::vector<int> lista, int numElem)
{

  std::queue<Nodo *> queue;
  int index = 0;
  arbol->ponerRaiz(lista[index]);
  ++index;
  queue.push(arbol->raiz());
  Nodo *np = nullptr;
  Nodo *nh = nullptr;
  while (index + 1 < lista.size())
  {
    np = queue.front();
    queue.pop();
    for (int i = 1; i <= numElem; ++i)
    {
      nh = arbol->agregarHijo(np, lista[index], i);
      queue.push(nh);
      ++index;
    }
  }
  return nh;
}

#ifdef ALG_BUSQUEDA_AHMI_HD
Nodo *buscarNodo(Arbol *arbol, int64_t etiqueta)
{
  std::queue<Nodo *> queue;
  queue.push(arbol->raiz());
  while (!queue.empty())
  {
    Nodo *nodoAux = queue.front();
    queue.pop();
    Nodo *nh = nodoAux->siguiente;
    while (nh)
    {
      queue.push(nh);
      nh = nh->hermanoDer;
    }
    if (nodoAux->etiqueta == etiqueta)
    {
      return nodoAux;
    }
  }
  return nullptr;
}
#endif

#ifdef ALG_BUSQUEDA_AUPP
Nodo *buscarNodo(Arbol *arbol, int64_t etiqueta)
{
  std::queue<Nodo *> queue;
  queue.push(arbol->raiz());
  while (!queue.empty())
  {
    Nodo *nodoAux = queue.front();
    queue.pop();
    Nodo *nh = nodoAux->siguiente;
    while (nh)
    {
      queue.push(nh);
      nh = nh->hermanoDer;
    }
    if (nodoAux->etiqueta == etiqueta)
    {
      return nodoAux;
    }
  }
  return nullptr;
}
#endif

#ifdef ALG_BUSQUEDA_ALH
Nodo *buscarNodo(Arbol *arbol, int64_t etiqueta)
{
  Nodo *nodo = arbol->raiz();
  while (nodo)
  {
    if (nodo->etiqueta == etiqueta)
    {
      return nodo;
    }
    nodo->siguiente;
  }
  return nullptr;
}
#endif

#ifdef ALG_BUSQUEDA_AARP
Nodo *buscarNodo(Arbol *arbol, int64_t etiqueta)
{
  Nodo *nodo = arbol->raiz();
  for (size_t index = 0; index < arbol->numNodos(); ++index)
  {
    if (etiqueta == arbol->nodos[index].etiqueta)
    {
      return &arbol->nodos[index];
    }
  }
  return nullptr;
}
#endif