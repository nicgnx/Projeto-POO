#include "../includes/Estoque.hpp"

// Construtores
Estoque::Estoque(){}
Estoque::~Estoque() {}
Estoque* Estoque::estoque = NULL;



// Funções Auxiliares
void Estoque::auxReabasteceEstoqueProduto(int idProduto, int quantidade) {
      // Reabastece as matérias-primas se necessario, para solicitar o Lote.
      if(capacidadeDeProducao(idProduto) < quantidade){reabasteceEstoqueMP(this->produto[idProduto],(quantidade - capacidadeDeProducao(idProduto)),ARBITRARIO);}
      // Cria a Ordem de Produção do Lote.
      OrdemDeProducao Solicitacao(this->produto[idProduto]->getNome(),idProduto,Data().dateNow(),quantidade);
      // Remove as matérias-primas necessárias para solicitar o Lote.
      retiraMateriaPrima(this->produto[idProduto],quantidade);   
      // Solicita o novo Lote.
      this->lotes[idProduto].push_back(Solicitacao.solicitaLote());
      auxPrintReabasteceEstoque(REALIZADO,idProduto);
}


std::vector<int> Estoque::auxRetiraLotes(int idProduto, int quantidade){
  vector<int> lotes;
  int aux, num = 0;
  for(;num < this->lotes[idProduto].size();num++){
    aux = this->lotes[idProduto][num]->getQuantidade();
    if (aux >= quantidade) {
      aux = aux - quantidade;
      this->lotes[idProduto][num]->setQuantidade(aux);
      lotes.push_back(this->lotes[idProduto][num]->getIdLote());
      reabasteceEstoqueProduto(idProduto,0,MINIMO);
      return lotes;
      }
    else {
      if((aux == 0) && (this->lotes[idProduto].size() > 1)){} 
      else {
        quantidade = quantidade - aux;
        this->lotes[idProduto][num]->setQuantidade(0);
        lotes.push_back(this->lotes[idProduto][num]->getIdLote());
      }      
    }
  } std::cout << "Não era nem pra essa compra ter sido aprovada! Vai ficar sem produto..."; return lotes;
}


void Estoque::auxPrintReabasteceEstoque(tipoRetorno mens,int id){
  switch(mens){
    case N_REALIZADO:{
      std::cout << "----------------------------------------------------------------------------------------------------\n\n";
      std::cout << "                  Solicitação de Reabastecimento de Estoque não realizada.\n\n"; 
      std::cout << "                  O estoque minímo do produto [ " << this->produto[id]->getNome() << " ] ainda não foi atingido."; 
      std::cout << "\n\n                  Quantidade disponível no estoque: " << verificaEstoqueProduto(id);
      std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n";  
      break;
    }
    case REALIZADO:{
      std::cout << "----------------------------------------------------------------------------------------------------\n\n";
      std::cout << "                  Solicitação de Reabastecimento do Estoque do produto [ " << this->produto[id]->getNome() <<   " ]\n\n";
      std::cout << "                  ID: " << id << "\n";
      std::cout << "                  Lote: " << lotes[id].back()->getIdLote() << "\n";
      std::cout << "                  Quantidade: " << lotes[id].back()->getQuantidade() << "\n";
      std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n";
      break;
    }
    case N_REALIZADO_MP:{
      std::cout << "----------------------------------------------------------------------------------------------------\n\n";
      std::cout << "                  Solicitação de Reabastecimento de Estoque não realizada.\n\n"; 
      std::cout << "                  O estoque minímo da Materia Prima [ " << this->materiaPrima[id]->getNome() << " ] ainda não foi atingido."; 
      std::cout << "\n\n                  Quantidade disponível no estoque: " << verificaEstoqueMP(id);
      std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n";  
      break;
    }
    case REALIZADO_MP:{
      std::cout << "----------------------------------------------------------------------------------------------------\n\n";
      std::cout << "                  Solicitação de Reabastecimento do Estoque da Materia Prima [ " << this->materiaPrima[id]->getNome() <<   " ]\n\n";
      std::cout << "                  ID: " << id << "\n";
      std::cout << "                  Quantidade: " << verificaEstoqueMP(id) << "\n";
      std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\n";
      break;
    }
    default:
      break;
  }
}


//getters
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


