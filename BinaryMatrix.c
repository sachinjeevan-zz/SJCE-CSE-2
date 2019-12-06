#include<stdio.h>
int min(int a,int b,int c){
    if(a<b && a<c){
        return a;
    }
    else if(b<a && b<c){
        return b;
    }
    else{
        return c;
    }
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(i==0 || j==0){
                dp[i][j]=arr[i][j];
            }
            else{
                if(arr[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
}