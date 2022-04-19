git add . 
set /p var="Please into commit message: "
echo "Please into commit message: "
echo "bat auto push:%date:~0,10%,%time:~0,8%" 
git commit -m  "%VAR%"
git push origin main
pause

