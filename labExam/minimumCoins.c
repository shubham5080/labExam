#include <stdio.h>
#include <time.h>

int main(){
    int n,i,amt,a[100],c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&amt);

    for(i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] < a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
        }
    }

    clock_t st,en; double t;
    st = clock();
    for(i=0;i<n;i++){
        if(amt==0) break;
        if(a[i] <= amt){
            c += amt / a[i];
            amt = amt % a[i];
        }
    }
    en = clock(); t = (double)(en-st)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",c,t);
    return 0;
}
