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
    Mercadoria mc;
    printf("\n\n***** Cadastro de Mercadorias *****\n");
    Mercadoria* p1 = (Mercadoria*) malloc(sizeof(Mercadoria));
    mc.cod_produto = cod_prod;
    mc.nome_produto = nome_prod;
    mc.tipo_produto = tipo_prod;
    mc.fabricante = fabric;
    mc.categoria = categ;
    mc.preco_custo = pcusto;
    mc.preco_venda = 0.0;

    return p1;
}


// Caalcula o preço de venda de um produto
float Calcular_pvenda(Mercadoria *mc)
{
   printf("Preco de custo é: %f", mc->preco_venda);
   mc->preco_venda = mc->preco_custo * 2;

   return mc->preco_venda;
}


// Altera o preço de venda de um produto
float Alterar_pvenda(Mercadoria *mc, float novo_preco)
{
   float preco_antigo = mc->preco_venda;
   mc->preco_venda = novo_preco;

   return *mc, preco_antigo, mc->preco_venda;
}