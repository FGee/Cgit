//�ҳ���������������һ���Ԫ��
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c[7] = { 1,1,3,3,5,3,9 };
	int n = 7 / 2;
	int ct = 0;//��¼Ԫ�س��ִ���
	int m = 0;//����Ѿ�һ����֤������Ԫ��
	while (ct < n) {//����������Ŀ����ʱһֱѭ��
		int aim = c[m];
		if (ct < n) {
			ct = 0;
			for (int i = 0; i < 7; ++i)
			{
				if (c[m] == c[i])
					++ct;
			}
		}
		++m;
	}
	printf("%d\n", c[m - 1]);

	system("pause");
	return 0;
}
