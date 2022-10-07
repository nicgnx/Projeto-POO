#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <string>
#include "../includes/Produto.hpp"
#include <map>


class Estoque {
private:
  static Estoque* estoque;
  Estoque() : value_(0){};
  ~Estoque();

  // Atributes
  vector <Produto*> produto;
  map <int idProduto,vector <Lotes*> lote> lotes;
  Estoque* Estoque::estoque = NULL;
public:
  // Operators 
  Estoque(const Estoque&);
  Estoque& operator=(const Estoque&);

//getters
  Produto* getProduto(int idProduto);
  int getQuantidade();
  static Estoque* getInstancia();

//setters
  void setProduto(Produto* produto);
  void setQuantidade(int quantidade);

//Métodos
  vector <int> retiraLotes();
  int  verificaEstoque(int idProduto);
  void cadastraProduto(Estoque* produto);
  void cadastraLote(int idProduto, Lote* lote);
  void solicitaLote();
  void reabasteceEstoqueMinimo(int idProduto);

  
};

Estoque* Estoque::getInstancia(){
  if(this->estoque == NULL){
    this->estoque = new Estoque();
  } return this->estoque;
}


#endif // ESTOQUE_H