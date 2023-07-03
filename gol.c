#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void read_in_file(FILE *infile,struct universe *u) {
	infile = fopen( "glider.txt", "r" );

	if (infile == NULL )//check if the file is NULL
		printf("Empty file\n");


	//used to print out the file
	char firstline[512];
	char oneline2[512];

	//used to get a line from the file to get the colnum
	fscanf(infile,"%s",oneline2);

	//count the number of rows by incrementing a variable within the while loop

	int characters=0;
	int colnum;
	int rownum;
	int i;
	int j;
	//int pointerpos = 0;

	//The column number is the number of all characters in a line
	colnum = strlen(oneline2);

	//while loop iterates till EOF
	while( fscanf(infile,"%c",firstline ) != EOF )
    {
    	characters = characters+1;
    }

    //calculate the row number by dividing it by the number of
    rownum = characters/colnum;

	// pointer to the universe values
	u->cols = colnum;
	u->rows = rownum;

    //create a list of pointers in the memory and dynamically allocate space for the universe

    char *arr[rownum];
	char *arr2[rownum];

    for (i=0;i<rownum;i++){
    	arr[i] =  (char *)malloc(colnum*sizeof(char));
		arr2[i] = (char *)malloc(colnum*sizeof(char));
    }

    char singleline[colnum];
    //char singlechar [colnum];

    //set the pointer back to the beginning
	fseek(infile,0L,SEEK_SET);

    //enter all the data in to the memory locations
    for (i=0; i<rownum; i++){
    	fscanf(infile,"%s",singleline);
    	for (j=0;j<colnum;j++){
    		arr[i][j]=singleline[j];
			arr2[i][j]=singleline[j];
    	}
    }

    u->unipointer = arr;
	u->structpointer->unipointer = arr2; // u's points to v, and set v's array to the arr
	
}

int is_alive(struct universe *u, int column, int row){
	//column and row are used in order to get the location of the cell
	if(row >= u->rows || row < 0){
		printf("No such row exists");
		exit(1);
	} else if (column >= u->cols || column < 0){
		printf("No such column exists");
		exit(1);
	}

	if (u->unipointer[row][column] == '.'){
		return 0;

	}
	else if (u->unipointer[row][column] == '*') {
		return 1;

	}
	return -1;
}

int will_be_alive(struct universe *u, int column, int row){
	// row number, col number
	int isAlive = is_alive(u,column, row); // 1 is alive (*)

	int validate(int in_row, int in_col){
		if(in_row < 0 || in_col < 0 || in_row >= u->rows || in_col >= u->cols){
			return 0;
		} else {
			return is_alive(u, in_col, in_row);
		}
		return -1;
	}

	int left = validate(row, column-1);
	int right = validate(row, column+1);
	int up = validate(row-1, column);
	int bottom = validate(row+1, column);
	int topleft = validate(row-1,column-1);
	int bottomleft = validate(row+1,column-1);
	int topright = validate(row-1,column+1);
	int bottomright = validate(row+1,column+1);
	int total = left + right + up + bottom + topleft + bottomleft + topright + bottomright;

	if(isAlive == 1){ // if alive
		if(total == 2 || total == 3){
			return 1;
		} else {
			return 0;
		}
 	} else if (isAlive == 0){ // if dead
		if(total == 3){
			return 1;
		} else {
			return 0;
		}
	}
	printf("how are you here?%d",isAlive);
	return -1;
}

int will_be_alive_torus(struct universe *u,  int column, int row){
	int isAlive = is_alive(u,row,column); // 1 is alive (*)
	int noAlive;

	int mod(int a, int b)
	{
		int r = a % b;
		return r < 0 ? r + b : r;
	}
	//topleft, top, topright, right, bottomright, bottom, bottomleft, left -> i.e. clockwise from topleft
	noAlive = is_alive(u,mod(column-1,u->cols),mod(row-1,u->rows)) + is_alive(u,mod(column,u->cols),mod(row-1,u->rows)) + is_alive(u,mod(column+1,u->cols),mod(row-1,u->rows)) +
	is_alive(u,mod(column+1,u->cols),mod(row,u->rows)) + is_alive(u,mod(column+1,u->cols),mod(row+1,u->rows)) + is_alive(u,mod(column,u->cols),mod(row+1,u->rows)) +
	is_alive(u,mod(column-1,u->cols),mod(row+1,u->rows)) + is_alive(u,mod(column-1,u->cols),mod(row,u->rows));


	if(isAlive == 1){ // if alive
		if(noAlive == 2 || 3){
			printf("%d",1);
			return 1;
		} else {
			return 0;
		}
 	} else if (isAlive == 0){ // if dead
		if(noAlive == 3){
			printf("%d",1);
			return 1;
		} else {
			printf("%d",0);
			return 0;
		}
	}
	return -1;
}

void evolve(struct universe *u, int (*rule)(struct universe *u, int column, int row)){
	printf("STARTED EVOLVE FUNCTION\n");
	//v's grid before doing anything
	printf("EVOLVE, V's before updating anything\n");

	for (int i=0; i<u->rows; i++){
		for (int j=0; j<u->cols; j++){
			printf("%c",u->structpointer->unipointer[i][j]);
		}
		printf("\n");
	}

	printf("%d",will_be_alive(u,3,6));
	printf("%d",will_be_alive(u,3,6));

	//update v's grid with the will_be_alive results
	for (int i=0; i<u->rows; i++){
		for (int j=0; j<u->cols; j++){

			//check whether the cell will 0 or 1 in the next gen
			int element = will_be_alive(u,j,i);
			
			//assign the new values to the grid that is stored in universe v
			//printf("(%d,%d):%d\n",i,j,element);
			if (element == 0){
				u->structpointer->unipointer[i][j] = '.';

			}
			else if (element == 1) {
				u->structpointer->unipointer[i][j] = '*';
			}
		}
	}

	//reassign the V's new grid as U's normal grid after all 'evolving' is done
	for (int i=0; i<u->rows; i++){
		for (int j=0; j<u->cols; j++){
			u->unipointer[i][j] = u->structpointer->unipointer[i][j];
		}
	}


	
	printf("EVOLVE, V's array updating\n");

	//print v's grid after assigning 
	for (int i=0; i<u->rows; i++){
		for (int j=0; j<u->cols; j++){
			printf("%c",u->structpointer->unipointer[i][j]);
		}
		printf("\n");
	}

	printf("EVOLVE, U's array after copy back\n");

	//print v's grid after assigning 
	for (int i=0; i<u->rows; i++){
		for (int j=0; j<u->cols; j++){
			printf("%c",u->unipointer[i][j]);
		}
	}

	printf("ENDING EVOLVE FUNCTION\n");
	
}

void print_statistics(struct universe *u){
	printf("%s","print some statistics");
}


void write_out_file(FILE *outfile, struct universe *u){	

	printf(u->unipointer[0][0],outfile);

}
