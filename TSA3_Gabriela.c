/********* Universidade de Brasília - UnB ************/
/************* Gabriela Alves da Gama ***************/
/*********Estrutura de Dados e Algoritmos **********/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define ERRO_C "\n\tIMPORTACAO DOS DADOS NAO EFETUADA!\n"

typedef struct{
  char UF[4];
  char municipio[50];
  int CDs;
  int EPAOs;
  int TPDs;
  int LBs;
  int TSBs;
  int ASBs;
  int APDs;
  int EPOs;
  int Total;
}dados;

/******* Lista encadeada para os dados *******/

struct CADASTRO{
  char UF[4];
  char municipio[50];
  int CDs;
  int EPAOs;
  int TPDs;
  int LBs;
  int TSBs;
  int ASBs;
  int APDs;
  int EPOs;
  int Total;
 struct CADASTRO *ant;
 struct CADASTRO *prox;
};
typedef struct CADASTRO C;

/******************** Árvores *********************/

struct ARVORE{
  char UF[4];
  char municipio[50];
  int CDs;
  int EPAOs;
  int TPDs;
  int LBs;
  int TSBs;
  int ASBs;
  int APDs;
  int EPOs;
  int Total;
 struct ARVORE *esq, *dir;
};

typedef struct ARVORE ARV;

struct ARVORE2{
  char UF[4];
  char municipio[50];
  int CDs;
  int EPAOs;
  int TPDs;
  int LBs;
  int TSBs;
  int ASBs;
  int APDs;
  int EPOs;
  int Total;
 struct ARVORE2 *esq, *dir;
};
typedef struct ARVORE2 ARV2;

typedef struct ARVORE ARV;

struct ARVORE3{
  char UF[4];
  char municipio[50];
  int CDs;
  int EPAOs;
  int TPDs;
  int LBs;
  int TSBs;
  int ASBs;
  int APDs;
  int EPOs;
  int Total;
 struct ARVORE3 *esq, *dir;
};
typedef struct ARVORE3 ARV3;

struct ARVORE4{
  char UF[4];
  char municipio[50];
  int CDs;
  int EPAOs;
  int TPDs;
  int LBs;
  int TSBs;
  int ASBs;
  int APDs;
  int EPOs;
  int Total;
 struct ARVORE4 *esq, *dir;
};
typedef struct ARVORE4 ARV4;

/******************* Protótipos *******************/

int menu();
int vazia(ARV *a);
int vazia2(ARV2 *a);
int vazia3(ARV3 *a);
int vazia4(ARV4 *a);
ARV *criaArvore();
ARV2 *criaArvore2();
ARV3 *criaArvore3();
ARV4 *criaArvore4();
ARV *criaCadastroMunicipio(ARV *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total);
ARV2 *criaCadastroCD(ARV2 *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total);
ARV3 *criaCadastroTotal(ARV3 *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total);
ARV4 *criaCadastroEstado(ARV4 *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total);
C *criaCadastro(C *c, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total);
void ExibiMunicipio(ARV *a);
void ExibiCD(ARV2 *a);
void ExibiTotal(ARV3 *a);
void ExibiEstado(ARV4 *a);
ARV *procuraNaEsquerda(ARV *a, char municipio[50]);
ARV2 *procuraNaEsquerda2(ARV2 *a, char municipio[50]);
ARV3 *procuraNaEsquerda3(ARV3 *a, char municipio[50]);
ARV4 *procuraNaEsquerda4(ARV4 *a, char municipio[50]);
ARV *procuraNaDireita(ARV *a, char municipio[50]);
ARV2 *procuraNaDireita2(ARV2 *a, char municipio[50]);
ARV3 *procuraNaDireita3(ARV3 *a, char municipio[50]);
ARV4 *procuraNaDireita4(ARV4 *a, char municipio[50]);
C *procuraCadastro(C *c, char municipio[50]);

/***************** Função Main () ********************/

