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
int reverse(int n)
{
  int temp=n;
  int count=0;
  while(n>0)
  {
    n/=10;
    count++;
  }
  int arr[count];
  int k=0;
  while(temp>0&&k<count)
  {
    int d=temp%10;
    arr[k++]=d;
    temp/=10;
  }

}
void compress(FILE* input,FILE* output,int* codeword,int last,int *temp) {

  if(input == NULL || output==NULL) {
    printf("invalid input");
    return;
  }

  unsigned char inputChar;
  unsigned char outputChar=0x00; //binary 0000 0000
  int filled = 0;
  char x = 0x80; //binary 1000 0000

  while((inputChar = fgetc(input))!=EOF) {
    for (int i = 0; i <last; ++i)
        {
          if(inputChar == temp[i]) {
            int cw = codeword[i];
            //find reverse of a number
            cw=reverse(cw);
            if(cw == 0) {
              ++filled;
              x = x>>1; //right shitf by 1 (Eg - 1000 0000>>1 =  0100 0000)
            }
            while(cw>0) {
              int bit = cw%10;
              cw/=10;
              if(bit == 1) {
                outputChar = outputChar | x;
              }
              ++filled;
              x = x>>1;
              if(filled == 8) {
                //write to the output stream
                fprintf(output,"%c",outputChar);


              }
            }
          }
        }
  }
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
      compress(fp,fptr,codeword,last,temp);
      // while((c = fgetc(fp))!=EOF){ 
      //   for (int i = 0; i <last; ++i)
      //   {
      //     if(temp[i]==c)
      //     {
      //       fprintf(fptr,"%d",codeword[i]);
      //     }
      //   }
        
      // }

      fclose(fp);
      fclose(fptr);
      return 0;
}