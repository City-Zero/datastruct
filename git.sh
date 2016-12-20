#!/bin/bash -
if [ ! $1 ]; then
    zhu=`date | awk '{print $1$2$3}'` 
else 
    zhu=$1
fi
git add .
git commit -m "$zhu"
git push origin master 

