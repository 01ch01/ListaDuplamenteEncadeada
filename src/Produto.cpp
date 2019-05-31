// by ch
#include "../include/Produto.h"

Produto::Produto() {
  this->id = 0;
  this->nome = "empty";
  this->pc = 0.0;
  this->pv = 0.0;
  this->qtd = 0;
}

void Produto::setQtd(int qtd) {
  this->qtd = qtd;
}

int Produto::getQtd() const {
  return qtd;
}

void Produto::setPv(float pv) {
  this->pv = pv;
}

float Produto::getPv() const {
  return pv;
}

void Produto::setPc(float pc) {
  this->pc = pc;
}

float Produto::getPc() const {
  return pc;
}

void Produto::setNome(string nome) {
  this->nome = nome;
}

string Produto::getNome() const {
  return nome;
}

void Produto::setId(int id) {
  this->id = id;
}

int Produto::getId() const {
  return id;
}

Produto::Produto(const Produto& p) {
  this->id = p.getId();
  this->nome = p.getNome();
  this->pc = p.getPc();
  this->pv = p.getPv();
  this->qtd = p.getQtd();
}

Produto::~Produto() {}

void Produto::fill() {
  cout << "\n\t\tINSERINDO DADOS SOBRE O PRODUTO\n";
  cout << "\tID: ";
  cin >> this->id;
  cout << "\tNome: ";
  cin >> this->nome;
  cout << "\tPreço de custo: R$";
  cin >> this->pc;
  cout << "\tPreço de venda: R$";
  cin >> this->pv;
  cout << "\tEstoque: ";
  cin >> this->qtd;
  cout << "\n";
}

void Produto::copy(Produto p) {
  this->id = p.getId();
  this->nome = p.getNome();
  this->pc = p.getPc();
  this->pv = p.getPv();
  this->qtd = p.getQtd();
}

void Produto::print() {
  cout << "\n\tID: " << this->id << "\n\tNome: " << this->nome
       << "\n\tPreço de custo: R$" << this->pc << "\n\tPreço de venda: R$"
       << this->pv << "\n\tEstoque: " << this->qtd << " unidades.\n";
  cout << "\t=============================\n";
}

void Produto::fillRandom(int i) {
  srand(i);
  this->id = rand() % 9999;
  this->nome = "Produto_" + to_string(i + 1);
  this->qtd = rand() % 99;
}
