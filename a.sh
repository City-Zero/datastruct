#!/bin/bash -
if [ ! $1 ]; then
    ab=`date | awk '{print $1$2$3}'`
else
    ab=$1
fi
echo $ab
git add .
git commit -m $ab
git push
