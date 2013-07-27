#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int colors[501];  
vector<int> matrix[501]; 
 
bool verifica(int k){  

	int v,i,size;

	size = matrix[k].size();

	for(i=0;i<size;i++){  

		v = matrix[k][i];  

		if(colors[v] == colors[k]) return false;
	
		if(!colors[v]){

			colors[v] = -colors[k];

            		if(!verifica(v)) return false;
		}  
	}  
	
	return true;

}

int main(){  

	int n,m,i;

	while(scanf("%d %d",&n,&m)!=EOF){  
		  
		int x,y;  
		memset(colors,0,sizeof(colors));  
        
		for(i = 0;i<=n;i++) matrix[i].clear();

		for(i = 0;i<m;i++){  
			scanf("%d %d",&x,&y);
			matrix[x].push_back(y);
			matrix[y].push_back(x); 
		}  

		colors[1] = 1;

		if(verifica(1)) printf("NOT SURE\n");  
		else  printf("NO\n");
	}
	
	return 0;  

} 