int main(){
 C *c = NULL;
 ARV *MUNICIPIO = criaArvore();
 ARV2 *CD = criaArvore2();
 ARV3 *TOTAL = criaArvore3();
 ARV4 *ESTADO = criaArvore4();
 ARV *a1;
 ARV2 *a2;
 ARV3 *a3;
 ARV4 *a4;
 int op;
 char uf [4], m[50];
 char *ptr;
 dados dados[3322];
 int i=0;
 FILE*arquivo;

 do{
  op = menu();
  system("clear");
  switch(op){
   case 1:{
    arquivo=fopen("CFO_UF_municipios_brasil.csv","rb");
    for(i=0;i<3322 && !feof(arquivo);i++){

             fscanf(arquivo, "%[^;]s", dados[i].UF);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%[^;]s", dados[i].municipio);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].CDs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].EPAOs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].TPDs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].LBs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].TSBs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].ASBs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].APDs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].EPOs);
             fseek(arquivo, +1, SEEK_CUR);
             fscanf(arquivo, "%d[^;]", &dados[i].Total);

    }
      for(i=0;i<3322;i++){
    c = criaCadastro(c,dados[i].UF,dados[i].municipio,dados[i].CDs,dados[i].EPAOs,dados[i].TPDs,dados[i].LBs,dados[i].TSBs,dados[i].ASBs,dados[i].APDs,dados[i].EPOs,dados[i].Total);
    }
    for(i=0;i<3322;i++){
    MUNICIPIO = criaCadastroMunicipio(MUNICIPIO,dados[i].UF,dados[i].municipio,dados[i].CDs,dados[i].EPAOs,dados[i].TPDs,dados[i].LBs,dados[i].TSBs,dados[i].ASBs,dados[i].APDs,dados[i].EPOs,dados[i].Total);
    }
    for(i=0;i<3322;i++){
    CD = criaCadastroCD(CD,dados[i].UF,dados[i].municipio,dados[i].CDs,dados[i].EPAOs,dados[i].TPDs,dados[i].LBs,dados[i].TSBs,dados[i].ASBs,dados[i].APDs,dados[i].EPOs,dados[i].Total);
    }
    system("clear");
    getchar();
    printf("\n\n\tCADASTRO REALIZADO COM SUCESSO!");
    break;
   }
   case 2:{
     if(!vazia(MUNICIPIO))
      ExibiMunicipio(MUNICIPIO);
     else
      printf(ERRO_C);
     getchar();
    break;
   }
   case 3:{
    if(!vazia2(CD))
     ExibiCD(CD);
    else
     printf(ERRO_C);
    getchar();
    break;
   }
   case 4:{
    if(!vazia3(TOTAL))
     ExibiTotal(TOTAL);
    else
     printf(ERRO_C);

    getchar();
    break;
   }
   case 5:{
    if(c !=NULL){
     printf("INFORME O ESTADO: ");
     gets(uf);
     getchar();
     a1 = procuraNaEsquerda(MUNICIPIO, uf);
     if(a1 == NULL){
      a1 = procuraNaDireita(MUNICIPIO, uf);
     }
     a2 = procuraNaEsquerda2(CD, uf);
     if(a2 == NULL){
      a2 = procuraNaDireita2(CD, uf);
     }
     a3 = procuraNaEsquerda3(TOTAL, uf);
     if(a3 == NULL){
      a3 = procuraNaDireita3(TOTAL, uf);
     }
     a4 = procuraNaEsquerda4(ESTADO, uf);
     if(a4 == NULL){
      a4 = procuraNaDireita4(ESTADO, uf);
     }
     if(a1 != NULL){
      system("clear");
      printf("UF:%s\nMunicipio:%s\nCDs:%d\nEPAOs:%d\nTPDs:%d\nLBs:%d\nTSBs:%d\nASBs:%d\nAPDs:%d\nEPOs:%d\nTotal:%d\n", a1->UF ,a1->municipio, a1->CDs, a1->EPAOs, a1->TPDs, a1->LBs, a1->TSBs, a1->ASBs, a1->APDs, a1->EPOs, a1->Total);
      getchar();
     }
     else{
      printf(ERRO_C);
      getchar();
     }
    }
    else {
     printf(ERRO_C);
     getchar();
    }
    break;
   }

   case 6:{
    if(c !=NULL){
     printf("INFORME O MUNICIPIO: ");
     gets(m);
     getchar();
     a1 = procuraNaEsquerda(MUNICIPIO, m);
     if(a1 == NULL){
      a1 = procuraNaDireita(MUNICIPIO, m);
     }
     a2 = procuraNaEsquerda2(CD, m);
     if(a2 == NULL){
      a2 = procuraNaDireita2(CD, m);
     }
     a3 = procuraNaEsquerda3(TOTAL, m);
     if(a3 == NULL){
      a3 = procuraNaDireita3(TOTAL, m);
     }
     a4 = procuraNaEsquerda4(ESTADO, m);
     if(a4 == NULL){
      a4 = procuraNaDireita4(ESTADO, m);
     }
     if(a1 != NULL){
      system("clear");
      printf("UF:%s\nMunicipio:%s\nCDs:%d\nEPAOs:%d\nTPDs:%d\nLBs:%d\nTSBs:%d\nASBs:%d\nAPDs:%d\nEPOs:%d\nTotal:%d\n", a1->UF ,a1->municipio, a1->CDs, a1->EPAOs, a1->TPDs, a1->LBs, a1->TSBs, a1->ASBs, a1->APDs, a1->EPOs, a1->Total);
      getchar();
     }
     else{
      printf(ERRO_C);
      getchar();
     }
    }
    else {
     printf(ERRO_C);
     getchar();
    }
    break;
   }

   case 0: exit(0);break;
   getchar();
   break;
  }
  getchar();
 }while(op != 0);
 return 0;
}

