众所周知，每次打代码，新建一个项目时，我们都不可避免的要敲一遍头文件，看CSDN上大家对这个添加头文件的教程文章较少，我就教大家添加头文件^\_^

![](https://img-blog.csdnimg.cn/7b741a5f6fdc48f4a7983ae227577bcb.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAU3VkYVBYREJE,size_20,color_FFFFFF,t_70,g_se,x_16)

效果如图....偷懒必备  那么 话不多说 直接开始

1.首先 我们要打开安装VS2019的文件，以博主为例，博主需打开D盘中下载VS2019的路径

然后在右上方搜索关键字  _**newc++file**_   

 ↓  注意位置  （这是本人是处理好后的效果图）

![](https://img-blog.csdnimg.cn/2a71da690fe547b89ef1a0c224a0675b.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAU3VkYVBYREJE,size_20,color_FFFFFF,t_70,g_se,x_16)

找到之后先右击鼠标键 选择用**记事本方式**打开后缀为.h的文件（_**newc++file  .h**_）

（我随便拿一个.h为后缀的文件为例） 

![](https://img-blog.csdnimg.cn/815954b4f70e4551a54259663ad2d64c.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAU3VkYVBYREJE,size_20,color_FFFFFF,t_70,g_se,x_16)

然后将自己要偷懒的头文件复制到记事本上

例如

#define \_CRT\_SECURE\_NO\_WARNINGS 1  
#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>  
#include<string.h>

#include<bits/stdc++.h>

.....等等头文件  
 此时保存关闭记事本时 会出现权限不够 需用**管理员权限**打开的提示

![](https://img-blog.csdnimg.cn/48fb714414884043bf97580fd36a4fb3.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAU3VkYVBYREJE,size_11,color_FFFFFF,t_70,g_se,x_16)

这是 我们将光标移动至最下面 找到记事本 再用鼠标右键 选择 以管理员权限运行

保存成功   哈哈  偷懒成功√

 我们的自动添加头文件教程就到此结束了

CSDN上写这类博客的博主有点少  所以我写了一遍  如有问题多多斧正  感谢阅读！！！