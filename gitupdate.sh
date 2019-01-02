#!/bin/sh


git pull
git add *
git commit -m "commited update"
echo "RubickFL FacelessLegion312" > git_tmp.txt
git push < git_tmp.txt
rm git_tmp.txt
