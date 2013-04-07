#include <stdlib.h>
#include <stdio.h>

int cmp(const void *va, const void *vb)
{
	const int *pa = *(const int (*)[2])va;
	const int *pb = *(const int (*)[2])vb;
	int i;

	for (i=1;i>=0;i--) if (pa[i] != pb[i]) return (pa[i] > pb[i]) ? 1 : -1;
	 
	return 0;
}


int disp(int *room, int s, int st, int k){
	
	int i;

	for(i=st;i<=k;i++)if (s >= room[i]) return i;
		
	return -1;
}

int main(){

	int n,i,tmp;
	int k;
	int *room;

	while(scanf("%d", &n) != EOF){
		
		int jobs[n][4];
		
		room = malloc(sizeof(int)*(n+1));

		for (i=0;i<n;i++){
			scanf("%d %d",&jobs[i][1],&jobs[i][0]);
			jobs[i][2] = i+1;
		}
		
		/* Ordenar pelo tempo inicial. */
		qsort(jobs, n, 4*sizeof(int), cmp);
				
		/* Inicio actividade. */
		k=0;
		room[k] = jobs[0][0];
		jobs[0][3] = 1;
		
		for (i=1;i<n;i++){
			
			if (jobs[i][1] == jobs[i-1][1]) tmp = disp(room,jobs[i][1],jobs[i-1][3],k);
			else tmp = disp(room,jobs[i][1],0,k);
			
			/* Existe sala disponivel? */
			
			/* Sim. */
			if (tmp+1){
				jobs[i][3] = tmp;
				room[tmp] = jobs[i][0];
			}

			/* Nao. */
			else {
				k++;
				jobs[i][3] = k;
				room[k] = jobs[i][0];
			}
			
		}

		/* output */
		fprintf(stdout,"%d %d\n",jobs[0][2],1);
		for (i=1;i<n;i++){
			fprintf(stdout,"%d %d\n",jobs[i][2],jobs[i][3]+1);
		}
		fprintf(stdout,"%d\n",k+1);

	}

	return 0;

}
