#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int pos, begin, end; /* posicao, inicio e fim do segmento */
	int block; /* start/end block */ 
} Line;

Line ly[2*32769];
Line lx[2*32769];
int xs[2*32769];

int n = 0;

int cmp(int *a, int *b){
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int area(Line *line){
	int block,i,j,ys;
	int height=0, a=0;
	
	printf("Vou calcular a área!\n");

	for(i=0;i<2*n;i++){ /* for each vertical line l */
		
		printf("\tSegmento %d!\n",i);		
		
		if(i){
			printf("\t\tActualiza área: %d = %d x %d\n",a,height,xs[i]-xs[i-1]);	
			 a += height*(xs[i]-xs[i-1]); /* actualiza area: altura x (diferenca entre posicao x actual e a anterior)*/
		}		
		height = block = 0;
		
		for(j=0;j<2*n;j++){ 
			printf("\t\tA verificar segmento %d(%d,%d)!\n",j,line[j].begin,line[j].end);
			if(line[j].begin <= xs[i] && line[j].end > xs[i]){ 	/* calcula altura */
				printf("\t\t\t begin(%d) <= xs[%d] e end(%d)> xs[%d]!\n",line[j].begin,xs[i],line[j].end,xs[i]);
				if(!block){ 
					printf("\t\t\t\tBloco = 0!\n");
					ys = line[j].pos;
					printf("\t\t\t\tys = %d!\n",line[j].pos);
				}			/* inicio de bloco/guarda valor de x */
					
				printf("\t\t\t Actualiza Bloco = %d + %d\n",block,line[j].block);			
				block += line[j].block;				/* incrementa se x, decrementa se X*/
				
				if(!block){ 
					printf("\t\t\t\theight = %d + %d\n",height,line[j].pos-ys);
					height += line[j].pos-ys; 		/* fim de bloco/guarda valor de X*/
				}
			}
		}
	}
	
	return a;
}

int perimetro(Line *line){

	int i,j,p=0;
	int repeat[32769];

	memset(repeat,0,sizeof(repeat));

	for (i=0;i<2*n;i++){ /* por cada segmento */

		for(j=line[i].begin; j<line[i].end;j++){ /* ponto valido do segmento */

			if (line[i].block==1){		 /* inicio de bloco */
				repeat[j]++;		 
				if (repeat[j]==1) p++; 	/* valido, sobreposto seria 2 */

			}

			else{				/* fim de bloco(tambem pode ser valido) */
				repeat[j]--;
				if (repeat[j]==0) p++; /* valido */
			}
		}
	}

	return p;
}

int main(){
	
  	int x,y,X,Y;

	while(scanf("%d %d %d %d", &x, &y, &X, &Y) != EOF){

		/* Vertical Lines */
		lx[2*n].begin = lx[2*n+1].begin = x; 
		lx[2*n].end = lx[2*n+1].end = X;

		lx[2*n].pos = y;
		lx[2*n+1].pos = Y;

		lx[2*n].block = 1;
		lx[2*n+1].block = -1;

		/* Horizontal Lines */
		ly[2*n].begin = ly[2*n+1].begin = xs[2*n] = y;
		ly[2*n].end = ly[2*n+1].end = xs[2*n+1] = Y;

		ly[2*n].pos = x; 
		ly[2*n+1].pos = X;
		
		ly[2*n].block = 1; 
		ly[2*n+1].block = -1;

		n++;
	}
	int i;
	for(i=0;i<2*n;i++) printf("%d ",xs[i]);

	qsort(lx, 2*n, sizeof(lx[0]), (void *)cmp);
	qsort(ly, 2*n, sizeof(ly[0]), (void *)cmp);
	qsort(xs, 2*n, sizeof(xs[0]), (void *)cmp);
	
	
	printf("\n");
	printf("%d %d\n",area(ly),perimetro(ly)+perimetro(lx));
	return 0;
}
