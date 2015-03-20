#!/bin/bash
#PBS -N AcquRoot_TaggEff
#PBS -m abe 
#PBS -M r.macrae.1@research.gla.ac.uk
#PBS -V 
#PBS -l walltime=5:00:00,file=20000000kb

tempdir=/scratch/roddym/tmp/

mkdir -p $tempdir
echo mkdir -p $tempdir

cd $tempdir
echo cd $tempdir
rm AcquData.dat.xz
rm Dummy.dat
touch Dummy.dat
cp $DataDirectory$DataFile ./
echo cp $DataDirectory$DataFile ./
echo $DataFile
ln -s $DataFile AcquData.dat.xz
echo ln -s $DataFile AcquData.dat.xz

cd $acqu
echo cd $acqu
echo $DISPLAY

AcquRoot --batch data/Offline-TaggEff-Farm.dat
echo AcquRoot data/Offline-TaggEff-Farm.dat

cd $tempdir
#cp $DataFile /home/roddym/
cp $Outfile /w/work14/roddym/
rm $DataFile
rm $Outfile
