﻿#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

	int a[101][101] = { 0, };
	int n = 1, s = 1, c = 1, r = 1, z = 1;
	int i, j, k, kk;

	scanf("%d", &k);	// 가로 세로 크기 

	kk = k;

	if (k % 2 == 1) {		// k값이 홀수 인 경우 변수 초기값 
		r = (k + 1) / 2;		// 달팽이 줄의 시작 위치
		c = (k + 1) / 2;		//        칸의 시작 위치 
		a[r][c] = 1;	// 달팽이 시작 위치 값 지정 
		s = -1;			// 달팽이 진행 방향 설정 ←
	}
	else {				// k값이 짝수 인 경우 변수 초기값 
		r = k / 2 + 1; 		// 달팽이 줄의 시작 위치 
		c = k / 2;			//        칸의 시작 위치 
		a[r][c] = 1;	// 달팽이 시작 위치 값 지정 
		s = 1;			// 달팽이 진행 방향 설정 → 
	}

	while (z <= k) {				// 변수 z 에 의해 반복 횟 수 결정 
		for (i = 1; i <= z; i++) { 	// 반복 횟 수를 1회, 2회, 3회, ...., k 값보다 작거나 같을 동안 반복 
			n = n + 1;				// 배열에 저장될 값 1씩 증가 
			c = c + s;				// 칸(열)의 위치 계산 
			a[r][c] = n;		// r줄 c칸에 현재 수 저장 
		}

		s = s * (-1); // -S	   		// 줄, 칸의 진행 방향을 반대로 변경 

		for (i = 1; i <= z; i++) { 	// 반복 횟 수를 1회, 2회, 3회, ...., k 값 보다 작거나 같을 동안 반복 
			n = n + 1;				// 배열에 저장될 값 1씩 증가 
			r = r + s;				// 칸(열)의 위치 계산
			a[r][c] = n;		// r줄 c칸에 현재 수 저장
		}
		z++;						// 반복 횟 수 1 증가 
	}

	// 배열 내용 출력하기 
	for (int i = 1; i <= kk; i++, puts(""))
		for (int j = 1; j <= kk; j++) 
			printf("%3d", a[i][j]);
		
	return 0;
}