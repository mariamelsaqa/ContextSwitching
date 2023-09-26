#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int calculateSum (int start, int jump ){
    int sum = 0;
    for (int i=start; i<=(start-1+jump); i++) {
        sum += i;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    clock_t startTime = clock();
    int NPROC, T;
    if(argc <= 2){
        printf("enter NPROC and T");
        exit(0);
    }
    NPROC = atoi(argv[1]);
    T = atoi(argv[2]);

    if(NPROC > T){
        printf("Error! NPROC is greater that T");
        exit(0);
    }
    int x = T/NPROC;
    
     int* shared = mmap(NULL, NPROC*sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
    int sum = 0;
    
    for(int i = 0; i < NPROC; i++)
    {
        int lowerBound = i*x+1;
        if(i==NPROC-1){
            x+=(T%NPROC);
        }
        
        if(fork() == 0){
            int innerSum = calculateSum(lowerBound,x);
             shared[i] = innerSum;
               
            exit(0);
        }
    }
    while(wait(NULL)!= -1)
    {}
   printf("\n");
    for(int c = 0;  c< NPROC; c++)
    {
    sum = sum + shared[c];
    }
    printf("Sum = %d\n",sum);
    clock_t endTime = clock();
    double ExecTime = (double) (endTime- startTime) / CLOCKS_PER_SEC;
    printf("Execution Time = %lf seconds\n", ExecTime);
    return 0;
}
