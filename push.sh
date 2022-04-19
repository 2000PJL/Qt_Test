#!/bin/bash
git add . 
read -p "Please into commit message: " var
git commit -m  "$var"
git push origin main
