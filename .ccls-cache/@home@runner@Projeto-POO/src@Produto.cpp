#include "../includes/Produto.hpp"

Produto::Produto(std::string nome, Categoria categoria, int loteMinimo,
                 int estoqueMinimo, PrecoProduto preco) {
  
  this->nome = nome;
  this->idProduto = this->staticIdProduto + 1;
  this->precos.push_back(&preco);
  this->categoria = categoria;
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
}

Produto::Produto(std::string nome, int loteMinimo, int estoqueMinimo) {
  this->nome = nome;
  this->idProduto = this->staticIdProduto + 1;
  this->loteMinimo = loteMinimo;
  this->estoqueMinimo = estoqueMinimo;
}

Produto::Produto() {
  this->idProduto = this->staticIdProduto + 1;
} // construtor padrão

Produto::~Produto() {} // destrutor

// Getters

std::string Produto::getNome() { return this->nome; }

int Produto::getIdProduto() { return this->idProduto; }

vector<PrecoProduto *> Produto::getPrecos() { return this->precos; }

Categoria Produto::getCategoria() { return this->categoria; }

int Produto::getLoteMinimo() { return this->loteMinimo; }

int Produto::getEstoqueMinimo() { return this->estoqueMinimo; }

// Setters

void Produto::setNome(std::string nome) { this->nome = nome; }

void Produto::setIdProduto(int idProduto) { this->idProduto = idProduto; }

void Produto::setCategoria(Categoria categoria) { this->categoria = categoria; }

void Produto::setLoteMinimo(int loteMinimo) { this->loteMinimo = loteMinimo; }

void Produto::setEstoqueMinimo(int estoqueMinimo) {this->estoqueMinimo = estoqueMinimo;}

// Métodos

void Produto::novoPreco(float precoBase, float percentualVariacao, Data data){
  PrecoProduto* preco = new PrecoProduto(precoBase,percentualVariacao,data);
  this->precos.push_back(preco);
}