#include<stdio.h>

int coinChange(int coins[],int n,int w);
int minimumCoin(int coins[],int n,int w);

int min(int a,int b)
{
    return (a<b)? a:b;
}

int main()
{
int w,n;
//printf("Enter total amount: ");
scanf("%d",&w);

//printf("Enter number of coins:");
scanf("%d",&n);

int coins[n],i,ans,ans2;

//printf("Enter the value of coins: ");
for(i=0;i<n;i++)
    scanf("%d",&coins[i]);

ans=coinChange(coins,n,w);
ans2=minimumCoin(coins,n,w);

printf("\n%d can be formed in %d ways.",w,ans);
printf("\nMinimum number of coins: %d\n",ans2);
}

int coinChange(int coins[],int n,int w)
{
    int i,j,m[n+1][w+1];

    for(i=0;i<=n;i++)
        m[i][0]=1;

    for(i=0;i<=w;i++)
        m[0][i]=0;

    for(i=1;i<=n;i++){           //i=number of rows
        for(j=1;j<=w;j++){      //j=number of columns
            if(coins[i-1]>j)
                m[i][j]=m[i-1][j];

            else
                m[i][j]=m[i-1][j]+m[i][j-coins[i-1]];
        }
    }


return m[n][w];
}


int minimumCoin(int coins[],int n,int w)
{
    int i,j,m[n+1][w+1];

    for(i=0;i<=n;i++)
        m[i][0]=0;

    for(i=0;i<=w;i++)
        m[0][i]=100000;

    for(i=1;i<=n;i++){           //i=number of rows
        for(j=1;j<=w;j++){      //j=number of columns
            if(coins[i-1]>j)
                m[i][j]=m[i-1][j];

            else
                m[i][j]=min((m[i-1][j]),(1+m[i][j-coins[i-1]]));
        }
    }

//printf("\n*****%d*****",m[n][w]);

return m[n][w];
}
