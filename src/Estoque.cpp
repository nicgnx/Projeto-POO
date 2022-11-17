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
    std::cout << "Esse produto não existe!";
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

int Estoque::verificaEstoque(int idProduto) {
  int estoqueDisponivel = 0;
  for (int num = 0; num < this->lotes[idProduto].size(); num++) {
    estoqueDisponivel += this->lotes[idProduto][num]->getQuantidade();
  }
  return estoqueDisponivel;
}

void Estoque::reabasteceEstoque(int idProduto) {
  if (verificaEstoque(idProduto) > this->produto[idProduto]->getEstoqueMinimo()){
    std::cout << "----------------------------------------------------------------------------------------------------\n\n";
    std::cout << "                  Solicitação de Reabastecimento de Estoque não realizada.\n\n"; 
    std::cout << "                  O estoque minímo do produto [ " << this->produto[idProduto]->getNome() << " ] ainda não foi atingido."; 
    std::cout << "\n\n                  Quantidade disponível no estoque: " << verificaEstoque(idProduto);
    std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n";  
  } else{ 
    if(this->produto[idProduto]->getEstoqueMinimo() > this->produto[idProduto]->getLoteMinimo()){
      int aux = this->produto[idProduto]->getEstoqueMinimo() - verificaEstoque(idProduto);
     
      OrdemDeProducao Solicitacao(this->produto[idProduto]->getNome(), idProduto,
                                  Data(2022, 10, 15, 0, 0, 0),
                                  ((aux/this->produto[idProduto]->getLoteMinimo())+1)*this->produto[idProduto]->getLoteMinimo());
      this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
      std::cout << "----------------------------------------------------------------------------------------------------\n\n";
      std::cout << "                  Solicitação de Reabastecimento do Estoque do produto [ " << this->produto[idProduto]->getNome() <<   " ]\n\n";
      std::cout << "                  ID: " << idProduto;
      std::cout << "\n                  Lote: " << lotes[idProduto].back()->getIdLote();
      std::cout << "\n                  Quantidade: " << lotes[idProduto].back()->getQuantidade();;
      std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n";
    } 
    else {
      OrdemDeProducao Solicitacao(this->produto[idProduto]->getNome(), idProduto,
                                   Data(2022, 10, 15, 0, 0, 0),
                                   this->produto[idProduto]->getLoteMinimo());
      this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
      std::cout << "----------------------------------------------------------------------------------------------------\n\n";
      std::cout << "                  Solicitação de Reabastecimento do Estoque do produto  [ " << this->produto[idProduto]->getNome() <<   " ]\n\n";
      std::cout << "                  ID: " << idProduto;
      std::cout << "\n                  Lote: " << lotes[idProduto].back()->getIdLote();
     std::cout << "\n                  Quantidade: " << lotes[idProduto].back()->getQuantidade();;
      std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n"; 
    } 
  }
}

vector<int> Estoque::retiraLotes(int idProduto, int quantidade) {
  vector<int> lotes;
  int aux, num = 0;
  for (; num < this->lotes[idProduto].size(); num++) {
    aux = this->lotes[idProduto][num]->getQuantidade();
    if (aux >= quantidade) {
      aux = aux - quantidade;
      this->lotes[idProduto][num]->setQuantidade(aux);
      lotes.push_back(this->lotes[idProduto][num]->getIdLote());
      reabasteceEstoque(idProduto);
      return lotes;
    } else {
      if((aux == 0) && (this->lotes[idProduto].size() > 1)){
        
      } 
      else {
        quantidade = quantidade - aux;
        this->lotes[idProduto][num]->setQuantidade(0);
        lotes.push_back(this->lotes[idProduto][num]->getIdLote());
      }      
    }
  } std::cout << "Não era nem pra essa compra ter sido aprovada! Vai ficar sem produto..."; return lotes;
}

void Estoque::retiraMateriaPrima (int idMateriaPrima, int quantidade){
  this->lotesMP[idMateriaPrima] = this->lotesMP[idMateriaPrima] - quantidade;
}

void Estoque::reabasteceEstoque(int idProduto, int quantidade) {
  if (quantidade >= this->produto[idProduto]->getLoteMinimo()) {
    OrdemDeProducao Solicitacao(this->produto[idProduto]->getNome(), idProduto,
                                Data(2022, 10, 15, 0, 0, 0), quantidade);
    this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
    std::cout << "----------------------------------------------------------------------------------------------------\n";
    std::cout << "   Solicitação de Reabastecimento do Estoque do produto: " << this->produto[idProduto]->getNome() << "\n\n";
    std::cout << "ID: " << idProduto << "   Lote: " << lotes[idProduto].back()->getIdLote() <<  "    Quantidade: " << lotes[idProduto].back()->getQuantidade();
    std::cout << "\n\n----------------------------------------------------------------------------------------------------\n";
  } else {
    throw("A quantidade solicitada é menor que o minímo permitido.");
  }
}

void Estoque::cadastraLote(int idProduto, Lote *lote) {
  this->lotes[idProduto].push_back(lote);
}

void Estoque::cadastraProduto(std::string nome, int loteMinimo,
                              int estoqueMinimo, PrecoProduto* preco) {
  Produto *produto = new Produto(nome, loteMinimo, estoqueMinimo, preco);
  this->produto[produto->getIdProduto()] = produto;
  this->lotes[produto->getIdProduto()].push_back(new Lote());
  this->lotes[produto->getIdProduto()][0]->setQuantidade(0);
  
}

void Estoque::printListaDeProdutos(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  std::cout << "                            Lista dos Produtos Cadastrados no Sistema\n\n";
  for(std::map<int,Produto*>::iterator it=produto.begin(); it!=produto.end(); ++it){
    std::cout << "Produto: " << this->produto[it->first]->getNome() << "     ID: " << this->produto[it->first]->getIdProduto() << "     Quantidade: " << verificaEstoque(this->produto[it->first]->getIdProduto()) << "\n";
  }
  std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
}

void Estoque::printListaDeLotes(int idProduto){
  for(int num =0; num < this->lotes[idProduto].size(); num++){
    std::cout << "Produto: " << this->produto[idProduto]->getNome() << "     ID: " << idProduto << "     Lote: " << this->lotes[idProduto][num]->getIdLote() << "     Quantidade: " << this->lotes[idProduto][num]->getQuantidade() << "\n";
  }
}