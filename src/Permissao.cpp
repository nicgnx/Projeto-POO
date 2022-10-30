#include "../includes/Permissao.hpp"
#include <iostream>

Permissao::Permissao(int idPermissao, std::string descricao){
  this->idPermissao = idPermissao;
  this->descricao = descricao;
}

int Permissao::getIdPermissao(){
  return this->idPermissao;
}

std::string Permissao::getDescricao(){
  return this->descricao;
}

void Permissao::setIdPermissao(int idPermissao){
  this->idPermissao = idPermissao;
}

void Permissao::setDescricao(std::string descricao){
  this->descricao = descricao;
}