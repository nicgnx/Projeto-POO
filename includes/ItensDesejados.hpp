#ifndef ITENS_DESEJADOS_H
#define ITENS_DESEJADOS_H

class ItensDesejados {
protected:
  std::string produto;
  int idProduto;
  float precoUnitario;
  int quantidade;
  float valorTotal;
  bool disponibilidade;

public:
  // Construtores e Destrutores
  ItensDesejados(
    std::string produto, int idProduto, float precoUnitario, int quantidade,
    float valorTotal, bool disponibilidade
  );
  ItensDesejados();
  ~ItensDesejados();

  // getters
  std::string getProduto();
  int getIdProduto();
  float getPrecoUnitario();
  int getQuantidade();
  float getValorTotal();
  bool getDisponibilidade();

  // setters
  void setProduto(std::string produto);
  void setIdProduto(int idProduto);
  void setPrecoUnitario(float precoUnitario);
  void setQuantidade(int quantidade);
  void setValorTotal(float valorTotal);
  void setDisponibilidade(bool disponibilidade);

  // misc
  float calculaCompra(float precoUnitario, int quantidade);
  bool verificaDisponibilidade(int idProduto);
};

#endif // ITENS_DESEJADOS_H