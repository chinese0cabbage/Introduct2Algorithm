#include<iostream>
#include"chapter4/MaxSunArray.h"

using namespace std;

int main(){
	double arr[10]={1,2,3,4,5,6,7,8,9,0};
	vector<double> v(arr,arr+10);
	MaxSumOfSunArray(v);
}
