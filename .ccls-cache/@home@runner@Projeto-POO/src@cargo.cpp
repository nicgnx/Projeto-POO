#include "../includes/Cargo.hpp"

Cargo::Cargo(std::string cargo) {
  this->cargo = cargo;
}

Cargo::Cargo(){
  this->cargo.clear();
}

Cargo::~Cargo(){}


std::string Cargo::getCargo (){
  return this->cargo;
}

void Cargo::setCargo (std::string cargo){
  this->cargo = cargo;
}