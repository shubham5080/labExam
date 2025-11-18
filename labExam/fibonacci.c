#include <stdio.h>
#include <time.h>

int main(){
    int n,f[100];
    scanf("%d",&n);
    clock_t s,e; double t;
    s = clock();
    f[0]=0; f[1]=1;
    for(int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",f[n],t);
    return 0;
}
