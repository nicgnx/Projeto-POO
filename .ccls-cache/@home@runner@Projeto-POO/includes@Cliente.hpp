#ifndef CLIENTE_H
#define CLIENTE_H

#include "../includes/Data.hpp"
#include "../includes/RegistroVenda.hpp"
#include "../includes/Usuario.hpp"

#include "../includes/Login.hpp"
#include "../constants/PERMISSOES.hpp"

enum tipoPessoa { PF, PJ };

class Cliente : public Usuario {

  tipoPessoa tipo;
  unsigned int telefone;

public:
  // Construtores e Destrutores
  Cliente();
  Cliente(
    std::string nome, std::string cpfCnpj, std::string email, std::string senha, 
    tipoPessoa tipo, unsigned int telefone
  );
  ~Cliente();

  // Getters
  tipoPessoa getTipoPessoa();
  unsigned int getTelefone();

  // Setters
  void setTipoPessoa(tipoPessoa tipo);
  void setTelefone(unsigned int telefone);

  // Métodos
  void compra(int idProduto, int quantidade, Data dataCompra);
};

#endif // CLIENTE_H