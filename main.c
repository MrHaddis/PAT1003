#include <stdio.h>

int main() {
    //定义count 获取需要检测的字符串个数
    int count;
    int index;
    //定义tag用来标记是否有除了PAT以外的字符
    int tag;
    //定义str 去获取输入的字符串
    char str;
    //输出需要循环检测的字符串个数,count前面需加上取地址符号
    scanf("%d", &count);
    //获取输入的字符串 并转为int。无符号 char 强制转换为 int 的形式返回读取的字符
    //并且getchar 会读入'\n' 回车符 清空缓冲区
    getchar();
    //循环count次，不为0时，皆为true
    while (count--) {
        //定义一个数组，并清0
        int a[3] = {0};
        //重新初始化  tag默认没有,index为判断是否有PT
        index = 0, tag = 1;
        //循环获取到本次的输入内容到取到回车符
        while ((str = getchar()) != '\n') {
            printf("%d\n", str);
            if (str == 'A') {
                //index只有 a[0]  a[1] a[2]三种情况
                //a[0]存的是P之前的A，1存的是P-T之间的A 2是T之后的A
                a[index]++;
            } else if (str == 'P' && index == 0) {
                index = 1;
            } else if (str == 'T' && index == 1) {
                index = 2;
            } else {
                //如果有PAT以外的字符就改变标志位
                //有多个P 或者多个T的时候 也会走这里1
                //P和T 有且只有一个，且顺序固定，先P后T。
                tag = 0;
            }
        }
        //tag!=0说明只有PAT
        //index==2 说明有T
        //a[1] 不是0说明有A
        //a[0] *a[1]==a[2]  a[0]的值代表P前面有几个A，a[1]的值代表 P和T之间有几个A，
        // a[2]的值代表 T后面有几个A
        //三者的关系需要满足题目的 aPbATca  即 A*AA=AA;
        if (tag && index == 2 && a[1] && a[0] * a[1] == a[2]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}