#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

bool road[1001][1001];  /* matrix estradas a destruir */
int low[1001], dfs[1001]; /* guarda profundidades mais pequenas e profundidades */
bool visit[1001]; /* visitados */
int roads; /* num estradas */
vector<int> matrix[1001]; /* lista de nós adjacentes */

int solution = 0; /* var auxiliar para "No road" */

int n;

int tarjan(int k, int origin, int level){

	int i,size;
	
	visit[k] = true;

	dfs[k] = low[k] = level; /* coloca nivel actual */

	size = matrix[k].size(); /* numero de nós adjacentes */
	int u;

	for(i=0;i<size;i++){

		int v = matrix[k][i];

		if(visit[v] && v != origin){ /* Se está visitado e v não é pai */
	
			if (low[k] > dfs[v]){

				low[k] = dfs[v]; /* guarda profundidade minima */
			}			
		}	
		if(!visit[v]){ /* nó v não visitado */

			tarjan(v,k,level+1); /* tarjan a partir de v, com origem k, incrementa nivel de profundidade */

			if(low[k] > low[v]){	
				low[k] = low[v]; /* guarda profundidade minima */
			}

			if(low[v] > dfs[k]){

				roads++; /* incrementa estradas rebentadas */
				road[k][v] = road[v][k] = true; /* marca estrada a destruir */
				solution = 1; /* pelo menos, uma solucao encontrada */
			}
		}
	}

	return 0;
}

int main(){        
	int i,j,m,x,y;

	while(scanf("%d %d", &n, &m) != EOF){
        
		/* reset */
		for(i=0;i<n;i++) matrix[i].clear();
		memset(road, false, sizeof(road));
		memset(visit, false, sizeof(visit));

		roads = 0;
		solution = 0;
	
		/* input */
		for(i=0;i<m;i++){
			scanf("%d %d",&x, &y);
			matrix[x].push_back(y);
			matrix[y].push_back(x);
		}

		/* calculo */
		for(i=0;i<n;i++){
			if(!visit[i]) tarjan(i, 0, 0);
		}

		/* output */
		if (solution){
			for(i=0;i<n;i++){
		    		for(j=i+1;j<n;j++){
		        		if(road[i][j]) printf("%d %d\n", i, j); 
		    		} 
			}
		}

		else printf("No road\n");
		
    	}  
	
	return 0;
}

