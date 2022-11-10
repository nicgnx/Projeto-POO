#ifndef ORCAMENTO_H
#define ORCAMENTO_H



class Orcamento {
protected:
  std::string cliente;
  int cpfCnpj;
  std::string email;
  // std::string cliente;
  float valorTotal;
  Data data;
  // PedidoDeCompra pedido;

public:
  // Construtores e Destrutores
  Orcamento(
    std::string inforacao
  );
  Orcamento();
  ~Orcamento();
};


#endif // ORCAMENTO_H