#include<stdio.h>

void NaiveDP(int n, int a[],int L[],int prev[]);
void print(int a[],int L[],int prev[]);
int maxLength=0,maxIndex=0;
int main()
{
int n;
//printf("Enter the array size: ");
scanf("%d",&n);

int a[n+1],L[n+1],prev[n+1],i;

a[0]=0;
L[0]=0;
prev[0]=-1;

//printf("Enter the values: ");
for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
}
NaiveDP(n,a,L,prev);

printf("\nThe maximum length of the common subsequence is: %d",maxLength);
printf("\nThe sequence is: ");
print(a,L,prev);
}

void NaiveDP(int n, int a[],int L[],int prev[])
{
int i,j;

for(i=1;i<=n;i++){
    L[i]=0;
    for(j=0;j<i;j++){
        if(a[j]<=a[i] && L[j]+1>=L[i])  //a[j]<a[i] && L[j]+1>L[i]
        {
            L[i]=L[j]+1;
            prev[i]=j;
        }
    }
    if (L[i]>maxLength){
        maxLength=L[i];
        maxIndex=i;
    }
}
}



void print(int a[],int L[],int prev[]){
    int i,p[maxLength];
    for(i=1;i<=maxLength;i++){
        p[maxLength-i]=a[maxIndex];
        maxIndex=prev[maxIndex];
    }

    for(i=0;i<maxLength;i++){
        printf("%d ",p[i]);
    }
}
