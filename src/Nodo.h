// by ch
#include "Produto.h"

#include <iostream>
#include <string>
using namespace std;
#ifndef NODO_H
#define NODO_H

class Nodo {
 public:
  Nodo();
  Nodo(Produto& p);
  Nodo(const Nodo& orig);
  virtual ~Nodo();

  void SetItem(Produto item);
  Produto GetItem() const;
  void SetAnt(Nodo* ant);
  Nodo* GetAnt() const;
  void SetProx(Nodo* prox);
  Nodo* GetProx() const;

 private:
  Produto item;
  Nodo* prox;
  Nodo* ant;
};

#endif /* NODO_H */
