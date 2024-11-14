#include <iostream>
using namespace std;
#define KEY 0
#define PROFIT 2
#define SPACE 1
#define RATIO 3
int main(){
	int num;
	cin >> num;
	int space = 100;
	int products[num + 1][4];
	int out = 0;
	bool run = true;
	for (int i = 1; i <= num; i++){
		products[i][KEY] = i;
		cin >> products[i][SPACE] >> products[i][PROFIT];
		products[i][RATIO] = products[i][PROFIT] / products[i][SPACE];
	}
	while (run){
		int max = 0;
		int min = 0;
		for (int i = 1; i <= num; i++){
			if (products[i][RATIO] > products[max][RATIO] && ((space - products[i][SPACE]) > 0)) max = i;
		}
		space -= products[max][SPACE];
		out += products[max][PROFIT];
		products[max][SPACE] = 0;
		products[max][PROFIT] = 0;
		products[max][RATIO] = 0;
		for (int i = 0; i <= num; i++){
			int count = 0;
			if (products[i][SPACE] < min && (products[i][SPACE] != 0)){
				min = products[i][SPACE];
				count++;
			}
			if (count == num){
				run = false;
				printf("%d\n", out);
			}
		}
	}
	return 0;
}
