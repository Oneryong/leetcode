/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:35:06
* >File Name: rectangle_area.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * https://leetcode.com/static/images/problemset/rectangle_area.png 
 * Assume that the total area is never beyond the maximum possible value of int.
 */

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int abcd = abs(C - A) * abs(D - B);
	int efgh = abs(G - E) * abs(H - F);
	int repeat;

	int maxx1 = (A > C) ? A : C;
	int minx1 = (A < C) ? A : C;
	int maxy1 = (B > D) ? B : D;
	int miny1 = (B < D) ? B : D;
	int maxx2 = (E > G) ? E : G;
	int minx2 = (E < G) ? E : G;
	int maxy2 = (F > H) ? F : H;
	int miny2 = (F < H) ? F : H;

	if((maxx1 <= minx2) || (maxx2 <= minx1) || (maxy1 <= miny2) || (maxy2 <= miny1))
		repeat = 0;
	else
	{
		int l1, l2, w1, w2;
		vector<int> array(4, 0);
		array[0] = A;
		array[1] = C;
		array[2] = E;
		array[3] = G;
		sort(array.begin(), array.end());
		l1 = array[1];
		l2 = array[2];
		array[0] = B;
		array[1] = D;
		array[2] = F;
		array[3] = H;
		sort(array.begin(), array.end());
		w1 = array[1];
		w2 = array[2];
		repeat = (l2 - l1) * (w2 - w1);
	}

	return abcd + efgh - repeat;
}

int main()
{
	return 0;
}