MateriaPrima* Estoque::getMateriaPrima(int idMateriaPrima){ return this->materiaPrima[idMateriaPrima];}


std::map<int,MateriaPrima*> Estoque::getListaMateriaPrima(){ return this->materiaPrima;}


std::vector<Fornecedor*> Estoque::getFornecedores(){ return this->fornecedores;}


std::map<int,int> Estoque::getEstoqueMP(){ return this->estoqueMP;}


//Métodos
int Estoque::capacidadeDeProducao(int idProduto){
  std::map<int,int> materiaPrima = this->produto[idProduto]->getMateriasPrimas();
  std::vector<int> estoqueMateriaPrima;
  int producao = 0;
  for(auto i = materiaPrima.begin();i != materiaPrima.end();i++){
    estoqueMateriaPrima.push_back(verificaEstoqueMP(i->first));
  }
  for(auto i = materiaPrima.begin();i != materiaPrima.end();i++){
    if(i == materiaPrima.begin())
      producao = verificaEstoqueMP(i->first)/i->second;
    else 
      producao > (verificaEstoqueMP(i->first)/i->second) ? producao = verificaEstoqueMP(i->first)/i->second : producao;
  } return producao;
}


int Estoque::verificaEstoqueProduto(int idProduto) {
  int estoqueDisponivel = 0;
  for (int num = 0; num < this->lotes[idProduto].size(); num++) {
    estoqueDisponivel += this->lotes[idProduto][num]->getQuantidade();
  }
  return estoqueDisponivel;
}


int Estoque::verificaEstoqueMP(int idMateriaPrima){return this->estoqueMP[idMateriaPrima];}


void Estoque::cadastraFornecedor(Fornecedor* fornecedor){this->fornecedores.push_back(fornecedor);}


void Estoque::cadastraProduto(std::string nome, int loteMinimo,int estoqueMinimo, PrecoProduto* preco) {
  Produto *produto = new Produto(nome, loteMinimo, estoqueMinimo, preco);
  this->produto[produto->getIdProduto()] = produto;
  this->lotes[produto->getIdProduto()].push_back(new Lote());
  this->lotes[produto->getIdProduto()][0]->setQuantidade(0);
  
}


void Estoque::cadastraMateriaPrima(int id, std::string nome, std::string unidade, int estoqueMinimo){
  this->materiaPrima.insert(std::pair<int,MateriaPrima*> (id,new MateriaPrima(id,nome,unidade,estoqueMinimo)));
  this->estoqueMP[id] = 0;
}


void Estoque::cadastraLote(int idProduto, Lote *lote) {this->lotes[idProduto].push_back(lote);}


void Estoque::reabasteceEstoqueProduto(int idProduto, int quantidade, tipoReabastece valor) {
  switch(valor){
    case MINIMO:
      if (verificaEstoqueProduto(idProduto) > this->produto[idProduto]->getEstoqueMinimo()){auxPrintReabasteceEstoque(N_REALIZADO,idProduto);}
      else{
        if(this->produto[idProduto]->getEstoqueMinimo() > this->produto[idProduto]->getLoteMinimo()){
          int aux = (this->produto[idProduto]->getEstoqueMinimo() - verificaEstoqueProduto(idProduto));
          quantidade = ((aux/this->produto[idProduto]->getLoteMinimo())+1)*this->produto[idProduto]->getLoteMinimo();
          auxReabasteceEstoqueProduto(idProduto,quantidade);
        }
        else {auxReabasteceEstoqueProduto(idProduto,this->produto[idProduto]->getLoteMinimo());}
      } 
    break;
    case ARBITRARIO:
      if(quantidade < this->produto[idProduto]->getLoteMinimo()){quantidade = this->produto[idProduto]->getLoteMinimo();}
    auxReabasteceEstoqueProduto(idProduto,quantidade);
    break;
  }
}


void Estoque::reabasteceEstoqueMP(int idMateriaPrima, int quantidade, tipoReabastece valor) {
 if((verificaEstoqueMP(idMateriaPrima) >= this->materiaPrima[idMateriaPrima]->getEstoqueMinimo()) && (valor == MINIMO))
    auxPrintReabasteceEstoque(N_REALIZADO_MP,idMateriaPrima);
  else{
    valor == MINIMO ? quantidade = (this->materiaPrima[idMateriaPrima]->getEstoqueMinimo() - verificaEstoqueMP(idMateriaPrima)) : quantidade;
    OrdemDeMateriaPrima* Solicitacao = new OrdemDeMateriaPrima(this->materiaPrima[idMateriaPrima],quantidade, Data().dateNow(),this->fornecedores);
    this->estoqueMP[idMateriaPrima] = this->estoqueMP[idMateriaPrima] + Solicitacao->getQuantidade();
    
    auxPrintReabasteceEstoque(REALIZADO_MP,idMateriaPrima);
    quantidade = 0;
  }
}


