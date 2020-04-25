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

/*
char* cifraDeSubstituicao(int nDeslocamento, char text[167])
{
	Uma cifra de substituicao e um algoritmo que permite a encriptacao 
	substituindo um dado caracter por outro. A forma como se encontra 
	a correspondência de um caracter do alfabeto para outro pode ser 
	definido atraves de um shift do alfabeto para a direita. Por exemplo 
	uma cifra de substituicao 5 tem a seguinte correspondência:

	0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ - Alfabeto
	56789ABCDEFGHIJKLMNOPQRSTUVWXYZ01234 - Alfebeto Cifrado

	CADA MALLOC PRECISA DE UM FREE - Frase original
	HFIF RFQQTH UWJHNXF IJ ZR KWJJ - Frase encriptada

	Nesta versao simplificada apenas os caracteres 
	0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ sao encriptados. Desta forma, 
	o texto devera ser convertido para letras maiúsculas e todos os caracteres 
	que nao pertencem ao grupo dos caracteres encriptados deverao manter-se 
	inalterados - como e o caso dos espaços no exemplo anterior. Caso o utilizador 
	especifique um número positivo, o deslocamento e ser feito para a direita 
	(como no caso do exemplo). Caso o número seja negativo, o deslocamento e feito
	 para a esquerda.

	O utilizador podera introduzir o texto utilizando letras maiúsculas ou minúsculas,
	 mas o resultado devera ser sempre apresentado em maiúsculas.

	O parametro n introduzido pelo utilizador tera obrigatoriamente que estar no 
	intervalo [-35 ; 35]. Caso o número esteja fora do intervalo o programa devera 
	imprimir a seguinte mensagem de erro: Error: out of bound e devera voltar a esperar
	 um novo input do utilizador.
	return " ";
}

char* desencriptarCifraDeSubstituicao(int nDeslocamento, char text[167])
{
	return " ";
}
*/
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
			textoEncriptado[count]=toupper(matrizTexto[i][j]);//coloca o caracter na posicao (i,j) na string encriptada 
			count++;//para ir para a proxima posicao count acresenta um
		}
		textoEncriptado[count]='\0';//finaliza o texto
	}

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
	for(int i=0;i<nColuna;i++)//percorre as linhas 
	{
		for (int j=0; j<numLinhas;j++)//percorre as colunar
		{
			printf("|  %c  |",matrizTexto[i][j]);//imprime sedula da coluna (i,j)
		}
		printf("\n");//pula pra proxima linha
	}

	count=0;//reset variavel

	//montando texto encriptado
	for(int j=0; j<numLinhas;j++)//percorre a coluna
	{
		//printf("J = %d",j);
		for(int i=0;i<nColuna;i++)//percorre as linhas
		{
			//printf("I = %d",i);
			textoEncriptado[count]=toupper(matrizTexto[i][j]);//coloca o caracter na posicao (i,j) na string encriptada 
			count++;//para ir para a proxima posicao count acresenta um
		}
		textoEncriptado[count]='\0';//finaliza o texto
	}

	printf("%s\n",textoEncriptado);//mostra o TEXTO ENCRIPTADO 
}

/*
char cifraDeTransposicaoExtra(char text)
{
	Um outro dipo de cifra de transposicao simples pode ser descrita da seguinte forma:

	Considere uma texting S, constituida por N carateres, identificados na forma S = S1S2...SN

		Se o comprimento de S e 1 ou 2 entao a funcao encript(S) = S, isto e, a própria texting.
		Se S for uma texting de comprimento N > 2 entao encript(S) = encript(Sk...S2S1) + encript(SNSN-1...Sk+1) + em que:
			k = N/2, divisao inteira
			símbolo + significa concatenacao de textings, e.g. AB+CB=ABCD

	Exemplos:

	encript("OK") = "OK"

	encript("12345678") = encript("4321") + encript("8765") 
						= encript("34") + encript("12") + encript("78") + encript("56") 
						= "34127856"

	Neste caso, todos os caracteres do texto deverao ser encriptados e o parametro n nao devera ser lido.

	Esta cifra implementa-se naturalmente usando uma funcao recursiva. Uma declaracao possível para esta funcao e a seguinte:

	char * encrypt(char * s, const int length);

	Sera tambem conveniente a implementacao de uma funcao que inverta uma texting com a seguinte declaracao:

	char * reverse(char * s, const unsigned int n);

	A implementacao desta funcionalidade e opcional e sera avaliada, num constest separado no PANDORA (2).
	 Os alunos que optarem por fazer esta implementacao poderao substituir a nota de um dos exercícios praticos
	  pela nota obtida nesta implementacao.

	Os alunos nao terao melhor nota no Mini Projecto pela implementacao desta funcionalidade. 
	Apenas poderao substituir a nota obtida num dos exercícios praticos.
	return ' ';
}

char desencriptarcifraDeTransposicaoExtra(char text)
{
	return ' ';
}
*/

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
			scanf("%1c%*c%d%*c%167[^\n]",&opcao, &nDeslocamento,text);//pegando opcao, numero de deslocamento e texto
	
		} while (validacao(opcao,nDeslocamento));//validando opcao e deslocamento, se inválido = mostrar erro e pedir novamente 

		switch (opcao)
		{
			case 's':
				//cifraDeSubstituicao(nDeslocamento,text);
				break;
			case 'S':
				//desencriptarCifraDeSubstituicao(nDeslocamento,text);
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