#include <stdio.h>
#include <time.h>
#define INF 999999

int main(){
    int n,coins[100],amt,dp[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&coins[i]);
    scanf("%d",&amt);

    clock_t s,e; double t;
    s = clock();
    for(int i=0;i<=amt;i++) dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=amt;j++){
            if(dp[j-coins[i]] + 1 < dp[j]) dp[j] = dp[j-coins[i]] + 1;
        }
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;
    if(dp[amt]==INF) printf("-1\n");
    else printf("%d\n",dp[amt]);
    printf("%f\n",t);
    return 0;
}
