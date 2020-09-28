#include <stdio.h>
#include "oper.h"


//Menu principal ou Tela  Inicial
int *imprime_menuprincipal () {
	int *menu, opcao;
	/*Menu principal para aparecer no começo do jogo*/
	printf("\t+------------------------------------------------------------------------------+\n");
	printf("\t|                                                                      x       | \n");
	printf("\t|  xxxx   x     xx   xxxx  x  x        x   xx   xxxx  x  x            xxx      | \n");
	printf("\t|  x   x  x    x  x  x     x x         x  x  x  x     x x            xxxxx     | \n");
	printf("\t|  xxxxx  x    x  x  x     xx          x  x  x  x     xx            xxxxxxx    | \n");
	printf("\t|  xxxx   x    xxxx  x     xx          x  xxxx  x     xx            xxxxxxx    | \n");
	printf("\t|  x   x  x    x  x  x     x x      x  x  x  x  x     x x           xxxxxxx    | \n");
	printf("\t|  xxxxx  xxx  x  x  xxxx  x  x     xxxx  x  x  xxxx  x  x            xxx      | \n");
	printf("\t|                                                                    xxxxx     | \n");
	printf("\t+------------------------------------------------------------------------------+\n");
	printf("\n\n\t\t\t - - - - - - M E N U  P R I N C I P A L - - - - - -\n");
	printf("\n\t\t\t |  1 - INICIAR O JOGO                              |\n");
	printf("\n\t\t\t |  2 - INSTRUCOES DO JOGO                          |\n");
	printf("\n\t\t\t |  3 - CREDITOS                                    |\n");
	printf("\n\t\t\t |  4 - SAIR DO JOGO                                |\n");
	printf("\n\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("\n\t\t\t --> Escolha a opcao que deseja: ");
	limpa_buffer();
	scanf("%d", &opcao);
	menu = &opcao;
	return menu;
}

//Imprimindo a tela de créditos
void creditos_txt () {
	/* Integrantes do Grupo: Participantes do Grupo*/
	printf("\t+------------------------------------------------------------------------------+\n");
	printf("\t|                                                                      x       | \n");
	printf("\t|  xxxx   x     xx   xxxx  x  x        x   xx   xxxx  x  x            xxx      | \n");
	printf("\t|  x   x  x    x  x  x     x x         x  x  x  x     x x            xxxxx     | \n");
	printf("\t|  xxxxx  x    x  x  x     xx          x  x  x  x     xx            xxxxxxx    | \n");
	printf("\t|  xxxx   x    xxxx  x     xx          x  xxxx  x     xx            xxxxxxx    | \n");
	printf("\t|  x   x  x    x  x  x     x x      x  x  x  x  x     x x           xxxxxxx    | \n");
	printf("\t|  xxxxx  xxx  x  x  xxxx  x  x     xxxx  x  x  xxxx  x  x            xxx      | \n");
	printf("\t|                                                                    xxxxx     | \n");
	printf("\t+------------------------------------------------------------------------------+\n");
	printf("\n\n\t\t\t - - - - I N T E G R A N T E S - - - -");
	printf("\n\t\t\t |  BRUNO BERTATO                     |");
	printf("\n\t\t\t |  BRUNO KADOOKA                     |");
	printf("\n\t\t\t |  FLAMERY FONSECA                   |");
	printf("\n\t\t\t |  GABRIELA BUENO                    |");
	printf("\n\t\t\t |  GABRIEL ZUIN                      |");
	printf("\n\t\t\t |  LUIS GUILHERME ROBLES             |");
	printf("\n\t\t\t - - - - - - - - - - - - - - - - - - \n\n");
}


//Imprimindo o cabeçalho das jogadas
void imprime_cabecalho (int pote) {
	printf(" BLACKJACK \t\t\t\t\tValor do Pote: %d\n", pote);
	printf("\n Menu de Jogadas: 1 - Sair do Jogo \t2 - Apostar \t3 - Pedir Cartas\t4 - Finalizar\n\n");
}

//Imprimindo a tela do pc mesa
void imprime_pc_mesa (int pc_caixa, int pc_aposta, int *pc_mesa, int pc_cartas) {

	int soma = soma_mesa (pc_mesa, pc_cartas);

	printf("\t\t - - - - - - - - - PC MESA - - - - - - - - -\n");
	printf("\t\t Valor do Caixa: %d          APOSTA: %d \n", pc_caixa, pc_aposta);
	printf("\n");
	printf("\t\t Cartas na mao: ");
	/* Substituindo os valores:
	1: A
	11:J
	12:Q
	13:K */
	for (int i = 0; i < pc_cartas; ++i) {
			if (pc_mesa[i] == 1) {
			printf(" **********      \n");
			printf(" * A      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      A *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 11) {
			printf(" **********      \n");
			printf(" * J      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      J *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 12) {
			printf("  **********      \n");
			printf("  * Q      *      \n");
			printf("  *        *      \n");
			printf("  *        *      \n");
			printf("  *        *      \n");
			printf(" *         *      \n");
			printf(" *       Q *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 13) {
			printf(" **********      \n");
			printf(" * K      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      K *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 2) {
			printf(" **********      \n");
			printf(" * 2      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      2 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 3) {
			printf(" **********      \n");
			printf(" * 3      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      3 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 4) {
			printf(" **********      \n");
			printf(" * 4      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      4 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 5) {
			printf(" **********      \n");
			printf(" * 5      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      5 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 6) {
			printf(" **********      \n");
			printf(" * 6      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      6 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 7) {
			printf(" **********      \n");
			printf(" * 7      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      7 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 8) {
			printf(" **********      \n");
			printf(" * 8      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      8 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 9) {
			printf(" **********      \n");
			printf(" * 9      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      9 *      \n");
			printf(" **********      \n");
		} else if (pc_mesa[i] == 10) {	
			printf(" **********      \n");
			printf(" * 10     *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *     10 *      \n");
			printf(" **********      \n");
		}
	}

	printf("\n\n");
	printf("\t\t Soma das cartas: %d\n", soma);
	printf("\t\t - - - - - - - - - - - - - - - - - - - - - -\n\n\n");
}

//Imprindo tela do jogador
void imprime_jogador_mesa (int jo_caixa, int jo_aposta, int *jo_mesa, int jo_cartas) {

	int soma = soma_mesa (jo_mesa, jo_cartas);

	printf("\t\t - - - - - - - - - JOGADOR - - - - - - - - -\n");
	printf("\t\t Valor do Caixa: %d          APOSTA: %d \n", jo_caixa, jo_aposta);
	printf("\n");
	printf("\t\t Cartas na mao: ");
	/* Substituindo os valores:
	1: A
	11:J
	12:Q
	13:K */
	for (int i = 0; i < jo_cartas; ++i) {
			if (jo_mesa[i] == 1) {
			printf(" **********      \n");
			printf(" * A      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      A *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 11) {
			printf(" **********      \n");
			printf(" * J      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      J *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 12) {
			printf("  **********      \n");
			printf("  * Q      *      \n");
			printf("  *        *      \n");
			printf("  *        *      \n");
			printf("  *        *      \n");
			printf(" *         *      \n");
			printf(" *       Q *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 13) {
			printf(" **********      \n");
			printf(" * K      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      K *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 2) {
			printf(" **********      \n");
			printf(" * 2      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      2 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 3) {
			printf(" **********      \n");
			printf(" * 3      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      3 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 4) {
			printf(" **********      \n");
			printf(" * 4      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      4 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 5) {
			printf(" **********      \n");
			printf(" * 5      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      5 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 6) {
			printf(" **********      \n");
			printf(" * 6      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      6 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 7) {
			printf(" **********      \n");
			printf(" * 7      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      7 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 8) {
			printf(" **********      \n");
			printf(" * 8      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      8 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 9) {
			printf(" **********      \n");
			printf(" * 9      *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *      9 *      \n");
			printf(" **********      \n");
		} else if (jo_mesa[i] == 10) {	
			printf(" **********      \n");
			printf(" * 10     *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *        *      \n");
			printf(" *     10 *      \n");
			printf(" **********      \n");
		}
	}
	printf("\n\n");
	printf("\t\t Soma das cartas: %d\n", soma);
	printf("\t\t - - - - - - - - - - - - - - - - - - - - - -\n\n\n");
}

void ler_arquivo () {
	FILE *f;
	char c;
	f = fopen("instrucao.txt", "r");
    if (f == NULL) {
      printf("O arquivo nao pode ser aberto e lido");
    }else{
		while ((c = fgetc(f)) != EOF) {
			printf("%c", c);
      	}
    }
  fclose(f);
}