#include "../includes/Cliente.hpp"
#include <iostream>

Cliente::Cliente(){}

Cliente::Cliente(std::string nome, std::string email, std::string cpfCnpj, tipoPessoa tipo, unsigned int telefone){

  this->nome = nome;
  this->email = email;
  this->cpfCnpj = cpfCnpj;
  this->tipo = tipo;
  this->telefone = telefone;
}

Cliente::~Cliente() {}

unsigned int Cliente::getTelefone(){
  return this->telefone;
}

tipoPessoa Cliente::getTipoPessoa(){
  return this->tipo;
}

void Cliente::setTipoPessoa(tipoPessoa tipo){
  this->tipo = tipo;
}

void Cliente::setTelefone(unsigned int telefone){
  this->telefone = telefone;
}
