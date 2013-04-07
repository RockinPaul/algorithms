/* http://www.ugrad.cs.ubc.ca/~cs490/sec202/notes/flow/Flow%20Intro.pdf*/

#include <stdio.h>
#include <stdlib.h>

#define INF 999999999


int capacity[402][402];
int seen[402];

int maxDancasIndividual;
int MaxDancasPar;
int pares;
int Htotal;
int Mtotal;

int find_minimum(int a, int b) {

	if (a > b) return b;
	return a;
}

int find_augmenting_path(int cur, int curflow) {

	int i;
	if (cur == Htotal + Mtotal + 1) return curflow;
    	
	seen[cur] = 1;

	for (i = 0; i <= Htotal + Mtotal + 1; ++i) {
		if (seen[i] == 0 && capacity[cur][i] != 0) {
			/*find how much flow we can push through in augmenting path*/
			int amt = find_minimum(curflow, capacity[cur][i]);

			/*recursively try to find the augmenting path*/
			int flow = find_augmenting_path(i, amt);

			if (flow > 0) { /*found augmenting path*/
				capacity[cur][i] -= flow;
				capacity[i][cur] += flow;

				return flow;
			}
        	}
	}

	return 0;
}

int main(int argc, char** argv) {
	int i,j, max_flow, flow;
	int homem, mulher;

	while (scanf("%d %d %d", &pares, &Htotal, &Mtotal) != EOF) {

		/* input */
		scanf("%d %d", &maxDancasIndividual, &MaxDancasPar);

		max_flow = 0;

 
		for (i=0; i<402; i++) {
			for (j=0; j<402; j++) {
			    capacity[i][j] = 0;
			}
		}	
		
		for (i = 1; i <= Htotal; i++) {
			capacity[0][i] = maxDancasIndividual;
		}

     
		for (i = Htotal + 1; i < Htotal + Mtotal + 1; i++) {
			capacity[i][Htotal + Mtotal + 1] = maxDancasIndividual;
		}

     
		for (i = 0; i < pares; i++) {
			scanf("%d %d", &homem, &mulher);
			capacity[homem][Htotal + mulher] = MaxDancasPar;
		}

		do {
			for(i=0;i<402;i++) seen[i] = 0;
			flow = find_augmenting_path(0, INF);
			max_flow += flow;
		} while (flow > 0);

		printf("%d\n", max_flow);
	}

	return 0;
   
}
