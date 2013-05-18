#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int z;

int maze(int maxlevel, int x, int y, int **tabela, int **solution){
	
	int symbol;

	symbol = tabela[x][y];

	/*
	if (symbol == 4){ printf("|\n");}
	if (symbol == 7){ printf("/\n");}	
	if (symbol == 2){ printf("\\\n");}	
	*/

	if (symbol == 5){ return 0;}	
	
	if (x == maxlevel){ z++;solution[z][0] = x; solution[z][1] = y;return 1;}

	tabela[x][y] = 5;

	if (symbol == 4){
		if (tabela[x+1][y-1] == 7){
			if (maze(maxlevel,x+1,y-1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}		
		if (tabela[x+1][y] == 4){
			if (maze(maxlevel,x+1,y,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		if (tabela[x+1][y+1] == 2){
			if (maze(maxlevel,x+1,y+1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
	}
				
	else if (symbol == 2){ /* direita */
		if (tabela[x+1][y+1] == 4){
			if (maze(maxlevel,x+1,y+1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}		
		if (tabela[x+1][y+1] == 2){
			if (maze(maxlevel,x+1,y+1,tabela,solution)){ 
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		if (tabela[x+1][y] == 7){
			if (maze(maxlevel,x+1,y,tabela,solution)){ 
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		/* SAME LINE */
		
		if (tabela[x][y+1] == 7){
			if (maze(maxlevel,x,y+1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
	
		if (tabela[x][y-1] == 7){
			if (maze(maxlevel,x,y-1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		
		
	}
		
	else if (symbol == 7){ /* esquerda */
		if (tabela[x+1][y-1] == 7){
			if (maze(maxlevel,x+1,y-1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		if (tabela[x+1][y-1] == 4){ 
			
			if (maze(maxlevel,x+1,y-1,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		if (tabela[x+1][y] == 2){
			if (maze(maxlevel,x+1,y,tabela,solution)){
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}
		/* SAME LINE */
		
		if (tabela[x][y-1] == 2){
			if (maze(maxlevel,x,y-1,tabela,solution)){ 
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}

		if (tabela[x][y+1] == 2){
			if (maze(maxlevel,x,y+1,tabela,solution)){ 
				z++;
				solution[z][0] = x; solution[z][1] = y;
				return 1;
			}
		}

	}
		
	tabela[x][y] = 5;
	
	return 0;

}

int main (int argc, const char * argv[])
{
	int m,n,i,j;
	   	
	

	while(scanf("%d %d",&m,&n) != EOF){
		char *s1;
		int **tabela;
		int **solution;
	

		tabela = (int**) malloc(m*sizeof(int*));
		for (i = 0; i < m; i++) {
			tabela[i] = (int*)malloc((n+3)*sizeof(int));
		}

		solution = (int**) malloc(m*n*sizeof(int*));
		for (i = 0; i < m*n; i++) {
			solution[i] = (int*)malloc(4*sizeof(int));
		}

		
		
		z=0;

		for(i=0;i<m;i++){
			tabela[i][0] = 5;
			tabela[i][n+2] = 5;
		}

		for(i=0;i<m;i++){
			s1 = malloc(sizeof(char)*(n+2));
			scanf("%s",s1);
			for(j=1;j<n+1;j++){
				tabela[i][j] = (int)s1[j-1]%10;
			}			
		}

		int found;
	
		for(i=1;i<n+1;i++){
			found = maze(m-1,0,i,tabela,solution);
			if (found==1) break;
		}
		
		
		
		if (found == 1){
			for (i=z;i>1;i--)
				printf("(%d,%d),",solution[i][0]+1,solution[i][1]);
			printf("(%d,%d)",solution[1][0]+1,solution[1][1]);
			printf("\n");
		}else{
			printf("No Path!\n");
		}
    	}

    	return 0;
}

