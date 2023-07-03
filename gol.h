struct universe {
    char **unipointer;
    int rows;
    int cols;
    //char **unipointer2;

	//points to 
	struct universe *structpointer;
	// u->rows
	// u->structpointer (struct v)-> unipointer[][]  //this is able to access the 2d array that universe v points to

	//number of cells in total
	int totalcells;

	//the number of generations required to evolve
	int numberofg;

	//the number of cells that are alive
	int cellsalive;
	//the number of cells that are dead
	int cellsdead;

};

/*Do not modify the next seven lines*/
void read_in_file(FILE *infile, struct universe *u);
void write_out_file(FILE *outfile, struct universe *u);
int is_alive(struct universe *u, int column, int row);
int will_be_alive(struct universe *u, int column, int row);
int will_be_alive_torus(struct universe *u,  int column, int row);
void evolve(struct universe *u, int (*rule)(struct universe *u, int column, int row));
void print_statistics(struct universe *u);
/*You can modify after this line again*/

