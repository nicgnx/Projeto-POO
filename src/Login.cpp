#include "../includes/Login.hpp"

Login* Login::instance = nullptr;

Login::Login(Usuario* usuario) {
    this->logadoEm = logadoEm.dateNow();
    this->usuario = usuario;
}

Login::~Login() { this->instance = nullptr; }

Login* Login::logar(Usuario* usuario) {
    if (Login::instance == nullptr) {
        Login::instance = new Login(usuario);
    }
    return Login::instance;
}

Login* Login::getInstance() { return Login::instance; }

void Login::deslogar() { Login::getInstance()->~Login(); }

std::string Login::getUsuarioNome() {
    return Login::getInstance()->usuario->getNome();
}
Usuario* Login::getUsuario() { return Login::getInstance()->usuario; }
std::string Login::getUsuarioSenha() {
    return Login::getInstance()->usuario->getSenha();
}
