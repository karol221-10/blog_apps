#include <memory>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	shared_ptr<int[]> int_table(new int[10]); 
	for (size_t i = 0; i < 10; i++) {
		int_table[i] = i;
	}
	for (size_t i = 0; i < 10; i++) {
		cout << "int_table[" << i << "] = " << int_table[i] << endl;
	}
	system("pause");
    return 0;
}

