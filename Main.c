#include <stdio.h>
#include <string.h>

void pegaInput(char* opcao,int* nDeslocamento, char* text)
{
	//essa função pegar e validar a opção de encriptação escolhida,
	//a quantidade de deslocamento e o texto.
}

int validaOpcao(char* opcao)
{
	//essa função valida a opção digitada pelo utilizador 
	// opcoes = (s,S,t,T,e,E,q)
}

int validaNdeslocamento(char* opcao)
{
	//essa função valida a opção digitada pelo utilizador 
	// [-35 ; 35]
}

char cifraDeSubstituição(char text,char* mensagemEncriptada)
{
	/*
	Uma cifra de substituição é um algoritmo que permite a encriptação 
	substituindo um dado caracter por outro. A forma como se encontra 
	a correspondência de um caracter do alfabeto para outro pode ser 
	definido através de um shift do alfabeto para a direita. Por exemplo 
	uma cifra de substituição 5 tem a seguinte correspondência:

	0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ - Alfabeto
	56789ABCDEFGHIJKLMNOPQRSTUVWXYZ01234 - Alfebeto Cifrado

	CADA MALLOC PRECISA DE UM FREE - Frase original
	HFIF RFQQTH UWJHNXF IJ ZR KWJJ - Frase encriptada

	Nesta versão simplificada apenas os caracteres 
	0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ são encriptados. Desta forma, 
	o texto deverá ser convertido para letras maiúsculas e todos os caracteres 
	que não pertencem ao grupo dos caracteres encriptados deverão manter-se 
	inalterados - como é o caso dos espaços no exemplo anterior. Caso o utilizador 
	especifique um número positivo, o deslocamento é ser feito para a direita 
	(como no caso do exemplo). Caso o número seja negativo, o deslocamento é feito
	 para a esquerda.

	O utilizador poderá introduzir o texto utilizando letras maiúsculas ou minúsculas,
	 mas o resultado deverá ser sempre apresentado em maiúsculas.

	O parâmetro n introduzido pelo utilizador terá obrigatoriamente que estar no 
	intervalo [-35 ; 35]. Caso o número esteja fora do intervalo o programa deverá 
	imprimir a seguinte mensagem de erro: Error: out of bound e deverá voltar a esperar
	 um novo input do utilizador.
	 */
}

char desencriptarCifraDeSubstituição(char text,char* mensagemEncriptada)
{

}

char cifraDeTransposição(char text,char* mensagemEncriptada)
{
	/*Ao contrario da cifra de substituição, numa cifra de transposição
	 as letras existentes na mensagem continuam a ser as mesmas que na 
	 mensagem original. Contudo estas letras são mostradas numa ordem 
	 diferente.

	Uma cifra de transposição simples pode ser feita com recurso a uma matriz. 
	O texto é disposto sobre a forma matricial. Essa matriz é transposta e o 
	texto cifrado é extraído dessa matriz.

	Exemplo:

	Texto original:

	"Sou um guardador de rebanhos."

	Texto disposto em forma matricial numa matriz com 4 colunas:

	+---+---+---+---+
	| S | o | u |   |
	+---+---+---+---+
	| u | m |   | g |
	+---+---+---+---+
	| u | a | r | d |
	+---+---+---+---+
	| a | d | o | r |
	+---+---+---+---+
	|   | d | e |   |
	+---+---+---+---+
	| r | e | b | a |
	+---+---+---+---+
	| n | h | o | s |
	+---+---+---+---+
	| . |   |   |   |
	+---+---+---+---+

	Matriz transposta:

	+---+---+---+---+---+---+---+---+
	| S | u | u | a |   | r | n | . |
	+---+---+---+---+---+---+---+---+
	| o | m | a | d | d | e | h |   |
	+---+---+---+---+---+---+---+---+
	| u |   | r | o | e | b | o |   |
	+---+---+---+---+---+---+---+---+
	|   | g | d | r |   | a | s |   |
	+---+---+---+---+---+---+---+---+

	Frase Cifrada: "Suua rn.omaddeh u roebo gdr as "

	O parâmetro n introduzido pelo utilizador terá obrigatoriamente que estar
	 no intervalo [2 ; 50]. Caso o número esteja fora do intervalo o programa 
	 deverá imprimir a seguinte mensagem de erro: Error: out of bound e deverá 
	 voltar a esperar um novo input do utilizador.
	 */
}

char desencriptarCifraDeTransposição(char text,char* mensagemEncriptada)
{

}

char cifradeTransposiçãoExtra(char text,char* mensagemEncriptada)
{
	/*Um outro dipo de cifra de transposição simples pode ser descrita da seguinte forma:

	Considere uma string S, constituida por N carateres, identificados na forma S = S1S2...SN

		Se o comprimento de S é 1 ou 2 então a função encript(S) = S, isto é, a própria string.
		Se S for uma string de comprimento N > 2 então encript(S) = encript(Sk...S2S1) + encript(SNSN-1...Sk+1) + em que:
			k = N/2, divisão inteira
			símbolo + significa concatenação de strings, e.g. AB+CB=ABCD

	Exemplos:

	encript("OK") = "OK"

	encript("12345678") = encript("4321") + encript("8765") 
						= encript("34") + encript("12") + encript("78") + encript("56") 
						= "34127856"

	Neste caso, todos os caracteres do texto deverão ser encriptados e o parâmetro n não deverá ser lido.

	Esta cifra implementa-se naturalmente usando uma função recursiva. Uma declaração possível para esta função é a seguinte:

	char * encrypt(char * s, const int length);

	Será também conveniente a implementação de uma função que inverta uma string com a seguinte declaração:

	char * reverse(char * s, const unsigned int n);

	A implementação desta funcionalidade é opcional e será avaliada, num constest separado no PANDORA (2).
	 Os alunos que optarem por fazer esta implementação poderão substituir a nota de um dos exercícios práticos
	  pela nota obtida nesta implementação.

	Os alunos não terão melhor nota no Mini Projecto pela implementação desta funcionalidade. 
	Apenas poderão substituir a nota obtida num dos exercícios práticos.*/
}

int main()
{
	//declaração das variáveis
	char opcao = ' ';
	int nDeslocamento = 0;
	char text[167] = "";
	char mensagemEncriptada[167];


}