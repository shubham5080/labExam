#include <stdio.h>
#include <time.h>

int main() {
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t s,e; double t;
    s = clock();
    for(int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j] < a[min])
                min=j;
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%f\n",t);
    return 0;
}
