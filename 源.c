#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//�𽥽�ÿ�������ĵ���ĳ���������кϲ�,�����ҳ��������ĵ�

//����:���ܷ���ͬ��,�ҳ������ķ����Ż�
 int f[20] = { 0 };
int get(int i) {
	if (f[i] == i) {   //ͨ��׷����Դ�ҵ��õ����յ�Ŀ�ĵ�
		return i;
	}
	else {
		f[i] = get(f[i]);   //���ϵݹ�,�����ں����ĵ�֮ǰδ�仯�ĵ�
		return f[i];
	}
}
int get_while(int i) {
	while (i != f[i]) {
		i = f[i];
	}
	return i;
}
int get_while_optimize(int i) {
	while (i != f[i]) {
		i = f[i]=f[f[i]];  //�Ѹõ�͸õ�ĸ��׶���ֵ�õ�ĸ��׵ĸ���,��ָ���ϵ
	}
	return i;
}
void merge(int i, int j) {
	int t1 = get(i);
	int t2 = get(j);   //���Զ�Ҫ�����յ�������ȶ�
	if (t1 != t2) {    //��ѭ ���Ϊ�� ԭ��
		f[t2] = t1;
	}
}
int main() {
	int sum = 0;
	int n = 0, m = 0;  //nΪ��ĸ���,mΪ��������
	scanf("%d%d", &n, &m);
	int i = 0;
	int x = 0, y = 0;
	for (i = 1; i <= n; i++) {   //��ʼ��,�ʼ����Ϊ��
		f[i] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (i = 1; i <= n; i++) {
		if (f[i] == i) {    //�õ�δ���ϲ���
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}




