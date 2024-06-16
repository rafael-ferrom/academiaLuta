Academia - Sistema de Gerenciamento de Aulas de Luta
Este é um sistema de gerenciamento de aulas de luta em uma academia fictícia. O sistema permite o cadastro de aulas de luta, a matrícula de alunos nessas aulas, e a desmatrícula de alunos.

Estrutura do Projeto

Arquivos Incluídos

<stdio.h>: Biblioteca padrão de entrada e saída.
<stdlib.h>: Biblioteca padrão para alocação de memória.
<ctype.h>: Biblioteca para funções de manipulação de caracteres.
<string.h>: Biblioteca para manipulação de strings.
<strings.h>: Biblioteca para manipulação de strings específicas do POSIX.

Estruturas de Dados
Aluno
Definição da estrutura:

char CPF[13]: CPF do aluno.
char nome[80]: Nome do aluno.
int numaula: Número do registro do tipo da aula.

Luta

Definição da estrutura:

int regaula: Registro do tipo de aula.
int qaluno: Quantidade de alunos matriculados.
char modalidade[20]: Modalidade da luta (ex.: jiu-jitsu, muay thai, boxe).
int grau: Grau da aula: [1] iniciante, [2] intermediário, [3] avançado.
float valor: Valor da aula.
Funções
Alocação de Memória para Luta
Função para alocar memória para as estruturas de luta.

Cadastro de Aulas de Luta
Função para cadastrar as diferentes aulas de luta oferecidas pela academia.

Exibição de Aulas de Luta
Função para exibir as aulas de luta cadastradas.

Alocação de Memória para Aluno
Função para alocar memória para as estruturas de aluno.

Cadastro de Aluno
Função para cadastrar um aluno e associá-lo a uma aula de luta.

Desmatrícula de Aluno
Função para desmatricular um aluno de uma aula de luta utilizando seu CPF.

Função Principal
A função principal do programa oferece um menu interativo para o usuário com as seguintes opções:

Cadastrar aluno: Aloca memória para um novo aluno, cadastra-o e associa-o a uma aula de luta.
Encerrar aulas (Desmatrícula): Permite ao aluno sair de uma aula usando seu CPF.
Fim: Encerra o programa.
Uso
Alocação de Memória para Lutas
Chamada da função para alocar memória para as lutas.

Cadastro de Lutas
Chamada da função para cadastrar as aulas de luta.

Menu de Opções
Exibição de um menu com as opções de cadastrar aluno, desmatricular aluno, ou encerrar o programa.

Como Compilar e Executar
Compilação
Use o compilador gcc para compilar o programa com o comando apropriado.

Execução
Após a compilação, execute o programa com o comando apropriado.







