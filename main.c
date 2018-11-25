#include "shanonfano.c"
#include "huffman.c"
int main()
{
  char c;
      double timeTakenShanonfano=executeShanonfano();
      double timeTakenHuffman =executeHuffman();
      int lengthShannonfano=0,lengthHuffman=0,lengthInputFile=0;
      int sizeOfInputFile=0 ,sizeOfShanonfanoEcodedFile=0,sizeOfHuffmanEcodedFile=0;
      FILE *inputFile = fopen( "test.c", "r" ) ;
      if ( inputFile== NULL ){
        printf( "Could not open file test.c\n" ) ;
        return 1;
      }
      while((c = fgetc(inputFile))!=EOF){
        lengthInputFile++;
      }
      sizeOfInputFile=lengthInputFile*8;
      FILE *outputShanonfano = fopen( "outputShanonfano.txt", "r" ) ;
      if ( outputShanonfano== NULL ){
        printf( "Could not open file test.c\n" ) ;
        return 1;
      }
      while((c = fgetc(outputShanonfano))!=EOF){
        lengthShannonfano++;
      }
      sizeOfShanonfanoEcodedFile=lengthShannonfano*1;
     FILE *outputHuffman = fopen( "outputHuffman.txt", "r" ) ;
      if ( outputHuffman== NULL ){
        printf( "Could not open file test.c\n" ) ;
        return 1;
      }
      while((c = fgetc(outputHuffman))!=EOF){
        lengthHuffman++;
      }
      sizeOfHuffmanEcodedFile=lengthHuffman*1;
      printf("time huffman %lf\n",timeTakenHuffman );
      printf("time shanonfano %lf\n",timeTakenShanonfano );
      printf("sizeOfHuffmanEcodedFile%d\n",sizeOfHuffmanEcodedFile );
      printf("sizeOfShanonfanoEcodedFile%d\n",sizeOfShanonfanoEcodedFile );
      printf("sizeOfInputFile%d\n",sizeOfInputFile );
}
