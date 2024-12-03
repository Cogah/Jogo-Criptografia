	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>	// Biblioteca que permite o acesso as funções baseadas em tempo, possibilitando o uso de n?meros rand?micos
	#include <locale.h> //Biblioteca que vai permitir o suporte de caracteres da l?ngua portuguesa


	//Vari?veis globais utilizadas ao longo do c?digo
	int w, jan = 0, i, j, x, y,xX,yX,xV,yV,xe,ye, roll, life = 3, contfase = 0, zoacaomorte;
	char input, map[60][60],submap[60][60];
	int concluido = 0, primeiraVezLendo = 1;
	/*		
		i e j = linha e coluna
		jan = janela
		map = mapa impresso
		submap = mapa auxiliar(contera apenas as informacoes do mapa original)
	*/
	
	void playermove(){//MECANICA DE MOVIMENTO DO PLAYER==============================================================================================
		if(input == 'w'){
			
			if(map[x-1][y] != '*' && map[x-1][y] != 'D' && map[x-1][y] != '=' && map[x-1][y] != 'O' && map[x-1][y] != 'x' && map[x-1][y] != '@' && map[x-1][y] != '#' && map[x-1][y] != '+' && map[x-1][y] != ']'){
				if(submap[x][y] == '@' ){
					map[x][y] = '@';
				}
				else if(submap[x][y] == '0' ){
					map[x][y] = '0';
				}
				else if(submap[x][y] == 'o' ){
					map[x][y] = 'o';
				}
				else if(map[x][y] == '#'  ){
					map[x][y] = '#';
				}
				else{
					map[x][y] = ' ';
				}
				
				map[x -1][y] = '&';
				x = x -1;
			}
	
		}
		else if(input == 'a'){
			
			if(map[x][y-1] != '*' && map[x][y-1] != 'D' && map[x][y-1] != '=' && map[x][y-1] != 'O' && map[x][y-1] != 'x' && map[x][y-1] != '@' && map[x][y-1] != '#' && map[x][y-1] != '+' && map[x][y-1] != ']'){
				if(submap[x][y] == '@' ){
					map[x][y] = '@';
				}
				else if(submap[x][y] == '0' ){
					map[x][y] = '0';
				}
				else if(submap[x][y] == 'o' ){
					map[x][y] = 'o';
				}
				else if(map[x][y] == '#' ){
					map[x][y] = '#';
				}
				else{
					map[x][y] = ' ';
				}
				
				map[x][y-1] = '&';
		 		y = y - 1;
			}
		}
		else if(input == 's'){
			if(map[x+1][y] != '*' && map[x+1][y] != 'D' && map[x+1][y] != '=' && map[x+1][y] != 'O' && map[x+1][y] != 'x' && map[x+1][y] != '@' && map[x+1][y] != '#' && map[x+1][y] != '+' && map[x+1][y] != ']'){
				if(submap[x][y] == '@' ){
					map[x][y] = '@';
				}
				else if(submap[x][y] == '0' ){
					map[x][y] = '0';
				}
				else if(submap[x][y] == 'o' ){
					map[x][y] = 'o';
				}
				else if(map[x][y] == '#' ){
					map[x][y] = '#';
				}
				else{
					map[x][y] = ' ';
				}
				map[x+1][y] = '&';
				x = x+1;
			}
		}
		else if(input == 'd'){
			if(map[x][y+1] != '*' && map[x][y+1] != 'D' && map[x][y+1] != '=' && map[x][y+1] != 'O' && map[x][y+1] != 'x' && map[x][y+1] != '@' && map[x][y+1] != '#' && map[x][y+1] != '+' && map[x][y+1] != ']'){
				if(submap[x][y] == '@' ){
					map[x][y] = '@';
				}
				else if(submap[x][y] == '0' ){
					map[x][y] = '0';
				}
				else if(submap[x][y] == 'o' ){
					map[x][y] = 'o';
				}
				else if(map[x][y] == '#' ){
					map[x][y] = '#';
				}
				else{
					map[x][y] = ' ';
				}
				map[x][y+1] = '&';
		 		y = y + 1;
			}
		}else if(input == 'q'){
			mainmenu();
		}
	}
	
	void perguntaTutorial(){
		if(primeiraVezLendo == 1){
			printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		    printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    Seja bem-vindo, aqui será seu        |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    terminal para inserir a resposta     |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    das palavras que você deve           |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    decodificar utilizando a             |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    criptografia de César. Sinta-se      |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    livre paraexplorar a sala, pode ser  |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    que você encontre informações úteis. |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		    printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		    printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		    printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
		    getch();
		}
		system("cls");
		printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |   Aqui está seu primeiro desafio para   |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |   testar suas habilidades:              |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                  Qsjtpo                 |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
	    
		char resposta[50];
		scanf("%49s", resposta);
		
		int i;
		for (i = 0; resposta[i]; i++){
        	resposta[i] = tolower(resposta[i]);
   	 	}
   	 	
		if (strcmp(resposta, "prison") == 0){
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta correta --\n");
		 	concluido = 1;
			getch();
		}else{
			if(primeiraVezLendo == 1){
				return;
			}
			life--;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta incorreta --\n");
			printf("\n\t\t\t\t\t\t\t\t\t\t\t -- tentativas restantes: %d --\n", life);
			getch();
		}
	}
	void pergunta1(){
		if(primeiraVezLendo == 1){
			printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		    printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    Muito bem, agora que confirmamos 	 |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    que você possui alguma aptidão em    |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    descriptografia, podemos             |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    compartilhar um pedacinho de         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    informação com você. Essa não é a    |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    primeira vez que fomos atrás de      |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    recrutas, nem a segunda e nem a      |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    décima, e alguns deles tiveram       |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    fins... desagradáveis após falharem  |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    conosco.                             |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		    printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		    printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		    printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
		    getch();
		}
		system("cls");
		printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |   Vamos começar o verdadeiro desafio:   |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                 Sureohp                 |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
	    
	    char resposta[50];
		scanf("%49s", resposta);
		
		int i;
		for (i = 0; resposta[i]; i++){
        	resposta[i] = tolower(resposta[i]);
   	 	}
   	 	
		if (strcmp(resposta, "problem") == 0){
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta correta --\n");
		 	concluido = 1;
			getch();
		}else{
			if(primeiraVezLendo == 1){
				return;
			}
			life--;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta incorreta --\n");
			printf("\n\t\t\t\t\t\t\t\t\t\t\t -- tentativas restantes: %d --\n", life);
			getch();
		}
	}
	
	void pergunta2(){
		if(primeiraVezLendo == 1){
			printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		    printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    Bom trabalho. Que tal uma charada?	 |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    O que tem 4 braços, uma cabeça, e    |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    perdeu 10 partidas seguidas antes    |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    de ser convocado para a melhor       |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    oportunidade de sua vida?            |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    encontre informações úteis.          |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    Dica: Ele pode salvar a IdopterLabs  |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    se triunfar na seleção.              |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		    printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		    printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		    printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
		    getch();
		}
		system("cls");
		printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |  Que tal elevarmos um pouco o desafio?  |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                Ingrrktmk                |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
	    
	    char resposta[50];
		scanf("%49s", resposta);
		
		int i;
		for (i = 0; resposta[i]; i++){
        	resposta[i] = tolower(resposta[i]);
   	 	}
   	 	
		if (strcmp(resposta, "challenge") == 0){
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta correta --\n");
		 	concluido = 1;
			getch();
		}else{
			if(primeiraVezLendo == 1){
				return;
			}
			life--;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta incorreta --\n");
			printf("\n\t\t\t\t\t\t\t\t\t\t\t -- tentativas restantes: %d --\n", life);
			getch();
		}
	}
	void pergunta3(){
		if(primeiraVezLendo == 1){
			printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		    printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    Parabéns! Você chegou ao desafio     |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    final! Mais um pouco e finalmente    |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    receberá o cargo sensacional de      |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    \"descriptografador não remunerado    |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |    da IdopterLabs\"! Quase lá!           |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		    printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		    printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		    printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
		    getch();
		}
		system("cls");
		printf("\t\t\t\t\t\t\t\t             ________________________________________________\n");
		printf("\t\t\t\t\t\t\t\t            /                                                \\\n");
		printf("\t\t\t\t\t\t\t\t           |    _________________________________________     |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |            Seu desafio final:           |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |             Jvunyhabshapvuz             |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |                                         |    |\n");
		printf("\t\t\t\t\t\t\t\t           |   |_________________________________________|    |\n");
		printf("\t\t\t\t\t\t\t\t           |                                                  |\n");
		printf("\t\t\t\t\t\t\t\t            \\_________________________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                   \\___________________________________/\n");
		printf("\t\t\t\t\t\t\t\t                ___________________________________________\n");
		printf("\t\t\t\t\t\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		printf("\t\t\t\t\t\t\t\t          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		printf("\t\t\t\t\t\t\t\t:-------------------------------------------------------------------------:\n");
		printf("\t\t\t\t\t\t\t\t`---._.-------------------------------------------------------------._.---'\n");
	    
	    char resposta[50];
		scanf("%49s", resposta);
		
		int i;
		for (i = 0; resposta[i]; i++){
        	resposta[i] = tolower(resposta[i]);
   	 	}
   	 	
		if (strcmp(resposta, "congratulations") == 0){
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta correta --\n");
		 	concluido = 1;
			getch();
		}else if(strcmp(resposta, " ") == 0){
		}else{
			if(primeiraVezLendo == 1){
				return;
			}
			life--;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t   -- Resposta incorreta --\n");
			printf("\n\t\t\t\t\t\t\t\t\t\t\t -- tentativas restantes: %d --\n", life);
;         	getch();
		}
	}
	
	void dica01(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t __________________________________________________\n");
		printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		printf("\t\t\t\t\t\t\t\t\t|=== ========= =====ARGO NEWS===== ========= ======|\n");
		printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		printf("\t\t\t\t\t\t\t\t\t|          CIFRA DE CÉSAR: COMO SE USA?            |\n");
		printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		printf("\t\t\t\t\t\t\t\t\t| A Cifra de César é uma técnica de criptografia   |\n");
		printf("\t\t\t\t\t\t\t\t\t| simples criada por Júlio César para proteger     |\n");
		printf("\t\t\t\t\t\t\t\t\t| mensagens militares. Ela funciona deslocando     |\n");
		printf("\t\t\t\t\t\t\t\t\t| cada letra do texto original um número fixo de   |\n");
		printf("\t\t\t\t\t\t\t\t\t| posições no alfabeto. Por exemplo, com um        |\n");
		printf("\t\t\t\t\t\t\t\t\t| deslocamento de 3, \"A\" vira \"D\", \"B\" vira \"E\" e  |\n");
		printf("\t\t\t\t\t\t\t\t\t| assim por diante; ao chegar ao fim do alfabeto,  |\n");
		printf("\t\t\t\t\t\t\t\t\t| ele reinicia (ex.: \"Y\" vira \"B\"). Para decifrar, |\n");
		printf("\t\t\t\t\t\t\t\t\t| basta inverter o deslocamento. Apesar de ser     |\n");
		printf("\t\t\t\t\t\t\t\t\t| insegura para usos modernos, a Cifra de César é  |\n");
		printf("\t\t\t\t\t\t\t\t\t| amplamente utilizada para ensinar os princípios  |\n");
		printf("\t\t\t\t\t\t\t\t\t| básicos da criptografia e como introdução a      |\n");
		printf("\t\t\t\t\t\t\t\t\t| sistemas mais complexos. Hoje, ela também        |\n");
		printf("\t\t\t\t\t\t\t\t\t| aparece em jogos, desafios e brincadeiras de     |\n");
		printf("\t\t\t\t\t\t\t\t\t| mensagens secretas. Que tal testar? Escolha um   |\n");
		printf("\t\t\t\t\t\t\t\t\t| número para o deslocamento, escreva uma frase e  |\n");
		printf("\t\t\t\t\t\t\t\t\t| crie sua própria mensagem criptografada!         |\n");
		printf("\t\t\t\t\t\t\t\t\t|__________________________________________________|\n");
		getch();
	}
	void dica02(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   o                   o\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t    \\               __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t     \\___          /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t         \\__    __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t            \\  /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t ____________\\/____________\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t/   ____________________   \\\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  /__/  \\__   \\__/  \\__\\  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  \\________\\___________/  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|                 _   _    |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  TV IL           (|) (/) |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t\\_________________________/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t    \"--\"           \"--\"\n");
	    printf("\n\t\t\t\t\t\t\t\t     --Professor: Para resolver este problema, que tal pegarmos o número 1 como exemplo?--\n");
	    getch();
	}
	
	void dica11(){
	    printf("\n\n\t\t\t\t\t\t\t\t\t                       @@@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                      @@@@@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                     @@@@@@@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                    @@@@@@@@@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                   @@@@@    @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                  @@@@@      @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                 @@@@@        @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t                @@@@@   @@@    @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t               @@@@@   @@@@@    @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t              @@@@@    @@@@@     @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t             @@@@@     @@@@@      @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t            @@@@@      @@@@@       @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t           @@@@@       @@@@@        @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t          @@@@@        @@@@@         @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t         @@@@@         @@@@@          @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t        @@@@@          @@@@@           @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t       @@@@@            @@@             @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t      @@@@@                              @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t     @@@@@             @@@@@              @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t    @@@@@             @@@@@@@              @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t   @@@@@               @@@@@                @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t  @@@@@                                      @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t @@@@@                                        @@@@@\n");
	    printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	    printf("\n\t\t\t\t\t\t--AVISO: As vezes as dicas podem indicar não o número do deslocamento, mas sim a palavra da resposta--\n");

		getch();
	}
	void dica12(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t   o                   o\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t    \\               __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t     \\___          /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t         \\__    __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t            \\  /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t ____________\\/____________\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t/   ____________________   \\\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t|  /__/  \\__   \\__/  \\__\\  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t|  \\________\\___________/  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t|                 _   _    |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t|  TV IL           (|) (/) |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\\_________________________/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t    \"--\"           \"--\"\n");
	    printf("\n\t\t\t\t--Repórter: Apesar de ter apresentado problemas no joelho pouco tempo antes da competição, o corredor conseguir conquistar a medalha de bronze!--\n");
	    getch();
	}
	void dica03(){
	    printf("\n\n\t\t\t\t\t\t\t\t\t\t    __________________   __________________\n");
	    printf("\t\t\t\t\t\t\t\t\t\t.-/|                  \\ /                  |\\-.\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||     Shrek 1:      |    Capítulo 1     ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||     O Livro       |     A Prisão      ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||  ===============  |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||                   |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||  ===============  |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||                   |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||  ===============  |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||                   |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||  ===============  |  ===============  ||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||||__________________ | __________________||||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t||/===================\\|/===================\\||\n");
	    printf("\t\t\t\t\t\t\t\t\t\t`--------------------~___~-------------------''\n");
	    getch();
	}
	 
	void dica21(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   o                   o\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t    \\               __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t     \\___          /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t         \\__    __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t            \\  /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t ____________\\/____________\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t/   ____________________   \\\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  /__/  \\__   \\__/  \\__\\  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  \\________\\___________/  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|                 _   _    |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  TV 66           (|) (/) |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t\\_________________________/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t    \"--\"           \"--\"\n");
	    printf("\n\t\t\t\t\t\t\t\t --Apresentador: Boa noite e sejam bem vindos ao canal das 6:00! No programa de hoje...--\n");
	    getch();
	}
	void sextou(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t.===================================================================.\n");
	    printf("\t\t\t\t\t\t\t\t\t||     		 ____  ____  _  _  ____  __   _  _  _   	   ||\n");
	    printf("\t\t\t\t\t\t\t\t\t|| 		/ ___)(  __)( \\/ )(_  _)/  \\ / )( \\/ \\  	   ||\n");
	    printf("\t\t\t\t\t\t\t\t\t|| 		\\___ \\ ) _)  )  (   )( (  O )) \\/ (\\_/   	   ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||    		(____/(____)(_/\\_) (__) \\__/ \\____/(_)  	   ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                          .'   '.                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                         /       \\           oOoOo               ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                        |         |       ,==|||||               ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                         \\       /       _|| |||||               ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                          '.___.'    _.-'^|| |||||               ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                        __/_______.-'     '==HHHHH               ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                   _.-'` /                   \"\"\"\"\"               ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                .-'     /   oOoOo                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                `-._   / ,==|||||                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                    '-/._|| |||||                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                     /  ^|| |||||                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                    /    '==HHHHH                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                   /________\"\"\"\"\"                                ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                   `\\       `\\                                   ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                     \\        `\\   /                             ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                      \\         `\\/                              ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                      /                                          ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                     /                                           ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                    /_____                                       ||\n");
	    printf("\t\t\t\t\t\t\t\t\t||                                                                 ||\n");
	    printf("\t\t\t\t\t\t\t\t\t'==================================================================='\n");
	    getch();
	}
	void dica31(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t __________________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t| Você está provando seu valor na criptografia por |\n");
		    printf("\t\t\t\t\t\t\t\t\t| um tempinho já. Que tal relaxar um pouco com uma |\n");
		    printf("\t\t\t\t\t\t\t\t\t| pequena equação?                                 |\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t|              sqr(2(X+2)-3) + 1 = 4               |\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t|  Qual será o valor de X nessa equação?           |\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t|                                                  |\n");
		    printf("\t\t\t\t\t\t\t\t\t|__________________________________________________|\n");
	    getch();
	}
	void dica32(){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   o                   o\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t    \\               __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t     \\___          /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t         \\__    __/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t            \\  /\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t ____________\\/____________\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t/   ____________________   \\\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  /__/  \\__   \\__/  \\__\\  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |    __   \\__    __   \\| |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t| |\\__/  \\__   \\__/  \\__ | |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  \\________\\___________/  |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|                 _   _    |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t|  TV IL           (|) (/) |\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t\\_________________________/\n");
	    printf("\t\t\t\t\t\t\t\t\t\t\t\t    \"--\"           \"--\"\n");
	    printf("\n\t\t\t\t\t\t\t\t\t\t    --Está passando o filme da Branca de neve da TV--\n");
	    getch();
	}
	
	void dica33(){
	    printf("\n\n\t\t\t\t\t\t\t                                        zzzzzzzzzzzzzzzzzz                                          \n");
	    printf("\t\t\t\t\t\t\t                                   zzyslea97655444555790bflsyzzz                                    \n");
	    printf("\t\t\t\t\t\t\t                               zzvg3222479aaaaaaaaaaaaaa07643329myzz                                \n");
	    printf("\t\t\t\t\t\t\t                          zzzti63468aaabceghjklllllkjihgedcbaa085540nvzz                            \n");
	    printf("\t\t\t\t\t\t\t                        zzug43690abehjkkjhgfffeeeeeeefgghjklkigdbaa9649jwzz                         \n");
	    printf("\t\t\t\t\t\t\t                       zq724800dikkjfddccb09877776777890cddddegjkkjeaa0650qz                        \n");
	    printf("\t\t\t\t\t\t\t                    zzo32590ahkjfcccb965544321ZZZZYZZ124555570ccdehkljdbb843kyzz                    \n");
	    printf("\t\t\t\t\t\t\t                   zq73600djkhdca96543ZXVVX146788887531XWVWX134560cdeiklgca856kyz                   \n");
	    printf("\t\t\t\t\t\t\t                 zt92590ejkgcb0653YVUX8krxzzzzz     zzzzytoi9ZVWY3570degjkica957mzz                 \n");
	    printf("\t\t\t\t\t\t\t                yj2390djkgcc0652VUWfvyzz                   zzzxq5VWZ568cdfjliba84buz                \n");
	    printf("\t\t\t\t\t\t\t              zw61690gjhbb9541VV4szz                            zyk1VX357bdfklgba65pzz              \n");
	    printf("\t\t\t\t\t\t\t           zzl2279djidb0641VWavz                                  zr8WW257cehkjcb85exz             \n");
	    printf("\t\t\t\t\t\t\t            yh1380fjgba642WU6tzz                                     zr5WY460efklfb95dwz            \n");
	    printf("\t\t\t\t\t\t\t           zdZ590hjda954YTVpz                                          zrZW268dejlgba5bx            \n");
	    printf("\t\t\t\t\t\t\t         zyaZ490jida943VT8vz                                            zv0XY57cehlgb06dzz          \n");
	    printf("\t\t\t\t\t\t\t        zye148aijda842VTdzz                                              zzhWY46behlhca7hzz         \n");
	    printf("\t\t\t\t\t\t\t        zn2380hjca743VUmz                                                  zoWX46bejlfb87nz         \n");
	    printf("\t\t\t\t\t\t\t       zw7168eic0843VVjz                                                    zkYY57celkdb7buz        \n");
	    printf("\t\t\t\t\t\t\t       zfY58bjf0842WVdyz                                                     w0W160egmhc06kz        \n");
	    printf("\t\t\t\t\t\t\t      zwZ3bejib953WT3xz                                                      zv3Y5ahgjortuuvxz      \n");
	    printf("\t\t\t\t\t\t\t      zmlqrrrrpjjopnpy                                                        zlisuuutuuuuuuuwz     \n");
	    printf("\t\t\t\t\t\t\t   zzzxprrrrrrrssssssrwyzzz                                                zzxvutuuuuuttttuuutttuyz \n");
	    printf("\t\t\t\t\t\t\t zyspqqqqppprrrqssssssssrrwz                                              zwtuuuuttuuuuuttuuttuuuuyz\n");
	    printf("\t\t\t\t\t\t\t zsqrrqpqrrqprsssrqrrrsttssy                                              ztuuutuuuuuuuuuuuuuuuuuuyz\n");
	    printf("\t\t\t\t\t\t\t zrqrqqrrrrssssssssssssstruz                                              zrqrqqrrrrssssssssssssstruz\n");
	    printf("\t\t\t\t\t\t\t zzsqqqqrrrrrrrrrrsssrsstyz                                                zzsqqqqrrrrrrrrrrsssrsstyz\n");
	    printf("\t\t\t\t\t\t\t   zzzzz zzzz zzzz zzzzz                                                     zzzzz zzzz zzzz zzzzz   \n");
	    printf("\n\n\t\t\t\t\t\t\t\t        --É possível ver um arco-íris com todas as suas cores à distância--\n");
	    getch();
	}
	void dica34(){
	    printf("\n\n\t\t\t\t\t\t\t\t      Dom       Seg       Ter       Qua       Qui       Sex       Sáb     \n");
	    printf("\t\t\t\t\t\t\t\t  -----------------------------------------------------------------------\n");
	    printf("\t\t\t\t\t\t\t\t  |         |1        |2        |3        |4        |5        |6        |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |11:40    |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |Apres.   |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |Trabalho |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |Girotto  |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  -----------------------------------------------------------------------\n");
	    printf("\t\t\t\t\t\t\t\t  |?        |8        |9        |10       |11       |12       |13       |\n");
	    printf("\t\t\t\t\t\t\t\t  |Início da|         |         |         |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |nova     |         |         |         |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |tentativa|         |         |         |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  -----------------------------------------------------------------------\n");
	    printf("\t\t\t\t\t\t\t\t  |??       |15       |16       |17       |18       |19       |20       |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |  \\  /   |Dia de   |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |   \\/    |coleta   |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |   /\\    |do lixo  |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |  /  \\   |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  -----------------------------------------------------------------------\n");
	    printf("\t\t\t\t\t\t\t\t  |??       |22       |23       |24       |25       |26       |27       |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |Véspera  |Natal    |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |de       |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |Natal    |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  -----------------------------------------------------------------------\n");
	    printf("\t\t\t\t\t\t\t\t  |??       |29       |30       |31       |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |Véspera  |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |de       |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |Ano Novo |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  |         |         |         |         |         |         |         |\n");
	    printf("\t\t\t\t\t\t\t\t  -----------------------------------------------------------------------\n");
	    getch();
	}
	
	void gameover(){
		system("cls");
		printf("\t\t\t\t\t                              _____              __  __   ______      ____   __      __  ______   _____  \n");
		printf("\t\t\t\t\t                             / ____|     /\\     |  \\/  | |  ____|    / __ \\  \\ \\    / / |  ____| |  __ \\ \n");
		printf("\t\t\t\t\t                            | |  __     /  \\    | \\  / | | |__      | |  | |  \\ \\  / /  | |__    | |__) |\n");
		printf("\t\t\t\t\t                            | | |_ |   / /\\ \\   | |\\/| | |  __|     | |  | |   \\ \\/ /   |  __|   |  _  / \n");
		printf("\t\t\t\t\t                            | |__| |  / ____ \\  | |  | | | |____    | |__| |    \\  /    | |____  | | \\ \\ \n");
		printf("\t\t\t\t\t                             \\_____| /_/    \\_\\ |_|  |_| |______|    \\____/      \\/     |______| |_|  \\_\\\n");
		printf("\t\t\t\t\t                                                                                                          \n");
		printf("\t\t\t\t\t                                                                                                          \n");
	  	printf(" \n\n\n\n\t\t\t\t  Parece que os monstros est?o se divertindo a sua custa. Ser? que voc? ? realmente t?o ruim em fugir? Talvez seja hora de aceitar o seu destino...\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t           --PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU--\n");
	  	getch();
		w = 0;
		life = 3;
		contfase = 0;
		system("cls");
		mainmenu();
	}
	
	void ending(){
		system("cls");
		printf("\nAp?s escapar da Argo, Serruya comemora sua liberdade com bebidas e fortune dragon, pois o tigrinho n?o esta pagando. No entanto, ? medida\nque a luz do dia comeca a raiar,  Serruya tem um momento de lucidez e se lembra que faltam poucas horas para a aula da Alessandra, sua\nprofessora mais temida. Serruya passa mal s? de imaginar o olhar desapontado da professora ao descobrir sua aus?ncia.\n");
		getch();
		//system("cls");
		printf("\nEnquanto a festan?a acontecia ao seu redor, Serruya percebe que, apesar de ter conseguido sobreviver, ainda existiam responsabilidades que\no aguardavam. ");
		printf("Ele respira fundo e vai para a faculdade, com ressaca e triste por ter perdido todo o seu dinheiro apostando.\n");
		getch();
		//system("cls");
		printf("\nDurante a aula da Alessandra, Serruya tentou acompanhar a explica??o sobre n?meros bin?rios, por?m, sucumbiu ao cansa?o novamente...\n");
		getch();
		//system("cls");
		printf("\nO resto ? historia.\n");
	    getch();
		system("cls");
		
		
		printf("\t\t\t\t\t                                                 ______ _____ __  __             ___   \n");
		printf("\t\t\t\t\t                                                |  ____|_   _|  \\/  |           |__ \\  \n");
		printf("\t\t\t\t\t                                                | |__    | | | \\  / |              ) | \n");
		printf("\t\t\t\t\t                                                |  __|   | | | |\\/| |             / /  \n");
		printf("\t\t\t\t\t                                                | |     _| |_| |  | |_   _   _   |_|   \n");
		printf("\t\t\t\t\t                                                |_|    |_____|_|  |_(_) (_) (_)  (_)   \n");
	  	printf(" \n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t          Obrigado por jogar!\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         --PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU--\n");
	  	getch();
		w = 0;
		life = 3;
		contfase = 0;
		system("cls");
		mainmenu();
	}
		
	//FECHAMENTO DO JOGO ================================================================================================================================================================================
	int saida(){
		system ("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t      --Obrigado por jogar!!!--\n\n\n\n\n");
		exit(0);
		return 0;
	}
	
	//FASE 3=========================================================================================================================================
	int fase3(){
		life = 5;
		primeiraVezLendo = 1;
		contfase = 1;
		concluido = 0;
		x = 13;
		y = 10;	
		for(i = 0; i <= 20; i++){
			for(j = 0;j<=20; j++){
				map[i][j] = '*';
			}
		}
		
		for(i = 1; i <= 19; i++){
			for(j = 1;j<=19; j++){
				map[i][j] = ' ';
				submap[i][j] = ' ';
			}
		}
		
		map [17][10] = 'O';
		map [18][10] = '=';
		submap [17][10] = 'O';
		submap [18][10] = '=';
		
		map [6][7] = 'x';
		submap [6][7] = 'x';
		
		map [18][18] = '#';
		submap [18][18] = '#';
		
		map [14][3] = '@';
		submap [14][3] = '@';
		
		map [7][15] = '+';
		submap [7][15] = '+';
		
		map [9][0] = ']';
		submap [9][0] = ']';
		
		map [x][y] = '&';
	
	
		//==========================================================================================================
		while(life != 0){
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t       Vida: %d\n\n", life);	
			printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);		
			
			//MENSAGENS DE LOGS=======================================================================================================
			if (concluido == 1){
				system("cls");
				printf("\t\t\t\t\t\t\t\t\t\t       -- Bom trabalho, vamos seguir em frente --\n");
				printf("\t\t\t\t\t\t\t\t\t\t          Aperte qualquer botão para continuar");
				getch();
				system("cls");
				saida();
			}
		
		
			printf("\n\n\n\n");
			for(i = 0; i <=20; i++){
				printf("\t\t\t\t\t\t\t\t\t\t       ");
				for(j = 0;j<=20; j++){
					printf("%c ", map [i] [j]);
				}
				printf("\n");
				
			}
			printf("\n\n\n\n\n");
			input = getche();
			playermove();
			system("cls");
		
			if(input == 'i'){
				if(map[x][y-1] == '=' || map[x][y-1] == 'O' || map[x][y+1] == '=' || map[x][y+1] == 'O' || map[x-1][y] == '=' || map[x-1][y] == 'O' || map[x+1][y] == '=' || map[x+1][y] == 'O'){
					pergunta3();
					primeiraVezLendo = 0;
					system("cls");
				}
				else if(map[x][y-1] == 'x' || map[x][y+1] == 'x' || map[x-1][y] == 'x' || map[x+1][y] == 'x'){
					dica01();
					system("cls");
				}else if(map[x][y-1] == '@' || map[x][y+1] == '@' || map[x-1][y] == '@' || map[x+1][y] == '@'){
					dica34();
					system("cls");
				}else if(map[x][y-1] == '#' || map[x][y+1] == '#' || map[x-1][y] == '#' || map[x+1][y] == '#'){
					dica32();
					system("cls");
				}else if(map[x][y-1] == '+' || map[x][y+1] == '+' || map[x-1][y] == '+' || map[x+1][y] == '+'){
					dica31();
					system("cls");
				}else if(map[x][y-1] == ']'){
					dica33();
					system("cls");
				}
			}
			
			else if(input == 'k'){
				life--;
				
				if(life == 0){
					gameover();
				}	
				else{
				}
			}
		}
	}
	
	//FASE 2=========================================================================================================================================
	int fase2(){
		life = 5;
		primeiraVezLendo = 1;
		contfase = 1;
		concluido = 0;
		x = 13;
		y = 10;	
		for(i = 0; i <= 20; i++){
			for(j = 0;j<=20; j++){
				map[i][j] = '*';
			}
		}
		
		for(i = 1; i <= 19; i++){
			for(j = 1;j<=19; j++){
				map[i][j] = ' ';
				submap[i][j] = ' ';
			}
		}
		
		map [17][15] = 'O';
		map [18][15] = '=';
		submap [17][15] = 'O';
		submap [18][15] = '=';
		
		map [18][11] = 'x';
		submap [18][11] = 'x';
		
		map [7][10] = '@';
		submap [7][10] = '@';
		
		map [12][1] = '#';
		submap [12][1] = '#';
		
		map [x][y] = '&';
	
	
		//==========================================================================================================
		while(life != 0){
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t       Vida: %d\n\n", life);	
			printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);		
			
			//MENSAGENS DE LOGS=======================================================================================================
			if (concluido == 1){
				system("cls");
				printf("\t\t\t\t\t\t\t\t\t\t       -- Bom trabalho, vamos seguir em frente --\n");
				printf("\t\t\t\t\t\t\t\t\t\t          Aperte qualquer botão para continuar");
				getch();
				system("cls");
				fase3();
			}
		
		
			printf("\n\n\n\n");
			for(i = 0; i <=20; i++){
				printf("\t\t\t\t\t\t\t\t\t\t       ");
				for(j = 0;j<=20; j++){
					printf("%c ", map [i] [j]);
				}
				printf("\n");
				
			}
			printf("\n\n\n\n\n");
			input = getche();
			playermove();
			system("cls");
		
			if(input == 'i'){
				if(map[x][y-1] == '=' || map[x][y-1] == 'O' || map[x][y+1] == '=' || map[x][y+1] == 'O' || map[x-1][y] == '=' || map[x-1][y] == 'O' || map[x+1][y] == '=' || map[x+1][y] == 'O'){
					pergunta2();
					primeiraVezLendo = 0;
					system("cls");
				}
				else if(map[x][y-1] == 'x' || map[x][y+1] == 'x' || map[x-1][y] == 'x' || map[x+1][y] == 'x'){
					dica01();
					system("cls");
				}else if(map[x][y-1] == '@' || map[x][y+1] == '@' || map[x-1][y] == '@' || map[x+1][y] == '@'){
					sextou();
					system("cls");
				}else if(map[x][y-1] == '#' || map[x][y+1] == '#' || map[x-1][y] == '#' || map[x+1][y] == '#'){
					dica21();
					system("cls");
				}
			}
			
			else if(input == 'k'){
				life--;
				
				if(life == 0){
					gameover();
				}	
				else{
				}
			}
		}
	}
	//FASE 1=========================================================================================================================================
	int fase1(){
		life = 5;
		primeiraVezLendo = 1;
		contfase = 1;
		concluido = 0;
		x = 13;
		y = 10;	
		for(i = 0; i <= 20; i++){
			for(j = 0;j<=20; j++){
				map[i][j] = '*';
			}
		}
		
		for(i = 1; i <= 19; i++){
			for(j = 1;j<=19; j++){
				map[i][j] = ' ';
				submap[i][j] = ' ';
			}
		}
		
		map [4][7] = 'O';
		map [5][7] = '=';
		submap [4][10] = 'O';
		submap [5][10] = '=';
		
		map [8][4] = '@';
		submap [8][4] = '@';
		
		map [4][15] = '#';
		submap [4][15] = '#';
		
		map [14][17] = 'x';
		submap [14][17] = 'x';
		
		map [x][y] = '&';
	
	
		//==========================================================================================================
		while(life != 0){
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t       Vida: %d\n\n", life);	
			printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);		
			
			//MENSAGENS DE LOGS=======================================================================================================
			if (concluido == 1){
				system("cls");
				printf("\t\t\t\t\t\t\t\t\t\t       -- Bom trabalho, vamos seguir em frente --\n");
				printf("\t\t\t\t\t\t\t\t\t\t          Aperte qualquer botão para continuar");
				getch();
				system("cls");
				fase2();
			}
		
		
			printf("\n\n\n\n");
			for(i = 0; i <=20; i++){
				printf("\t\t\t\t\t\t\t\t\t\t       ");
				for(j = 0;j<=20; j++){
					printf("%c ", map [i] [j]);
				}
				printf("\n");
				
			}
			printf("\n\n\n\n\n");
			input = getche();
			playermove();
			system("cls");
		
			if(input == 'i'){
				if(map[x][y-1] == '=' || map[x][y-1] == 'O' || map[x][y+1] == '=' || map[x][y+1] == 'O' || map[x-1][y] == '=' || map[x-1][y] == 'O' || map[x+1][y] == '=' || map[x+1][y] == 'O'){
					pergunta1();
					primeiraVezLendo = 0;
					system("cls");
				}
				else if(map[x][y-1] == 'x' || map[x][y+1] == 'x' || map[x-1][y] == 'x' || map[x+1][y] == 'x'){
					dica01();
					system("cls");
				}else if(map[x][y-1] == '@' || map[x][y+1] == '@' || map[x-1][y] == '@' || map[x+1][y] == '@'){
					dica11();
					system("cls");
				}else if(map[x][y-1] == '#' || map[x][y+1] == '#' || map[x-1][y] == '#' || map[x+1][y] == '#'){
					dica12();
					system("cls");
				}
			}
			
			else if(input == 'k'){
				life--;
				
				if(life == 0){
					gameover();
				}	
				else{
				}
			}
		}
	}
	//TUTORIAL=========================================================================================================================================
	int faseTutorial(){
		life = 5;
		primeiraVezLendo = 1;
		contfase = 0;
		concluido = 0;
		x = 13;
		y = 10;	
		for(i = 0; i <= 20; i++){
			for(j = 0;j<=20; j++){
				map[i][j] = '*';
			}
		}
		
		for(i = 1; i <= 19; i++){
			for(j = 1;j<=19; j++){
				map[i][j] = ' ';
				submap[i][j] = ' ';
			}
		}
		
		map [7][10] = 'O';
		map [8][10] = '=';
		submap [7][10] = 'O';
		submap [8][10] = '=';
		
		map [14][10] = 'x';
		submap [14][10] = 'x';
		
		map [9][7] = '@';
		submap [9][7] = '@';
		
		map [6][14] = '#';
		submap [6][14] = '#';
		
		map [x][y] = '&';
	
	
		//==========================================================================================================
		while(life != 0){
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t       Vidas: %d\n\n", life);	
			printf("\t\t\t\t\t\t\t\t\t\t\t\t       [%d][%d]\n\n\n",x,y);		
			
			//MENSAGENS DE LOGS=======================================================================================================
			if (concluido == 1){
				printf("\t\t\t\t\t\t\t\t\t       -- Muito bem, vamos começar os verdadeiros testes agora --\n");
				printf("\t\t\t\t\t\t\t\t\t\t          Aperte qualquer botão para continuar");
				fase1();
			}
		
		
			printf("\n\n\n\n");
			for(i = 0; i <=20; i++){
				printf("\t\t\t\t\t\t\t\t\t\t       ");
				for(j = 0;j<=20; j++){
					printf("%c ", map [i] [j]);
				}
				printf("\n");
				
			}
			printf("\n\n\n\n\n");
			input = getche();
			playermove();
			system("cls");
		
			if(input == 'i'){
				if(map[x][y-1] == '=' || map[x][y-1] == 'O' || map[x][y+1] == '=' || map[x][y+1] == 'O' || map[x-1][y] == '=' || map[x-1][y] == 'O' || map[x+1][y] == '=' || map[x+1][y] == 'O'){
					perguntaTutorial();
					primeiraVezLendo = 0;
					system("cls");
				}
				else if(map[x][y-1] == 'x' || map[x][y+1] == 'x' || map[x-1][y] == 'x' || map[x+1][y] == 'x'){
					dica01();
					system("cls");
				}else if(map[x][y-1] == '@' || map[x][y+1] == '@' || map[x-1][y] == '@' || map[x+1][y] == '@'){
					dica03();
					system("cls");
				}else if(map[x][y-1] == '#' || map[x][y+1] == '#' || map[x-1][y] == '#' || map[x+1][y] == '#'){
					dica02();
					system("cls");
				}else if(map[x][y-1] == '+' || map[x][y+1] == '+' || map[x-1][y] == '+' || map[x+1][y] == '+'){
					dica31();
					system("cls");
				}
			}
			
			else if(input == 'k'){
				life--;
				
				if(life == 0){
					gameover();
				}	
				else{
				}
			}
		}
	}
	void textoinicial(){
		printf("\t\t\t\t\t\t\t\t             ___________________________________________________________\n");
	    printf("\t\t\t\t\t\t\t\t            /                                                 		\\\n");
	    printf("\t\t\t\t\t\t\t\t           |    _____________________________________________________    |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    Era um domingo à noite, e Bernardo após perder   |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    a decima partida seguida se preparava para       |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    desligar o computador, quando de repente,        |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    algo chamou sua atenção.                         |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    Um e-mail com o assunto                          |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    \"Oportunidade Exclusiva, Idopter Labs\"           |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    destacava-se na caixa de entrada.                |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    Bernardo reconheceu aquele nome instantaneamente |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |    e logo clicou no e-mail.                         |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |_____________________________________________________|   |\n");
	    printf("\t\t\t\t\t\t\t\t           |                                                             |\n");
	    printf("\t\t\t\t\t\t\t\t            \\___________________________________________________________/\n");
	    printf("\t\t\t\t\t\t\t\t                   \\_______________________________________________/\n");
	    printf("\t\t\t\t\t\t\t\t                      ___________________________________________\n");
	    printf("\t\t\t\t\t\t\t\t                   _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
	    printf("\t\t\t\t\t\t\t\t                _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t             _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t          _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t      :-------------------------------------------------------------------------:\n");
	    printf("\t\t\t\t\t\t\t\t      `---._.-------------------------------------------------------------._.---'\n");
	    getch();
	    
	    system("cls");
	    printf("\t\t\t\t\t\t\t\t             ___________________________________________________________\n");
	    printf("\t\t\t\t\t\t\t\t            /                                                 		\\\n");
	    printf("\t\t\t\t\t\t\t\t           |    _____________________________________________________    |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  \"Querido Bernardo,                                 |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  Identificamos suas habilidades e acreditamos que   |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  você seria uma peça fundamental para nossa equipe  |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  na Idopter Labs. Somos uma empresa inovadora,      |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  trabalhando em projetos que podem mudar o futuro.  |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  Essa mensagem é confidencial. Caso aceite explorar |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  esta oportunidade, clique no link abaixo.          |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  Atenciosamente,                                    |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  Equipe Idopter Labs.\"                              |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |_____________________________________________________|   |\n");
	    printf("\t\t\t\t\t\t\t\t           |                                                             |\n");
	    printf("\t\t\t\t\t\t\t\t            \\___________________________________________________________/\n");
	    printf("\t\t\t\t\t\t\t\t                   \\_______________________________________________/\n");
	    printf("\t\t\t\t\t\t\t\t                      ___________________________________________\n");
	    printf("\t\t\t\t\t\t\t\t                   _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
	    printf("\t\t\t\t\t\t\t\t                _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t             _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t          _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t      :-------------------------------------------------------------------------:\n");
	    printf("\t\t\t\t\t\t\t\t      `---._.-------------------------------------------------------------._.---'\n");
	    getch();
	    
	    system("cls");
	    printf("\t\t\t\t\t\t\t\t             ___________________________________________________________\n");
	    printf("\t\t\t\t\t\t\t\t            /                                                 		\\\n");
	    printf("\t\t\t\t\t\t\t\t           |    _____________________________________________________    |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  Bernardo desconfiou , pois ele não se lembrava de  |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  ter enviado seu currículo recentemente.            |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  Algo naquele e-mail misterioso o deixava com um    |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  pressentimento ruim.                               |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  No final da mensagem havia dois links:             |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  -> Aceitar e Saber Mais(A)                         |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |  -> Ignorar e Excluir(B)                            |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
	    printf("\t\t\t\t\t\t\t\t           |   |_____________________________________________________|   |\n");
	    printf("\t\t\t\t\t\t\t\t           |                                                             |\n");
	    printf("\t\t\t\t\t\t\t\t            \\___________________________________________________________/\n");
	    printf("\t\t\t\t\t\t\t\t                   \\_______________________________________________/\n");
	    printf("\t\t\t\t\t\t\t\t                      ___________________________________________\n");
	    printf("\t\t\t\t\t\t\t\t                   _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
	    printf("\t\t\t\t\t\t\t\t                _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t             _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t          _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
	    printf("\t\t\t\t\t\t\t\t      :-------------------------------------------------------------------------:\n");
	    printf("\t\t\t\t\t\t\t\t      `---._.-------------------------------------------------------------._.---'\n");
	    getch();
	    
	    int loop = 1;
	    do{
		    system("cls");
		    printf("\t\t\t\t\t\t\t\t             ___________________________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t            /                                                 		\\\n");
		    printf("\t\t\t\t\t\t\t\t           |    _____________________________________________________    |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  Bernardo desconfiou , pois ele não se lembrava de  |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  ter enviado seu currículo recentemente.            |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  Algo naquele e-mail misterioso o deixava com um    |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  pressentimento ruim.                               |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  No final da mensagem havia dois links:             |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  -> Aceitar e Saber Mais(A)                         |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |  -> Ignorar e Excluir(B)                            |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |         Qual das alternativas você escolhe?         |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
		    printf("\t\t\t\t\t\t\t\t           |   |_____________________________________________________|   |\n");
		    printf("\t\t\t\t\t\t\t\t           |                                                             |\n");
		    printf("\t\t\t\t\t\t\t\t            \\___________________________________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                   \\_______________________________________________/\n");
		    printf("\t\t\t\t\t\t\t\t                      ___________________________________________\n");
		    printf("\t\t\t\t\t\t\t\t                   _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
		    printf("\t\t\t\t\t\t\t\t                _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t             _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t          _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
		    printf("\t\t\t\t\t\t\t\t      :-------------------------------------------------------------------------:\n");
		    printf("\t\t\t\t\t\t\t\t      `---._.-------------------------------------------------------------._.---'\n");
		    
			char op = getche();
			op = tolower(op);
			system("cls");
			if(op == 'a'){
				system("cls");
			    printf("\t\t\t\t\t\t\t\t             ___________________________________________________________\n");
			    printf("\t\t\t\t\t\t\t\t            /                                                 		\\\n");
			    printf("\t\t\t\t\t\t\t\t           |    _____________________________________________________    |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       Após aceitar a oferta, Bernardo foi           |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       sequestrado por agentes de elite da           |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       idopter Labs e foi jogado em uma sala         |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       escura na sede secreta.                       |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |_____________________________________________________|   |\n");
			    printf("\t\t\t\t\t\t\t\t           |                                                             |\n");
			    printf("\t\t\t\t\t\t\t\t            \\___________________________________________________________/\n");
			    printf("\t\t\t\t\t\t\t\t                   \\_______________________________________________/\n");
			    printf("\t\t\t\t\t\t\t\t                      ___________________________________________\n");
			    printf("\t\t\t\t\t\t\t\t                   _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
			    printf("\t\t\t\t\t\t\t\t                _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t             _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t          _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t      :-------------------------------------------------------------------------:\n");
			    printf("\t\t\t\t\t\t\t\t      `---._.-------------------------------------------------------------._.---'\n");
			    getch();
			    system("cls");
				faseTutorial();
				loop = 0;
			}else if(op == 'b'){
				system("cls");
			    printf("\t\t\t\t\t\t\t\t             ___________________________________________________________\n");
			    printf("\t\t\t\t\t\t\t\t            /                                                 		\\\n");
			    printf("\t\t\t\t\t\t\t\t           |    _____________________________________________________    |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       Bernardo foi encontrado morto em seu          |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       apartamento com 22 facadas nas costas         |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |       e uma carta de suicídio.                      |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |                                                     |   |\n");
			    printf("\t\t\t\t\t\t\t\t           |   |_____________________________________________________|   |\n");
			    printf("\t\t\t\t\t\t\t\t           |                                                             |\n");
			    printf("\t\t\t\t\t\t\t\t            \\___________________________________________________________/\n");
			    printf("\t\t\t\t\t\t\t\t                   \\_______________________________________________/\n");
			    printf("\t\t\t\t\t\t\t\t                      ___________________________________________\n");
			    printf("\t\t\t\t\t\t\t\t                   _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_\n");
			    printf("\t\t\t\t\t\t\t\t                _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t             _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t          _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t       _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_\n");
			    printf("\t\t\t\t\t\t\t\t      :-------------------------------------------------------------------------:\n");
			    printf("\t\t\t\t\t\t\t\t      `---._.-------------------------------------------------------------._.---'\n");
				getch();
				mainmenu();
				loop = 0;
			}
		}while(loop == 1);
	}
	//Tela inicial
	int mainmenu(){
		w = 0;
		
	    do {
	    	system("cls");

		    printf("\t\t\t\t\t\t\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");
		    printf("\t\t\t\t\t\t\t¦       ¦¦¦       ¦¦¦¦      ¦¦¦        ¦¦        ¦¦        ¦¦¦      ¦¦¦¦¦¦¦¦¦        ¦¦¦      ¦¦¦        ¦\n");
		    printf("\t\t\t\t\t\t\t¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦\n");
		    printf("\t\t\t\t\t\t\t¦       ¦¦¦       ¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦      ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦      ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦\n");
		    printf("\t\t\t\t\t\t\t¦  ¦¦¦¦¦¦¦¦  ¦¦¦  ¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦\n");
		    printf("\t\t\t\t\t\t\t¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦      ¦¦¦¦      ¦¦¦        ¦¦¦¦¦  ¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦        ¦¦¦      ¦¦¦        ¦\n");
		    printf("\t\t\t\t\t\t\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");
   
		    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t   Esquadrão de Criptografia da IdopterLabs");
		    
			printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tA) JOGAR\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tB) INFORMAÇÕES\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tC) TROCAR O TEMA\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tD) SAIR\n");
	        
			input = getche();
			input = tolower(input);
	        system("cls");
	        int w = 1;
	        if (input == 'a') {
	        	do{
	        		system("cls");
	        		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  Deseja jogar o tutorial? S ou N");
	        		input = getche();
	        		input = tolower(input);
	        		if(input == 's'){
		        		system("cls");
		        		textoinicial();
					}else if(input == 'n'){
						system("cls");
						fase1();
					}else{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  Comando invalido. Digite conforme as opcoes oferecidas.\n");
						getch();
					}
				}while(w = 1);
	        	
	        	
	        }
			else if (input == 'b') {
				w = 1;
				while (w == 1) {
		 			printf("\n\n\n\t\t\t\t\t\t\t\t\t\tW: O jogador movimenta uma unidade para cima.\n\n\n\t\t\t\t\t\t\t\t\t\tA: O jogador movimenta uma unidade para esquerda.\n\n\n\t\t\t\t\t\t\t\t\t\tS: O jogador movimenta uma unidade para baixo.\n\n\n\t\t\t\t\t\t\t\t\t\tD: O jogador movimenta uma unidade para direita.\n\n\n\t\t\t\t\t\t\t\t\t\tI: O jogador interage com o objeto que esta em cima.");
	        		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t@ : Chave.\n\n\n\t\t\t\t\t\t\t\t\t\tD : Porta fechada.\n\n\n\t\t\t\t\t\t\t\t\t\t= : Porta aberta.\n\n\n\t\t\t\t\t\t\t\t\t\to : Bot?o que o player pode interagir.\n\n\n\t\t\t\t\t\t\t\t\t\t0 : Portal.");
	       	 		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t# : Espinho que mata o player ao encostrar nele, reiniciando a fase.\n\n\n\t\t\t\t\t\t\t\t\t\tX : Monstro que se move aleatoriamente pelo mapa.\n\n\n\t\t\t\t\t\t\t\t\t\te : Monstro que possui um comportamento contr?rio ao do jogador.\n\n\n\t\t\t\t\t\t\t\t\t\tV : Monstro que te segue.\n\n\n\n\n");
	       	 		printf("\t\t\t\t\t\t\t\t\t\t--Pressione qualquer tecla para voltar para o Menu--\n\n\t");
	       	 		getch();
	      	  		w = 0;
	      	  		system("cls");
				}
			}
			else if (input == 'c'){
				system("cls");
				w = 4;
				while(w == 4){
					printf("\n\t\t\t\t\t\t\t\t                  APERTE [E] PARA MODO ESCURO E [C] PARA MODO CLARO\n");
					input = getch();
					input = tolower(input);
				
					if (input == 'e'){//ESCURO
						system("color 02");
						printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t          --Tema definido para MODO ESCURO--\n\n");
					}
					else if (input == 'c'){//CLARO
						system("color F1");
						printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t          --Tema definido para MODO CLARO--\n\n");
					}else{
						printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  Comando invalido. Digite conforme as opcoes oferecidas.\n");
					}
					
					printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  --Pressione qualquer tecla para voltar para o Menu--");
					getch();
					w = 0;
					system("cls");
				}
			}
		
			else if (input == 'd') {
	        	system("cls");
	            w = 3;
	            if(w == 3){
	            	saida();
				}
				
			} else {
	        	system("cls");
	            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t  Comando invalido. Digite conforme as opcoes oferecidas.\n");
	            getch();
	        }
	    } while (w == 0);
	}
	
	
	int main(int argc, char *argv[]) {
		srand(time(NULL));
		
		setlocale(LC_ALL, "Portuguese");
		//system("color 2");
		system("color F1");
		
		//textoinicial();
		mainmenu();
		//faseTutorial();
		//gameover();
		//fase1();
		//fase2();
		//fase3();
		//morreu();
		//ending();
		
		//perguntaTutorial();
		//sextou();
		//dica21();
		//dica11();
	}
