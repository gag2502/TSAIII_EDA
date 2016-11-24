#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noLista
{
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
  struct noLista *proximo;
};
typedef struct noLista noLista;

struct noArvore
{
    struct noLista *no;
    struct noArvore *esq, *dir;
};
typedef struct noArvore noArvore;

noLista *adicionarNaLista(noLista *lista, noLista *temp);
noLista *carregarLista(noLista *lista);

noLista *carregarLista(noLista *lista) {

    char caractere, atual[100], varTemp[100], string[10], string2[10];
    int i, contador = 0;
    FILE *arquivo;
    noLista *noTemp;
    arquivo = fopen("dadoscfo.csv", "r");
    noTemp = (noLista *) malloc(sizeof(noLista));
    strcpy(atual, "");
    strcpy(varTemp, "");
    string[1] = '\0';
    string2[1] = '\0';

	if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
	else
		while((caractere = fgetc(arquivo)) != EOF)
        {
            if(caractere == '\n')
            {
                strcat(atual, "\n");
                for(i = 0; contador <= 10; i++)
                {
                    if(atual[i] == '\n' || atual[i] == ';')
                    {
                        switch(contador)
                        {
                            case 0:
                                strcpy(noTemp->UF, varTemp);
                                break;
                            case 1:
                                strcpy(noTemp->municipio, varTemp);
                                break;
                            case 2:
                                noTemp->CDs = atoi(varTemp);
                                break;
                            case 3:
                                noTemp->EPAOs = atoi(varTemp);
                                break;
                            case 4:
                                noTemp->TPDs = atoi(varTemp);
                                break;
                            case 5:
                                noTemp->LBs = atoi(varTemp);
                                break;
                            case 6:
                                noTemp->TSBs = atoi(varTemp);
                                break;
                            case 7:
                                noTemp->ASBs = atoi(varTemp);
                                break;
                            case 8:
                                noTemp->APDs = atoi(varTemp);
                                break;
                            case 9:
                                noTemp->EPOs = atoi(varTemp);
                                break;
                            case 10:
                                noTemp->Total = atoi(varTemp);
                        }
                        contador++;
                        strcpy(varTemp, "");
                    }
                    else
                    {
                        string2[0] = atual[i];
                        strcat(varTemp, string2);
                    }
                }
                contador = 0;
                lista = adicionarNaLista(lista, noTemp);
                strcpy(atual, "");
            }
            else
            {
                string[0] = caractere;
                strcat(atual, string);
            }
		}
    free(noTemp);
    fclose(arquivo);
    return lista;
}

noLista *adicionarNaLista(noLista *lista, noLista *temp)
{
    noLista *novo;
    novo = (noLista *) malloc(sizeof(noLista));
    strcpy(novo->UF, temp->UF);
    strcpy(novo->municipio, temp->municipio);
    novo->CDs = temp->CDs;
    novo->EPAOs = temp->EPAOs;
    novo->TPDs = temp->TPDs;
    novo->LBs = temp->LBs;
    novo->TSBs = temp->TSBs;
    novo->ASBs = temp->ASBs;
    novo->APDs = temp->APDs;
    novo->EPOs = temp->EPOs;
    novo->Total = temp->Total;
    novo->proximo = lista;
    lista = novo;
    return lista;
}

void imprimeTeste(noLista *lista)
{
    int i = 1;
    noLista *auxiliar = lista;

    while(auxiliar != NULL)
    {
        printf("%d: %s - %s\n", i++, auxiliar->municipio, auxiliar->UF);
        auxiliar = auxiliar->proximo;
    }
}

int main()
{
    noLista *lista = NULL;
    lista = carregarLista(lista);
    imprimeTeste(lista);
    return 0;
}
