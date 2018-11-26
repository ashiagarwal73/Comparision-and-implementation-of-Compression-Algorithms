#include "shanonfano.c"
#include "huffman.c"
#include "lz.c"
int main()
{
      char c;
      printf("Enter Input File Name with extension\n");
      char filename[20];
      scanf("%s",filename );
      double compressionRatioHuffman=0.0,compressionRatioShanonfano=0.0,compressionRatioLz=0.0;
      double compressionFactorHuffman=0.0,compressionFactorShanonfano=0.0,compressionFactorLz=0.0;
      double savingPercentageHuffman=0.0,savingPercentageShanonfano=0.0,savingPercentageLz=0.0;
      int lengthShannonfano=0,lengthHuffman=0,lengthInputFile=0;
      int sizeOfInputFile=0 ,sizeOfShanonfanoEcodedFile=0,sizeOfHuffmanEcodedFile=0,sizeOfLzEcodedFile=0;
      double timeTakenShanonfano=executeShanonfano(filename);
      double timeTakenHuffman =executeHuffman(filename);
      sizeOfLzEcodedFile=executeLZ(filename);
      double timeTakenLz=timecomplexity();
      FILE *inputFile = fopen( "input.txt", "r" ) ;
      if ( inputFile== NULL ){
        printf( "Could not open file input.txt\n" ) ;
        return 1;
      }
      while((c = fgetc(inputFile))!=EOF){
        lengthInputFile++;
      }
      sizeOfInputFile=(lengthInputFile-1)*8;
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
      compressionRatioLz=sizeOfLzEcodedFile/(float)sizeOfInputFile;
      compressionFactorHuffman=sizeOfInputFile/(float)sizeOfHuffmanEcodedFile;
      compressionFactorShanonfano=sizeOfInputFile/(float)sizeOfShanonfanoEcodedFile;
      compressionFactorLz=sizeOfInputFile/(float)sizeOfLzEcodedFile;
      savingPercentageHuffman=((sizeOfInputFile-sizeOfHuffmanEcodedFile)/(float)sizeOfInputFile)*100;
      savingPercentageShanonfano=((sizeOfInputFile-sizeOfShanonfanoEcodedFile)/(float)sizeOfInputFile)*100;
      savingPercentageLz=((sizeOfInputFile-sizeOfLzEcodedFile)/(float)sizeOfInputFile)*100;
      printf("time complexity huffman %lf\n",timeTakenHuffman );
      printf("time complexity shanonfano %lf\n",timeTakenShanonfano );
      printf("time complexity LZ %lf\n",timeTakenLz );
      printf("sizeOfInputFile %d\n",sizeOfInputFile );
      printf("sizeOfHuffmanEcodedFile %d\n",sizeOfHuffmanEcodedFile );
      printf("sizeOfShanonfanoEcodedFile %d\n",sizeOfShanonfanoEcodedFile );
      printf("sizeOfLzEcodedFile %d\n",sizeOfLzEcodedFile );
      printf("compressionRatioHuffman %lf\n",compressionRatioHuffman );
      printf("compressionRatioShanonfano %lf\n",compressionRatioShanonfano );
      printf("compressionRatioLz %lf\n",compressionRatioLz );
      printf("compressionFactorHuffman %lf\n",compressionFactorHuffman );
      printf("compressionFactorShanonfano %lf\n",compressionFactorShanonfano );
      printf("compressionFactorLz %lf\n",compressionFactorLz );
      printf("savingPercentageHuffman %lf\n",savingPercentageHuffman );
      printf("savingPercentageShanonfano %lf\n",savingPercentageShanonfano );
      printf("savingPercentageLz %lf\n",savingPercentageLz);

}
