#!/bin/bash -
if [ ! $1 ]; then
    ab=`date +%F-%T`
else
    ab=$1
fi
git add .
git commit -am $ab
git push
