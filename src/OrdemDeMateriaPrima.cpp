#include "../includes/OrdemDeMateriaPrima.hpp"

    OrdemDeMateriaPrima::OrdemDeMateriaPrima(int quantidade, std::string materiaPrima, Data data) {
      this->quantidade = quantidade;
      this->materiaPrima = materiaPrima;
      this->data = data;
      
    }
    OrdemDeMateriaPrima::~OrdemDeMateriaPrima() {
      
    }

    //getters
    std::string OrdemDeMateriaPrima::getMateriaPrima() {
      return this->materiaPrima;
    }
    int OrdemDeMateriaPrima::getquantidade() {
      return this->quantidade;
    }
    Data OrdemDeMateriaPrima::getData() {
      return this->data;
    }

    //setters
    void OrdemDeMateriaPrima::setMateriaPrima(std::string materiaPrima) {
      this->materiaPrima = materiaPrima;
    }
    void OrdemDeMateriaPrima::setQuantidade(int quantidade) {
      this->quantidade = quantidade;
    }
    void OrdemDeMateriaPrima::setData(Data data) {
      this->data = data;
    }