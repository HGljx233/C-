#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<tgmath.h>
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
	int* res = malloc(sizeof(int) * fmax(10, numSize + 1));
	*returnSize = 0;
	for (int i = numSize - 1; i >= 0 || k > 0; --i, k /= 10) {
		if (i >= 0) {
			k += num[i];
		}
		res[(*returnSize)++] = k%10;
	}
	for (int i = 0; i < (*returnSize) / 2; i++) {
		int tmp = res[i];
		res[i] = res[(*returnSize - 1 - i)];
		res[(*returnSize - 1 - i)] = tmp;

	}
	return res;
}
int main() {
	int arr[] = { 1,2,0,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int c[1024];
	int *d=addToArrayForm(arr, size, 1234,c);
	for (int i = 0; i < 4; i++) {
		printf("%d ", d[i]);
	}
}
#if 0
int removeElement(int* nums, int numsSize, int val) {
	int left = 0;
	for (int right = 0; right < numsSize; right++) {
		if (nums[right] != val) {
			nums[left] = nums[right];
			left++;
		}
	}
	return left;
}
int main() {
	int arr[] = { 0,2,2,3,3,4,5,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = removeElement(arr, len,3);
	printf("%d,num=", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}


int removeDelete(int* nums, int numsSize) {
	if (numsSize == 0 || nums == NULL) {
		return 0;
	}
	int slow = 1;
	int fast = 1;
	while (fast < numsSize) {
		if (nums[fast] != nums[fast - 1]) {
			nums[slow] = nums[fast];
			++slow;
		}
		++fast;
	}
	return slow;
}
int main() {
	int arr[] = {0,0,1,1,1,2,2,2,3,3,4,5,5,5,6,6,7,7,7,8,8,8,8,9,9,9,9,9};
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret=removeDelete(arr, len);
	printf("%d,num=", ret);
	for (int i = 0; i < ret; i++) {
		printf("%d ", arr[i]);
	}
	system("pause");
		return 0;
}
//ÓÒÐý,k=Ðý×ª´ÎÊý
void rotate(int* arr, int length, int k) {
	int newArr[1024];
	for (int i = 0; i < length; i++) {
		newArr[(i + k) % length] = arr[i];
	}
	for (int i = 0; i < length; i++) {
		arr[i] = newArr[i];
	}
}

void rotate(int* nums, int numsSize, int k) {
	int newArr[1024];
	for (int i = 0; i < numsSize; ++i) {
		newArr[(i + k) % numsSize] = nums[i];
	}
	for (int i = 0; i < numsSize; ++i) {
		nums[i] = newArr[i];
	}
}
int main() {
	int a[] = { 1,2,3,-10,-1,6,7 };
	rotate(a, 7, 2);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;

}

void sort(int* num1,  int m, int* num2, int n) {
	int p1 = m - 1, p2 = n - 1;
	int tail = m + n - 1;
	int cur;
	while (p1 >= 0 || p2 >= 0) {
		if (p1 == -1) {
			cur = num2[p2--];
		}
		else if (p2 == -1) {
			cur = num1[p1--];
		}
		else if (num1[p1] > num2[p2]) {
			cur = num1[p1--];
		}
		else {
			cur = num2[p2--];
		}
		num1[tail--] = cur;
	}
}
int main() {
	int a[] = { 1,2,3,0,0,0 };
	int b[] = { 2,5,6 };
	int m = 3;
	int n = 3;
	sort(a,m ,b,n);
	for (int i = 0; i < m+n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}

#define N 1024
void sort(int* a, int* b, int* c, int numSize1, int numSize2) {
	int i = 0; int j = 0;
	while (i < numSize1 && j < numSize2) {
		if (a[i] < b[j]) {
			c[i + j] = a[i];
			i++;
			continue;
		}
		c[i + j] = b[j];
		j++;
	}
	while (i < numSize1) {
		c[i + j] = a[i];
		i++;
	}
	while (j < numSize2) {
		c[i + j] = b[j];
		j++;
	}

}
int main() {
	int a[] = { 1,2,3,0,0,0 };
	int b[] = { 2,5,6};
	int c[N];
	int size1 = sizeof(a) / sizeof(a[0]);
	int size2 = sizeof(b) / sizeof(b[0]);
	int n = size1 + size2;
	sort(a, b, c, size1, size2);
	for (int i = 0; i < n; i++) {
		printf("%d ",c[i]);
	}
	system("pause");
	return 0;
}
#endif