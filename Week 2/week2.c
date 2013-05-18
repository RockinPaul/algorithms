#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <math.h> 

int r;
char** rocks;

int build(int n, int x, int y, int w, int h, int b){
	
	if(n == 0){
		if(b) rocks[(x/2)][(y/2)] = '1';
		else rocks[(x/2)][(y/2)] = '0';
	}
    
	else{

		if(r==0){/* r=0 */
			build(n-1, x, y, w/2, h/2, b);
			build(n-1, x + w, y,  w/2, h/2, b); 
			build(n-1, x, y + h, w/2, h/2, b); 
			build(n-1, x + w, y + h, w/2, h/2, !b);
		}else if(r==1){/* r=2 */
			build(n-1, x, y, w/2, h/2, b); 
			build(n-1, x + w, y + h, w/2, h/2, b);
			build(n-1, x + w, y,  w/2, h/2, b); 
			build(n-1, x, y + h, w/2, h/2, !b); 
		}else if(r==2){/* r=3 */
			build(n-1, x, y, w/2, h/2, !b); 
			build(n-1, x + w, y + h, w/2, h/2, b);
			build(n-1, x + w, y,  w/2, h/2, b); 
			build(n-1, x, y + h, w/2, h/2, b); 
		}else{/* r=4 */
			build(n-1, x, y, w/2, h/2, b); 
			build(n-1, x + w, y + h, w/2, h/2, b);
			build(n-1, x + w, y,  w/2, h/2, !b); 
			build(n-1, x, y + h, w/2, h/2, b); 
		}
	}

	return 0;
	
}

int main(){

	int n,i,max;	
	
	while(scanf("%d %d", &n, &r) != EOF){
			
		r = r%4;

		max = pow(2,n);

    		rocks = (char**)malloc(max*sizeof(char*));

		for(i=0;i<max;i++){
		        rocks[i] = (char*) malloc(max);
		}

		build(n, 0, 0, max, max,0);
	
		for(i=0;i<max;i++){
			fprintf(stdout,"%s\n", rocks[i]);
		}
		
	}

	return 0;

}
