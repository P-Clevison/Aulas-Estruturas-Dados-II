#include <stdio.h>
#include <stdlib.h>

typedef struct mercadoria Mercadoria;

struct mercadoria {
    int cod_produto;
    char nome_produto, tipo_produto, fabricante, categoria;
    float preco_custo, preco_venda;
};


// Cadastra uma nova mercadoria baseado nos dados recebidos
Mercadoria* Nova_mercadoria(int cod_prod, char nome_prod, char tipo_prod, char fabric, char categ, float pcusto)
{
    printf("\n\n***** Cadastro de Mercadorias *****\n");
    Mercadoria* p1 = (Mercadoria*) malloc(sizeof(Mercadoria));
    p1->cod_produto = cod_prod;
    p1->nome_produto = nome_prod;
    p1->tipo_produto = tipo_prod;
    p1->fabricante = fabric;
    p1->categoria = categ;
    p1->preco_custo = pcusto;
    p1->preco_venda = 0.0;

    return p1;
}


// Caalcula o preço de venda de um produto
float Calcular_pvenda(Mercadoria *mc)
{
   mc->preco_venda = mc->preco_custo * 2;

   return mc->preco_venda;
}


// Altera o preço de venda de um produto
void Alterar_pvenda(Mercadoria *mc, float novo_preco)
{
   float preco_antigo = mc->preco_venda;
   mc->preco_venda = novo_preco;
   printf("Preco foi atualizado de: %f para %f", preco_antigo, mc->preco_venda);

}
