#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "oper.h"

/* Abertura do Menu Principal com as mensagens, limpando a tela, e observando as opções desejada... */
int *menu_principal () {
	int *menu, a = 0;
	do {
		system("cls");
		limpa_buffer();
		menu = imprime_menuprincipal();
		if (*menu >= 1 && *menu <= 4) {
			a = 0;
		}
		else {
			printf("\nOpcao invalida...\n");
			system("pause");
			a = 1;
		} 
	} while (a);
	return menu;
}
/* Saindo do jogo na parte do menu */
int sair_jogo () {
	printf("Saindo do jogo...\n");
	system("pause");
	return 0;
}
/* Creditos inserindo os dados do grupo */
void creditos () {
	system("cls");
	creditos_txt ();
	system("pause");
}
/* Iniciando o jogo */
void iniciando_jogo () {
	int a = 1; // Saindo do-while
	//Variaveis do jogo
	int pc_cartas = 1, jo_cartas = 1, *ppc = &pc_cartas, *pjo = &jo_cartas;
	int pc_caixa = 1000, jo_caixa = 1000;
	int pc_aposta = 0, jo_aposta = 0, *ppa = &pc_aposta, *pja = &jo_aposta;
	int pote = 0;
	int jogada, reg = 0, *preg = &reg;
	int jo_soma = 0, pc_soma = 0, *pps = &pc_soma, *pjs = &jo_soma;
	int aux = 0, *paux = &aux;
	jo_caixa = pc_caixa;
	/* Criando uma mesa para o jogador e para o PC */
	int *jo_mesa = cria_mesa(jo_cartas);
	int *pc_mesa = cria_mesa(pc_cartas);
	do {
		/* Condições para ganhar o jogo ...
		SE o caixa do PC zerar, o Jogador irá ganhar */
		if (pc_caixa <= 0 && pc_aposta == 0) {
			printf("\n\nPARABENS....\nVOCE GANHOU\n\n");
			system("pause");
			a = 0;
			break;
		/*SENAO SE o caixa do Jogador zerar, o PC irá ganhar*/
		} else if (jo_caixa <= 0 && jo_aposta == 0) {
			printf("\n\nINFELIZMENTE....\nVOCE PERDEU\n\n");
			system("pause");
			a = 0;
			break;
		/* SENAO SE nenhum caixa zerar irá rodar o jogo normalmente, encerrando apenas a jogada */
		} else {
			/* Parte de design do jogo, imprimindo as telas iniciais do jogo */		
			system("cls");
			limpa_buffer();
			imprime_cabecalho (pote);
			imprime_pc_mesa (pc_caixa, pc_aposta, pc_mesa, pc_cartas);
			imprime_jogador_mesa (jo_caixa, jo_aposta, jo_mesa, jo_cartas);
			/* Somando o total de cartas na mão do Jogador e do PC */
			jo_soma = soma_mesa (jo_mesa, jo_cartas);
			pc_soma = soma_mesa (pc_mesa, pc_cartas);
			/* Depois da soma das cartas será analisadas algumas condições de vitória e a IA da máquina */

			/* IA da máquina: irá analisar a soma das cartas do Jogador, enquanto for menor do jogador e abaixo de 21
			a PC-MESA irá pedir cartas para sua mão.
			Lembrando que o PC precisa saber quando é sua vez, ou seja, precisa saber quando a jogada do Jogador for encerrada
			entao há o aux != 0 significa que o jogador encerrou a jogada.*/
			if (aux != 0 && (pc_soma <= jo_soma && pc_soma < 21)) {
				pc_cartas++;
				pc_mesa = pedir_cartas (pc_mesa, pc_cartas);
			/* Se o jogador fizer uma soma superior de 21 pontos ao encerrar uma jogada, entao ele irá perder, pois estorou a soma total*/
			} else if (jo_soma > 21 && jo_aposta != 0) {
				printf("Voce estorou... Vitoria do PC-MESA\n");
				system("pause");
				libera_memoria (pc_mesa);
				pc_mesa = cria_mesa(pc_cartas);
				reiniciando_jogo (preg, ppc, pjo, ppa, pja, pps, pjs, paux);
				pc_caixa += pote;
				pote = 0;
				libera_memoria(jo_mesa);
				jo_mesa = cria_mesa(jo_cartas);
			/* Se o Jogador fizer uma soma total de 21 pontos, ou seja, um blackjack, entao a vitória é do Jogador */
			} else if (jo_soma == 21 && jo_aposta != 0) {
				printf("Voce efetuou o BlackJack... Portanto voce VENCEU\n");
				system("pause");
				libera_memoria (pc_mesa);
				pc_mesa = cria_mesa(pc_cartas);			
				reiniciando_jogo (preg, ppc, pjo, ppa, pja, pps, pjs, paux);
				jo_caixa += pote;
				pote = 0;
				libera_memoria(jo_mesa);
				jo_mesa = cria_mesa(jo_cartas);
			/* Se o PC fizer uma soma de 21, a vitoria é do PC */
			} else if (pc_soma == 21 && pc_aposta != 0) {
				printf("A maquina efetuou o BlackJack... Portanto voce PERDEU\n");
				system("pause");
				libera_memoria (pc_mesa);
				pc_mesa = cria_mesa(pc_cartas);			
				reiniciando_jogo (preg, ppc, pjo, ppa, pja, pps, pjs, paux);
				pc_caixa += pote;
				pote = 0;
				libera_memoria(jo_mesa);
				jo_mesa = cria_mesa(jo_cartas);
			/* --> Caso os pontos da máquina seja maior que os pontos do Jogador e abaixo de 21 pontos, a vitoria é do PC 
			   --> Esta condição nao existe para o Jogador, porque caso o jogador faça 20 pts, só resta a opção de 21 pts (Blackjack)
			   para o PC ganhar, se o PC  fizer mais de 21 ele vai estourar (As duas condições já foram criadas).
			   --> Não existe condição de empate.*/
			} else if (aux != 0 && pc_soma > jo_soma && pc_soma < 21) {
				printf("A maquina fez mais pontos... Portanto voce PERDEU\n");
				system("pause");
				libera_memoria (pc_mesa);
				pc_mesa = cria_mesa(pc_cartas);			
				reiniciando_jogo (preg, ppc, pjo, ppa, pja, pps, pjs, paux);
				pc_caixa += pote;
				pote = 0;
				libera_memoria(jo_mesa);
				jo_mesa = cria_mesa(jo_cartas);
			/* Se o PC fizer uma soma superior de 21 pts, entao o PC estorou e a vitoria  é do Jogador */
			} else if (pc_soma > 21 && pc_aposta != 0) {
				printf("A mesa estorou... Vitoria do JOGADOR\n");
				system("pause");
				libera_memoria (pc_mesa);
				pc_mesa = cria_mesa(pc_cartas);
				reiniciando_jogo (preg, ppc, pjo, ppa, pja, pps, pjs, paux);
				jo_caixa += pote;
				pote = 0;
				libera_memoria(jo_mesa);
				jo_mesa = cria_mesa(jo_cartas);
			/* Se não acontecer nenhuma condicao de vitoria, entao irá rodar as jogadas */
			} else {
				// Perguntando a próxima jogada do jogador...
				printf("\n--> Escolha sua jogada: ");
				limpa_buffer();
				scanf("%d", &jogada);
				switch (jogada) {
					//Caso a jogada seja inválida, ou seja, diferente das marcadas no menu do jogo
					default:
						printf("Jogada invalida....\n");
						printf("Escolha uma jogada válida..\n");
						break;
					/* Caso a opção seja sair do jogo, irá sair do loop no jogo iniciado, e voltará para o menu principal */
					case 1:
						a = 0;
						break;
					/* Caso o jogador queira apostar
					   Esta é uma jogada obrigatória, pois antes de qualquer jogada obrigatoriamente ele deve iniciar uma aposta */
					case 2:
						/* A variavel reg irá cuidar da regra de aposta:
						reg = 0 --> O jogador não apostou, e com isso, a unica jogada que ele poderá fazer é APOSTAR
						reg = 1 --> O jogador já apostou, e não deve apostar até encerrar uma jogada, com isso ele deve pedir cartas ou finalizar */
						if (reg != 0) {
							printf("A rodada de apostas ja foi encerrada...\n");
							printf("Tente uma nova jogada...\n");
							system("pause");
							break;
						//variavel aux controla a parte de finalizar jogada, se ele for diferente de 0, significa que suas jogadas já acabou...
						} else if (aux != 0) {
							printf("Voce ja finalizou suas jogadas...\n");
							system("pause");							
						//reg == 0 --> inciando apostas...
						} else {
							reg++; //Fechando as proximas apostas
							/* Pedindo ao usuario digitar o valor total da aposta */
							printf("\nDigite o valor que deseja apostar: ");
							limpa_buffer();
							scanf("%d", &jo_aposta);
							limpa_buffer();
							/* Se a aposta digitada for maior que o caixa do Jogador ou do PC-Mesa, não será possivel realizar esta aposta */
							if (jo_aposta > jo_caixa || jo_aposta > pc_caixa) {
								printf("Esta aposta esta muito alta...\nTente apostar um valor menor \n");
								reg = 0; //Nao foi possivel apostar
								jo_aposta = 0; // Zerando o contador de aposta
								system("pause");
								break;
							/* SENAO: Se o jogador realmente apostar...*/
							} else if (jo_aposta < 1) {
								reg = 0; //Nao foi possivel apostar
								jo_aposta = 0; // Zerando o contador de aposta
								break;
							} else {
								pc_aposta = jo_aposta; //O pc irá igualar a aposta.
								pc_caixa -= pc_aposta; //O caixa do PC irá atualizar, retirando o valor da aposta no caixa
								jo_caixa -= jo_aposta; //Assim se repetira no caixa do Jogador, tambem irá atualizar
								pote = pc_aposta + jo_aposta; //O pote é a soma das duas apostas, quem ganhar a rodada, ira ganhar a rodada
								break;
							}
						}
					/*Caso o jogador escolha a opcao de PEDIR CARTAS ...
					Vai ser verificada algumas regras de condições, a regra de aposta e a de finalizar a jogada*/
					case 3:
						//Se voce nao apostou, nao poderá pedir cartas..
						if (reg == 0) {
							printf("Voce deve iniciar uma aposta...\n");
							system("pause");
							break;
						//Se voce já finalizou suas jogadas...
						} else if (aux != 0) {
							printf("Voce ja finalizou suas jogadas...\n");
							system("pause");
						//SE já apostou e nao finalizou, o jogador irá pedir cartas para sua MESA
						} else {
							jo_cartas++;
							jo_mesa = pedir_cartas (jo_mesa, jo_cartas);
							break;
						}
					/* Caso o jogador queira finalizar suas jogadas */
					case 4:
						//Se o jogador nao efetuou uma aposta ele nao pode finalizar uma jogada
						if (reg == 0) {
							printf("Voce deve iniciar uma aposta...\n");
							system("pause");
							break;
						//Se o jogador já finalizou uma jogada ele nao pode efetuar a mesma duas vezes na mesma rodada
						} else if (aux != 0) {
							printf("Voce ja finalizou suas jogadas...\n");
							system("pause");
							break;
						//Se o jogadr finalizar a jogada, o aux que esta em todas jogadas vai ser diferente de 0, assim o nao poderá efetuar mais
						} else if (aux == 0) {
							aux++;
							break;
						}
				}
			}
		}
	} while (a);
	//Liberando a memoria do vetor dinamico.
	libera_memoria (pc_mesa);
	libera_memoria(jo_mesa);
}