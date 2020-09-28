#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack.h"
#include "oper.h"
#include "text.h"



int main(int argc, char const *argv[]) {
	int a = 1;
	srand(time(NULL));
	do {
		//Iniciando o menu principal
		limpa_buffer();
		int *menu = menu_principal();
		switch(*menu) {
			/* Caso o jogador queira iniciar o jogo*/
			case 1:
				iniciando_jogo();
				break;
			/* Imprimindo as intruções do jogo */
			case 2:
				//Intruções do Jogo();
				system("cls");
				ler_arquivo ();
				system("pause");
				break;
			//Imprimindo os creditos
			case 3:
				creditos();
				break;
			//Saindo do jogo
			case 4:
				a = sair_jogo();		
				break;
		
		}
	} while (a);
	return 0;
}