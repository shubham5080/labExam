#include <stdio.h>
#include <time.h>

int max(int a,int b){ if(a>b) return a; return b; }

int main(){
    int n,price[100],dp[100];
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&price[i]);

    clock_t s,e; double t;
    s = clock();
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=-999999;
        for(int j=1;j<=i;j++)
            dp[i]=max(dp[i],price[j]+dp[i-j]);
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",dp[n],t);
    return 0;
}
