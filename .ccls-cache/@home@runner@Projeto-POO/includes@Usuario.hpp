#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {

  std::string nome;
  std::string cpfCnpj;
  std::string email;
 


protected:
  
  virtual ~Usuario() = default;
  std::string getNome();
  std::string getcpfCnpj();
  std::string getEmail();
  void setNome(std::string nome);
  void setcpfCnpj(std::string cpfCnpj);
  void setEmail(std::string email);

};

#include "../src/Usuario.cpp"

#endif