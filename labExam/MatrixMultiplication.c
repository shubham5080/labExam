#include <stdio.h>
#include <time.h>
#define INF 999999

int min(int a,int b){
    if(a<b) return a;
    return b;
}

int main(){
    int n,p[100],dp[100][100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i]);

    clock_t s,e; double t;
    s = clock();
    for(int i=1;i<n;i++) dp[i][i]=0;
    for(int len=2;len<n;len++){
        for(int i=1;i<n-len+1;i++){
            int j=i+len-1;
            dp[i][j]=INF;
            for(int k=i;k<j;k++){
                int cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                dp[i][j] = min(dp[i][j],cost);
            }
        }
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",dp[1][n-1],t);
    return 0;
}
