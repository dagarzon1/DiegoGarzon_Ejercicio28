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
    double s, total;

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
        MPI_Reduce(&summ,&s, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0){
        total = s / (double) size;
        print(total);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;

}

double f(double x){

    return exp(x);
}