void Estoque::reabasteceEstoqueMP(Produto* produto, int quantidade, tipoReabastece valor){
  valor == MINIMO ? quantidade = produto->getEstoqueMinimo() : quantidade;
  std::map <int,int> materiasPrimas = produto->getMateriasPrimas();
  for(auto i = materiasPrimas.begin(); i != materiasPrimas.end(); i++){   
    if((verificaEstoqueMP(i->first)/i->second) < quantidade){
    reabasteceEstoqueMP(i->first,(quantidade - (verificaEstoqueMP(i->first)/i->second))*(i->second),valor);
    }
  } 
}


void Estoque::retiraMateriaPrima(int idMateriaPrima, int quantidade){
  this->estoqueMP[idMateriaPrima] -= quantidade;
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  std::cout << "Materia Prima [ " << this->materiaPrima[idMateriaPrima]->getNome() << " ] " << "retirada.\n\n"
            << " Quantidade: " << quantidade << "\n";  
  std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";  
  if(this->estoqueMP[idMateriaPrima] < this->materiaPrima[idMateriaPrima]->getEstoqueMinimo())
    reabasteceEstoqueMP(idMateriaPrima,0,MINIMO);
}


void Estoque::retiraMateriaPrima(Produto* produto, int quantidade){
  std::map <int,int> materiasPrimas = produto->getMateriasPrimas();
  for(auto i = materiasPrimas.begin() ;i != materiasPrimas.end();i++)
    retiraMateriaPrima(i->first,i->second*quantidade);
}


vector<int> Estoque::retiraLotes(int idProduto, int quantidade) {
  int aux = 0;
  if(verificaEstoqueProduto(idProduto) > quantidade) {return auxRetiraLotes(idProduto,quantidade);}
  else{
    aux = quantidade - verificaEstoqueProduto(idProduto);
    reabasteceEstoqueProduto(idProduto,aux,ARBITRARIO);
    return auxRetiraLotes(idProduto,quantidade);
  }
}


void Estoque::printListaDeProdutos(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  std::cout << "                            Lista dos Produtos Cadastrados no Sistema\n\n";
  for(std::map<int,Produto*>::iterator it=produto.begin(); it!=produto.end(); ++it){
    std::cout << "Produto: " << this->produto[it->first]->getNome() << "     ID: " << this->produto[it->first]->getIdProduto() << "     Quantidade: " << verificaEstoqueProduto(this->produto[it->first]->getIdProduto()) << "\n";
  }
  std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
}


void Estoque::printListaDeMateriasPrimas(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  std::cout << "                            Lista das Materia Primas Cadastradas no Sistema\n\n";
  for(auto it =this->materiaPrima.begin(); it!=this->materiaPrima.end(); ++it){
    std::cout << "Materia Prima: " << it->second->getNome() << "     ID: " << it->first << "     Quantidade: " << verificaEstoqueMP(it->first) << "\n\n";
  }
  std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
}



void Estoque::printListaDeLotes(int idProduto){
  for(int num =0; num < this->lotes[idProduto].size(); num++){
    std::cout << "Produto: " << this->produto[idProduto]->getNome() << "     ID: " << idProduto << "     Lote: " << this->lotes[idProduto][num]->getIdLote() << "     Quantidade: " << this->lotes[idProduto][num]->getQuantidade() << "\n";
  }
}

void Estoque::printListaDeFornecedores(){
  std::cout << "----------------------------------------------------------------------------------------------------\n\n";
  std::cout << "                            Lista dos Fornecedores Cadastradas no Sistema\n\n\n\n";
  for(int it = 0; it < this->fornecedores.size(); ++it){
    std::cout << "Nome: " << this->fornecedores[it]->getNome() << "\n";
    this->fornecedores[it]->printProdutos();
    std::cout << "\n\n";
  }
  std::cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
}