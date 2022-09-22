#ifndef CLIENTE_H
#define CLIENTE_H

#include "usuario.hpp"

enum tipoPessoa {PF, PJ};

class Cliente : public Usuario {
  
  tipoPessoa tipo;
  unsigned int telefone;

public:
  Cliente(std::string, std::string, std::string, tipoPessoa, unsigned int);
  ~Cliente();
  tipoPessoa getTipoPessoa();
  int getTelefone();
  void setTipoPessoa(tipoPessoa);
  void setTelefone(unsigned int);


};

#include "../src/Cliente.cpp"

#endif