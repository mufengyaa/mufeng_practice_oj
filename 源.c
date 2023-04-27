#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//逐渐将每个孤立的点以某种条件进行合并,可以找出最后孤立的点

//例题:解密犯罪同伙,找出独立的犯罪团伙
 int f[20] = { 0 };
int get(int i) {
	if (f[i] == i) {   //通过追根溯源找到该点最终的目的地
		return i;
	}
	else {
		f[i] = get(f[i]);   //不断递归,可以在后续改掉之前未变化的点
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
		i = f[i]=f[f[i]];  //把该点和该点的父亲都赋值该点的父亲的父亲,简化指向关系
	}
	return i;
}
void merge(int i, int j) {
	int t1 = get(i);
	int t2 = get(j);   //各自都要以最终的身份来比对
	if (t1 != t2) {    //依循 左边为王 原则
		f[t2] = t1;
	}
}
int main() {
	int sum = 0;
	int n = 0, m = 0;  //n为点的个数,m为条件个数
	scanf("%d%d", &n, &m);
	int i = 0;
	int x = 0, y = 0;
	for (i = 1; i <= n; i++) {   //初始化,最开始各自为王
		f[i] = i;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (i = 1; i <= n; i++) {
		if (f[i] == i) {    //该点未被合并掉
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}




