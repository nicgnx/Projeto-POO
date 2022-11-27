#include "../includes/Login.hpp"

Login::Login() {
  this -> usuario = NULL;
}

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

bool Login::verificaPermissao(
  int idPermissao, 
  // argumentos opcionais
  std::string classeAcessada = "", 
  std::string instanciaAcessada = "", 
  std::string metodoAcessado = ""
) {
  if (this->getInstance() == nullptr) {
    std::cout << "\nVoce precisa estar logado para realizar esta acao.\n";
    return false;
  }

  // puxa as permissoes do usuario logado
  std::vector<Permissao*> permissoes = this->usuario->getPermissao();

  for (Permissao* permissao : permissoes) {
    if (permissao->getIdPermissao() == idPermissao) {
      return true;
    }
  }

  // se chegou ate aqui nao tem permissao: dispara logs
  HistoricoDeLogs* historicoLogs = HistoricoDeLogs::getInstacia();
  std::string final6Digits = this->usuario->getcpfCnpj().substr(this->usuario->getcpfCnpj().size() - 6);

  LogExcecao* logExcecao = new LogExcecao(
    this->usuario->getNome(),
    std::stoi(final6Digits),
    Data().dateNow(),
    classeAcessada,
    instanciaAcessada,
    metodoAcessado
  );
  historicoLogs->setLogExcecao(
    std::stoi(final6Digits), 
    logExcecao
  );
  std::cout << "\nVoce não possui permissão para realizar esta acao!\n";


  return false;
}
