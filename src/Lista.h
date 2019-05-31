/*  Essa aqui é a lista duplamente encadeada, ou seja, cada nó agora possui:
 *  Um item;
 *  Um apontador para o próximo nodo;
 *  Um apontador para o nodo anterior.
 */
#include <iostream>
#include <string>
#include "Nodo.h"
#include "Produto.h"
using namespace std;

#ifndef LISTA_H
#define LISTA_H

class Lista {
 public:
  Lista();
  Lista(const Lista& orig);
  virtual ~Lista();

  Nodo* search(int id);
  Nodo* getElemento(int index);

  void insert();    // insere na posição desejada
  void remove();    // remove na posição desejada
  void searchId();  // busca por ID
  Produto* buscar(string nome);

  bool isEmpty();
  void print();
  void shift();

  void setHead(Nodo* head);
  Nodo* getHead() const;
  void setQuant(int quant);
  int getQuant() const;

 private:
  int quant;
  Nodo* head;
};

#endif /* LISTA_H */
