!/bin/bash

#PBS -l nodes=2:ppn=16,mem=64gb,walltime=00:10:00
#PBS -M da.garzon1@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
cd $PBS_O_WORKDIR 
mpic++ integra.c -o integra.x

for i in 100 10000 100000 1000000 10000000 100000000
do
    mpirun -np 16 ./integra.x i
done