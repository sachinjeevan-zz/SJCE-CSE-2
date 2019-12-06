#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a=2,b=8;
    int c=4*b+a;
    printf("%d %d ",a,b);
    while(c<=n){
        printf("%d ",c);
        a=b;
        b=c;
        c=4*b+a;
    }
}