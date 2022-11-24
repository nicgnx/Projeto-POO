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
void PedidoDeCompra::registraPagamento(std::string tipo, std::string forma) {
  for (int i = 0; i < sizeof(tiposDePagamento) / sizeof(int); i++) {
    std::string tipoIt = tiposDePagamento[i];
    if (tipo == tipoIt)
      break;
    else if (i == (sizeof(tiposDePagamento) / sizeof(int)) - 1) {
      std::cout << "\nErro! Tipo de pagamento não registrado.\n";
      return ;
    }
  }

  for (int i = 0; i < sizeof(formasDePagamento) / sizeof(int); i++) {
    std::string formaIt = formasDePagamento[i];
    if (forma == formaIt)
      break;
    else if (i == (sizeof(formasDePagamento) / sizeof(int)) - 1) {
      std::cout << "\nErro! Tipo de pagamento não registrado.\n";
      return ;
    }
  }

  // switch (tipo) {
  //   case "boleto":
  //     switch (forma) {
  //       case "30":
  //         break;
  //     }
  //     break;
  //   case "credito":
  //     switch (forma) {
  //       case "a_vista":
  //         break;
  //     }
  //     break;
  // }
}

void PedidoDeCompra::executaCompra() {}

void PedidoDeCompra::printaCompra() {
  if (this->registroPagamento == nullptr) {
    std::cout << "\n Erro! Escolha uma forma de pagamento. \n";
    return ;
  }
  
}