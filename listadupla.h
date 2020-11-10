#ifndef LISTADUPLA_H
#define LISTADUPLA_H

typedef struct
{
	char nome[30];

} Pessoa;

typedef struct
{
	int choice;
	int cont;
	char tnome[30];
	int i;
	int tam;
	Pessoa auxnome;

} Menu;

struct elemento
{
	struct elemento *ant;
	Pessoa dados;
	struct elemento *prox;
	
}; //a lista duplamente encadeada

typedef struct 
{
	char nomef[30];

} Fila;

typedef struct elemento Elem; //facilitar manipula��es nas implementa��es
//� um auxiliar, porque eu crio um Elem *no nas implementa��es
//e esse n� por ser um ponteiro de Elem, que � um elemento,
// pode receber as mesmas coisas que a lista, uma vez que a
//lista tamb�m � um ponteiro de elemento, que � minha struct com os dados e o n� anterior e posterior.

// (*no).ant ou no->ant , no->prox

typedef struct elemento* Lista; //ponteiro do tipo elemento (que � uma struct) de nome Lista

//Fun��es da lista encadeada dupla:
Lista* cria_lista();
int copiar(Lista* li, Fila* fila);
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_inicio(Lista* li, void* pbuffer);
int insere_lista_meio(Lista* li, void* pbuffer);
int remove_lista(Lista * li, char* nome);
int consulta_lista_pos(Lista* li, int pos, void* pbuffer);
int consulta_nome(Lista* li, char* nome, void* pbuffer);
void imprime_nome(Lista* li);
//-------- Fun��o da fila ------
int pop(Lista * li); //remove do come�o da fila
int push(Lista* li, void* pbuffer); //insere no final da fila
void ordemCrescente(Fila* fila, int n);
void ordemDecrescente(Fila* fila, int n);

#endif