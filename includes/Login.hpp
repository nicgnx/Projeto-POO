#ifndef LOGIN_H
#define LOGIN_H

#include "Data.hpp"
#include "Usuario.hpp"
#include <string>

class Login {
private:
  Usuario* usuario;
  Data logadoEm;
  static Login* instance;

  // Construtor e Destrutor
  Login();
  ~Login();

public:
  static Login* getInstance();

  Login* logar(Usuario*);
  void deslogar();
  std::string getUsuarioNome();
  std::string getUsuarioSenha();
  Usuario* getUsuario();
  bool verificaPermissao(int idPermissao);
};

#endif // LOGIN_H