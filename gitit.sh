#!/bin/bash

git add .
if [ $# == 0 ]
then
	git commit -m "No comment commit"
else
	git commit -m "$*"
fi
git push git_cloud master
