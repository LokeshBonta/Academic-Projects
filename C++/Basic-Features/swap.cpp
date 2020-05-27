#include <iostream>
/*
Difficult to use and prone to errors
Also needs a null check
*/
void Swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//Easy to use and no null check required
void Swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
using namespace std;
void default_params( int &&x = 10, int &&y = 20);

int main() {
	using namespace std;
	int a = 5, b = 10;
	Swap(a, b);
	cout << "a:" << a << "\n";
	cout << "b:" << b << "\n";
    int x = 1;
    const int y = x;
    const int *z = &y; // Value at the adress is constant
    //z = &x;
    auto k{10};
    cout << k << endl;
    int array[5]{1, 2, 3, 4, 5};
    cout << array[2] << endl;
    for(auto &i : array)
    {
        cout << i << endl;
    }
    auto &&e = 1;
    e = 2;
    cout << e << endl;
    default_params(20, 30);
	return 0;
}

void default_params( int &&x, int &&y)
{
    cout << x << y<< endl;
}