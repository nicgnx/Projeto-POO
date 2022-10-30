#include "../includes/Utils.hpp"

Utils::Utils() { }

bool Utils::verificaCPF(std::string cpf) {
  // CPF deve estar sem pontos, traços ou espaço em branco
  int digito1,
      digito2,
      temp = 0;

  // verifica se tem 11 digitos
  if (strlen(cpf) != 11) {
    return false;
  }

  // verifica se todos os digitos sao numericos
  if (!std::all_of(cpf.begin(), cpf.end(), ::isdigit)) {
    return false;
  }

  // verifica o primeiro digito verificador
  for(char i = 0; i < 9; i++)
      temp += (cpf[i] * (10 - i));

  temp %= 11;

  if(temp < 2)
      digito1 = 0;
  else
      digito1 = 11 - temp;

  // verifica o segundo digito verificador
  temp = 0;
  for(char i = 0; i < 10; i++)
      temp += (cpf[i] * (11 - i));

  temp %= 11;

  if(temp < 2)
    digito2 = 0;
  else
    digito2 = 11 - temp;

  // compara os digitos verificadores com os informados pelo cliente
  if(digito1 == cpf[9] && digito2 == cpf[10])
    return true;
  else
      return false;
}

bool Utils::verificaCNPJ(std::string cnpj) {
  // CNPJ deve estar sem pontos, traços ou espaço em branco

  // verifica se tem 14 digitos
  if (strlen(cnpj) != 14) {
    return false;
  }

  // verifica se todos os digitos sao numericos
  if (!std::all_of(cnpj.begin(), cnpj.end(), ::isdigit)) {
    return false;
  }

  // se chegou até aqui, é CNPJ válido
  return true;
}

