#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Limpando buffer */
void limpa_buffer() {
	setbuf(stdin, NULL);
}
/* Criando mesa para os jogadores */
int *cria_mesa (int n) {
	//Criando um vetor dinamico
	int *mesa = malloc (n * sizeof(int));
	//inserindo um valor aleatorio de 1 a 13
	for (int i = 0; i < n; ++i) {
		mesa[i] = (rand() % 13) + 1;
	}
	return mesa;
}
// Liberando um vetor dinamico
void libera_memoria (int *vetor) {
	free(vetor);
}

//Somando as cartas no vetor dinamico
int soma_mesa (int *mesa, int cartas) {
	int soma = 0, i;
	int aux = 0;
	//Percorrendo o vetor dinamico para ver se tem um blackjack
	if (cartas == 2) {
		for (i = 0; i < cartas; ++i) {
			/* Se o vetor encontrar um ás e junto ele encontrar um Valete, um Dama e Reis
			Lembrando que isso só ocorrerá se tiver 2 cartas... 
			Obtendo um blackjack..*/
			if (mesa[i] == 1) {
				for (int j = 0; j < cartas; ++j) {
					if (mesa[j] == 11 || mesa[j] == 12 || mesa[j] == 13) aux++;
				}
			}
		}
	}
	// Soma das cartas quando há um blackjack  da 21
	if (aux == 2) {
		soma = 21;
		return soma;
	//Se não tiver blackjack, ele irá analisar as condições das outras cartas para somar
	} else {
		// Cartas de Imagem como Valete, Damas e Reis vale 10.
		for (i = 0; i < cartas; ++i) {
			if (mesa[i] == 11 || mesa[i] == 12 || mesa[i] == 13) {
				soma = soma + 10;
			//Cartas de A para 10 é a propria soma
			} else {
				soma = soma + mesa[i];
			}
		}
		return soma;
	}
}

//Pedir  cartas
int *pedir_cartas (int *mesa, int cartas) {
	//Quando for pedir carta, o vetor dinamico sera realocado + 1
	mesa = realloc (mesa, cartas * sizeof(int));
	//A ultima posicao que foi criada receberá uma valor aleatorio
	mesa[--cartas] = (rand () % 13) + 1;
	return mesa;
}

//Funcao que serve para reiniciar o jogo, ou seja, devolver as caras, zerar as apostas....
void reiniciando_jogo (int *preg, int *ppc, int *pjo, int *ppa, int *pja, int *pps, int *pjs, int *paux) {
	*preg = 0; //Aux aposta = 0 
	*ppc = 1;  //Cartas para mesa 1
	*pjo = 1;  //Cartas para o jogador 1
	*ppa = 0; //aposta do pc zerada
	*pja = 0; //aposta do jogador zerada
	*pps = 0;  // soma das cartas do pc zerada
	*pjs = 0; //soma das cartas jogador zerada
	*paux = 0; //aux de finalizar = 0
}