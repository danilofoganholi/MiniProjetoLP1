#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int validacao(char opcao,int nDeslocamento)
{		
	switch (opcao)
	{
		case 's':
		case 'S':
			if (nDeslocamento<=35 && nDeslocamento>=-35)
			{
				return 0;
			}
			printf("Error: out of bound\n");
			break;
		case 't':
		case 'T':
			if (nDeslocamento<=50 && nDeslocamento>=2)
			{
				return 0;
			}
			printf("Error: out of bound\n");
			break;
		case 'e':
		case 'E':
		case 'q':
		case '\n':
			return 0;
			break;
		default:
			printf("Error: Unkown option\n");//mensagem de erro para opcao invalida
			break;
	}
	return 1;
}

void cifraDeSubstituicao(int nDeslocamento, char text[167])
{
	char indice=' ';//variavel que guardará o indice que esta sendo analisado

	for (int i = 0; text[i] != '\0'; i++){// percorrendo o texto passado

		indice = toupper(text[i]);//pegando o caracter e passando para maiuscula
   
   		if (indice>='A' && indice<='Z')//verificando se é uma letra
		{
			indice += nDeslocamento;//se for um letra acrescentamos a quantidade de deslocamento

			if(indice > 'Z')//se o deslocamente der um codigo ASCII maior que o codigo ASCII de Z 
			{
				indice = indice - 'Z';//calculamos o excedente que passou do codigo ASCII do Z

				//Depois verificamos se ele é maior que 10 para saber se caracter passara a ser numero ou nao
				//pois se for maior que 10 ele passara por todas os numeros e voltara a ser letra
				if(indice > 10)
				{	// calculamos o excedente de 10 e acrescentamos 64 para voltar ao codigo ASCII das letras maiusculas
					indice =  64 + (indice-10);
				}
				else//caso seja menor ou igual a 10 significa que a letra passara a ser numero logo
				{
					indice +=47;//ascrescentamos ao excedente do codigo ASCII do Z, 47
				}
 			}
			else if(indice<'A')//se o deslocamente der um codigo ASCII menor que o codigo ASCII de A
			{
         		indice = ('A' - indice);//calculamos o excedente que passou do codigo ASCII do A

				//Depois verificamos se ele é maior que 10 para saber se caractere passara a ser numero ou nao
				//pois se for maior que 10 ele passara por todas os numeros e voltara a ser letra
				if(indice>10)
				{
					indice = 91 -(indice - 10);
				}
				else if(indice<=10)//caso seja menor ou igual a 10 significa que a letra passara a ser numero logo
				{
					indice = 58 - indice;//decrementamos ao excedente do codigo ASCII do Z, 47
				}
			}
		}
    	else if (indice >='0' && indice <='9')//verificando se é um numero
		{
			indice += nDeslocamento;///se for um numero acrescentamos a quantidade de deslocamento

			if(indice > '9')//se der um codigo ASCII maior que o codigo ASCII do 9 esse caractere devera passar para letra
			{
				indice = indice - '9';//calculamos o excedente que passou do codigo ASCII do 9

				//Depois verificamos se ele é maior que 26 para saber se caracter passara a ser uma letra ou nao
				//pois se for maior que 26 ele passara por todas as letras e voltara a ser um numero
				if(indice > 26)
				{	// calculamos o excedente de 26 e acrescentamos  para voltar ao codigo ASCII das letras maiusculas
					indice =  47 + (indice-26);
				}
				else //caso seja menor ou igual a 26 significa que a numero passara a ser letra logo
				{
					indice += 64;//ascrescentamos ao excedente do codigo ASCII que comeca o alfabeto em maiusculas
				}
		  	}
			else if(indice<'0')//se der um codigo ASCII menor que o codigo ASCII de 0 esse caractere devera passar para letra
			{
        		indice = ('0' - indice);//calculamos o excedente que passou do codigo ASCII do 0

				//Depois verificamos se ele é maior que 26 para saber se caracter passara a ser uma letra ou nao
				//pois se for maior que 26 ele passara por todas as letras e voltara a ser um numero
        		if(indice > 26)
				{	// calculamos o excedente de 26 e acrescentamos  para voltar ao codigo ASCII dos numeros
            		indice= 58 -(indice-26);
        		}
				else//se for nenor ou igual a 26 o numero passara a ser letra
				{
            		indice= 91 - indice;
        		}
      		}
		}

		text[i] = indice;
  	}
	printf("%s\n", text);
}

