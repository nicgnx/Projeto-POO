#include "../includes/Login.hpp"


Login::Login(Usuario* usuario) {
  this->logadoEm = Data::dateNow();
  this->usuario = usuario;
}

Login::~Login() {
  this->instance = nullptr;
}

static Login& Login::logar(Usuario* usuario) { 
  if (instance == nullptr) {
    instance = new Login(usuario);
    }
  return *instance;
}
void Login::deslogar() {
  ~Login();
}
