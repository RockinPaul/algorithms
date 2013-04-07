#include <stdio.h>
#include <stdlib.h>

int tumor(int **tabela,int m, int n){

	int i,j,k,cand;
	int max = 0, min = 0;
	int *s;

	s = (int*) malloc(sizeof(int)*(n+1));

	for (k=1;k<=m;k++){
		for (i=k;i<=m;i++){
			min = 0;
			for (j=1;j<=n;j++){
				s[j] = tabela[i][j] - tabela[k-1][j];
				cand = s[j] - min;
				if (cand>max) max = cand;
				if (s[j]<min) min = s[j];
			}
		}
	}

	return max;
}

int main()
{  
        int m,n,i,j;
	int **tabela;

	while(scanf("%d %d",&m,&n) != EOF){

		if (m > n){
			tabela = (int**) malloc(sizeof(int)*(n));

			for(i=0;i<=n;i++) tabela[i] = (int*) malloc(sizeof(int)*(m+1));

			for(i=1;i<=m;i++){
				for(j=1;j<=n;j++){
					scanf("%d",&tabela[j][i]);
					tabela[j][i] += tabela[j][i-1] + tabela[j-1][i] - tabela[j-1][i-1];
				}
			}

			printf("%d\n",tumor(tabela,n,m));
		}

		else {
			tabela = (int**) malloc(sizeof(int)*(m));

			for(i=0;i<=m;i++) tabela[i] = (int*) malloc(sizeof(int)*(n+1));

			for(i=1;i<=m;i++){
				for(j=1;j<=n;j++){
					scanf("%d",&tabela[i][j]);
					tabela[i][j] += tabela[i][j-1] + tabela[i-1][j] - tabela[i-1][j-1];
				}
			}

			printf("%d\n",tumor(tabela, m,n));
		}

	
	}
		
	return 0;
}


