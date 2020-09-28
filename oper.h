#ifndef _OPER_H_
#define _OPER_H_
void limpa_buffer();
int *cria_mesa (int);
void libera_memoria (int *);
int soma_mesa (int *, int);
int *pedir_cartas (int *, int);
void reiniciando_jogo (int *, int *, int *, int *, int *, int *, int *, int *);
#endif