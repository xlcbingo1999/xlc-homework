---
layout: default
title: 我的RPG游戏开发
---

# 我的RPG游戏开发

![](https://raw.githubusercontent.com/xlcbingo1999/xlc-homework/gh-pages/images/游戏.gif)

游戏预览，因为游戏底图很大所以只能截取一点点了。

## 一、前期准备

作为一个中国普通大学生，我无法利用最最最最最简单的语言从头开始制作游戏，所以我们必须有一个制作游戏的高级软件，这个时候我的目光聚焦到了[Construct](https://www.scirra.com/construct2)。

软件下载：https://www.scirra.com/construct2/releases/r262/download

进入页面的时候浏览器会自动跳出下载提示。

假如你是一个土豪，你可以购买更多拓展，否则你只能制作HTML5网页游戏。

![](https://wx3.sinaimg.cn/mw690/a093d017gy1fvx4o3dubgj20m70k0h33.jpg)

## 二、初步学习

作为一个新学者，不管是使用C、C++等语言，还是Adobe、Construct这类软件，对软件的基本了解还是非常必要的。

  Beginner’s guide to Construct 2 网址：https://www.scirra.com/tutorials/top

![](https://wx1.sinaimg.cn/thumb180/a093d017gy1fvx4uozamij20ua0budsx.jpg)

你可以通过选择文章中的 zh 和 zh-tw 来选择中文阅读。

## 三、懒人福利

对于中国人来说，能够把所有的英文变成中文是一件无比幸福的事情，假如你想要使用中文版，你可以考虑一下汉化破解。

汉化准备工具：[Notepad++](https://notepad-plus-plus.org/
) 和[Radialix 3](www.pc0359.cn/downinfo/43558.html
)

一、Notepad++：下载这个工具是为了汉化语言包en-US.xml，路径在Construct 2/languages/en-US.xml和其它的一些html与xml文件。

二、Radialix 3：下载这个工具是为了汉化主程序Construct2.exe，有些英文内容在语言包en-US.xml找不到，就要到exe里面找了：

1、打开Radialix 3：文件、新建本地化方案、增加文件…（选择Construct2.exe）、确定、下一步、增加中文（简体）、下一步、完成。

2、当汉化完成之后，点击右键选择构建目标文件（先保存一下项目再构建目标），之后就会有一个Construct2.CHS生成，把Construct2.CHS更改为Construct2CHS.dll，放到Construct 2根目录下就可以汉化主程序内容了。

## 四、游戏开发

我们可能玩过以撒的结合这类rpg即实战略游戏，对于rpg迷来讲，自己做出一个rpg游戏太舒服了，这节我们就来制作一个rpg游戏吧！

### 1、新建

首先我们打开Construct2，像很多软件一样，左上角File中我们能够找到“新建”选项，一切从新建开始。

![](https://www.scirra.com/images/articles/filenew.png)

![](https://www.scirra.com/images/articles/newprojdialog65.png)

点击第一个

### 2、背景

新建一个项目之后，我们双击屏幕空白出，这个时候我们会得到 ![](https://www.scirra.com/images/articles/insertobject.png)

我们选择新增一个背景 “Title Background”，我们选择一张合适的图片来成为背景（单图背景建议找与画布背景大小相同的图片，或者可以无限平铺的图片）

![](https://www.scirra.com/images/articles/tiledproperties.png)

你可以通过设置“size”来控制你的背景大小

### 3、游戏层

背景层一般不能运行游戏，如果我们真的需要玩耍，我们需要在游戏层里对游戏进行操作，这时候我们点击右侧“project”选择“layer”，点击绿色的加号新建层，这和Adobe 软件是相似的。

![](https://www.scirra.com/images/articles/layersbar.png)

### 4、增加游戏角色

你们选择几张图片作为游戏角色的底图，我们选择新建的层，双击中间的操作区，选择添加“Object”，把图片导入，并选择为其改名即可。

![](https://www.scirra.com/images/articles/objectname.png)

### 5、增加行动

![](https://www.scirra.com/images/articles/openbehaviors.png)

![](https://www.scirra.com/images/articles/add8dir.png)

我们可以选择“八方向运动”、“毁灭”、“转换"等行动命令，我们需要根据实际情况来设置各种命令。

因为每个命令各有不同，所以要根据自己的想法来制作。

### 6、event 

![](https://www.scirra.com/images/articles/alwayslookatmouse.png)

![](https://www.scirra.com/images/articles/newevent_2.png)

你可以通过add event来对各种图层进行操作：

System层是对整个游戏系统本身的操作

也可以对各种角色进行操作，如角色行动、角色去向等

当然，也可以根据鼠标、键盘的行为来控制角色的行为，这就涉及到“mouse”和“keyboard”选项中的内容。

### 7、设置游戏胜利与失败选项或目标

一般游戏分为 积分制和生存制

两者都需要一项共同的机制“score”。

我们选择右键事件廊的空白部分，选择新建一个global variable，并改名为Score，再进行微量设计即可。

![](https://www.scirra.com/images/articles/addglobal.png)

### 8、游戏预览

我们可以左击左上角的预览按键来运行一下自己的游戏（注意游戏是在HTML浏览器中运行的）

![](https://www.scirra.com/images/articles/runbutton.png)

## 五、玩游戏吧！！

在结束了一长串操作之后

我们就开始享受自己的游戏吧

假如你想分享

你可以选择公布在社交软件中

或者将整个运行文件发送出去。

祝你玩得愉快！