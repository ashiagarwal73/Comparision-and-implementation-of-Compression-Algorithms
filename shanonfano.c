#include<string.h>
#include<stdio.h>
int codeword[128]={0};
void sort(int *frequency ,int *temp)
{
  int a,i,j;
  for (i = 0; i < 128; ++i) {
    for (j = i + 1; j < 128; ++j)
    {
      if (frequency[i] < frequency[j]) 
      {
        a =  frequency[i];
        frequency[i] = frequency[j];
        frequency[j] = a;  
        a=temp[i];
        temp[i]=temp[j];
        temp[j]=a;      
      }
    }
  }
}
void shannonfano(int initial,int final,int code,float *probability,int *character)
{
  if(initial==final)
  {
    
    codeword[initial]=code;
    return ;
  }
  int first=initial;
  int last=final;
  float sumFront=probability[first];
  float sumLast=probability[last];
  while(first!=last)
  {
    if(sumFront>=sumLast)
    {
      last--;
      sumLast=sumLast+probability[last];
    }
    else{
      first++;
      sumFront=sumFront+probability[first];
    }
  }
  code=code*10;
  shannonfano(initial,first,code+0,probability,character);
  shannonfano(first+1,final,code+1,probability,character);

}
int main(){
      FILE *fp;
      int length=0;
      int frequency[128]={0};
      int i;
      int temp[128];
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
        length++;
      }  
      for(i=0;i<128;i++)
      {
          temp[i]=i;
      }
      sort(frequency,temp);
      float probab[128]={0.0};
      int last=0;
      for(i=0;i<128;i++)
      {
          if(frequency[i]==0)
          {
            last=i;
            break;
          } 
          probab[i]=frequency[i]/(float)length;      
      }
      shannonfano(0,last-1,0,probab,temp);
      for (int i = 0; i < last; ++i)
      {
        printf("code=%d for character=%c\n",codeword[i],temp[i] );
      }
      fclose(fp);
      printf("\nClosing the file test.c\n") ;
      //starting to write in binary file
      FILE *fptr;
       if ((fptr = fopen("output.txt","w")) == NULL){
           printf("Error! opening file");
           // Program exits if the file pointer returns NULL.
           return 0;
       }
      fp = fopen( "test.c", "r" ) ;
      if ( fp == NULL ){
        printf( "Could not open file test.c\n" ) ;
        return 1;
      }
      printf( "Reading the file test.c\n" ) ;
      while((c = fgetc(fp))!=EOF){ 
        for (int i = 0; i <last; ++i)
        {
          if(temp[i]==c)
          {
            fprintf(fptr,"%d",codeword[i]);
          }
        }
        
      }
      fclose(fp);
      fclose(fptr);
      return 0;
}