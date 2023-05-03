
#include <limits.h>
#include <stdio.h>
int x=1;
void disp(int i,int j,int n,int b[n][n]){
	if(i==j){
		printf("A%d",x);
		x++;
		return;
	}
	printf("(");
	disp(i,b[i][j],n,b);
	disp(b[i][j]+1,j,n,b);
	printf(")");
}

int MChain(int a[], int n)
{
	int m[n][n],p[n][n];
    int i, j, k, L, q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j]=0;
			p[i][j]=0;
        }
    }

	for (L = 2; L < n; L++) {
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
				if (q < m[i][j]){
					m[i][j]=q;
					p[i][j]=k;
				}
					
			}
		}
	}

	//return m[1][n - 1];
	disp(1,n-1,n,p);
}

// Driver code
int main()
{
	int arr[] = {40, 20, 30, 10, 30};
	int size = sizeof(arr) / sizeof(arr[0]);
	MChain(arr,size);
	//printf("%d",MChain(arr, size));
	return 0;
}
