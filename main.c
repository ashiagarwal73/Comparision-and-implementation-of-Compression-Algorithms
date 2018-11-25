#include "shanonfano.c"
#include "huffman.c"
int main()
{
      char c;
      double timeTakenShanonfano=executeShanonfano();
      double timeTakenHuffman =executeHuffman();
      double compressionRatioHuffman=0.0,compressionRatioShanonfano=0.0;
      double compressionFactorHuffman=0.0,compressionFactorShanonfano=0.0;
      double savingPercentageHuffman=0.0,savingPercentageShanonfano=0.0;
      int lengthShannonfano=0,lengthHuffman=0,lengthInputFile=0;
      int sizeOfInputFile=0 ,sizeOfShanonfanoEcodedFile=0,sizeOfHuffmanEcodedFile=0;
      FILE *inputFile = fopen( "input.txt", "r" ) ;
      if ( inputFile== NULL ){
        printf( "Could not open file input.txt\n" ) ;
        return 1;
      }
      while((c = fgetc(inputFile))!=EOF){
        lengthInputFile++;
      }
      sizeOfInputFile=lengthInputFile*8;
      FILE *outputShanonfano = fopen( "outputShanonfano.txt", "r" ) ;
      if ( outputShanonfano== NULL ){
        printf( "Could not open file input.txt\n" ) ;
        return 1;
      }
      while((c = fgetc(outputShanonfano))!=EOF){
        lengthShannonfano++;
      }
      sizeOfShanonfanoEcodedFile=lengthShannonfano*1;
     FILE *outputHuffman = fopen( "outputHuffman.txt", "r" ) ;
      if ( outputHuffman== NULL ){
        printf( "Could not open file input.txt\n" ) ;
        return 1;
      }
      while((c = fgetc(outputHuffman))!=EOF){
        lengthHuffman++;
      }
      sizeOfHuffmanEcodedFile=lengthHuffman*1;
      compressionRatioHuffman=sizeOfHuffmanEcodedFile/(float)sizeOfInputFile;
      compressionRatioShanonfano=sizeOfShanonfanoEcodedFile/(float)sizeOfInputFile;
      compressionFactorHuffman=sizeOfInputFile/(float)sizeOfHuffmanEcodedFile;
      compressionFactorShanonfano=sizeOfInputFile/(float)sizeOfShanonfanoEcodedFile;
      savingPercentageHuffman=((sizeOfInputFile-sizeOfHuffmanEcodedFile)/(float)sizeOfInputFile)*100;
      savingPercentageShanonfano=((sizeOfInputFile-sizeOfShanonfanoEcodedFile)/(float)sizeOfInputFile)*100;
      printf("time complexity huffman %lf\n",timeTakenHuffman );
      printf("time complexity shanonfano %lf\n",timeTakenShanonfano );
      printf("sizeOfInputFile %d\n",sizeOfInputFile );
      printf("sizeOfHuffmanEcodedFile %d\n",sizeOfHuffmanEcodedFile );
      printf("sizeOfShanonfanoEcodedFile %d\n",sizeOfShanonfanoEcodedFile );
      printf("compressionRatioHuffman %lf\n",compressionRatioHuffman );
      printf("compressionRatioShanonfano %lf\n",compressionRatioShanonfano );
      printf("compressionFactorHuffman %lf\n",compressionFactorHuffman );
      printf("compressionFactorShanonfano %lf\n",compressionFactorShanonfano );
      printf("savingPercentageHuffman %lf\n",savingPercentageHuffman );
      printf("savingPercentageShanonfano %lf\n",savingPercentageShanonfano );
}
