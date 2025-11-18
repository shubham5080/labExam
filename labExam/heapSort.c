#include <stdio.h>
#include <time.h>

int heapify(int a[], int n, int i){
    int l = 2*i+1, r = 2*i+2, max=i;
    if(l<n && a[l] > a[max]) max=l;
    if(r<n && a[r] > a[max]) max=r;
    if(max!=i){
        int t=a[i]; a[i]=a[max]; a[max]=t;
        heapify(a,n,max);
    }
}

int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t s,e; double t;
    s = clock();
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        int p=a[0]; a[0]=a[i]; a[i]=p;
        heapify(a,i,0);
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%f\n",t);
    return 0;
}
