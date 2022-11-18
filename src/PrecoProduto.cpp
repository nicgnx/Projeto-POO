#include "../includes/PrecoProduto.hpp"

PrecoProduto::PrecoProduto(
    float precoBase, float percentualVariacao, Data dataVariacao
) {
    this->precoBase = precoBase;
    this->percentualVariacao = percentualVariacao;
    this->dataVariacao = dataVariacao;
}

PrecoProduto::PrecoProduto() {} // construtor padrão

PrecoProduto::~PrecoProduto() {} // destrutor

float PrecoProduto::getPrecoBase() { return this->precoBase; }

float PrecoProduto::getPercentualVariacao() { return this->percentualVariacao; }

Data PrecoProduto::getDataVariacao() { return this->dataVariacao; }

void PrecoProduto::setPrecoBase(float precoBase) {
    this->precoBase = precoBase;
}

void PrecoProduto::setPercentualVariacao(float percentualVariacao) {
    this->percentualVariacao = percentualVariacao;
}

void PrecoProduto::setDataVariacao(Data dataVariacao) {
    this->dataVariacao = dataVariacao;
}
