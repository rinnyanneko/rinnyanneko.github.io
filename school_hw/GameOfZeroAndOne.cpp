#include <iostream>
using namespace std;
int main(){
	int num;
	int max;
	while(cin >> num){
		//do something
		max = (1 << num);
		for (int i = 0; i < max; i++){
			for (int j = num - 1; j >= 0; j--){
			i & (1 << j) ? cout << '1': cout << '0';
			}
			cout << '\n';
		}
	}
	return 0;
}
