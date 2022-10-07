#include "../includes/Estoque.hpp"


Estoque::~Estoque(){}

//getters

Produto* Estoque::getProduto (int idProduto){
  Produto* produto = this->produto.find(idProduto);
  if (produto == this->produto.end()){throw ("Esse produto não existe!");}
  else{return produto;}
}

Lote* Estoque::getLote(int idProduto, int idLote){
  for(int num = 0;num < this->lotes[idProduto].size(); num++){ 
    if (this->lotes[idProduto][num]->getIdLote() == idLote){
      return this->lotes[idProduto][num];
    }
  } throw("Esse lote não existe!");
}

//Métodos

vector <int> Estoque::retiraLotes(int idProduto,int quantidade){
  vector <int> lotes;
  int aux,num = 0;
  for (;num < this->lotes[idProduto].size();num++){
    aux = this->lotes[idProduto][num]->getQuantidade();
    if(aux >= quantidade){
      aux = aux - quantidade;
      this->lotes[idProduto][num]->setQuantidade(aux);
      lotes.push_back(this->lotes[idProduto][num]->getIdLote());
      return lotes;
    }else{
      quantidade = quantidade - aux;
      this->lotes[idProduto][num]->setQuantidade(0);
      lotes.push_back(this->lotes[idProduto][num]->getIdLote());
    }
  }throw ("Não era nem pra essa compra ter sido aprovada! Vai ficar sem produto...")
}

int Estoque::verificaEstoque(int idProduto){
  int estoqueDisponivel
  for(int num = 0;num < this->lotes[idProduto].size();num++){
    estoqueDisponivel += this->lotes[idProduto][num]->getQuantidade();
  } return estoqueDisponivel;
}

void Estoque::reabasteceEstoqueMinimo(Produto* produto){
  if(verificaEstoque(produto->getIdProduto()) <= produto->getEstoqueMinimo()){
    OrdemDeProducao Solicitacao (produto->getNome(),produto->getIdProduto(),Data (2022,10,15,0,0,0),produto->getLoteMinimo());
    Lote lote = Solicitacao.solicitaLote();
    this->lotes[produto->getIdProduto()].push_back(&lote);
  }
}