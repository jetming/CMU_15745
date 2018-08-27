/*************************************************************************
	> File Name: test.c
	> Author: puzhiming
	> Mail: puzhiming@migu.cn
	> Created Time: 2018年08月27日 星期一 11时04分57秒
 ************************************************************************/

#include<stdio.h>

int g;
int g_incr (int c)
{
    g += c;
    return g;
}

int loop(int a, int b, int c)
{
    int i;
    int ret = 0;
    for(i =  a; i < b; i++){
        g_incr(c);
    }
    return ret + g;
}
