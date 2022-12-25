#include<stdio.h>
#include<math.h>
#define MAX INFINITY

int MCM(int p[],int i,int j);

long long int m[100][100];
int main()
{
int n;
//printf("Enter number of matrices: ");
scanf("%d",&n);

int p[n+1],i,j;

for(i=0;i<=n;i++)
    scanf("%d",&p[i]);

for(i=1;i<=n;i++){
    for(j=i;j<=n;j++){
        m[i][j]=-1;
    }
}

int result= MCM(p,1,n);

printf("Cost: %d",result);

}

int MCM(int p[],int i,int j)
{
    int k,q;

    if (m[i][j]!=-1)
  	 return m[i][j];

    if (i>=j)
        m[i][j]=0;

    else {
        m[i][j]=MAX;
        for(k=i;k<j;k++){
                q=MCM(p,i,k)+MCM(p,k+1,j)+p[i-1]*p[k]*p[j];
                if (q<m[i][j])
                    m[i][j]=q;
  			 }
    }
return m[i][j];
}
