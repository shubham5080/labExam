#include <stdio.h>
#include <time.h>

int main(){
    int n,W,w[100],v[100],dp[100][100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    scanf("%d",&W);

    clock_t s,e; double t;
    s = clock();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(w[i-1] <= j){
                int a = v[i-1] + dp[i-1][j-w[i-1]];
                int b = dp[i-1][j];
                dp[i][j] = (a>b)?a:b;
            } else dp[i][j] = dp[i-1][j];
        }
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",dp[n][W],t);
    return 0;
}
