#include <stdlib.h>
#include <stdio.h>

int busca(int *city,int m,int n){
	int i;

	for(i=0;i<m;i++) if (city[i] == m-1) return i;
	return -1;
}

int main(){

	int m,n,i,out,s,d;
	int *city;

	while(scanf("%d %d",&m,&n) != EOF){
		city = malloc(sizeof(int)*(m+1));
		
		for (i=0;i<n;i++){
			scanf("%d %d",&s,&d);
			city[d]++;
			city[s]--;
		}

		out = busca(city,m,n);

		if (out != -1) printf("%d\n", out);
		else printf("nix\n");

	}

	return 0;
}
