#define _CRT_SECURE_NO_WARNINGS

int maxArea(int* height, int heightSize) {
    int n = heightSize;
    int max = 0, t = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        int min = height[i] < height[j] ? height[i] : height[j];
        t = (j - i) * min;
        if (t > max) {
            max = t;
        }
        if (height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }
    return max;
}