void desencriptarCifraDeSubstituicao(int nDeslocamento, char text[167])
{
  nDeslocamento = nDeslocamento * (-1);
  char indice=' ';//variavel que guardará o indice que esta sendo analisado

	for (int i = 0; text[i] != '\0'; i++){// percorrendo o texto passado

		indice = toupper(text[i]);//pegando o caracter e passando para maiuscula
   
   		if (indice>='A' && indice<='Z')//verificando se é uma letra
		{
			indice += nDeslocamento;//se for um letra acrescentamos a quantidade de deslocamento

			if(indice > 'Z')//se o deslocamente der um codigo ASCII maior que o codigo ASCII de Z 
			{
				indice = indice - 'Z';//calculamos o excedente que passou do codigo ASCII do Z

				//Depois verificamos se ele é maior que 10 para saber se caracter passara a ser numero ou nao
				//pois se for maior que 10 ele passara por todas os numeros e voltara a ser letra
				if(indice > 10)
				{	// calculamos o excedente de 10 e acrescentamos 64 para voltar ao codigo ASCII das letras maiusculas
					indice =  64 + (indice-10);
				}
				else//caso seja menor ou igual a 10 significa que a letra passara a ser numero logo
				{
					indice +=47;//ascrescentamos ao excedente do codigo ASCII do Z, 47
				}
 			}
			else if(indice<'A')//se o deslocamente der um codigo ASCII menor que o codigo ASCII de A
			{
         		indice = ('A' - indice);//calculamos o excedente que passou do codigo ASCII do A

				//Depois verificamos se ele é maior que 10 para saber se caractere passara a ser numero ou nao
				//pois se for maior que 10 ele passara por todas os numeros e voltara a ser letra
				if(indice>10)
				{
					indice = 91 -(indice - 10);
				}
				else if(indice<=10)//caso seja menor ou igual a 10 significa que a letra passara a ser numero logo
				{
					indice = 58 - indice;//decrementamos ao excedente do codigo ASCII do Z, 47
				}
			}
		}
    	else if (indice >='0' && indice <='9')//verificando se é um numero
		{
			indice += nDeslocamento;///se for um numero acrescentamos a quantidade de deslocamento

			if(indice > '9')//se der um codigo ASCII maior que o codigo ASCII do 9 esse caractere devera passar para letra
			{
				indice = indice - '9';//calculamos o excedente que passou do codigo ASCII do 9

				//Depois verificamos se ele é maior que 26 para saber se caracter passara a ser uma letra ou nao
				//pois se for maior que 26 ele passara por todas as letras e voltara a ser um numero
				if(indice > 26)
				{	// calculamos o excedente de 26 e acrescentamos  para voltar ao codigo ASCII das letras maiusculas
					indice =  47 + (indice-26);
				}
				else //caso seja menor ou igual a 26 significa que a numero passara a ser letra logo
				{
					indice += 64;//ascrescentamos ao excedente do codigo ASCII que comeca o alfabeto em maiusculas
				}
		  	}
			else if(indice<'0')//se der um codigo ASCII menor que o codigo ASCII de 0 esse caractere devera passar para letra
			{
        		indice = ('0' - indice);//calculamos o excedente que passou do codigo ASCII do 0

				//Depois verificamos se ele é maior que 26 para saber se caracter passara a ser uma letra ou nao
				//pois se for maior que 26 ele passara por todas as letras e voltara a ser um numero
        		if(indice > 26)
				{	// calculamos o excedente de 26 e acrescentamos  para voltar ao codigo ASCII dos numeros
            		indice= 58 -(indice-26);
        		}
				else//se for nenor ou igual a 26 o numero passara a ser letra
				{
            		indice= 91 - indice;
        		}
      		}
		}

		text[i] = indice;
  	}
	printf("%s\n", text);
}

void cifraDeTransposicao(int nColuna, char text[167])
{
	//declarando variaveis 
	char textoEncriptado[300];//variavel para guardar o texto encriptado
	char matrizTexto[100][100];//matriz para encriptar 
	int textSize=0, count=0, aux=0, numLinhas=0;// variaveis auxiliares

	//decobrindo quantos caracteres o texto possui
	for(int i=0; i<=166;i++)
	{
		if (text[i]=='\0')//quando encontrar o caracter que fecha a string
		{
			textSize=i;//gravar o numero de caracteres menos o primeiro e ultimo que são vazios
			break;//sair
		}
	}

	//decobrindo quantas linhas seram necessárias
	if ((textSize%nColuna)!=0)//se o numero de calavras dividido por colunas der resto é pq precisa de mais uma linha
	{
		numLinhas=(textSize/nColuna)+1;//acrescentar mais uma linha na divisão
	}else//caso de exato nao precisa acrescentar 
	{
		numLinhas=(textSize/nColuna);//numeros de linhas
	}
	
	//passando o texto para a matriz
	for(int i=0;i<numLinhas;i++)//indo pela linha
	{
		for(int j=0; j<nColuna;j++)//indo pela coluna
		{
			if (!(aux))//verifica se o texto já acabou 
			{
				if (text[count]=='\0')//verifica se o caracter é o fim da string
				{
					matrizTexto[i][j]=' '; //colocar espaco na ultima posição 
					aux=1;//colocar auxiliar a 1 para preencher o resto da matriz com espaco
				}else
				{
					matrizTexto[i][j]=text[count];//ir colocando caracter na linha e coluna certo
				}
			}else
			{
				matrizTexto[i][j]=' ';//preencher o resto da matrix com espaco caso precise
			}
			count++;//acrescentar o count para encaixar proximo caracter do texto
		}
	}

	//print da matrix
	/*
	for(int i=0;i<numLinhas;i++)//percorre as linhas 
	{
		for (int j=0; j<nColuna;j++)//percorre as colunar
		{
			printf("|  %c  |",matrizTexto[i][j]);//imprime sedula da coluna (i,j)
		}
		printf("\n");//pula pra proxima linha
	}
	*/
	

	count=0;//reset variavel

	//montando texto encriptado
	for(int j=0; j<nColuna;j++)//percorre a coluna
	{
		for(int i=0;i<numLinhas;i++)//percorre as linhas
		{
			textoEncriptado[count]=matrizTexto[i][j];//coloca o caracter na posicao (i,j) na string encriptada 
			count++;//para ir para a proxima posicao count acresenta um
		}
	}
	textoEncriptado[count]='\0';//finaliza o texto

	printf("%s\n",textoEncriptado);//mostra o TEXTO ENCRIPTADO 
}

