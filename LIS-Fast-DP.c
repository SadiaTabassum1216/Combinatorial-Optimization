#include<stdio.h>

int LISDP(int n, int a[],int L[],int prev[]);
void print(int a[],int index,int prev[]);
int Llength;
int main()
{
int n;
//printf("Enter the array size: ");
scanf("%d",&n);

int a[n+1],L[n+1],prev[n+1],i;

a[0]=0;
L[0]=-1000;
prev[0]=-1;

//printf("Enter the values: ");
for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
}

int index=LISDP(n,a,L,prev);

printf("\nThe maximum length of the common subsequence is: %d",Llength);

printf("\nThe sequence is: ");
print(a,index,prev);
}


int LISDP(int n, int a[],int L[],int prev[])
{
int L2[n],i,size=0,s,h,m;
L2[0]=-1;

for(i=1;i<=n;i++){
    if(L[size]<a[i]){
        L[size+1]=a[i]; //append
        size++;
        L2[size]=i;
        prev[i]=L2[size-1];
    }
    else{
        s=0;
        h=size;
        while(s<h){
            m=(s+h)/2;
 	       if(L[m]<a[i])
               s=m+1;
            else
                h=m;
            }
        L[s]=a[i];
        L2[s]=i;   //save index of a[i] in L’, so that we can use it for prev later
        prev[i]=L2[s-1];
    }
}

Llength=size;
return L2[size];
}
void print(int a[],int index,int prev[])
{
  int i,p[Llength];

  for(i=1;i<=Llength;i++){
  p[Llength-i]=a[index];
    index=prev[index];
  }

  for(i=0;i<Llength;i++)
    printf("%d ",p[i]);
}
