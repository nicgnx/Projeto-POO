#include "../includes/PedidoDeCompra.hpp"

// Construtores e Destrutores
PedidoDeCompra::PedidoDeCompra(std::vector<ItensDesejados*> itens, Data dataPedido, float valorDaCompra,std::string cpfCnpj) {
  this->dataPedido = dataPedido;
  this->valorDaCompra = valorDaCompra;
  
  for(auto it = itens.begin(); it != itens.end(); it++){
    RegistroVenda* registroDeVenda = new RegistroVenda(cpfCnpj,(*it)->getIdProduto(),(*it)->getQuantidade() ,(*it)->getPrecoUnitario(), getDataPedido());

    this->registroVenda.push_back(registroDeVenda);
  }
}
PedidoDeCompra::PedidoDeCompra() {}
PedidoDeCompra::~PedidoDeCompra() {}

// getters
float PedidoDeCompra::getValorDaCompra() { return this->valorDaCompra; }

Data PedidoDeCompra::getDataPedido() { return this->dataPedido; }

PagamentoAbstrata* PedidoDeCompra::getRegistroPagamento() {
  return this->registroPagamento;
}

std::vector<RegistroVenda*> PedidoDeCompra::getRegistroVenda() {
  return this->registroVenda;
}

// setters
void PedidoDeCompra::setValorDaCompra(float valor) { this->valorDaCompra = valor; }

void PedidoDeCompra::setRegistroVenda(std::vector<RegistroVenda*> registroVenda
) {
  this->registroVenda = registroVenda;
}

void PedidoDeCompra::setDataPedido(Data dataPedido) { this->dataPedido = dataPedido; }

void PedidoDeCompra::setRegistroPagamento(PagamentoAbstrata* registroPagamento
) {
  this->registroPagamento = registroPagamento;
}
// métodos
bool PedidoDeCompra::validaEntrada(std::string tipo, std::string forma) {
  for (int i = 0; i < sizeof(tiposDePagamento) / sizeof(int); i++) {
    std::string tipoIt = tiposDePagamento[i];
    if (tipo == tipoIt)
      break;
    else if (i == (sizeof(tiposDePagamento) / sizeof(int)) - 1) {
      std::cout << "\nErro! Tipo de pagamento não registrado.\n";
      return false;
    }
  }

  for (int i = 0; i < sizeof(formasDePagamento) / sizeof(int); i++) {
    std::string formaIt = formasDePagamento[i];
    if (forma == formaIt)
      break;
    else if (i == (sizeof(formasDePagamento) / sizeof(int)) - 1) {
      std::cout << "\nErro! Forma de pagamento não registrada.\n";
      return false;
    }
  }
  return true;
}

void PedidoDeCompra::registraPagamento(std::string tipo, std::string forma) {
  if (this->validaEntrada(tipo, forma) == false)
    return;
  if (tipo.compare("boleto") == 0) {
    if (forma.compare("30") == 0) {
      this->registroPagamento = new Boleto(this->dataPedido.dateNow(), this->valorDaCompra, Periodo::DIAS_30);
    }
    else if (forma.compare("60") == 0) {
      this->registroPagamento = new Boleto(this->dataPedido.dateNow(), this->valorDaCompra, Periodo::DIAS_60);
    }
    else if (forma.compare("90") == 0) {
      this->registroPagamento = new Boleto(this->dataPedido.dateNow(), this->valorDaCompra, Periodo::DIAS_90);
    }
    else {
      std::cout << "\nForma de pagamento não é valida para boleto\n";
      return;
    }
  }
  else if (tipo.compare("credito") == 0) {
    if (forma.compare("a_vista") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::A_VISTA);
    }
    else if (forma.compare("x1") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::x1);
    }
    else if (forma.compare("x2") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::x2);
    }
    else if (forma.compare("x3") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::x3);
    }
    else if (forma.compare("x4") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::x4);
    }
    else if (forma.compare("x5") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::x5);
    }
    else if (forma.compare("x6") == 0) {
      this->registroPagamento = new Credito(this->dataPedido.dateNow(), this->valorDaCompra, Parcelamento::x6);
    }
    else {
      std::cout << "\n Forma de pagamento não é valida para credito.\n";
      return;
    }
  }
  else {
    std::cout << "\nErro! Tipo de pagamento não validado.\n";
    return;
  }
  this->executaCompra();
}

void PedidoDeCompra::executaCompra() {
  for (auto it : this->registroVenda) {
    it->executaVenda();
  }
}

void PedidoDeCompra::printaCompra() {
  if (this->registroPagamento == nullptr) {
    std::cout << "\n Erro! Escolha uma forma de pagamento. \n";
    return;
  }
  for (auto it : this->registroVenda) {
    if (it->getStatus() != STATUS::CONCLUIDO)
      std::cout <<"\n" << it->getIdProduto() << " : Aguardando a confirmação do pedido.\n";
    else
      std::cout <<"\n" << it->getIdProduto() << " : Compra executada.\n";
  }
  this->registroPagamento->printaPagamento();
}