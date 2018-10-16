	
/* Open, Read and close a file: reading string by string */
#include<string.h>
# include <stdio.h>
int main( ){

        FILE *fp;
        int frequency[128]={0};
        int i;
        printf( "Opening the file test.c in read mode\n" ) ;
        fp = fopen( "test.c", "r" ) ;
        if ( fp == NULL ){
                printf( "Could not open file test.c\n" ) ;
                return 1;
        }
        printf( "Reading the file test.c\n" ) ;
        int c;
        while((c = fgetc(fp))!=EOF){ 
                frequency[c]++;
        }   
        for(i=0;i<128;i++){
                if(frequency[i]!=0)
                printf("%c is %d times\n",i,frequency[i]);
        }
        printf("\nClosing the file test.c\n") ;
        fclose(fp) ;
        return 0;

}