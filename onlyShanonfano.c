#include<string.h>
#include<stdio.h>
float probability[6]={0.30,0.25,0.15,0.12,0.10,0.08};
char character[6]={'a','c','s','b','m','n'};
int shannonfano(int initial,int final,int code)
{
  if(initial==final)
  {
    printf("code=%d for character=%c\n",code,character[initial] );
    return code;
  }
  int first=initial;
  int last=final;
  float sumFront=probability[first];
  float sumLast=probability[last];
  while(first!=last)
  {
    if(sumFront>sumLast)
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
  shannonfano(initial,first,code+0);
  shannonfano(first+1,final,code+1);

}
int main(){
      shannonfano(0,5,0);
      return 0;
}
