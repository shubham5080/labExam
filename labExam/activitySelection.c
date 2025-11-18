#include <stdio.h>
#include <time.h>

int main(){
    int n,s[100],f[100],i,j,c=1;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&s[i]);
    for(i=0;i<n;i++) scanf("%d",&f[i]);

    clock_t st,en; double t;
    st = clock();
    int last=0;
    for(i=1;i<n;i++){
        if(s[i] >= f[last]){
            c++;
            last=i;
        }
    }
    en = clock(); t = (double)(en-st)/CLOCKS_PER_SEC;
    printf("%d\n%f\n",c,t);
    return 0;
}
