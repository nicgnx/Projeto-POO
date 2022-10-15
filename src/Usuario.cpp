#include <iostream>

#include "../includes/Usuario.hpp"


std::string Usuario::getNome(){
  
  return this->nome;
}

std::string Usuario::getcpfCnpj(){
  
  return this->cpfCnpj;
}

std::string Usuario::getEmail(){
  
  return this->email;
}

std::string Usuario::getSenha(){
  
  return this->senha;
}

std::vector <Permissao*> Usuario::getPermissao(){
  
  return this->permissoes;
}

void Usuario::setNome(std::string nome){

  this->nome = nome;
}

void Usuario::setcpfCnpj(std::string cpfCnpj){

  this->cpfCnpj = cpfCnpj;
}

void Usuario::setEmail(std::string email){

  this->email = email;
}

void Usuario::setSenha(std::string senha){

  this->senha = senha;
}

void Usuario::adicionaPermissoes(Permissao* permissao){

  this->permissoes.push_back(permissao);
}