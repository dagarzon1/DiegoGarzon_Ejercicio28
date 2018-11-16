!/bin/bash

#PBS -l nodes=2:ppn=16,mem=64gb,walltime=00:10:00
#PBS -M da.garzon1@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
make clean
cd $PBS_O_WORKDIR 
make

mpirun -np 16 ./list12_7.x<<'EOF'
1000
0