#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#include <time.h>
#include <iostream>

using namespace std;
double f(double x);

int main(int argc, char * argv[]){
    
    int N = atof(argv[1]);
    int rank, size;
        
    MPI_Init (&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    
    
    int n = N/size;
    
    if (rank != 0){
        srand(time(NULL));
        double mx = 1;
        double mn = 0;
        double summ = 0;

        double * puntos = new double[n];
        for(int i=0;i<n;i++){
            double t = double(rand()) / double(RAND_MAX) ;
            t = ( mx-mn ) * t + mn;
            puntos[i] = f(t);
        }
        for(int i=0;i<n;i++){
            summ = summ + puntos[i];
        }
        summ = summ / (double) n;
        MPI_Send(&summ, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    
    if (rank == 0){
        char filename[128];
        FILE *out;
        double S = 0;
        for (int i=1;i<n;i++){
            double s;
            MPI_Recv(&s, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            S = S + s;
        }
        S = S / (double) N;
        sprintf(filename, "integra_%d.txt", N);
        fprintf(out, "%f\n", S);
        fclose(out);
    }
    
    return 0;
    
}

double f(double x){
    
    return exp(x);
}