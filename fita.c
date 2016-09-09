/*
 ============================================================================
 Name        : fita.c
 Author      : Eric Azevedo Carvalho
 Version     : 1.0
 Description : Questão da
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	// Variáveis
	int fita[13],			// fita inicial -> OBS: basta mudar para 1000 para atender a questao
		fita_teste[13],		// fita para testar
		posicao_gota, 		// posicao da gota na fita
		pingar = 1,			// testa se o usuário está pingango em lugar valido
		propagacao,			// crescimento da expansão por dia
		inicio_simetria,	// posicicao inicial da expansão para manter a simetria
		dias = 1,			// contagem de dias
		novo_dia = 0;		// testa se precisa ou nao de um novo dia

	// Zera a fita
	for(int i=0; i<13; i++) fita[i]=0;

	// Marca pontos iniciais de acordo com a entrada do usuário
	do{
		scanf("%d",&posicao_gota);
		if(posicao_gota>0 && posicao_gota<14){
			fita[posicao_gota-1] = 1;
		}else{
			pingar = 0; // Se o usuário digitar algo fora do limite da fita para de pingar
		}
	}while(pingar);

	// #DESCARTÁVEL - Imprime preenchimento inicial do usuário
	for(int z=0; z<13; z++) printf("%d ",fita[z]);
	printf("\n");

	do{
		for(int i=0; i<13; i++) fita_teste[i]=0;
		// calcula o tamanho da propagacao no dia atual
		propagacao = 1 + (dias*2);
		// para cada dia percorre a fita em busca da gota inicial
		for(int z=0; z<13; z++){
			if(fita[z]){
				// determina a posição inicial da propagação para manter a simetria
				inicio_simetria = (z - dias);
				// marca na fita auxiliar a propagação
				for(int i=0; i<propagacao; i++){
					// se o index não existe nada acontece
					// caso contrário a marcação é feita na fita auxiliar
					fita_teste[inicio_simetria] = 1;
					// vai para a proxima posicao da propagacao
					inicio_simetria += 1;
				};
			}
		}
		// ver se a fita auxiliar foi completamente marcada
		// se nao foi 'novo-dia' é setado como '0' e o while continua
		novo_dia = 0;
		for(int i=0; i<13; i++){
			if(fita_teste[i] == 0){
				novo_dia = 1;
			}
		};
		// incrementa o dia
		dias += 1;
		// #DESCARTÁVEL - Imprime estado atual da fita auxiliar
		for(int i=0; i<13; i++) printf("%d ",fita_teste[i]);
		printf("\n");

	}while(novo_dia);
	dias -= 1;
	printf("o número de dias para a fita ficar ficar completamente tomada pelo reagente é: %d", dias);

	return 0;
}