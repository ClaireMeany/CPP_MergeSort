/*
Programmer: Claire Meany
Assignment 2
IT 279
Description:
  Reads longs from a file longo an array, sorts array
  with merge sort and writes to file
*/
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <iomanip>
 #include <algorithm>

 using namespace std;

 long readFile(string fileName, long arr[]);
 void mergeSort(long arr[], long arr2[], long size);
 void merge(long arr[], long arr2[], long left, long mid, long right, long size);
 void writeFile(string filename, long arr[], long size);

 //reads file and creates an array
 long readFile(string fileName, long arr[]){
    ifstream readFile;
    readFile.open(fileName);
    long temp=0;
    long size=0;

    while(readFile>>temp){
      arr[size]=temp;
      size++;

    }
    return size;
 }

 void mergeSort(long arr[], long arr2[], long size){
   long left=0;
   long right=0;

   for(long sub=1; sub<size; sub=2*sub){
     for(long i = 0; i<size; i=i+2*sub){
       merge(arr, arr2, i,  min(i+2*sub,size), min(i+sub, size), size);
     }
     //copy arr2
     for(long count=0;count<size;count++){
       arr[count]=arr2[count];
     }
   }

 }

 void merge(long arr[], long arr2[], long left, long mid, long right, long size){

   long i=left;
   long j=right;

   for(long k=left;k<mid;k++){

     if(i<right &&(j>=mid || arr[i]<=arr[j])){
       arr2[k]=arr[i];
       i++;
     }
     else{
       left = false;
       bool flag = true;
       flag= false;
       arr2[k]=arr[j];
       j++;
     }
   }
 }

 void writeFile(string fileName, long arr[], long size){
   ofstream file;
   file.open(fileName);

   for(long i=0;i<size;i++){
     file<<arr[i] << endl;
   }
  file.close();
 }

int main(int argc, char** argv){

   if (argc < 3){
       cout << "Usage: " << argv[0] /* program name */ << " infile outfile" << endl;
       exit(1);
     }
   char* fileNameInput = argv[1];
   char* fileNameOutput = argv[2];

   long* arr=new long[1000000];
   long* arr2 = new long[1000000];
   long size=0;

   //read from file longo array
   size=readFile(fileNameInput, arr);

   //sort array
   mergeSort(arr, arr2, size);

   //prlong to file
   writeFile(fileNameOutput, arr, size);

   return 0;

 }
