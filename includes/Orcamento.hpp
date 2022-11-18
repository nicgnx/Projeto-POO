#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "ItensDesejados.hpp"
#include "PedidoDeCompra.hpp"
#include <vector>

class Orcamento {
protected:
    std::string cliente;
    int cpfCnpj;
    std::string email;
    vector<ItensDesejados> carrinho;
    float valorTotal;
    Data data;
    PedidoDeCompra pedido;

public:
    // Construtores e Destrutores
    Orcamento(
        std::string cliente, int cpfCnpj, std::string email,
        vector<ItensDesejados> carrinho, float valorTotal, Data data,
        PedidoDeCompra pedido
    );
    Orcamento();
    ~Orcamento();

    // getters
    std::string getCliente();
    int getCpfCnpj();
    std::string getEmail();
    vector<ItensDesejados> getCarrinho();
    float getValorTotal();
    Data getData();
    PedidoDeCompra getPedido();

    // setters
    void setCliente(std::string cliente);
    void setCpfCnpj(int cpfCnpj);
    void setEmail(std::string email);
    void setCarrinho(vector<ItensDesejados> carrinho);
    void setValorTotal(float valorTotal);
    void setData(Data data);
    void setPedido(PedidoDeCompra pedido);

    // misc
    bool verificaOrcamento(vector<ItensDesejados> carrinho);
    void printaOrcamento();
    PedidoDeCompra gerarPedidoDeCompra(
        vector<ItensDesejados> itens, string tipoPagamento, string forma
    );
};

#endif // ORCAMENTO_H