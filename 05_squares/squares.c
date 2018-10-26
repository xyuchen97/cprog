#include <stdio.h>
#include <stdlib.h>

void squares ( int size1, int x_offset, int y_offset, int size2){
  int w= size1>(x_offset +size2)?size1:(x_offset+ size2);
  int h= size1>(y_offset+ size2)?size1:(y_offset+size2);
  for (int y=0; y < h; y++){
    for (int x=0; x< w; x++){
      if(((x_offset <= x && x< x_offset + size2) && (y==y_offset || y == y_offset + size2 -1)) || ((y_offset <= y && y < y_offset + size2)
	  &&(x == x_offset || x== x_offset + size2 -1)))
	{   printf("*");}
    else if
      ((x < size1 && (y==0 || y== size1 - 1)) || (y< size1 && (x== 0 || x==size1 -1)))
    {
	  printf("#");}
      else{ printf(" ");}
    }
      printf("\n");}}
      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline
     
   