void desencriptarCifraDeTransposicao(int nColuna, char text[167])
{
	//declarando variaveis 
	char textoEncriptado[300];//variavel para guardar o texto encriptado
	char matrizTexto[100][100];//matriz para encriptar 
	int textSize=0, count=0, aux=0, numLinhas=0;// variaveis auxiliares

	//decobrindo quantos caracteres o texto possui
	for(int i=0; i<=166;i++)
	{
		if (text[i]=='\0')//quando encontrar o caracter que fecha a string
		{
			textSize=i;//gravar o numero de caracteres menos o primeiro e ultimo que são vazios
			break;//sair
		}
	}

	//decobrindo quantas linhas seram necessárias
	if ((textSize%nColuna)!=0)//se o numero de calavras dividido por colunas der resto é pq precisa de mais uma linha
	{
		numLinhas=(textSize/nColuna)+1;//acrescentar mais uma linha na divisão
	}else//caso de exato nao precisa acrescentar 
	{
		numLinhas=(textSize/nColuna);//numeros de linhas
	}
	
	//passando o texto para a matriz
	for(int i=0;i<nColuna;i++)//indo pela linha
	{
		for(int j=0; j<numLinhas;j++)//indo pela coluna
		{
			if (!(aux))//verifica se o texto já acabou 
			{
				if (text[count]=='\0')//verifica se o caracter é o fim da string
				{
					matrizTexto[i][j]=' '; //colocar espaco na ultima posição 
					aux=1;//colocar auxiliar a 1 para preencher o resto da matriz com espaco
				}else
				{
					matrizTexto[i][j]=text[count];//ir colocando caracter na linha e coluna certo
				}
			}else
			{
				matrizTexto[i][j]=' ';//preencher o resto da matrix com espaco caso precise
			}
			count++;//acrescentar o count para encaixar proximo caracter do texto
		}
	}

	//print da matrix
	/*
	for(int i=0;i<nColuna;i++)//percorre as linhas 
	{
		for (int j=0; j<numLinhas;j++)//percorre as colunar
		{
			printf("|  %c  |",matrizTexto[i][j]);//imprime sedula da coluna (i,j)
		}
		printf("\n");//pula pra proxima linha
	}
	*/

	count=0;//reset variavel

	//montando texto encriptado
	for(int j=0; j<numLinhas;j++)//percorre a coluna
	{
		//printf("J = %d",j);
		for(int i=0;i<nColuna;i++)//percorre as linhas
		{
			//printf("I = %d",i);
			textoEncriptado[count]=matrizTexto[i][j];//coloca o caracter na posicao (i,j) na string encriptada 
			count++;//para ir para a proxima posicao count acresenta um
		}
		textoEncriptado[count]='\0';//finaliza o texto
	}

	printf("%s\n",textoEncriptado);//mostra o TEXTO ENCRIPTADO 
}

int main()
{
	//declaracao das variaveis
	char opcao = ' ';
	int nDeslocamento = 0;
	char text[167];
	
	do//rodar o programa enquanto opcao for diferente de q
	{
		do//pegando input e validando
		{
			scanf(" %1c", &opcao);
			if (opcao!='q')
			{
				scanf("%*c%d%*c%167[^\n]", &nDeslocamento,text);//pegando opcao, numero de deslocamento e texto
			}

		} while (validacao(opcao,nDeslocamento));//validando opcao e deslocamento, se inválido = mostrar erro e pedir novamente 

		switch (opcao)
		{
			case 's':
				cifraDeSubstituicao(nDeslocamento,text);
				break;
			case 'S':
				desencriptarCifraDeSubstituicao(nDeslocamento,text);
				break;
			case 't':
				cifraDeTransposicao(nDeslocamento,text);
				break;
			case 'T':
				desencriptarCifraDeTransposicao(nDeslocamento,text);
				break;
			case 'e':
			case 'E':
			case 'q':
			case '\n':
				break;
			default:
				break;
		}
		
	}while(opcao!='q');
	printf("Exiting->\n");
}

