#include<stdio.h>
#include"gol.h"
#include"gol.c"

int main(int argc, char *argv[]){
  struct universe u;
  struct universe v;

  //u's struct pointer points to the universe v
  u.structpointer = &v;

  FILE infile;

  /*
  int numGenerations = 5;

  for(int i=1; i<argc;i++){
    if(i>argc){
      break;
    }
    printf("\nloop number=%d\n",i);
    char firstItem = argv[i][0]; // first char of parameter
    char n = argv[i][1]; // second char of parameter

    if(firstItem == '-' && strlen(argv[i]) == 2){ // check parameter starts with - and is length 2
      printf("this starts with -\n");
      printf("lengthofparam=%d \n",strlen(argv[i]));
      switch(n); //passes the second char i.e -t pass t
    } else {
      printf("Unrecognized parameters.");
      exit(1);
    }

    switch (n) {
      int arg;
      case 'i': // code to be executed if n = 1;
        //char filename[]= argv[i+1] //-i filename.txt -o

        //if filename[]
        i++;
        break;

      case 'o': // code to be executed if n = 2;
        i++;

        break;
      case 'g': // code to be executed if n = 2;
        //arg = *argv[i+1];
        //printf("%d",arg);
        //numGenerations = (int)*argv[i+1];
        //make sure argv[i+1] is a number
        i++;
        break;
      case 's':
        //use statistics
        break;
      case 't':

        break;
      default: // code to be executed if n doesn't match any cases
        printf("%s","This is not a valid command.");
        exit(1);
    }
  }
  */
  read_in_file(&infile, &u);

  /*evolve(&u,will_be_alive);
  evolve(&u,will_be_alive);
  evolve(&u,will_be_alive);
  evolve(&u,will_be_alive);
  evolve(&u,will_be_alive); */

  /*char arr3[u.rows];

  for (int i=0;i<u.rows*u.cols;i++){
    arr3[i] = (char )malloc(u.rows*u.cols*sizeof(char));
  }

  for (int i=0; i<u.rows*u.cols; i++){
		for (int j=0; j<u.cols; j++){
      int position = i*u.cols + j;
			arr3[position] = u.unipointer[i][j];
      putc(arr3[i],stdout);
      
		}
	}
  
  u.array1d = arr3; */

  FILE *outfile;
  
  outfile = fopen("test.txt","w+");
  write_out_file(outfile,&u);
  

 /*

  for(int j=0; j<numGenerations;j++){ // will evolve numGenerations # of times
    evolve(&v,will_be_alive);
  } */

  return 0;
}
