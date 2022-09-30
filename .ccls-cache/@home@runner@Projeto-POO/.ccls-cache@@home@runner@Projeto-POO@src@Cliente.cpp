
#include <iostream>
#include <string>
#include "../includes/Usuario.hpp"


Cliente::Cliente(std::string nome, std::string email, std::string cpfCnpj, tipoPessoa tipo, unsigned int telefone){
  
  this->nome = nome;
  this->email = email;
  this->cpfCnpj = cpfCnpj;
  this->tipoPessoa = tipoPessoa;
  this->telefone = telefone;
  
}

Cliente::~Cliente() {

}