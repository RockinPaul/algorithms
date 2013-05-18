#include <stdlib.h>
#include <stdio.h>

int cmp(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(){

	
	int *start;
	int *end;

	int n,rooms,i,j;

	while(scanf("%d", &n) != EOF){

		start = malloc(sizeof(int)*(n+1));
		end = malloc(sizeof(int)*(n+1));

		for (i=0;i<n;i++) scanf("%d %d",&start[i],&end[i]);

		qsort(start, n, sizeof(int), cmp);
		qsort(end, n, sizeof(int), cmp);

		rooms = 0;
		j = 1;

		for(i=1;i<n;i++){
			if (start[i] < end[j]) rooms++;
			else j++;
		}
	
		printf("%d\n", rooms);
	}

	return 0;
}
