#include <mpi.h>	
#include <stdio.h>
#include <stdlib.h>  
#include <math.h>

#define SIZE 4    

int main(int argc, char *argv[])      
	{     
	int pid, np; 
	char rec_buf[100]; // buffer where the received data should be stored

	// the data to be distributed      
	char data[SIZE][SIZE] = {  
		{'a', 'b', 'c', 'd'},   
		{'e', 'f', 'g', 'h'}, 
		{'i', 'j', 'k', 'l'},  
		{'m', 'n', 'o', 'p'}    
		};             
	
	MPI_Init(&argc, &argv);  
	MPI_Comm_rank(MPI_COMM_WORLD, &pid); 
	MPI_Comm_size(MPI_COMM_WORLD, &np);   
	
	int sendcounts[4] = {0,6,5,5};   
	int displs[4]= {0,0,6,11}; 
	
	// divide the data among processes as described by sendcounts and displs 
	MPI_Scatterv(&data, sendcounts, displs, MPI_CHAR, &rec_buf, 100, MPI_CHAR, 0, MPI_COMM_WORLD);  
	
	// print what each process received
	printf("%d: ", pid);  
	for (int i = 0; i < sendcounts[pid]; i++) {   
		printf("%c\t", rec_buf[i]);      
		}                    
	printf("\n");       
	MPI_Finalize();   
	return 0;      
	}
