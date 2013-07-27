#include <stdio.h>
#include <string.h>

typedef struct{
	int x, y;
} Point;

int n;

int clock(Point aP, Point bP, Point cP){
	/*Cross Product */

	Point p1,p2; /*BA, BC*/

	/* A - B*/
	p1.x = aP.x - bP.x; 
	p1.y = aP.y - bP.y;

	/* C - B*/
	p2.x = cP.x - bP.x;
	p2.y = cP.y - bP.y;
		
	int cross = (p1.x * p2.y) - (p1.y * p2.x); /* BA.x * BC.y  - BC.x * BA.y */

	return cross;
}

int main(){
	int n, i,j, ears;

	while(scanf("%d",&n) != EOF){
		Point p[n];

		for(i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
	
		ears = 0;
	
		for (i=0;i<n;i++){ /* for each point */
			
 			/* Pick three consecutive points */
			Point p1 = p[i];
			Point p2 = p[(i+1) % n];		
			Point p3 = p[(i+2) % n];

			if (clock(p1, p2, p3) > 0){ /*if is valid triangle */

				for (j=0;j<n;j++){ /* for each point */

					if ((j!=i) && (j != (i+1)%n) && (j != (i+2)%n)){ /* exclude traiangle points */
						
						if (clock(p1, p2, p[j]) > 0 && clock(p2, p3,p[j]) > 0 && clock(p3, p1, p[j]) > 0) break;
					}
				}
				
				if (j == n) ears++;
			}
		}
	
		printf("%d\n", ears);
	}

	return 0;
}
