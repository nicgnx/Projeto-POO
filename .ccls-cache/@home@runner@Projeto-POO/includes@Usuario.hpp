#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
  std::string nome;
  std::string cpfCnpj;
  std::string email;
 
public:
  virtual ~Usuario() = default;
  std::string getNome();
  std::string getcpfCnpj();
  std::string getEmail();
  void setNome(std::string nome);
  void setcpfCnpj(std::string cpfCnpj);
  void setEmail(std::string email);

};

#endif // USUARIO_H