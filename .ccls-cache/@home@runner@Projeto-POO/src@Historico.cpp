#include "../includes/Historico.hpp"
#include "../includes/Data.hpp"
#include <string>

Historico::Historico(int ano, int mes, int dia, int hora, int minuto,
                     int segundo, std::string reg) {
  Data data(ano, mes, dia, hora, minuto, segundo);
  std::string registro = reg;
}

Historico::~Historico() {}

Data Historico::getData() {
  Data intermediarioData;
  intermediarioData.setAno(data.getAno());
  intermediarioData.setMes(data.getMes());
  intermediarioData.setDia(data.getDia());
  intermediarioData.setHora(data.getHora());
  intermediarioData.setMin(data.getMin());
  intermediarioData.setSeg(data.getSeg());
  return intermediarioData;
}

std::string Historico::getRegistro() {
  std::string intermediarioReg = " ";
  intermediarioReg = registro;
  return intermediarioReg;
}

void Historico::setData(Data intermediarioData) { data = intermediarioData; }

void Historico::setRegistro(std::string intermediarioString) {
  registro = intermediarioString;
}