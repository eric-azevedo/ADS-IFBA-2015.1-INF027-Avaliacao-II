/*
============================================================================
Name        : fita.c
Author      : Eric Azevedo Carvalho
Version     : 1.0
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int fita[13], fita_teste[13], posicao_gota, pingar = 1,
		propagacao,	inicio_simetria, dias = 1, novo_dia = 0;
	for(int i=0; i<13; i++) fita[i]=0;
	do{
		scanf("%d",&posicao_gota);
		if(posicao_gota>0 && posicao_gota<14){
			fita[posicao_gota-1] = 1;
		}else{
			pingar = 0;
		}
	}while(pingar);
	do{
		for(int i=0; i<13; i++) fita_teste[i]=0;
		propagacao = 1 + (dias*2);
		for(int z=0; z<13; z++){
			if(fita[z]){
				inicio_simetria = (z - dias);
				for(int i=0; i<propagacao; i++){
					fita_teste[inicio_simetria] = 1;
					inicio_simetria += 1;
				};
			}
		}
		novo_dia = 0;
		for(int i=0; i<13; i++){
			if(fita_teste[i] == 0) novo_dia = 1;
		};
		dias += 1;
	}while(novo_dia);
	dias -= 1;
	printf("O número de dias para a fita ficar ficar completamente tomada pelo reagente é: %d", dias);
	return 0;
}