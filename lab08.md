---
layout: default
title: 自顶向下，逐步求精
---

# 自顶向下，逐步求精

## 一、自顶向下

从维基百科上，我们能够查到自顶向下思想的解释。

链接：https://en.wikipedia.org/wiki/Top-down_and_bottom-up_design

为方便读者阅读，我把维基百科中的部分重要内容摘录并翻译。

A top-down approach (also known as stepwise design and in some cases used as a synonym of decomposition) is essentially the breaking down of a system to gain insight into its compositional sub-systems in a reverse engineering fashion. 

自上而下的‎‎方法 (也称为‎‎逐步设计‎‎, 在某些情况下也叫分解‎‎) 本质上是对一个系统的分解, 以便在逆向工程中深入了解其组成子系统的内容。

In a top-down approach an overview of the system is formulated, specifying, but not detailing, any first-level subsystems. Each subsystem is then refined in yet greater detail, sometimes in many additional subsystem levels, until the entire specification is reduced to base elements. 

‎在自上而下的方法中, 系统的概述被制定出来, 而不是详细说明任何第一级子系统。然后对每个子系统进行更详细的改进, 有时在许多额外的子系统级别中, 直到整个规范简化为基本元素。‎

![](http://p.ananas.chaoxing.com/star/1024_0/1386903028919afxat.jpg)

在维基百科中，自顶向下的思想不仅运用与计算机领域，它还被深刻地贯彻在管理学、心理学、纳米科技、神经网络中。

其实，我们自小到大的学习过程中，无不例外地都在使用这一种学习思想：在学习走路时，我们把步行分解成抬腿、下脚、换腿、停止等步骤；在最初的计算过程时，我们其实也是像计算机一样，按照存储-调用-运算-结果输出的过程解决问题，只是我们在反复的训练过程中得以缩短这一个过程，使其几乎是瞬间进行的。

在自顶向下的过程中，最关键的两个字，其实就是分解。

![](https://images2017.cnblogs.com/blog/999371/201708/999371-20170806194911678-1554398745.png)

#二、实例:洗衣机控制程序

![](https://goss1.vcg.com/creative/vcg/800/version23/VCG41170753623.jpg)

1) 伪代码表达大步骤的过程（即分解的过程）

选择模式、水位要求、浸水要求时间、电机要求转动时间、烘干时间

注水

浸泡

电机转动

排水

烘干

结束

2) 伪代码执行小步骤的过程（即下层级的解决问题过程）

READ   水位；时间

WHILE   水位低于要求

    REPEAT  注水

ENDWHILE

WHILE   时间短于浸水要求时间

    REPEAT  浸水

    INCREASE    浸泡实际时间

ENDWHILE

WHILE   电机运行时间短于电机要求转动时间

    REPEAT  电机转动

    INCREASE 电机实际运行时间 
    
ENDWHILE

WHILE   水位不等于0

    REPEAT  排水

ENDWHILE

WHILE   烘干实际时间小于烘干要求时间   

    REPEAT  烘干

    INCREASE  烘干实际时间

ENDWHILE

END