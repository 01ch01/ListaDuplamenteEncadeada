// by ch
#include <iostream>
#include <string>
using namespace std;
#ifndef PRODUTO_H
#define PRODUTO_H

class Produto {
 public:
  Produto();
  Produto(const Produto& orig);
  virtual ~Produto();

  void print();
  void fill();
  void fillRandom(int i);
  void copy(Produto p);

  void setQtd(int qtd);
  int getQtd() const;
  void setPv(float pv);
  float getPv() const;
  void setPc(float pc);
  float getPc() const;
  void setNome(string nome);
  string getNome() const;
  void setId(int id);
  int getId() const;

 private:
  string nome;
  float pc, pv;
  int qtd, id;
};

#endif /* PRODUTO_H */
