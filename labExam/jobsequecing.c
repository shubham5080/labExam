#include <stdio.h>
#include <time.h>

int main(){
    int n,i,j,d[100],p[100],mx=0,slot[100],ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&d[i]);
    for(i=0;i<n;i++) scanf("%d",&p[i]);

    for(i=0;i<n;i++) if(d[i]>mx) mx=d[i];
    for(i=0;i<=mx;i++) slot[i]=-1;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j] < p[j+1]){
                int t1=p[j]; p[j]=p[j+1]; p[j+1]=t1;
                int t2=d[j]; d[j]=d[j+1]; d[j+1]=t2;
            }
        }
    }

    clock_t st,en; double t;
    st = clock();
    for(i=0;i<n;i++){
        for(j=d[i];j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                ans += p[i];
                break;
            }
        }
    }
    en = clock(); t = (double)(en-st)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",ans,t);
    return 0;
}
