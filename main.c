#include <stdio.h>

int main() {
    //����count ��ȡ��Ҫ�����ַ�������
    int count;
    int index;
    //����tag��������Ƿ��г���PAT������ַ�
    int tag;
    //����str ȥ��ȡ������ַ���
    char str;
    //�����Ҫѭ�������ַ�������,countǰ�������ȡ��ַ����
    scanf("%d", &count);
    //��ȡ������ַ��� ��תΪint���޷��� char ǿ��ת��Ϊ int ����ʽ���ض�ȡ���ַ�
    //����getchar �����'\n' �س��� ��ջ�����
    getchar();
    //ѭ��count�Σ���Ϊ0ʱ����Ϊtrue
    while (count--) {
        //����һ�����飬����0
        int a[3] = {0};
        //���³�ʼ��  tagĬ��û��,indexΪ�ж��Ƿ���PT
        index = 0, tag = 1;
        //ѭ����ȡ�����ε��������ݵ�ȡ���س���
        while ((str = getchar()) != '\n') {
            printf("%d\n", str);
            if (str == 'A') {
                //indexֻ�� a[0]  a[1] a[2]�������
                //a[0]�����P֮ǰ��A��1�����P-T֮���A 2��T֮���A
                a[index]++;
            } else if (str == 'P' && index == 0) {
                index = 1;
            } else if (str == 'T' && index == 1) {
                index = 2;
            } else {
                //�����PAT������ַ��͸ı��־λ
                //�ж��P ���߶��T��ʱ�� Ҳ��������1
                //P��T ����ֻ��һ������˳��̶�����P��T��
                tag = 0;
            }
        }
        //tag!=0˵��ֻ��PAT
        //index==2 ˵����T
        //a[1] ����0˵����A
        //a[0] *a[1]==a[2]  a[0]��ֵ����Pǰ���м���A��a[1]��ֵ���� P��T֮���м���A��
        // a[2]��ֵ���� T�����м���A
        //���ߵĹ�ϵ��Ҫ������Ŀ�� aPbATca  �� A*AA=AA;
        if (tag && index == 2 && a[1] && a[0] * a[1] == a[2]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}