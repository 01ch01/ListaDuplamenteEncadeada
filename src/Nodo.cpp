// by ch
#include "../include/Nodo.h"

Nodo::Nodo() {
  this->ant = NULL;
  this->prox = NULL;
}

Nodo::Nodo(Produto& p) {
  this->item.copy(p);
  this->prox = NULL;
}

Nodo::Nodo(const Nodo& orig) {
  this->item.copy(orig.GetItem());
}

Nodo::~Nodo() {}

void Nodo::SetItem(Produto item) {
  this->item = item;
}

Produto Nodo::GetItem() const {
  return item;
}

void Nodo::SetAnt(Nodo* ant) {
  this->ant = ant;
}

Nodo* Nodo::GetAnt() const {
  return ant;
}

void Nodo::SetProx(Nodo* prox) {
  this->prox = prox;
}

Nodo* Nodo::GetProx() const {
  return prox;
}
