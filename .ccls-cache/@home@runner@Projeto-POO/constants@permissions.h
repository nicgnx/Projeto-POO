#ifndef PERMISSOES_H
#define PERMISSOES_H

// os ints representam o id da instancia da permissao
struct PERMISSOES {
  const int LOGAR = 0;
  const int CADASTRAR_EDITAR_FUNCIONARIO = 1;
  const int CADASTRAR_EDITAR_CLIENTE = 2;
  const int EDITAR_SALARIO = 3;
  const int DEMITIR_FUNCIONARIO = 4;
  const int CADASTRAR_EDITAR_PRODUTO = 5;
  const int EMITIR_ORDEM = 8;
  const int COMPRAR_PRODUTO = 7;
  const int EDITAR_PERMISSOES = 8;
  const int EDITAR_EMPRESA = 9;
};

#endif // PERMISSOES_H