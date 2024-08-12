#include <stdio.h>
#include "Mercadoria.h"

int main() {
	int oper = 0;
	int cod_produto;
	char nome_produto, tipo_produto, fabricante, categoria;
	float pcusto, pvenda, novo_pvenda;
	Mercadoria *p;

	while (oper == 0)
	{
		printf("\n\nSelecione uma operacao para ser realizada: \n 1. Cadastrar mercadoria \n 2. Calcular preco de venda \n 3. Alterar preco de venda \n\n");
		oper = -1;
		scanf("%d", &oper);

		if (oper == 1)
		{
			printf("\nDigite o codigo do produto: ");
			scanf("%d", &cod_produto);
			printf("\nDigite o nome do produto: ");
			scanf("%s", &nome_produto);
			printf("\nDigite o tipo do produto: ");
			scanf("%s", &tipo_produto);
			printf("\nDigite o fabricante do produto: ");
			scanf("%s", &fabricante);
			printf("\nDigite a categoria do produto: ");
			scanf("%s", &categoria);
			printf("\nDigite o preco de custo do produto: ");
			scanf("%f", &pcusto);

			p = Nova_mercadoria(cod_produto, nome_produto, tipo_produto, fabricante, categoria, pcusto);
			printf("%p", p);

			oper = 0;
		}
		if (oper == 2)
		{
			if (p !=NULL)
			{
				pvenda = Calcular_pvenda(p);
				printf("O preco de venda sera: %1f", pvenda);
			}
		}
		if (oper == 3)
		{
			if (p !=NULL)
			{
				scanf("%f", &pvenda);
				Alterar_pvenda(p, pvenda);
				printf("O preço de venda foi atualizado de : %f", pvenda);
				printf(" para : %f", novo_pvenda);
			}
		}

	}






	return 0;
}
