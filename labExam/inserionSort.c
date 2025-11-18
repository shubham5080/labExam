#include <stdio.h>
#include <time.h>

int main() {
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t s,e; double t;
    s = clock();
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j] > key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%f\n",t);
    return 0;
}
