#include "../includes/Estoque.hpp"


Estoque::Estoque(){}
Estoque::~Estoque() {}
Estoque* Estoque::estoque = NULL;

// getters
Estoque* Estoque::getInstancia(){
  if(estoque == NULL){
  estoque = new Estoque();
  } return estoque;
}

std::map <int,Produto*> Estoque::getListaDeProdutos(){
  return this->produto;
}

Produto* Estoque::getProduto(int idProduto) {
  std::map<int, Produto *>::iterator produto = this->produto.find(idProduto);
  if (produto == this->produto.end()) {
    throw("Esse produto não existe!");
  } else {
    return this->produto[idProduto];
  }
}

Lote* Estoque::getLote(int idProduto, int idLote) {
  for (int num = 0; num < this->lotes[idProduto].size(); num++) {
    if (this->lotes[idProduto][num]->getIdLote() == idLote) {
      return this->lotes[idProduto][num];
    }
  }
  throw("Esse lote não existe!");
}

// Métodos

vector<int> Estoque::retiraLotes(int idProduto, int quantidade) {
  vector<int> lotes;
  int aux, num = 0;
  for (; num < this->lotes[idProduto].size(); num++) {
    aux = this->lotes[idProduto][num]->getQuantidade();
    if (aux >= quantidade) {
      aux = aux - quantidade;
      this->lotes[idProduto][num]->setQuantidade(aux);
      lotes.push_back(this->lotes[idProduto][num]->getIdLote());
      return lotes;
    } else {
      quantidade = quantidade - aux;
      this->lotes[idProduto][num]->setQuantidade(0);
      lotes.push_back(this->lotes[idProduto][num]->getIdLote());
    }
  }
  throw("Não era nem pra essa compra ter sido aprovada! Vai ficar sem "
        "produto...");
}

int Estoque::verificaEstoque(int idProduto) {
  int estoqueDisponivel;
  for (int num = 0; num < this->lotes[idProduto].size(); num++) {
    estoqueDisponivel += this->lotes[idProduto][num]->getQuantidade();
  }
  return estoqueDisponivel;
}

void Estoque::reabasteceEstoque(int idProduto) {
  if (verificaEstoque(idProduto) <=
      this->produto[idProduto]->getEstoqueMinimo()) {
    OrdemDeProducao Solicitacao(this->produto[idProduto]->getNome(), idProduto,
                                Data(2022, 10, 15, 0, 0, 0),
                                this->produto[idProduto]->getLoteMinimo());
    this->lotes[idProduto].push_back(Solicitacao.solicitaLote());

  } else {throw("O estoque minímo ainda não foi atingido");}
}

void Estoque::reabasteceEstoque(int idProduto, int quantidade) {
  if (quantidade >= this->produto[idProduto]->getLoteMinimo()) {
    OrdemDeProducao Solicitacao(this->produto[idProduto]->getNome(), idProduto,
                                Data(2022, 10, 15, 0, 0, 0), quantidade);
    this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
  } else {
    throw("A quantidade solicitada é menor que o minímo permitido.");
  }
}

void Estoque::cadastraLote(int idProduto, Lote *lote) {
  this->lotes[idProduto].push_back(lote);
}

void Estoque::cadastraProduto(std::string nome, int loteMinimo,
                              int estoqueMinimo) {
  Produto *produto = new Produto(nome, loteMinimo, estoqueMinimo);
  this->produto[produto->getIdProduto()] = produto;
}

void Estoque::printListaDeProdutos(){
  for(std::map<int,Produto*>::iterator it=produto.begin(); it!=produto.end(); ++it){
    std::cout << "Produto: " << this->produto[it->first]->getNome() << "     ID: " << this->produto[it->first]->getIdProduto() << "     Quantidade: " << verificaEstoque(this->produto[it->first]->getIdProduto()) << "\n";
  }
}