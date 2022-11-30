#include "../includes/Login.hpp"

Login::Login() {
  this->usuario = nullptr;
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
  HistoricoDeLogs* historico = HistoricoDeLogs::getInstancia();
  historico->setLog(new LogLoginLogout(usuario->getNome(),usuario->getcpfCnpj(),Data().dateNow(),"Login",LOGIN));
}

void Login::deslogar() {
  HistoricoDeLogs* historico = HistoricoDeLogs::getInstancia();
  historico->setLog(new LogLoginLogout(usuario->getNome(),usuario->getcpfCnpj(),Data().dateNow(),"Login",LOGOUT));
  this->usuario = NULL;
}

std::string Login::getUsuarioNome() {
  return this->usuario->getNome();
}

Usuario* Login::getUsuario() { return this->usuario; }

std::string Login::getUsuarioSenha() {
  return this->usuario->getSenha();
}

bool Login::auxVerificaPermissao(int idPermissao){
  
  if (this->getInstance() == nullptr) {
    throw "Voce precisa estar logado para realizar essa ação.";
    return false;
  }
  // puxa as permissoes do usuario logado
  std::vector<Permissao*> permissoes = this->usuario->getPermissao();

  for (Permissao* permissao : permissoes) {
    if (permissao->getIdPermissao() == idPermissao) {
      return true;
    }
  }

  // Não tem a permissão.
  return false;
}

void Login::disparaExcecao(std::string frase,std::string classe,std::string instancia,std::string metodo){
  // se chegou ate aqui nao tem permissao: dispara logs
  HistoricoDeLogs* historicoLogs = HistoricoDeLogs::getInstancia();
  historicoLogs->setLog(new LogExcecao(this->usuario->getNome(),this->usuario->getcpfCnpj(),Data().dateNow(),classe,instancia,metodo));
  
  char arr[frase.length() + 1]; 
	strcpy(arr, frase.c_str()); 
  
  throw ExecaoCustomizada(arr);
}

bool Login::verificaPermissao(int idPermissao,std::string permissao,std::string classe,std::string instancia,std::string metodo) {
  std::string text = "O usuario não possuí a permissao " + permissao + "\n\n";
  if(auxVerificaPermissao(idPermissao)){
    return true;
  }else{
    disparaExcecao(text,classe,instancia,metodo);
    return false;
  }  
}

bool Login::verificaPermissao(int a,int b,std::vector<std::string> frases,std::string classe,std::string instancia,std::string metodo) {
  std::string text = "O usuario não possuí nenhuma das permissões a seguir: ";
  if(auxVerificaPermissao(a) || auxVerificaPermissao(b)){
    return true;
  }else{
    for(int i = 0;i < frases.size();i++){
      i != frases.size()-1 ? text += frases[i] + "," : text += frases[i]+"\n\n\n";
    }
    disparaExcecao(text,classe,instancia,metodo);
    return false;
  }  
}


bool Login::verificaPermissao(int a,int b,int c,std::vector<std::string> frases,std::string classe,std::string instancia,std::string metodo) {
  std::string text = "O usuario não possuí nenhuma das permissões a seguir: ";
  if(auxVerificaPermissao(a) || auxVerificaPermissao(b) || auxVerificaPermissao(c)){
    return true;
  }else{
    for(int i = 0;i < frases.size();i++){
      i != frases.size()-1 ? text += frases[i] + "," : text += frases[i]+"\n\n\n";
    }
    disparaExcecao(text,classe,instancia,metodo);
    return false;
  }  
}

bool Login::verificaPermissao(int a,int b,int c,int d,std::vector<std::string> frases,std::string classe,std::string instancia,std::string metodo) {std::string text = "O usuario não possuí nenhuma das permissões a seguir: ";
  if(auxVerificaPermissao(a) || auxVerificaPermissao(b) || auxVerificaPermissao(c) || auxVerificaPermissao(d) ){
    return true;
  }else{
    for(int i = 0;i < frases.size();i++){
      i != frases.size()-1 ? text += frases[i] + "," : text += text += frases[i]+"\n\n\n";
    }
    disparaExcecao(text,classe,instancia,metodo);
    return false;
  }  
}
