#!/bin/bash

git add *
read -p "Type commit message : " name
git commit -m "$name"
git status
git push
echo "done !"