#ifndef CLIENTE_H
#define CLIENTE_H

#include "../includes/Data.hpp"
#include "../includes/Usuario.hpp"
#include "../includes/Orcamento.hpp"
//#include "../includes/Login.hpp"
//#include "../constants/PERMISSOES.hpp"
#include <map>

enum tipoPessoa { PF, PJ };

class Cliente : public Usuario {

  tipoPessoa tipo;
  unsigned int telefone;
  std::vector<Orcamento*> orcamentosAprovados;

public:
  // Construtores e Destrutores
  Cliente();
  Cliente(std::string nome, std::string email, std::string senha, std::string cpfCnpj,
  tipoPessoa tipo, unsigned int telefonee
  );
  ~Cliente();

  // Getters
  tipoPessoa getTipoPessoa();
  unsigned int getTelefone();
  std::vector<Orcamento*> getOrcamentosAprovados();

  // Setters
  void setTipoPessoa(tipoPessoa tipo);
  void setTelefone(unsigned int telefone);
  void setOrcamentosAprovados(Orcamento* orcamento);

  // Métodos
  void compra(Orcamento* orcamento, Data dataCompra);
  Orcamento* solicitaOrcamento(std::map<int, int> itensDesejados);
};

#endif // CLIENTE_H