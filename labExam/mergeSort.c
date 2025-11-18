#include <stdio.h>
#include <time.h>

int merge(int a[], int l, int m, int r){
    int x = m-l+1, y = r-m;
    int L[100], R[100];
    for(int i=0;i<x;i++) L[i]=a[l+i];
    for(int j=0;j<y;j++) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<x && j<y){
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i<x) a[k++] = L[i++];
    while(j<y) a[k++] = R[j++];
}

int mergeSort(int a[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t s,e; double t;
    s = clock();
    mergeSort(a,0,n-1);
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%f\n",t);
    return 0;
}
