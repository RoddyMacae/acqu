#!/bin/bash
export FileList=$1

#Set to copying time
sleeptime=20

export DataDirectory=$(grep File-Directory: $FileList | grep -v \# | awk '{print $2}')
grep File-Name: $FileList | grep -v \# | awk '{print $2}' | awk -F"." '{print $1}' | while read -r file ; do
export DataFile=$file'.dat.xz'
export Outfile=$file'.out.root'
echo $DataFile
echo $Outfile
qsub /home/roddym/Documents/acqu/Scripts/runJob.bash
sleep $sleeptime
done

echo "!!!ALL JOBS LOADED!!!"