/************* Função Menu() *************/

int menu(){
 int op;
 do{
  system("clear");
  printf("------- Seja Bem Vindo ao Cadastro do Conselho Federal de Odontologia (CFO)! -------\n");
  printf("1. Importar Dados\nRelatorio por : \n2. Municipio\n3. CD\n4. Total\n5. Relatorio de um Estado\n6. Consultar os dados de um Municipio\n0. SAIR\n");
  scanf("%d", &op);
  if(op<0 || op >5){
   printf("OPCAO INVALIDA");
   getchar();
  }
  getchar();

 }while(op<0 || op >5);

 return op;
}

/********************* Funções para criar árvores ********************/

ARV *criaArvore(){
 return NULL;
}
ARV2 *criaArvore2(){
 return NULL;
}
ARV3 *criaArvore3(){
 return NULL;
}
ARV4 *criaArvore4(){
 return NULL;
}

/******** Função para criar uma lista com os dados ***********/

C *criaCadastro(C *c, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total){
 C *nTemp = (C *)malloc(sizeof(C));
  strcpy(nTemp->UF, UF);
  nTemp->CDs = CDs;
  strcpy(nTemp->municipio, municipio);
  nTemp->EPAOs = EPAOs;
  nTemp->TPDs = TPDs;
  nTemp->LBs = LBs;
  nTemp->TSBs = TSBs;
  nTemp->ASBs = ASBs;
  nTemp->APDs = APDs;
  nTemp->EPOs = EPOs;
  nTemp->Total = Total;
  nTemp->ant = NULL;
  nTemp->prox = c;
  if(c != NULL){
   c->ant = nTemp;
  }
 return nTemp;
}

/*************** Carregar dados nas árvores ***********/

ARV *criaCadastroMunicipio(ARV *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total){
 ARV *aTemp;
 if(a == NULL) {
  aTemp = (ARV *)malloc(sizeof(ARV));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore();
  aTemp->dir = criaArvore();
  return aTemp;
 }else{
  int dir = 0;
  aTemp = a;
  ARV *pai, *raiz = a;
  while(!vazia(aTemp)){
   if(municipio<= aTemp->municipio){
    pai = aTemp;
    aTemp = aTemp->esq;
    dir = 0;
   }else{
    pai=aTemp;
    aTemp = aTemp->dir;
    dir = 1;
   }
  }
  aTemp = (ARV *)malloc(sizeof(ARV));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore();
  aTemp->dir = criaArvore();

  if(dir)
   pai->dir = aTemp;
  else
   pai->esq = aTemp;
  return raiz;
 }
}

