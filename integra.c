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

        double summ = 0;

        double * puntos = new double[n];
        for(int i=0;i<n;i++){
                puntos[i] = f();
        }
        for(int i=0;i<n;i++){
            summ = summ + puntos[i];
        }
        summ = summ / (double) pow(n,10);
        MPI_Reduce(&summ,&s, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0){
        total = s / (double) size;
       cout<<total<<endl;
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;

}

double f(){

        double d=0.0;
        srand(time(NULL));
        for (int i=0;i<10;i++){
        double t = double(rand()) / double(RAND_MAX);
        d = d + t;
        }
        d = d * d;
        return d;
}
