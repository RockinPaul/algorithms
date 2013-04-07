#include <stdio.h>
#include <stdlib.h>

int total;

int unsocial(int n, int no_actual, int soma, int *cor, int **tabela)
{
	int i;
	int k = 0;

	if(n-no_actual+soma<total) return 0;
	
	if(n==no_actual){
		if(soma>total) total = soma;
		return 0;
	}

	for(i=0;i<n;i++){
		if(tabela[no_actual][i] != 0){
			if(cor[i] == -1){
				cor[no_actual] = 1;
				unsocial(n,no_actual+1,soma,cor,tabela);
				return 0;
			}

			else if(cor[i]==0) k++;
		}
	}
	
	cor[no_actual] = -1;

	unsocial(n,no_actual+1,soma+1,cor,tabela);
    
	if(k!=0){
		cor[no_actual] = 1;
		unsocial(n,no_actual+1,soma,cor,tabela);
	}

	cor[no_actual] = 0;
	
	return 0;

}

 


int main()
{

	int i,j,k,n,m;

	int *cor;
    	int **tabela;

	scanf("%d %d",&n,&m);

	if (m==0) printf("%d\n",n);
	
	else{
	
		tabela = (int**) malloc(sizeof(int)*n*n);
		for(i=0;i<n;i++) tabela[i] = (int*) malloc(sizeof(int)*n);
	
		cor = (int*) malloc(sizeof(int)*n);

		for (i=0;i<m;i++){
			scanf("%d %d",&j,&k);
			tabela[j][k] = 1;
			tabela[k][j] = 1;
		}

		total = 0;

		unsocial(n,0,0,cor,tabela);


		printf("%d\n",total);	
	}

	return 0;
}          

