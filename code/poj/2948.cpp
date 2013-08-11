#include <cstdio>
//#include <algorithm>
#define max(a,b) ((a) > (b) ? (a) : (b)) 

int n, m;
int y[505][505];
int b[505][505];
int r[505][505];

int dp( int i, int j )
{
  if (r[i][j] != -1)
		return r[i][j];
	if (i==0)
		r[i][j] = max(y[i][j], b[i][j]+dp(i, j-1));
	else if (j==0)
		r[i][j] = max(y[i][j]+dp(i-1, j), b[i][j]);
	else
		r[i][j] = max(y[i][j]+dp(i-1, j), b[i][j]+dp(i, j-1));
	return r[i][j];
}

int main ()
{

	while (scanf("%d%d", &n, &m), n!=0)
	{
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++){
				scanf("%d", &y[i][j]);
				if (j>0)
					y[i][j] += y[i][j-1];
			}
	
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++){
				scanf("%d", &b[i][j]);
				if (i>0)
					b[i][j] += b[i-1][j];
			}
	
		/*
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++)
				printf("%d ", y[i][j]);
			printf("\n");
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++)
				printf("%d ", b[i][j]);
			printf("\n");
		}
		*/
	
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				r[i][j] = -1;
		
		printf("%d\n", dp(n-1, m-1));
	}
	
	return 0;
	
}
