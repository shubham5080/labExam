#include <stdio.h>
#include <time.h>

int main(){
    int a[2][2],b[2][2],c[2][2];
    int p1,p2,p3,p4,p5,p6,p7;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&b[i][j]);

    clock_t s,e; double t;
    s = clock();
    p1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    p2 = (a[1][0] + a[1][1]) * b[0][0];
    p3 = a[0][0] * (b[0][1] - b[1][1]);
    p4 = a[1][1] * (b[1][0] - b[0][0]);
    p5 = (a[0][0] + a[0][1]) * b[1][1];
    p6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    p7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = p1 + p4 - p5 + p7;
    c[0][1] = p3 + p5;
    c[1][0] = p2 + p4;
    c[1][1] = p1 + p3 - p2 + p6;

    e = clock(); t = (double)(e-s)/CLOCKS_PER_SEC;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
    printf("%f\n",t);
    return 0;
}
