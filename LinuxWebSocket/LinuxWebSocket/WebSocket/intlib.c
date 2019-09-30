/*********************************************************************************
 *      Copyright:  (C) 2017 Yang Zheng<yz2012ww@gmail.com>  
 *                  All rights reserved.
 *
 *       Filename:  intlib.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(08/17/2017~)
 *         Author:  Yang Zheng <yz2012ww@gmail.com>
 *      ChangeLog:  1, Release initial version on "08/17/2017 02:09:51 PM"
 *                 
 ********************************************************************************/
int tolower(int c) 	//将大写字母字符转换为小写字母字符
{ 
    if (c >= 'A' && c <= 'Z') 	//判断是否为大写字符
    { 
        return c + 'a' - 'A'; 	//返回小写字符
    } 
    else 
    { 
        return c; 				//不为大写字符则不处理
    } 
} 
 
int htoi(const char s[],int start,int len) 		//传入(16进制数,起始位置,长度)返回int类型
{ 
    int i,j; 		//给循环使用
    int n = 0; 		
    if (s[0] == '0' && (s[1]=='x' || s[1]=='X')) //判断是否有前导0x或者0X
    { 
        i = 2; 		//有前导0x或者0X则设置i=2(从第3位开始,数组下标为2)							
    } 
    else 
    { 
        i = 0; 
    } 
    i+=start;	//i+start为实际需要转换的起始位置
    j=0;		
    for (; (s[i] >= '0' && s[i] <= '9') 
            || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >='A' && s[i] <= 'F');++i) 
    {   
        if(j>=len)	//当j大于要转换的数据长度则跳出循环
        {
            break;
        }
        if (tolower(s[i]) > '9')	//判断s[i]为字母
        { 
            n = 16 * n + (10 + tolower(s[i]) - 'a');	//当s[i]为字母时n=n*16+10+s[i]转换为小写字母-a
        } 
        else 
        { 
            n = 16 * n + (tolower(s[i]) - '0'); 		//当s[i]不为字母时n=n*16+s[i]-9
        } 
        j++;
    } 
    return n; 
} 