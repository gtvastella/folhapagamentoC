/*Gabriel V. 182803 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Funcionario{
  char nome[101];
  float salariobase;
  float comissao;
  float total;
} funcionario;
 /* criando a estrutura Funcionaro que será usada para armazenar dados*/

funcionario funcs[100];
int fs = 0;
int uniqueSalarios;
/* inicialização das variáveis que serão usadas ao longo do programa*/

void addFunc(int f, char n[102], float sb, float c){
  funcionario fb;
  n[strlen(n)-1] = '\0';
  strcpy(fb.nome, n);
  fb.salariobase = sb;
  fb.comissao = c;
  fb.total = c + sb;
  funcs[f] = fb;
 /* procedimento para adicionar funcionaro durante leitura*/
}
float* uniqueSort(int tm, float base[]){
  for(int i=0;i<tm;i++) {
      for(int x=i+1;x<tm;) {
         if(base[x]==base[i]) {
            for(int z=x;z<tm;z++) {
              base[z]=base[z + 1];
            }
            tm--;
         } else{
            x++;
        } 
      }  
  }
   uniqueSalarios =tm;

  for(int i=0;i<uniqueSalarios;i++){
    for(int y=i+1; y<uniqueSalarios; y++){
      if(base[y] <base[i]){
        float aux = base[i];
        base[i] = base[y];
        base[y] = aux;
      }
    }
  }
   return base;
  /* função que retorna uma array organizando salários em ordem crescente*/
 }

void printFolha(){
  printf("Folha de Pagamento\n\n");
  int total =fs;
  float salarios[fs];
  float* finais;
  /* iniciando impressão da folha de pagamento com inicialização das variáveis que serão usadas*/

  for (int i=0;i<total;i++)
    salarios[i] = funcs[i].total;
    finais = uniqueSort(total, salarios);
    /* coletando e organizando salários por ordem crescente*/
  for(int i = 0;i<uniqueSalarios;i++){
    int unique =0;
    printf("Salario no Mes: R$%.2f\n", finais[i]);
    /* imprimindo para cada salário específico*/
    char nomes[100][100];
    for (int x=0;x<fs;x++){
      if (funcs[x].total == finais[i]){
        strcpy(nomes[unique], funcs[x].nome);
        unique++;
      }  
    }
    /* salvando nomes para organização alfabética*/

    char aux[unique];
    for(int i=0;i<unique;i++){
      for(int y=i+1; y<unique; y++){
        if(strcmp(nomes[i],nomes[y])>0){
          strcpy(aux,nomes[i]);
          strcpy(nomes[i],nomes[y]);
          strcpy(nomes[y],aux);
    
        }
      }
    }
    /* realizada organização alfabética dos nomes na array nome*/
    for (int x=0;x<unique;x++){
      printf("- %s\n", nomes[x]);
      /* definindo a string que deve ser lida para declarar o FIM da leitura de dados*/
    }

    printf("\n");
    /* linha antes de iniciar outro salário*/
  }
      



}
int main(void) {
  char fim[5] = {'F', 'I', 'M', '\n', '\0'};
  /* definindo a string que deve ser lida para declarar o FIM da leitura de dados*/
  
  while (fs != 100){
    char nm[101];
    char novo [100];
    float ssb;
    float ccm;
    char ftest[5];
    /* declarada as variáveis que serão usadas na leitura para formar a struct Funcionario*/

    fgets(nm, 101, stdin);
    /* lendo o nome do funcionário*/

    if (fs>0){
      ftest[strlen(ftest)] = '\0';
      strcpy(novo, ftest);
      strcat(novo, nm);
      /* trecho para evitar conflitos de leitura após o 1 funcionário*/
    }

    scanf("%f", &ssb);
    scanf("%f", &ccm);
    getchar();
    /* trecho para ler os salários*/

    if (fs>0)
    addFunc(fs, novo, ssb, ccm);
    else
    addFunc(fs, nm, ssb, ccm);
    fs++;
    /* funcionário lido (com ressalvas para evitar conflitos de leitura) e contabilizado na int global*/
   
    if (fs==100)
      break;
    if (fgets(ftest, 5, stdin)){
      if (strcmp(ftest, fim) == 0)
        break;
    }
    /* caso ler a palavra FIM ou atingir 100 funcionários, terminar leitura.*/
  }

  printFolha();
  /* chamada a função printFolha para imprimir a folha após leitura*/

  return 0;
  /* fim da tarefa*/
}