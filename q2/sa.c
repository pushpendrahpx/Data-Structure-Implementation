#include <stdio.h>
int main(){
    int a[5]={1,2,4,7,10};
    int num = 9;
    int count = 0;
    for(int i = 0; i < 5;i++){
        if(a[i] > num){
            count = i;
        }
    }
    printf("%d",count);
}