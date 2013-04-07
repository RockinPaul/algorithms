#include <stdlib.h>
#include <stdio.h>

/*
	Bibliografia
	Needleman-Wunsch Algorithm
	http://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm
*/

char *strrev(char *s,int n)
{
	/* funcao para inverter palavras */	
	
	int i=0;

	while (i<n/2)
	{
		*(s+n) = *(s+i);
		*(s+i) = *(s + n - i -1);
		*(s+n-i-1) = *(s+n);
		i++;
	}

	*(s+n) = '\0';

	return s;
}

int estica(char* s1, int l1, char* s2, int l2){

	int i,j,k;
	int **tabela;
	char *ss1,*ss2;
	int tmp;

	/* inicializa tabela */
	tabela = malloc(sizeof(int *) * (l1+1));
	for (i = 0; i <= l1; i++) tabela[i] = malloc(sizeof(int) * (l2+1));

	for (i = 1; i <= l1; i++)  tabela[i][0] = i * -1;
	for (i = 1; i <= l2; i++)  tabela[0][i] = i * -1;

	/*preenche tabela dp*/
	for (i = 1; i <= l1; i++)
	{			
		for (j = 1; j <= l2; j++)
		{
			if (s1[i] == s2[j]) tabela[i][j] = tabela[i-1][j-1] + 1;
			else tabela[i][j] = tabela[i-1][j-1] - 1;

			tmp = tabela[i-1][j] - 1;
			if (tmp > tabela[i][j]) tabela[i][j] = tmp;

			tmp = tabela[i][j-1] - 1;
			if (tmp > tabela[i][j]) tabela[i][j] = tmp;
      		}
	}

	
	/* constroi palavras p/output */
	ss1 = malloc(sizeof(char) * (l1+l2+1));
	ss2 = malloc(sizeof(char) * (l1+l2+1));

	i = l1;
	j = l2;
	k = 0;

	while (i > 0 || j > 0)
	{
		/* caso 1 -> s1[i] com s2[j] (match) */
		if (i > 0 && j > 0) 
		{
			tmp = tabela[i-1][j-1];

			if (s1[i] == s2[j]) tmp++;
			else tmp--;

			if (tabela[i][j] == tmp) {
				ss1[k] = s1[i]; 
				ss2[k] = s2[j]; 
				k++;
				i--;
				j--;
			} 
		}

		/* caso 2 -> s1[i] com '-' */
		if (i > 0)
		{
			if (tabela[i][j] == tabela[i-1][j] - 1) {
				ss1[k] = s1[i]; 
				ss2[k] = '-';
				k++;
				i--;
			}
		}

		/* caso 3 -> s2[j] com '-' */
		if (j > 0) 
		{
			if (tabela[i][j] == tabela[i][j-1] - 1) { 
				ss1[k] = '-'; 
				ss2[k] = s2[j]; 
				k++;
				j--;
			}
		}
	}
	
	/* output */
	printf("%s\n", strrev(ss1, k));
	printf("%s\n", strrev(ss2, k));
	printf("%d\n", tabela[l1][l2]);

	return 0;

}

int main()
{
	int l1,l2;
	char *s1,*s2;	

	/* input */
	while(scanf("%d", &l1) != EOF){

		s1 = malloc(sizeof(char) * (l1+1));
		scanf("%s",s1+1);

		scanf("%d",&l2);
		s2 = malloc(sizeof(char) * (l2+1));
		scanf("%s",s2+1);

		estica(s1,l1,s2,l2);
	}

	return 0;
}

