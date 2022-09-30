#ifndef CLIENTE_H
#define CLIENTE_H

#include "../includes/Usuario.hpp"

enum tipoPessoa {PF, PJ};

class Cliente : public Usuario {
  
  tipoPessoa tipo;
  unsigned int telefone;

public:
  Cliente();
  Cliente(std::string nome, std::string email, std::string cpfCnpj, tipoPessoa tipo, unsigned int telefone);
  ~Cliente();
  tipoPessoa getTipoPessoa();
  unsigned int getTelefone();
  void setTipoPessoa(tipoPessoa tipo);
  void setTelefone(unsigned int telefone);


};

#endif // CLIENTE_H