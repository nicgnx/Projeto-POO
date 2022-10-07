#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <string>
#include "../includes/Produto.hpp"
#include "../includes/OrdemProducao.hpp"
#include <map>
#include <list>


class Estoque {
private:
  static Estoque* estoque;
  Estoque() : value_(0){};
  ~Estoque();

  // Atributes
  std::map <int,Produto*> produto; // Parâmetros: idProduto, Produto
  std::map <int,std::vector<Lotes*>> lotes; // Parâmetros: idProduto, Lote
  std::list <OrdemProducao*> ordensDeProducao;
  Estoque* Estoque::estoque = NULL;
public:
  // Operators 
  Estoque(const Estoque&);
  Estoque& operator=(const Estoque&);

//getters
  Produto* getProduto(int idProduto);
  Lote* getLote(int idProduto, int idLote);
  static Estoque* getInstancia();

//Métodos
  vector <int> retiraLotes(int idProduto,int quantidade);
  int  verificaEstoque(int idProduto);
  void cadastraProduto(std::string nome, int loteMinimo, int estoqueMinimoProduto*);
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