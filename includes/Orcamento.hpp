#ifndef ORCAMENTO_H
#define ORCAMENTO_H



class Orcamento {
protected:
  std::string cliente;
  int cpfCnpj;
  std::string email;
  // std::string cliente;
  float valorTotal;
  Data data;
  P cliente;
  std::string cliente;
  std::string cliente;

public:
  // Construtores e Destrutores
  Orcamento(
    std::string inforacao
  );
  Orcamento();
  ~Orcamento();

  // Getters
  std::string getInformacao();

  // Setters
  void setInformacao(std::string informacao);
};


#endif // ORCAMENTO_H