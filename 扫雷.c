#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) {
	//for (int row = 0; row < MAX_ROW; row++) {
	//	for (int col = 0; col < MAX_COL; col++) {
	//		showMap[row][col] = '*';
	//	}
	//}
	// ' mem' => memory 内存
	// set: 设置, 集合
	// memset 的功能就是把一段内存上的每个字节都设置成一个具体的值
	// 二维数组的每个元素都是在一个连续的内存空间上布局的~~ 
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	// 随机产生十个位置作为地雷~~
	// 先设置随机种子
	srand((unsigned int)time(0));
	int mineCount = 0;
	while (mineCount < MINE_COUNT) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			continue;
		}
		mineMap[row][col] = '1';
		mineCount++;
	}
}

// 希望这一个函数能同时具备打印两种地图的功能. 
// 取决于实参填啥~~ 
// 形参名字叫做 "map" 不太合适. C++ 标准库里有一个 std::map 
void print(char theMap[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}
}

void update(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	// 表示周围的地雷的个数~
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) {
				// 此时 r, c 坐标超出棋盘的范围, 直接跳过
				continue;
			}
			if (r == row && c == col) {
				// 不需要判断, 直接下次循环
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	// 如果直接赋值的话, 此时假设 count 是2, 
	// 当前 row, col 位置的元素就被设置成了 ASCII 值为 2 的字符
	// 而不是 '2' 
	// 类似于这样的转换, 只是 C 语言中是这么写的. 
	// 其他的主流编程语言中, 一般是不允许 字符类型 和 整数类型 进行混合运算的
	showMap[row][col] = '0' + count;
}
int main() {
	// 1. 创建地图并初始化
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedCount = 0;
	while (1) {
		// 加上清屏
		system("cls");
		// 2. 打印地图
		print(showMap);
		// 此处为了验证 update 函数的正确性,   #define _CRT_SECURE_NO_WARNINGS


		// 先把地雷的布局也打印出来~~ 
		// printf("================\n");
		// print(mineMap);
		// 3. 玩家输入坐标
		int row = 0;
		int col = 0;
		printf("请输入坐标(row, col):");
		scanf_s("%d %d", &row, &col);
		// 进行合法性判定
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您输入的坐标有误! 请重新输入!\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("您输入的位置已经翻开了! 请重新输入!\n");
			continue;
		}
		// 4. 判定是否踩雷
		if (mineMap[row][col] == '1') {
			printf("您踩雷了!! 游戏结束!\n");
			break;
		}
		// 5. 更新 showMap, 显示当前位置周围有多少个雷
		update(showMap, mineMap, row, col);
		// 6. 进行游戏胜利的判定, 统计当前一共翻开了多少个格子~
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("恭喜你, 获胜了!\n");
			break;
		}
	}
	system("pause");
	return 0;
}