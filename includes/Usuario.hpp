#ifndef USUARIO_H
#define USUARIO_H

#include "./Permissao.hpp"
#include <string>
#include <vector>

class Usuario {
protected:
  std::string nome;
  std::string email;
  std::string cpfCnpj;
  std::string senha;
  std::vector<Permissao*> permissoes;

public:
  virtual ~Usuario() = default;
  std::string getNome();
  std::string getcpfCnpj();
  std::string getEmail();
  std::string getSenha();
  std::vector<Permissao*> getPermissao();

  void setNome(std::string nome);
  void setcpfCnpj(std::string cpfCnpj);
  void setEmail(std::string email);
  void setSenha(std::string senha);
  void setPermissoes(std::vector<Permissao*> permissoes);

  std::string exibePermissao();
  void adicionaPermissoes(Permissao* permissao);
};

#endif // USUARIO_H