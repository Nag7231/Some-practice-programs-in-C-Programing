#include <stdio.h>
#include <stdlib.h>
void towerOfHanoi(int n,int source,int aux,int dest){
    if(n==1){
        printf("the disk moves from tower no: %d to tower no :%d\n",source,dest);
        return;
    }
    towerOfHanoi(n-1,source,dest,aux);
    towerOfHanoi(1,source,aux,dest);
    towerOfHanoi(n-1,aux,source,dest);
}
int main()
{
    towerOfHanoi(3,1,2,3);
    return 0;
}
