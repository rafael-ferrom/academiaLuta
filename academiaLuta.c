#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

typedef struct aluno
{
char CPF[13]; // CPF do aluno
char nome[80]; // nome do aluno
int numaula; // número do registro do tipo da aula
}aluno;

typedef struct luta
{
int regaula; //registro do tipo de aula
int qaluno; //registra a quantidade de alunos matriculados
char modalidade[20]; //exemplo: jiu-jitsu, muay thai, boxe
int grau; // [1]iniciante, [2]intermediário, [3]avançado
float valor; //valor da aula
}luta;

void alocaluta(luta **pl, int tam);
void cadastraluta(luta *pl);
void mostra(luta *pl);
void alocaaluno(aluno **palu, int tam);
void cadastraaluno(aluno *palu, luta *pl);
void desmatricula(char cpf2 [13], aluno *palu, luta *pl, int tam);

main()
{
	int op;
	int aux = 0;
	char cpf2 [30];
	
	luta *pluta = NULL;
	aluno *paluno = NULL;
	
	alocaluta(&pluta,9);
	cadastraluta(pluta);
	
	do
	{
		printf("\n --------------------ACADEMIA DO RAFAO-------------------- \n");
		printf("\nEscolha a opcao\n");
		mostra(pluta);
		printf("\n[1]-Cadastrar\n[2]-Encerrar aulas\n[3]-Fim\n");
		scanf("%i",&op);
		fflush(stdin);
		
		switch(op)
		{
			case 1:
				alocaaluno(&paluno,aux+1);
				cadastraaluno(paluno+aux,pluta);
				aux++;
				break;
			case 2:
				printf("\ndigite seu cpf\n");
				gets(cpf2);
				fflush(stdin);
				desmatricula(cpf2,paluno,pluta,aux);
				break;
		}
	}while(op != 3);
}//main

void alocaluta(luta **pl, int tam)
{
	if((*pl = (luta*)realloc(*pl, tam * sizeof(luta)))==NULL)
	{
		printf("ero na alocacao");
		exit(1);
	}//IF
}//alocaluta


void cadastraluta(luta *pl )
{
	strcpy(pl->modalidade,"judo");
	pl->grau = 1;
	pl->qaluno = 0;
	pl->regaula = 1;
	pl->valor = 90;
	pl++;
	
	strcpy(pl->modalidade,"judo");
	pl->grau = 2;
	pl->qaluno = 0;
	pl->regaula = 2;
	pl->valor = 95;
	pl++;
	
	strcpy(pl->modalidade,"judo");
	pl->grau = 3;
	pl->qaluno = 0;
	pl->regaula = 3;
	pl->valor = 100;
	pl++;
	
	strcpy(pl->modalidade,"boxe");
	pl->grau = 1;
	pl->qaluno = 0;
	pl->regaula = 4;
	pl->valor = 90;
	pl++;
	
	strcpy(pl->modalidade,"boxe");
	pl->grau = 2;
	pl->qaluno=0;
	pl->regaula=5;
	pl->valor=95;
	pl++;
	
	strcpy(pl->modalidade,"boxe");
	pl->grau=3;
	pl->qaluno=0;
	pl->regaula=6;
	pl->valor= 100;
	pl++;
	
	strcpy(pl->modalidade,"jiu jitsu");
	pl->grau = 1;
	pl->qaluno=0;
	pl->regaula=7;
	pl->valor=90;
	pl++;
	
	strcpy(pl->modalidade,"jiu jitsu");
	pl->grau=2;
	pl->qaluno=0;
	pl->regaula=8;
	pl->valor=95;
	pl++;
	
	strcpy(pl->modalidade,"jiu jitsu");
	pl->grau=3;
	pl->qaluno=0;
	pl->regaula=9;
	pl->valor=100;
	pl++;
	
}//cadastraluta

void mostra(luta *pl)
{
	int i;
	for(i=0;i<9;i++,pl++)
	{
		printf("\n Luta %i\n modalidade %s\n nivel %i\n quantidade de alunos %i\n preco %f\n",pl->regaula,pl->modalidade,pl->grau,pl->qaluno,pl->valor);
	}//for
}//mostra

void alocaaluno(aluno **palu, int tam)
{
	if((*palu = (aluno*)realloc(*palu, tam * sizeof(aluno)))==NULL)
	{
		printf("erro na alocacao");
		exit(1);
	}//IF
}//ALOCAALUNO

void cadastraaluno(aluno *palu, luta *pl)
{
	char auxluta [30];
	int auxnivel;
	int i;
	
	printf("\ndigite o seu nome\n");
	gets(palu->nome);
	fflush(stdin);
	
	printf("\ndigite o seu cpf\n");
	gets(palu->CPF);
	fflush(stdin);
	
	printf("\nCADASTRO FEITO\n");
	
	printf("\nescolha a luta que deseja\n");
	gets(auxluta);
	fflush(stdin);
	
	printf("\nqual sera o nivel de sua luta\n[1]-iniciante\n[2]-intermediario\n[3]-dificil\n");
	scanf("%i",&auxnivel);
	fflush(stdin);
	
	for(i=0;i<9;i++,pl++)
	{
		if(strcasecmp(auxluta,pl->modalidade)==0 && auxnivel == pl->grau)
		{
			pl->qaluno++;
			palu->numaula = i+1;
		}//if
	}//for
	
}//cadastraaluno

void desmatricula(char cpf2 [13], aluno *palu, luta *pl, int tam)
{
	int i;
	int j;
	
	for(i=0;i<tam;i++,palu++)
	{
		if(strcasecmp(cpf2,palu->CPF)==0)
		{
			for(j=0;j<9;j++,pl++)
			{
				if(palu->numaula == pl->regaula)
				{
					pl->qaluno--;
				}//if
			}//for
			palu->numaula = -1;
		}//if
	}//for
}//desmatricula
