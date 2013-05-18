#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
		
	int n,m,i,j,k;
	
	int **dp;
	int wv[301][16][2];
	int d[301];

	/* input */

	while(scanf("%d %d",&n,&m)!=EOF){

		dp = (int**) malloc(sizeof(int)*(n+1));
		
		for(i=0;i<=n;i++) dp[i] = (int*) malloc(sizeof(int)*(m+1));

		for(j=1;j<=n;j++){
			scanf("%d",&d[j]);
			for(i=1;i<=d[j];i++) scanf("%d %d",&wv[j][i][0],&wv[j][i][1]);
		}
	}

	int x = 0;

	/* DP */
	for(i=1;i<=n;i++){ /* 1 to #departaments */
		for(j=0;j<=m;j++){ /* 0 to max_ects */
			dp[i][j] = dp[i-1][j];
			for(k=1;k<=d[i];k++){ /* 1 to department i */
				if(wv[i][k][0] <= j){
					x = dp[i-1][j-wv[i][k][0]] + wv[i][k][1];
					if (dp[i][j] < x) dp[i][j] = x;
				}
			}
		}
	}

	printf("%d\n",dp[n][m]);

  	return 0;
}
 
