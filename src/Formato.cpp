#include "../includes/Formato.hpp"
#include "../includes/ExecaoCustomizada.hpp"
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

Formato::Formato() {
  nome = "PT-BR";
  separadorData = '/';
  separadorHorario = ':';
}

Formato::Formato(string valNome) {
  nome = valNome;
  if (strcmp(valNome.c_str(), "PT-BR") == 0)
    separadorData = '/';
  else if (strcmp(valNome.c_str(), "EN-US") == 0)
    separadorData = '-';
  separadorHorario = ':';
}

Formato::~Formato() {}

string Formato::getNome() { return nome; }

string Formato::getSeparadorData() { return separadorData; }

string Formato::getSeparadorHorario() { return separadorHorario; }
