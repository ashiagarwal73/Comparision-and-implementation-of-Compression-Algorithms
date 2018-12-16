#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define HEIGHT 100
int frequency[128]={0};
int temp[128];
int* ard[107];
int len;
typedef struct NODE Node;
struct NODE {
    char data;
    int freq;
    Node *left, *right;
};
typedef struct  {
    int size;
    int capacity;
    Node** array;
}MinHeap;

Node* newNode(char data, int freq)
{
    Node* temp= (Node*)malloc
(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}
void sort_huffman(int *frequency ,int *temp)
{
  int a,i,j;
  for (i = 0; i < 128; ++i) {
    if(!(frequency[i]>0.0))
      {
       continue;
      }
  for (j = i + 1; j < 128; ++j)
    {
      if (frequency[i] < frequency[j]) {
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
void file_read(char * filename)
{
      FILE *fp;
      int length=0;
      int i;
      fp = fopen( filename, "r" ) ;
      if ( fp == NULL ){
        printf( "Could not open file %s\n",filename ) ;

      }
      int c;
      while((c = fgetc(fp))!=EOF){
        frequency[c]++;
        length++;
      }
      for(i=0;i<128;i++)
      {
          temp[i]=i;
      }
      sort_huffman(frequency,temp);
      fclose(fp);
}
MinHeap* createMinHeap(int capacity)
{
MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array
        = (Node**)malloc(minHeap->
capacity * sizeof(Node*));
    return minHeap;
}
void swapNode(Node** a,Node** b)
{
Node* t = *a;
*a = *b;
*b = t;
}

void minHeapify(MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap)
{

    return (minHeap->size == 1);
}

Node* extractMin(MinHeap* minHeap)
{
Node *temp = minHeap->array[0];
    minHeap->array[0]= minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(MinHeap* minHeap,Node* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(MinHeap* minHeap)
{

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    ard[len]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    ard[len][i]=arr[i];
    len++;
}
int isLeaf(Node* root)
{
    return !(root->left) && !(root->right);
}
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
   int i;
   MinHeap* minHeap = createMinHeap(size);

    for ( i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
Node* buildHuffmanTree(char data[], int freq[], int size)
{
    Node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printCodes(Node* root, int arr[], int top)
{
int i=0;
int j=0;
    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printArr(arr, top);
    }
}
void HuffmanCodes(char data[], int freq[], int size)
{
    Node* root
        = buildHuffmanTree(data, freq, size);
    int arr[HEIGHT], top = 0;

    printCodes(root, arr, top);
}
double executeHuffman(char * filename)
{
  clock_t start,end;
double total_time;
start=clock();
len=0;
char c;
int i=0 ,j=0,k=0;
char arr[128];
int freq[128];
file_read(filename);
for(i=0;i<128;i++)
{
if(frequency[i]>0)
{
freq[k]=frequency[i];
arr[k]=(char)temp[i];
k++;
}
}
int size =k;
HuffmanCodes(arr, freq, size);
FILE *fp;
 FILE *fptr;
       if ((fptr = fopen("outputHuffman.txt","w")) == NULL){
           printf("Error! opening file");
           // Program exits if the file pointer returns NULL.
           return 0;
       }
      fp = fopen( filename, "r" ) ;
      if ( fp == NULL ){
        printf( "Could not open file %s\n" ,filename) ;
        return 1;
      }
      while((c = fgetc(fp))!=EOF){
      for ( i = 0; i <size; ++i)
        {
          if(arr[i]==c)
          {

          for(j=0;j<sizeof(ard[i])/sizeof(int);j++)
          {
          fprintf(fptr,"%d",ard[i][j]);
          }
        }
      }
      }
fclose(fp);
fclose(fptr);
end=clock();
total_time=(double)(end-start)/CLOCKS_PER_SEC;
return total_time;
}
