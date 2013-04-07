#include <stdio.h>
#include <stdlib.h>

int points[1002][2];

int max(int a, int b){
	if (a<b) return b;
	else return a;
}

int min(int a, int b){
	if (a>b) return b;
	else return a;
}

int cmpX(const void *va, const void *vb)
{
	const int *pa = *(const int (*)[0])va;
	const int *pb = *(const int (*)[0])vb;
	int i;
    
	for (i = 0; i <= 1; i++) {
		if (pa[i] != pb[i])
			return (pa[i] > pb[i]) ? 1 : -1;
	}    
	
	return 0;
}

int cmpY(const void *va, const void *vb)
{
	const int *pa = *(const int (*)[0])va;
	const int *pb = *(const int (*)[0])vb;
	int i;
    
	for (i = 1; i >= 0; i--) {
		if (pa[i] != pb[i])
			return (pa[i] > pb[i]) ? 1 : -1;
	}    
	
	return 0;
}

int buildmypool(int n, int w, int h){

	int i,j,ylow,ytop,xright,xleft;

	int area = 0;

	qsort(points, n, 2*sizeof(int), cmpX);

	for(i=0;i<n;i++){
		ylow = 0;
		ytop = h;
		for (j=i+1;j<n;j++){
			if (points[i][0] != points[j][0]){
				area = max(area,(points[j][0]-points[i][0])*(ytop-ylow));
				if (points[j][1] < points[i][1]) ylow = max(ylow, points[j][1]);
				else ytop = min(ytop, points[j][1]);	
			}
		}
	}

	qsort(points, n, 2*sizeof(int), cmpY);
	
	for(i=0;i<n;i++){
		xleft = 0;
		xright = w;
		for(j=i+1;j<n;j++){
			if (points[j][1] != points[i][1]){
				area = max(area,(points[j][1]-points[i][1])*(xright-xleft));
				if (points[j][0] < points[i][0]) xleft = max(xleft, points[j][0]);
				else xright = min(xright, points[j][0]);
			}		
		}
	}

	return area;
}




int main(){
	int i,n,w,h,x1,y1,x2,y2,p1,p2; 
	
	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF){
		
		w = x2-x1;
		h = y2-y1;

		scanf("%d", &n);

		points[0][0] = 0;
		points[0][1] = 0;

		for(i = 1; i <= n; i++){
			scanf("%d %d", &p1, &p2);
			points[i][0] = p1-x1;
			points[i][1] = p2-y1;
		}

		points[n+1][0] = w;
		points[n+1][1] = h;

		printf("%d\n",buildmypool(n+2, w, h));
	}

	return 0;
}
