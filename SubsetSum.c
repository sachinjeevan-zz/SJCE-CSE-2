#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int dp[n][k+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<k+1;j++){
            if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                if(j==arr[i]){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=0;
                }
            }
            else{
                if(arr[i]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k+1;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    int i=n-1;
    int j=k;
    while(i!=0 && j!=0){
        if(dp[i-1][j]==1){
            i--;
        }
        else{
            printf("%d ",arr[i]);
            j=j-arr[i];
            i--;
        }
    }
    if(j!=0){
        printf("%d ",arr[0]);
    }
}