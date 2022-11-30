#include "../includes/OrdemDeMateriaPrima.hpp"

OrdemDeMateriaPrima::OrdemDeMateriaPrima() {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeMateriaPrima"," ","Construtor OrdemDeMateriaPrima");
  
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"OrdemDeMateriaPrima","","",CRIACAO));
}

OrdemDeMateriaPrima::OrdemDeMateriaPrima( MateriaPrima* materiaPrima, int quantidade, Data data, std::vector<Fornecedor*> fornecedores)
{
 std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"OrdemDeMateriaPrima",materiaPrima->getNome(),"Construtor OrdemDeMateriaPrima");
  
  this->quantidade = quantidade;
  this->materiaPrima = materiaPrima;
  this->data = data;
  this->fornecedor = melhorPreco(materiaPrima->getId(), fornecedores);
  
  Login* login = Login::getInstance();
  HistoricoDeLogs* historic = HistoricoDeLogs::getInstancia();
  historic->setLog(new LogCriacaoDelecao(login->getUsuario()->getNome(),login->getUsuario()->getcpfCnpj(),Data().dateNow(),"OrdemDeMateriaPrima",materiaPrima->getNome(),to_string(quantidade),CRIACAO));
}
OrdemDeMateriaPrima::~OrdemDeMateriaPrima() {}

// getters
MateriaPrima* OrdemDeMateriaPrima::getMateriaPrima() {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"OrdemDeMateriaPrima",this->materiaPrima->getNome(),"getMateriaPrima");
  return this->materiaPrima;
}

int OrdemDeMateriaPrima::getQuantidade() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"OrdemDeMateriaPrima",this->materiaPrima->getNome(),"getQuantidade");
  return this->quantidade; 
}

float OrdemDeMateriaPrima::getValorFinal() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"OrdemDeMateriaPrima",this->materiaPrima->getNome(),"getValorFinal");
return this->valorFinal; 
}

Data OrdemDeMateriaPrima::getData() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"OrdemDeMateriaPrima",this->materiaPrima->getNome(),"getData");
  return this->data; 
}

Fornecedor* OrdemDeMateriaPrima::getFornecedor() { 
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("LEITURA_ESTOQUE");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::LEITURA_ESTOQUE,frases,"OrdemDeMateriaPrima",this->materiaPrima->getNome(),"get");
  return this->fornecedor; 
}

// setters
void OrdemDeMateriaPrima::setMateriaPrima(MateriaPrima* materiaPrima) {
 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","OrdemDeMateriaPrima",this->materiaPrima->getNome(),"setMateriaPrima");
  this->materiaPrima = materiaPrima;
}

void OrdemDeMateriaPrima::setQuantidade(int quantidade) {
 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","OrdemDeMateriaPrima",this->materiaPrima->getNome(),"setQuantidade");
  this->quantidade = quantidade;
}

void OrdemDeMateriaPrima::setValorFinal(float valorFinal) {
 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","OrdemDeMateriaPrima",this->materiaPrima->getNome(),"setValorFinal");
  this->valorFinal = valorFinal;
}

void OrdemDeMateriaPrima::setData(Data data) { 
 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","OrdemDeMateriaPrima",this->materiaPrima->getNome(),"setData");
  this->data = data; }

void OrdemDeMateriaPrima::setFornecedor(Fornecedor* fornecedor) {
 
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,"MANUSEAR_ESTOQUE","OrdemDeMateriaPrima",this->materiaPrima->getNome(),"setFornecedor");
  this->fornecedor = fornecedor;
}

// Métodos
Fornecedor* OrdemDeMateriaPrima::melhorPreco(int idMateriaPrima, std::vector<Fornecedor*> fornecedores) {
  std::vector<std::string> frases;
  frases.push_back("MANUSEAR_ESTOQUE");
  frases.push_back("EMITIR_ORDEM_PRODUCAO");
  Login::getInstance()->verificaPermissao(PERMISSOES::MANUSEAR_ESTOQUE,PERMISSOES::EMITIR_ORDEM_PRODUCAO,frases,"MateriaPrima","Estoque","melhorPreco");
  std::vector<Fornecedor*> auxFornecedores;
  Fornecedor* fornecedor = NULL;
  for (int i = 0; i < fornecedores.size(); i++) {
    if (fornecedores[i]->possuiProduto(idMateriaPrima))
      auxFornecedores.push_back(fornecedores[i]);
  }
  if (auxFornecedores.size() <= 0) {
    std::cout << "Não temos fornecedores dessa materia prima.";
    return fornecedor;
  } else {
    float preco = 0.0;
    for (int i = 0; i < auxFornecedores.size(); i++) {
      if (i != 0) {
        if (preco > auxFornecedores[i]->enviaPreco(idMateriaPrima)) {
          preco = auxFornecedores[i]->enviaPreco(idMateriaPrima);
          fornecedor = auxFornecedores[i];
        }
      } else {
        preco = auxFornecedores[i]->enviaPreco(idMateriaPrima);
        fornecedor = auxFornecedores[i];
      }
    }
    this->valorFinal =
      this->quantidade * fornecedor->enviaPreco(this->materiaPrima->getId());
    return fornecedor;
  }
}

void OrdemDeMateriaPrima::printOrdemDeMP() {
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------\n"
            << "                      Resumo da Ordem de Reabastecimento de "
               "Materia Prima\n\n"
            << "Materia Prima: " << this->materiaPrima->getNome() << "\n"
            << "Identificador: " << this->materiaPrima->getId() << "\n"
            << "Quantidade:    " << this->quantidade << "\n"
            << "Preço:         R$ "
            << this->fornecedor->enviaPreco(this->materiaPrima->getId()) << "\n"
            << "Valor Final:   R$ " << this->valorFinal << "\n"
            << "Fornecedor:    " << this->fornecedor->getNome() << "\n"
            << "Data (UTC):    ";
  this->data.printData();
  std::cout << "\n"
            << "---------------------------------------------------------------"
               "-------------------------------------\n";
}