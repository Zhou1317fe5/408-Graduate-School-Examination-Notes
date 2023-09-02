# 白底黑字效果
echo -e "\033[47;30m>>>>>>>>>>>>>>>>>>>>git add .<<<<<<<<<<<<<<<<<<<<\033[0m"
git add .
echo -e "\033[47;30m>>>>>>>>>>>>>>>>>>>>git commit -m "update"<<<<<<<<<<<<<<<<<<<<\033[0m"
git commit -m "update"
echo -e "\033[47;30m>>>>>>>>>>>>>>>>>>>>git push gitee master<<<<<<<<<<<<<<<<<<<<\033[0m"
git push gitee master
echo -e "\033[47;30m>>>>>>>>>>>>>>>>>>>>git push github master<<<<<<<<<<<<<<<<<<<<\033[0m"
git push github master
# 执行完毕不退出
exec /bin/bash