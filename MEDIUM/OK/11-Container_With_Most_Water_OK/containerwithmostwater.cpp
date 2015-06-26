/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/23 10:21:40
* >File Name: containerwithmostwater.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinatei(坐标) (i, ai). n vertical(垂直的) lines are drawn such that the two endpoints(断点) of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis(x-轴) forms(构成) a container(容器), such that the container contains the most water.
 *
 *Note: You may not slant(倾斜) the container.
 */

int maxArea(vector<int>& height)
{
	int len = height.size();
	if(len < 2)
		return 0;

	int max = 0;
	int temp1;
	int temp2;
	int i = 0;
	int j = len - 1;

	while(i < j)
	{
		temp1 = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
		if(temp1 > max)
		{
			max = temp1;
		}
		if(height[i] < height[j])
		{
			temp2 = height[i];
			while(height[i] <= temp2 && i < j)
				++i;
		}
		else
		{
			temp2 = height[j];
			while(height[j] <= temp2 && i < j)
				--j;
		}

	}

	return max;
}

int main()
{
	return 0;
}
