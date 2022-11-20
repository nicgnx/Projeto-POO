#ifndef LOTE_H
#define LOTE_H

#include "Data.hpp"
#include "Produto.hpp"

enum Status { ESTOQUE, VENDIDO };

class Lote {
private:
  int idProduto;
  Data data;
  int quantidade;
  Status status;
  const int idLote;
  static int lotesTotais;

public:
  Lote(int, Data, int);
  Lote();
  ~Lote();

  void updateLotes(int);

  // getters
  int getIdProduto();
  Data getData();
  int getQuantidade();
  int getIdLote();
  int getLotesTotais();
  Status getStatus();

  // setters
  void setIdProduto(int);
  void setData(Data);
  void setQuantidade(int);
  void setStatus(Status);
};

#endif // LOTE_H