#include <stdio.h>
#include <time.h>

int main() {
    int n,a[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t s,e; double t;
    s = clock();
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%f\n",t);
    return 0;
}
