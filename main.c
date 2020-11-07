#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"
#include <string.h>
#include <locale.h>

int main()
{
	//------- Inicializa variáveis, cria a lista duplamente encadeada ----
	setlocale(LC_ALL, "portuguese");

	Menu* menu;
	void* pbuffer = malloc(sizeof(Menu));
	menu = pbuffer;
	menu->tam = 0;
	
	Pessoa* pessoa = malloc(sizeof(Pessoa));

	menu->cont = 2;
	Lista *li; //crio um ponteiro para ponteiro, pois Lista já é um ponteiro
	li = cria_lista(); //recebe o ponteiro de ponteiro, aponta para o endereço do primeiro nó da lista
	
	Fila* fila;
	fila = (Fila*) malloc(sizeof(Fila));
	
	// ------ Menu ---------
	while(1)
	{
		printf("Menu: \n");
		printf("\tAdicionar pessoa:(1)\n");
		printf("\tRemover pessoa:(2)\n");
		printf("\tListar pessoas:(3)\n");
		printf("\tBuscar nome:(4)\n");
		printf("\tSair:(0)\n");
		printf("\nDigite a opção desejada: ");

		scanf("%d", &menu->choice);

		if(menu->choice == 1)
		{
			if(menu->cont == 2)
			{
				printf("Qual nome deseja inserir? ");
				scanf("%s", menu->tnome);
				strcpy(pessoa->nome, menu->tnome);

				if(insere_lista_inicio(li, pessoa) == 1)
				{
					printf("Nome inserido com sucesso\n");
					pessoa++;
					  
				}
				else
				{
					printf("Erro na inserção\n");
				}

			}
			else
			{
				printf("Qual nome deseja inserir?\n");
				scanf("%s", menu->tnome);
				strcpy(pessoa->nome, menu->tnome);
				
				printf("Em qual parte da lista deseja inserir? Inicio(1), Meio(2), Fim(3)\n");
				scanf("%d", &menu->choice);
				if(menu->choice == 1)
				{
					insere_lista_inicio(li, pessoa);
					pessoa++;

				}
				else if(menu->choice == 2)
				{
					insere_lista_meio(li, pessoa);
					pessoa++;

					  
				}
				else if(menu-> choice == 3)
				{
					push(li, pessoa);
					pessoa++;
				
				}
				else
				{
					printf("Opção inválida, tente novamente!\n");
				}
			}

			menu->cont++;
			pessoa = (Pessoa*) malloc(sizeof(Pessoa) * menu->cont);
		}

		else if(menu->choice == 2)
		{
			if(lista_vazia(li) == 1)
			{
				printf("A lista está vazia\n");
			}
			else
			{
				printf("Qual nome deseja remover? ");
				scanf("%s", menu->tnome);

				if(remove_lista(li, menu->tnome) == 1)
				{
					printf("Nome removido com sucesso!\n");
				}
				else
				{
					printf("Esse nome não consta na lista!\n");
				}
			}

		}
		else if(menu->choice == 3)
		{
			if(lista_vazia(li) == 1)
			{
				printf("A lista está vazia\n");
			}
			
			printf("Como deseja ordenar sua lista?\n");
			printf("Ordem Crescente(1)| Ordem Decrescente(2) | Não-ordenar(3): ");
			scanf("%d", &menu->choice);
			
			fila = malloc(sizeof(Fila) * tamanho_lista(li));
			
			if(menu->choice == 1)
			{
				
				menu->tam = copiar(li, fila);
				ordemCrescente(fila, menu->tam);
			}
			
			if(menu->choice == 2)
			{
				menu->tam = copiar(li, fila);
				ordemDecrescente(fila, menu->tam);
			}
			
			if(menu->choice == 3)
			{
				imprime_nome(li);
			}
			
		}
		else if(menu->choice == 4)
		{
			if(lista_vazia(li) == 1)
			{
				printf("A lista está vazia\n");
			}
			else
			{
				printf("Qual nome deseja procurar? ");

				scanf("%s", menu->tnome);

				if(consulta_nome(li, menu->tnome, pessoa) == 1)
				{
					printf("O nome: %s consta na lista\n", menu->tnome);
				}
				else
				{
					printf("O nome %s não consta na lista\n", menu->tnome);
				}

			}
			
		}

		else if(menu->choice == 0)
		{
			printf("Saindo...\n");
			free(pbuffer);
			free(pessoa);
			libera_lista(li);
			free(fila);
			
			break;
		}
	
		else
		{
			printf("Opção inválida. Tente novamente....\n");
		}
		
	}

	return 0;
}
