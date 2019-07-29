#include <stdio.h>
#include <stdlib.h>
void sequences(int , int , int *, int , int );
void nonIncreasing(int );
int main()
{
    nonIncreasing(4);
    return 0;
}
void nonIncreasing(int n){
    int *res;
    res = (int*)malloc(n*sizeof(int));
    if(res==NULL){
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    sequences(n,0,res,0,n);
    free(res);
}
void sequences(int n, int used, int *res, int level, int box){
    int i,j,k;
    int flag=0;
    printf("used: %d\n",used);
    ///termination condition
printf("1. BRGINING\n");
    if(level==box){
printf("2. TERMINATION CONDITION level: %d box: %d\n",level, box);
        if(used==n){
printf("3. CHECK THE ORDER used: %d, n: %d\n",used, n);
            if(box!=1){ /// check whether it decreasing order or not
                for(i=0;i<used-1;i++){
                    if(res[i]<res[i+1])
                        flag=1;
                }
            }else{
                printf("=================RESULT: {%d }===================",res[0]);
                exit(1);
            }
            if(flag==0){
printf("4. Decreasing => print\n");
                    printf("=================RESULT: {");/// print the result
                        for(i=0;i<box;i++){
                            printf("%d ", res[i]);
                        }
                    printf("}===================\n\n");
                    if(box==1)
                        exit(1);
                return;
            }else{
printf("4. NON decreasing => return\n");
                flag=0;
                return;
            }
                return;
        }
            return;
    }
printf("6. NON TERMINATION\n");
    for(j=0;j<n;j++){
        res[level]=1+j;
        printf("j: %d res[%d]: %d\n",j, level, res[level]);
        used=0;
        for(k=0;k<level+1;k++){
            used=used+res[k];
            printf("res[%d]: %d\n",k, res[k]);
        }
        printf("used: %d\n",used);

        if(used>n){
            printf("RETURN used: %d \n",used);
            return;
        }
printf("7. BEFORE RECURSION\n used: %d, level : %d, box: %d\n",used, level+1,box);
        sequences(n, used, res, level+1, box);
        used=used-res[level];
        printf("New used: %d\n",used);
printf("8. AFTER RECURTION\n used: %d, level :%d, box: %d\n",used, level,box);
    }
printf("9. BEFORE RECURSION\n used: %d, level :%d, box: %d\n",used, level+1,box-1);
        sequences(n, used, res, level, box-1);
        used=used-res[level];
printf("10. AFTER RECURTION\n used: %d, level :%d, box: %d\n",used, level,box);
}
