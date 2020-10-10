/* 
	Jogo da Velha ~ Funções
	
	@autor Samuel Mendes Rodrigues

	data de criação: 	08/06/2016
	ultima atualização: 08/06/2016
*/

#include <stdio.h>
#include <stdlib.h>

#define Low  1
#define High 10

/* 
	Função para analise da partida

	OBS: Essa função analisa uma matriz composta por 0(espaços vazios),
		 valores altos(High) e valores baixos(Low).  
*/

int analisar_jogo(int* g)
	{
	char i, resultado = 0;
	
	for(i = 0; i < 3; i++)
	{
		if((*(g + i*3) + *(g + i*3 + 1) + *(g + i*3 + 2)) == 3*Low)
			resultado = 1;
		if((*(g + i*3) + *(g + i*3 + 1) + *(g + i*3 + 2)) == 3*High)
			resultado = 2;
	}

	for(i = 0; i < 3; i++)
	{
		if((*(g + i) + *(g + i + 3) + *(g + i + 6)) == 3*Low)
			resultado = 1;
		if((*(g + i) + *(g + i + 3) + *(g + i + 6)) == 3*High)
			resultado = 2;
	}

	if((*(g + 0) + *(g + 4) + *(g + 8)) == 3*Low)
		resultado = 1;
	if((*(g + 0) + *(g + 4) + *(g + 8)) == 3*High)
		resultado = 2;

	if((*(g + 6) + *(g + 4) + *(g + 2)) == 3*Low)
		resultado = 1;
	if((*(g + 6) + *(g + 4) + *(g + 2)) == 3*High)
		resultado = 2;

	return resultado;
}

/* 
	Função para expor o jogo

	~> Substitui os valores High e Low por caracteres dados a função, "X" ou "O".  
*/

void expor_jogo(int* game, char player_1, char player_2)
	{
	int i;

	printf("\n");

	for(i = 0; i < 9; i++)
	{
        if((!(i%3))&&i)
            printf("\n");
		
		if(*(game+i) == Low)
			printf("[%c]", player_1);
		else if(*(game+i) == High)
			printf("[%c]", player_2);
		else
			printf("[ ]");			
    }
	
	printf("\n");

}
