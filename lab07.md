---
layout: default
title: 硬件编程–机器指令编程实验报告
---









# 实验名称：硬件编程–机器指令编程实验

专业：软件工程

学号：18342105

姓名：肖霖畅

日期：2018年11月6日





# 目录

## 一、	实验目标	

## 二、	实验步骤与结果

## 三、	实验小结	
	
## 四、 任务一、任务二解答


### 一、实验目标

1．	了解计算机的编译与运行；

2．	理解CPU中各类寄存器的功能、各种指令的执行过程；

3．	了解高级语言与汇编语言的关系。


### 二、实验步骤与结果

1.  安装Windows XP虚拟机：
    在软工三班大佬的指引下，我安装了Windows XP虚拟操作系统，在虚拟操作系统中，我成功安装了JRE 1.6并成功打开了实验所需网站。

2.  熟悉网站的基本操作：
    点开网站，我先尝试了一下网站内的各种应用，如"RESET"、"STOP"、"STEP"、"PLAY"等，基本了解了其基本操作。

3.  实验一：Add 2 numbers

![](https://wx3.sinaimg.cn/mw690/a093d017gy1fwy64bvoiuj20m80go0ug.jpg)


    过程：

     LOD #3   STO W   LOD #7   STO X   ADD W    STO Z   HLT

4.  实验二：求1到10整数的和

![](https://wx3.sinaimg.cn/mw690/a093d017gy1fwy64bvgr2j20gw0ajq3d.jpg)


![](http://wx4.sinaimg.cn/bmiddle/a093d017gy1fwy6uy8idpj20gu0ant95.jpg)

![](https://wx2.sinaimg.cn/mw690/a093d017gy1fwy64bw7c5j20h20ay0t6.jpg)

![](https://wx2.sinaimg.cn/mw690/a093d017gy1fwy64enkwlj20h90ax74q.jpg)

![](https://wx1.sinaimg.cn/mw690/a093d017gy1fwy64enpmpj20gy0b574q.jpg)

![](https://wx1.sinaimg.cn/mw690/a093d017gy1fwy64eocdjj20h80b43yy.jpg)

    如图，原理是使用W暂时存储被加数，X暂时存储和的值，然后通过多次循环进行求和，得到的最终答案存储在Y中。

    实验一得到了 3 + 7 = 10 的值

    实验二得到了 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 55 的值

    顺利完成两次实验，并形象地了解了CPU的运行方式。

    实验结果已经在图片中展示。

### 三、实验小结

    已经初步了解了CPU的编译和运行原理，能够根据C语言程序来写出编译程序，同时能够运用查表完成机器语言的编译。

    了解了CPU中 PC ACC IR Decoder MUX 等器件的用途，能够大致了解其运行顺序与方式。（详情可见第四节讲解）

    明确了高级语言与编译语言的联系与差距。

### 四、任务一、任务二解答

#### 1.任务一

##### step after step：

 1) PC(program counter):程序计数器，用于存放下一条指令所在单元的地址的地方。

     IR(Instructinon register):指令寄存器，接收数据寄存器传来的指令数据，用来存放当前正在执行的指令，包括指令的操作码。

2) ACC 全称：Accumulator；作用：用来存放操作数或运算结果。

3)" LOD #3"过程分析：

    过程一:PC从RAM中读取并存放"LOD #3"指令的地址和操作数；
  
    过程二：PC将指令传入IR,指令再被送入Decoder，之后操作数会进入MUX;

    过程三：操作数被送入ALU后，再传入ACC中寄存。

4)"ADD W"过程分析：

    过程一：PC从RAM中读取并存放"ADD W"指令的地址和操作数；

    过程二：PC将指令传入IR，指令再被送入Decoder；

    过程三：ALU从ACC中取出上次的值；

    过程四：IR访问RAM中的地址"W",从"W"中读取操作数；

    过程五：ALU读取"W"的值；

    过程六: ALU执行加法操作，结果传入ACC中寄存。

5)"LOD #3"在整个运算周期中，需要访问两次RAM，IR需要两次接受指令，ALU需要两次操作；

"ADD W"在整个运算周期中，只需要访问一次RAM，IR需要一次接受指令，ALU进行一次操作。

##### Binary

1) "LOD #7":00010100 00000111

2) RAM（）与ROM相对，只能用于暂时存放地址和数据，这种存储器在断电时将丢失其存储内容，主要用于存储短时间使用的程序。

3) 16位

4) 
    #include <stdio.h>

    int main(){

        int a = 3;

        int w = 7;

        int sum = a + w;

    }

#### 2.任务二

##### (1) Program 2 

1) 计算10+9+8+7+6+5+4+3+2+1的结果值；

2) 
    #include <stdio.h>

    int main(){

        int sum = 0;

        for(int i = 0 ; i > 0 ; -- i){
            
            sum = sum + i ;

        }

    }

##### (2) 

1)
    #include <stdio.h>

    int main(){

        int i = 10 ; 

        int sum = 0;

        while(i > 0){

        sum = sum + i;

        i = i - 1;

        }

        int add = sum;

    }

2)机器语言计算过程：

3) 

高级语言: 面向的对象是人，容易阅读，相对简单，需要经过编译成机器语言才能运行，为人类编程和修改程序提供了方便。

机器语言：面向的对象是机器，难以阅读，已经成为机器能够识别和操作的语言，保证了机器运行的准确高效性。