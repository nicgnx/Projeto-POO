#ifndef PERMISSAO_H
#define PERMISSAO_H

#include <iostream>
#include <string>
#include <vector>

class Permissao {

  int idPermissao;
  std::string descricao;

public:
  Permissao();
  Permissao(int idPermissao, std::string descricao);

  int getIdPermissao();
  std::string getDescricao();

  void setIdPermissao(int idPermissao);
  void setDescricao(std::string permissao);
};

#endif // PERMISSAO_H