ARV2 *criaCadastroCD(ARV2 *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total){
 ARV2 *aTemp;
 if(a == NULL){
  aTemp = (ARV2 *)malloc(sizeof(ARV2));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore2();
  aTemp->dir = criaArvore2();
  return aTemp;
 }else{
  int dir = 0;
  aTemp = a;
  ARV2 *pai, *raiz = a;
  while(!vazia2(aTemp)){
   if(CDs<= aTemp->CDs){
    pai = aTemp;
    aTemp = aTemp->esq;
    dir = 0;
   }else{
    pai=aTemp;
    aTemp = aTemp->dir;
    dir = 1;
   }
  }
  aTemp = (ARV2 *)malloc(sizeof(ARV2));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore2();
  aTemp->dir = criaArvore2();
  if(dir)
   pai->dir = aTemp;
  else
   pai->esq = aTemp;
  return raiz;
 }
}

ARV3 *criaCadastroTotal(ARV3 *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total){
 ARV3 *aTemp;
 if(a == NULL){
  aTemp = (ARV3 *)malloc(sizeof(ARV3));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore3();
  aTemp->dir = criaArvore3();
  return aTemp;
 }else{
  int dir = 0;
  aTemp = a;
  ARV3 *pai, *raiz = a;
  while(!vazia3(aTemp)){
   if(Total<= aTemp->Total){
    pai = aTemp;
    aTemp = aTemp->esq;
    dir = 0;
   }else{
    pai=aTemp;
    aTemp = aTemp->dir;
    dir = 1;
   }
  }
  aTemp = (ARV3 *)malloc(sizeof(ARV3));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore3();
  aTemp->dir = criaArvore3();
  if(dir)
   pai->dir = aTemp;
  else
   pai->esq = aTemp;
  return raiz;
 }
}

ARV4 *criaCadastroEstado(ARV4 *a, char UF[4],char municipio[50],int CDs,int EPAOs,int TPDs,int LBs,int TSBs,int ASBs,int APDs,int EPOs,int Total){
 ARV4 *aTemp;
 if(a == NULL){
  aTemp = (ARV4 *)malloc(sizeof(ARV4));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore4();
  aTemp->dir = criaArvore4();
  return aTemp;
 }else{
  int dir = 0;
  aTemp = a;
  ARV4 *pai, *raiz = a;
  while(!vazia4(aTemp)){
   if(UF<= aTemp->UF){
    pai = aTemp;
    aTemp = aTemp->esq;
    dir = 0;
   }else{
    pai=aTemp;
    aTemp = aTemp->dir;
    dir = 1;
   }
  }
  aTemp = (ARV4 *)malloc(sizeof(ARV4));
  strcpy(aTemp->UF, UF);
  aTemp->CDs = CDs;
  strcpy(aTemp->municipio, municipio);
  aTemp->EPAOs = EPAOs;
  aTemp->TPDs = TPDs;
  aTemp->LBs = LBs;
  aTemp->TSBs = TSBs;
  aTemp->ASBs = ASBs;
  aTemp->APDs = APDs;
  aTemp->EPOs = EPOs;
  aTemp->Total = Total;
  aTemp->esq = criaArvore4();
  aTemp->dir = criaArvore4();
  if(dir)
   pai->dir = aTemp;
  else
   pai->esq = aTemp;
  return raiz;
 }
}

/****** Funções para verificar se as árvores estão vazias ******/

int vazia(ARV *a){
 return a==NULL;
}

int vazia2(ARV2 *a){
 return a==NULL;
}

int vazia3(ARV3 *a){
 return a==NULL;
}

int vazia4(ARV4 *a){
 return a==NULL;
}

/*********** Funções para exibir dados **********/

void ExibiCD(ARV2 *a){
 if(a->esq != NULL) {
  ExibiCD(a->esq);
 }
printf("UF:%s\nMunicipio:%s\nCDs:%d\nEPAOs:%d\nTPDs:%d\nLBs:%d\nTSBs:%d\nASBs:%d\nAPDs:%d\nEPOs:%d\nTotal:%d\n", a->UF ,a->municipio, a->CDs, a->EPAOs, a->TPDs, a->LBs, a->TSBs, a->ASBs, a->APDs, a->EPOs, a->Total);

 if(a->dir != NULL){
  ExibiCD(a->dir);
 }
}

