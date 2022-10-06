#ifndef CLIENTE_H
#define CLIENTE_H

#include "../includes/Usuario.hpp"
#include "../includes/Data.hpp"

enum tipoPessoa {PF, PJ};

class Cliente : public Usuario {
  
  tipoPessoa tipo;
  unsigned int telefone;

public:

// Construtores e Destrutores
  Cliente();
  Cliente(std::string nome, std::string email, std::string cpfCnpj, tipoPessoa tipo, unsigned int telefone);
  ~Cliente();

// Getters
  tipoPessoa getTipoPessoa();
  unsigned int getTelefone();

//Setters
  void setTipoPessoa(tipoPessoa tipo);
  void setTelefone(unsigned int telefone);

//Métodos
std::string compra (int idProduto, int quantidade, Data dataCompra, Cliente* cliente);


};

#endif // CLIENTE_H