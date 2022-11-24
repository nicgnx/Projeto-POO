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
  for (auto t : tiposDePagamento) {
    if (tipo == t)
        break;
    else if (t == tiposDePagamento.end()) {
      std::cout << "\nErro! Tipo de pagamento não registrado.\n";
      return ;
    }
  }
  for (auto f : formasDePagamento) {
    if (forma == f)
        break;
    else if (f == formasDePagamento.end()) {
      std::cout << "\nErro! Forma de pagamento não registrada.\n";
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