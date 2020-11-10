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

typedef struct elemento Elem; //facilitar manipulações nas implementações
//é um auxiliar, porque eu crio um Elem *no nas implementações
//e esse nó por ser um ponteiro de Elem, que é um elemento,
// pode receber as mesmas coisas que a lista, uma vez que a
//lista também é um ponteiro de elemento, que é minha struct com os dados e o nó anterior e posterior.

// (*no).ant ou no->ant , no->prox

typedef struct elemento* Lista; //ponteiro do tipo elemento (que é uma struct) de nome Lista

//Funções da lista encadeada dupla:
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
//-------- Função da fila ------
int pop(Lista * li); //remove do começo da fila
int push(Lista* li, void* pbuffer); //insere no final da fila
void ordemCrescente(Fila* fila, int n);
void ordemDecrescente(Fila* fila, int n);

#endif