#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
    char a[100],b[100];
    scanf("%s",a);
    scanf("%s",b);
    int n=strlen(a),m=strlen(b);
    int dp[101][101];

    clock_t s,e; double t;
    s = clock();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else {
                int x=dp[i-1][j],y=dp[i][j-1];
                dp[i][j] = (x>y)?x:y;
            }
        }
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",dp[n][m],t);
    return 0;
}
