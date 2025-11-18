#include <stdio.h>
#include <time.h>

int partition(int a[], int low, int high){
    int p=a[high], i=low-1;
    for(int j=low;j<high;j++){
        if(a[j] < p){
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[i+1]; a[i+1]=a[high]; a[high]=t;
    return i+1;
}

int quickSort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main(){
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t s,e; double t;
    s = clock();
    quickSort(a,0,n-1);
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%f\n",t);
    return 0;
}
