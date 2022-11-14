## FALTANDO FAZER

(3) alinhar maneira de fazer singleton (alguns lugares estão sem e outros feitos de maneiras diferentes)
	* aplicar Singleton no codigo a todas as classes que precisam ser singleton conforme o modelo

(5) implementar classes Estoque, MateriaPrima, OrdemDeMateriaPrima, Fornecedor conforme modelo mais recente
	* deixar funcional

(6) implementar classes Orçamento, ItensDesejados, PedidoDeCompra, RegistroDeVenda, PagamentoAbstrata, Boleto, Credito conforme modelo mais recente
	* deixar funcional

(8) implementar alterações na classe Funcionario (Sprint 7).
  * deixar funcional

(9) (fazer por ultimo) passar a limpo todas funcionalidades de todas sprints e ver se o codigo atende tudo

(10) (fazer por ultimo) revisao geral do codigo conforme funcionalidades passadas a limpo
	* padronizações, tratamentos de erros e casos particulares, etc

----------------------------------------------------------------------


## EM ANDAMENTO -> colocar nome de quem está fazendo

(2) (Raphael) implementar funcionalidade de permissões
	* fazer os métodos necessários verificarem a permissão do usuario logado e disparar
	exceção se não tiver
  * testar funcionalidade de login junto aqui

(1) (Gustavo) implementar funcionalidade de Logs
	* finalizar implementação - OK
	* testar com outros métodos criando logs de erro, operação, etc
     * Testado separado do código, funcionando. Falta implementar logs nas classes do projeto e testar.

(4) (Gustavo) adaptar classe Empresa para o modelo mais recente.
  * Alterar o construtor da classse afim dele para criar um usuário root que possuí todas as permissões quando a 1º instância de Empresa é criada.
    * Precisamos de decidir e implementar as permissões para fazer esse ponto.

(7) (Gustavo) implementar classes Veiculo e Turno.
  * deixar funcional
  * Classe Turno - OK
  * Classe Veiculo - Parcialmente concluída. Falta implementar os métodos calculaDistancia() e defineRota().


----------------------------------------------------------------------

## FEITAS -> colocar nome de quem fez

