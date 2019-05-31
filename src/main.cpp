// by ch
#include <iostream>
#include <string>
#include "../include/Lista.h"
#include "../include/Nodo.h"
#include "../include/Produto.h"
using namespace std;

/*Funções que estão prontas:
 * Inserir na posição (NÃO É ÍNDICE, então não pode ser zero)
 * Trocar os nodos de lugar
 * Imprimir
 */

int main(int argc, char** argv) {
  Lista cadastro;
  // 5 inserções
  cadastro.insert();
  cadastro.insert();
  cadastro.insert();
  cadastro.insert();
  cadastro.insert();
  cadastro.print();
  cadastro.shift();
  cadastro.print();
  return 0;
}
