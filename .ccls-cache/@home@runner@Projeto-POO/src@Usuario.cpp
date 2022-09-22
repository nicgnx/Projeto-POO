
#include <iostream>
#include <string>
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

void Usuario::setNome(std::string nome){

  this->nome = nome;
}

void Usuario::setcpfCnpj(std::string cpfCnpj){

  this->cpfCnpj = cpfCnpj;
}

void Usuario::setEmail(std::string email){

  this->email = email;
}