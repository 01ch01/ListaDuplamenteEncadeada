/*  Essa aqui é a lista duplamente encadeada, ou seja, cada nó agora possui:
 *  Um item;
 *  Um apontador para o próximo nodo;
 *  Um apontador para o nodo anterior.
 */

#include "../include/Lista.h"
#include "../include/Nodo.h"

Lista::Lista() {
  this->head = NULL;
  this->quant = 0;
}

void Lista::setHead(Nodo* head) {
  this->head = head;
}

Nodo* Lista::getHead() const {
  return head;
}

void Lista::setQuant(int quant) {
  this->quant = quant;
}

int Lista::getQuant() const {
  return quant;
}

Lista::Lista(const Lista& orig) {}

Lista::~Lista() {}

bool Lista::isEmpty() {
  if (this->quant == 0)
    return true;
  else
    return false;
}

Nodo* Lista::getElemento(int index) {
  Nodo* nodoDesejado = head;

  int i = 1;
  while (i < index && nodoDesejado->GetProx() != NULL) {
    nodoDesejado = nodoDesejado->GetProx();
    i++;
  }
  if (i == index)
    return nodoDesejado;
  else
    return NULL;
}

/*O ALGORITMO DE INSERIR NA POSIÇÃO DESEJADA É:
 * Instancie o item e o nodo;
 * Insira o item no nodo;
 * Encontrar o TRÁS e o FRENTE (N-1 e N);
 * Maaaass...temos um problema aqui
 * Temos que elaborar algoritmos diferentes para cada caso
 * if(quant == 0), ou seja, if(frente == NULL && tras == NULL);
 * if(frente == NULL && tras != NULL), ou seja, se eu quiser inserir na posição
 * subsequente à última; if(frente != NULL && tras == NULL), ou seja, se eu
 * quiser inserir na primeira posição; if(frente != NULL && tras != NULL), ou
 * seja, se eu quiser inserir em uma posição que não seja a primeira nem seja
 * subsequente à última;
 */

void Lista::insert() {
  int index;
  Produto p;                // instanciar produto
  Nodo* novo = new Nodo();  // instanciar nodo

  // p.setNome("Arroz");
  p.fill();          // preencher produto
  novo->SetItem(p);  // inserir produto no nodo

  if (this->isEmpty() == true) {  // INSERINDO NA PRIMEIRA POSIÇÃO
    this->head = novo;
    novo->SetAnt(NULL);
    novo->SetProx(NULL);
    this->quant++;

  } else {
    do {
      cout << "\n\tEm qual posição (NÃO É ÍNDICE, ou seja, não pode ser zero) "
              "deseja inserir o nodo? ";
      cin >> index;
      if (index > this->quant + 1)
        cout << "\n\tERRO! Posição inválida. Insira um número menor\n";
      else if (index < 1)
        cout << "\n\tERRO! Posição inválida. Insira um número maior.\n";
    } while (index < 1 || index > this->quant + 1);

    // agora vou instanciar o FRENTE e o  TRÁS
    Nodo* frente = this->getElemento(index);
    Nodo* tras = this->getElemento(index - 1);

    // agora vou "entortar" as setas para elas apontarem para os lugares certos,
    // de acordo com a escolha do usuário É HORA DOS DESENHOS!!!

    if (frente == NULL &&
        tras !=
            NULL) {  // ALGORITMO PARA INSERIR NA POSIÇÃO SUBSEQUENTE A ÚLTIMA
      novo->SetAnt(tras);
      novo->SetProx(NULL);
      tras->SetProx(novo);
      this->quant++;

    } else if (frente != NULL &&
               tras == NULL) {  // ALGORITMO PARA INSERIR NA PRIMEIRA POSIÇÃO
                                // (QUANDO A LISTA NÃO ESTIVER VAZIA)
      novo->SetProx(this->head);
      novo->SetAnt(NULL);
      this->head = novo;
      this->quant++;

    } else if (frente != NULL &&
               tras != NULL) {  // POSIÇÃO QUE NÃO SEJA A PRIMEIRA NEM A
                                // SUBSEQUENTE A ÚLTIMA;
      novo->SetAnt(tras);
      novo->SetProx(frente);
      tras->SetProx(novo);
      frente->SetAnt(novo);
      this->quant++;
    }
  }
}

void Lista::print() {
  cout << "\n\t__________________________________";
  cout << "\n\t\t|LISTA DE PRODUTOS|\n";

  if (this->isEmpty() == true)
    cout << "\n\t\tA LISTA ESTÁ VAZIA =(\n";
  else {
    Nodo* p = this->head;
    while (p != NULL) {
      p->GetItem().print();
      p = p->GetProx();
    }
  }
}

void Lista::remove() {  // a regra é: se niguém apontar pra vc, tu é eliminado
  int index;

  if (this->isEmpty() == true)
    cout << "\n\tA LISTA ESTÁ VAZIA\n";

  else {
    do {
      cout << "\n\tQual é a posição (NÃO É ÍNDICE) da lista que deseja "
              "remover? ";
      cin >> index;
      if (index < 1)
        cout << "\n\tERRO! Posição inválida. Favor inserir um número maior.\n";
      if (index > this->quant)
        cout << "\n\tERRO! Posição inválida. Favor inserir um número menor.\n";
    } while (index < 1 || index > this->quant);

    // ALGORITMOS PARA REMOÇÃO
    if (index == 1) {  // remover na primeira posição
      this->head = this->getElemento(
          index + 1);  // a cabeça aponta pro próximo do índice
      this->getElemento(index + 1)->SetAnt(
          NULL);  // o anterior do índice aponta pro NULO
      this->quant--;

    } else if (index == this->quant) {  // remover na última posição
      this->getElemento(index - 1)->SetProx(NULL);  // o anterior aponta pro
                                                    // NULO
      this->quant--;

    } else {  //é só parar de apontar pra ele que tá tranquilo
      this->getElemento(index - 1)->SetProx(this->getElemento(index + 1));
      this->getElemento(index + 1)->SetAnt(this->getElemento(index - 1));
      this->quant--;
    }
  }
}

void Lista::shift() {
  Produto p;
  int indexUm, indexDois;

  cout << "\n\tVou trocar o produto da posição...? ";
  cin >> indexUm;
  cout << "\n\tCom o produto da posição...? ";
  cin >> indexDois;

  this->getElemento(indexUm)->GetItem();

  p = this->getElemento(indexUm)->GetItem();  // fiz um bkp
  this->getElemento(indexUm)->SetItem(
      this->getElemento(indexDois)->GetItem());  // coloquei o dois dentro do um
  this->getElemento(indexDois)->SetItem(p);  // e coloco o bkp dentro do dois
}
