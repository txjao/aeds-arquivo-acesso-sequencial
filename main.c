#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//int countNumRows(FILE*arquivo);

int main()
{
    setlocale (LC_ALL,"portuguese");

    FILE * fibonacci;
    FILE * fileImpar;
    FILE * filePar;
    FILE * filePrimos;

    int control, numRowsAux,numRows=0;

    do
    {
        printf("Qual opção deseja: \n 1-armazenar 64 digitos \n 2-Separar par de impar \n 3- armazenar primos \n 4- ler valores\n 0- sair \n");
        scanf("%i", &control);
        switch(control)
        {
        case 1:

            fibonacci = fopen("fibonacci.txt","w");

            if( fibonacci == NULL)
            {
                printf("Erro de abertura! \n");
            }

            unsigned long long a = 1;
            unsigned long long b = 0;

            for(int i = 0; i < 64; i++)
            {
                unsigned long long aux = a + b;
                a = b;
                b = aux;
                printf("%i %llu\n", 1+i,aux);
                fprintf(fibonacci, "%llu\n", aux);
            }

            fclose(fibonacci);
            printf("Arquivo salvo! \n\n");
            break;

        case 2:

            filePar = fopen("filePar.txt","w");
            fileImpar = fopen("fileImpar.txt","w");
            fibonacci = fopen("fibonacci.txt","r");

            if( fibonacci == NULL && filePar == NULL && fileImpar == NULL)
            {
                printf("Erro de abertura! \n");
            }
            else
            {
                while((numRowsAux = fgetc(fibonacci)) != EOF)
                {
                    numRows++;
                    for(int i = 0; i < numRows; i++)
                    {
                        for(int i = 0; i < numRows; i++)
                        {
                            unsigned long long n;
                            fscanf(fibonacci,"%llu\n", &n);

                            if(n %2 == 0)
                            {
                                printf("Par:   %15llu\n", n);
                                fprintf(filePar,"%llu\n", n);
                            }
                            else
                            {
                                printf("Impar:   %15llu\n", n);
                                fprintf(fileImpar,"llu\n",n);
                            }
                            break;
                        }

                    }


                }
            }
            fclose(filePar);
            fclose(fileImpar);
            break;
        case 3:
            filePrimos = fopen("filePrimos.txt","w");
            fibonacci = fopen("fibonacci.txt","r");

            if( fibonacci == NULL && filePar == NULL && fileImpar == NULL)
            {
                printf("Erro de abertura! \n");
            }
            else
            {
                while((numRowsAux = fgetc(fibonacci)) != EOF)
                {
                    numRows++;
                    for(int i = 0; i < numRows; i++)
                    {
                        unsigned long long n;
                        fscanf(fibonacci,"%llu\n", &n);


                        int d = 2;
                        int EhPrimo = 1;
                        if (n <= 1)
                            EhPrimo = 0;

                        while (EhPrimo == 1 && d <= n / 2)
                        {
                            if (n % d  == 0)
                                EhPrimo = 0;
                            d = d + 1;
                        }

                        if (EhPrimo == 1)
                        {
                            printf("Primo:   %llu\n", n);
                            fprintf(filePrimos,"%llu\n", n);
                        }
                    }
                }
            }
            fclose(filePrimos);
            break;


        case 4:
            do
            {
                fibonacci = fopen("fibonacci.txt","r");

                printf("\n Digite um número: \n");
                printf("Digite um número negativo para sair! \n");
                scanf("%i", &control);


                if( fibonacci == NULL)
                {
                    printf("Erro de abertura! \n");
                }
                else
                {
                    unsigned long long n[64];
                    for(int i=0; i < 64; i++)
                    {

                        fscanf(fibonacci,"%llu\n", &n[i+1]);

                        if(control == n[i])

                        {
                            printf("Posição: %i Número: %llu\n", i,n[i], "\n");

                            break;
                        }

                    }
                }

                fclose(fibonacci);
            }
            while(control > -1);
            break;

        }


    }while(control != 0);



}



//  int countNumRows(FILE*arquivo)
//  {
//      int numRows=0, numRowsAux;
//      arquivo = fopen(arquivo,"w");

//     while ((numRowsAux = fgetc(arquivo)) != EOF )
//      {
//          numRows++;
//      }

//     return numRows;
// }