void ExibiMunicipio(ARV *a){
 if(a->esq != NULL) {
  ExibiMunicipio(a->esq);
 }
  printf("UF:%s\nMunicipio:%s\nCDs:%d\nEPAOs:%d\nTPDs:%d\nLBs:%d\nTSBs:%d\nASBs:%d\nAPDs:%d\nEPOs:%d\nTotal:%d\n", a->UF ,a->municipio, a->CDs, a->EPAOs, a->TPDs, a->LBs, a->TSBs, a->ASBs, a->APDs, a->EPOs, a->Total);
 if(a->dir != NULL){
  ExibiMunicipio(a->dir);
 }
}

void ExibiTotal(ARV3 *a){
 if(a->esq != NULL) {
  ExibiTotal(a->esq);
 }
  printf("UF:%s\nMunicipio:%s\nCDs:%d\nEPAOs:%d\nTPDs:%d\nLBs:%d\nTSBs:%d\nASBs:%d\nAPDs:%d\nEPOs:%d\nTotal:%d\n", a->UF ,a->municipio, a->CDs, a->EPAOs, a->TPDs, a->LBs, a->TSBs, a->ASBs, a->APDs, a->EPOs, a->Total);
 if(a->dir != NULL){
  ExibiTotal(a->dir);
 }
}

void ExibiEstado(ARV4 *a){
 if(a->esq != NULL) {
  ExibiEstado(a->esq);
 }
  printf("UF:%s\nMunicipio:%s\nCDs:%d\nEPAOs:%d\nTPDs:%d\nLBs:%d\nTSBs:%d\nASBs:%d\nAPDs:%d\nEPOs:%d\nTotal:%d\n", a->UF ,a->municipio, a->CDs, a->EPAOs, a->TPDs, a->LBs, a->TSBs, a->ASBs, a->APDs, a->EPOs, a->Total);
 if(a->dir != NULL){
  ExibiEstado(a->dir);
 }
}

/****** Funções para fazer pesquisas nas árvores binárias ******/

ARV *procuraNaEsquerda(ARV *a, char municipio [50]){
 ARV *p;
 p = NULL;
 while(a != NULL){
  if((a->municipio) == municipio) {
   p = a;
   break;
  }
  a = a->esq;
 }
 return p;
}

ARV *procuraNaDireita(ARV *a, char municipio[50]){
 ARV *p;
 p = NULL;
 while(a != NULL){
  if((a->municipio) == municipio) {
   p = a;
   break;
  }
  a = a->dir;
 }
 return p;
}

ARV2 *procuraNaEsquerda2(ARV2 *a, char municipio [50]){
 ARV2 *p;
 p = NULL;
 while(a != NULL){
  if((a->municipio) == municipio){
   p = a;
   break;
  }
  a = a->esq;
 }
 return p;
}


ARV2 *procuraNaDireita2(ARV2 *a, char municipio [50]){
 ARV2 *p;
 p = NULL;
 while(a != NULL) {
  if((a->municipio) == municipio){
   p = a;
   break;
  }
  a = a->dir;
 }
 return p;
}

ARV3 *procuraNaEsquerda3(ARV3 *a, char municipio [50]){
 ARV3 *p;
 p = NULL;
 while(a != NULL){
  if((a->municipio) == municipio){
   p = a;
   break;
  }
  a = a->esq;
 }
 return p;
}


ARV3 *procuraNaDireita3(ARV3 *a, char municipio [50]){
 ARV3 *p;
 p = NULL;
 while(a != NULL) {
  if((a->municipio) == municipio){
   p = a;
   break;
  }
  a = a->dir;
 }
 return p;
}

ARV4 *procuraNaEsquerda4(ARV4 *a, char municipio [50]){
 ARV4 *p;
 p = NULL;
 while(a != NULL){
  if((a->municipio) == municipio){
   p = a;
   break;
  }
  a = a->esq;
 }
 return p;
}


ARV4 *procuraNaDireita4(ARV4 *a, char municipio [50]){
 ARV4 *p;
 p = NULL;
 while(a != NULL) {
  if((a->municipio) == municipio){
   p = a;
   break;
  }
  a = a->dir;
 }
 return p;
}

C *procuraCadastro(C *c, char municipio [50]){

 C *p;
 p = NULL;
 while(c != NULL){
  if((c->municipio) == municipio){
   p = c;
   break;
  }
  c = c->prox;
 }
 return p;
}
