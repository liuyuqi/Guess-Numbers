Guess Numbers V2.1

This program can only be compiled and run on Windows

Dev-C++ 4.9.9.2 enabled.

Author: Yuqi Liu, Ludi Fang, Jiaxi Wang

Date: Apr 15th, 2010.

Some bux fixes.


猜数字游戏V2.0版本说明

    最近相当忙，也许是因为过年吧！祝大家春节快乐！
    自从1.2版本发布以后，相当多的人给我挑bug，特别感谢方璐迪同学，条件相当苛刻，使我的代码由80多行增加到170多行！本人非常喜欢这样，呵呵！
    汪嘉曦同学提供了部分源代码，更加打开了思路，同样感谢！
    希望使用者多提宝贵意见。每个人都有将它完善的权利，同时有把更改后的代码传给本人和与其他人分享的义务。
    本人联系方式   ＱＱ 无穷动  617806604@qq.com  

                                                              刘雨齐
                                                          2010年2月13日
    ________________________________________

     2.0版发布方式：开源                      
          编写语言：标准C
          编写软件：dev C++ 4.9.9.2
              作者：刘雨齐，汪嘉曦，方璐迪
    ________________________________________
    
    ********V2.0说明********（2010年2月13日发布）
    2.0版用函数和指针改写源程序，并对以前版本存在的不少漏洞进行了改进。
    修正了输入空格会导致程序把空格或Tab键当成数字记录下来的错误。
    修正了猜错后程序不给提示直接退出的错误。
    如果用户输入相同的数字，程序会报错并提示重新输入，而不会继续下去，导致算法不匹配出现错误。
    修正了首位不能为0的错误。若首位为0，同样可以猜对。
    在输入猜测次数的过程中，按esc可以选择退出。
    每次猜测时，用户输入4个数字后，程序会给出提示，是否确认本次猜测。按回车确认，按R键重新输入。这样就实现了更改的功能。
    增加了每局结束后，可以选择退出或开始新一局的功能。
    游戏说明及猜对后的提示信息有更改，更富有幽默性。
    增添了部分文本界面下的图形元素，界面更友好。
    
    ********V1.2说明********（2010年1月29日发布）
    1.2版修复了以前版本两个数字中间需要输入空格的漏洞，改进了算法，并首次试用goto语句。

    
    ********V1.1说明********（2010年1月28日发布）
    1.1版新增选择猜测次数功能，同时增加判断输入的正确性功能。用户可输入自己允许猜测的次数，当然次数越多越容易猜中咯！    

    ********V1.0说明********（2010年1月26日发布）
    放寒假了！想想这寒假怎么也不能荒废了不是！于是拾起顾琪同学伟大的猜数字游戏，继续将它改进，顺便也提升一下我用C语言编程的能力！
    在学校写的那个版本暂且叫做1.0版，以后的版本逐次向上增加。
    游戏的使用方法和1.0类似。
    用户需要输入4个不同的数字，每个数字之间用 一 个 空 格 隔开，这很重要，否则会出错。
    输完最后一个数字后，直接按回车键确认。系统会给出形如“1A2B”的提示。这表示：有一个数字猜对且位置正确，有两个数字猜对但位置不正确。之后可以继续猜。
    如果某一次猜中，系统会给出正确信息。如果七次都没猜中，则给出正确答案。
    1.0版作者：顾琪。
