#include <stdio.h>
#include <stdlib.h>

int total,n;
int ligacoes[36][36];

int verificar(int *nos){
	int i;	
	
	for(i=0;i<n;i++) if(nos[i] == 0) return 0;

	return 1;	
}

int *adicionar(int i, int *nos){
	int j;
	
	for(j=0;j<n;j++) nos[j] += ligacoes[i][j];

	return nos;
}

int *remover(int i, int *nos){
	int j;

	for(j=0;j<n;j++) nos[j] -= ligacoes[i][j];

	return nos;

}

int p2p(int x, int k, int *nos)
{
	int i;

	if(k+1 >= total) return 0;

	for (i=x; i<n; i++)
	{
		k++;

		nos = adicionar(i,nos);

		if(verificar(nos)){
			total = k;
			nos = remover(i,nos);
			return 0;
		}

		p2p(i+1,k,nos);
	
		k--;

		nos = remover(i,nos);
	
	}

	return 0;
}



int main()
{

	int a,b;
	int *nos;

	scanf("%d",&n);

	nos = (int*) malloc(sizeof(int)*n);

	while(scanf("%d %d", &a, &b) != EOF){
		ligacoes[a-1][b-1] = 1; ligacoes[a-1][a-1] = 1;
		ligacoes[b-1][a-1] = 1; ligacoes[b-1][b-1] = 1;
	}
	
	total = n;
	
	p2p(0,0,nos);

	printf("%d\n",total);

	return 0;
}          

