#include <stdio.h>
#include <time.h>

int main(){
    int n,i,j,W,w[100],v[100];
    float ratio[100],ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&w[i]);
    for(i=0;i<n;i++) scanf("%d",&v[i]);
    scanf("%d",&W);

    for(i=0;i<n;i++) ratio[i]=(float)v[i]/w[i];
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ratio[j] < ratio[j+1]){
                float t1=ratio[j]; ratio[j]=ratio[j+1]; ratio[j+1]=t1;
                int t2=v[j]; v[j]=v[j+1]; v[j+1]=t2;
                int t3=w[j]; w[j]=w[j+1]; w[j+1]=t3;
            }
        }
    }

    clock_t st,en; double t;
    st = clock();
    for(i=0;i<n;i++){
        if(W==0) break;
        if(w[i] <= W){
            ans += v[i];
            W -= w[i];
        } else {
            ans += ratio[i] * W;
            W = 0;
        }
    }
    en = clock(); t = (double)(en-st)/CLOCKS_PER_SEC;
    printf("%.2f\n%f\n",ans,t);
    return 0;
}
