#include "../includes/Cargo.hpp"

Cargo::Cargo(std::string nome) {
  this->nome = nome;
}

std::string Cargo::getCargo (){
  return this->nome;
}

void Cargo::setCargo (std::string nome){
  this->nome = nome;
}