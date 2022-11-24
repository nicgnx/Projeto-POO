#include "../includes/Login.hpp"

Login::Login() {}
Login::~Login() {}
Login* Login::instance = NULL;

Login* Login::getInstance() {
  if (instance == NULL) {
    instance = new Login();
  }
  return instance;
}

void Login::logar(Usuario* usuario) {
  this->usuario = usuario;
  this->logadoEm = (new Data())->dateNow();
}

void Login::deslogar() {
  this->usuario = NULL;
}

std::string Login::getUsuarioNome() {
  return this->usuario->getNome();
}

Usuario* Login::getUsuario() { return this->usuario; }

std::string Login::getUsuarioSenha() {
  return this->usuario->getSenha();
}

bool Login::verificaPermissao(int idPermissao) {
  // puxa as permissoes do usuario logado
  std::vector<Permissao*> permissoes = this->usuario->getPermissao();

  for (Permissao* permissao : permissoes) {
    if (permissao->getIdPermissao() == idPermissao) {
      return true;
    }
  }

  // se chegou ate aqui nao tem permissao: dispara logs
  HistoricoDeLogs* historicoLogs = HistoricoDeLogs::getInstacia();
  LogExcecao* logExcecao = new LogExcecao(
    this->usuario->getNome(),
    std::stoi(this->usuario->getcpfCnpj()),
    Data().dateNow(),
    "Login",
    "Login",
    "Login::verificaPermissao"
  );
  historicoLogs->setLogExcecao(
    std::stoi(this->usuario->getcpfCnpj()), 
    logExcecao
  );

  return false;
}
