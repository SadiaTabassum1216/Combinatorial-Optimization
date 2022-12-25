#include<stdio.h>
#include<math.h>

void CutRod(int p[],int n,int r[],int s[]);
void print(int p[],int n,int r[],int s[]);

int main()
{
    FILE *fp;
    int n,i;

//**********This part will be used to read from file********************

/*if((fp=freopen("rodCutting-Input.txt","r",stdin))==NULL){
    printf("cannot open file.\n");
    exit(1);
}*/

   // printf("Enter number of rod: ");
    scanf("%d",&n);
    int price[n],r[n+1],s[n+1];

   // printf("Enter the price:");
    for(i=0;i<n;i++){
        scanf("%d",&price[i]);
    }

//fclose(fp);       //********use this too to read input from file********

    print(price,n,r,s);

}

void CutRod(int p[],int n,int r[],int s[])
{
    int i,j,q;
    r[0]=0;

 for(j=1;j<=n;j++)
 {
    q=-INFINITY;

    for(i=1;i<=j;i++)
       {
          if(q<(p[i-1]+r[j-i])){
            q=p[i-1]+r[j-i];
            s[j]=i;
            }
       }

    r[j]=q;
 }

    printf("\nMax profit: %d\n",r[n]);
}

void print(int p[],int n,int r[],int s[])
{
    CutRod(p,n,r,s);
    printf("Optimal cutting lengths of a rod of length %d is: ",n);

    while(n>0)
    {
        printf("%d   ",s[n]);
        n=n-s[n];
    }
}
