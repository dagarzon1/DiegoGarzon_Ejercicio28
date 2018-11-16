!/bin/bash

#PBS -l nodes=2:ppn=16,mem=64gb,walltime=00:10:00
#PBS -M da.garzon1@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
cd $PBS_O_WORKDIR
mpic++ integra.c -o integra.x

for i in {2..8..1}
do
    mpiexec -np 8 ./integra.x 10**i > "data${i}.txt"
done

python integra.py
