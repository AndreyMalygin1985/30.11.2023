#include <iostream>
#include <Windows.h>

using namespace std;

template <class T_ONE, class T_TWO>
class Pair
{
	T_ONE val_one;
	T_TWO val_two;
public:
	Pair() : val_one{ T_ONE() }, val_two{ T_TWO() } {};
	Pair(const T_ONE& val_one, const T_TWO& val_two) : val_one{ val_one }, val_two{ val_two } {}

	void setValOne(T_ONE val)
	{
		val_one = val;
	}
	void setValTwo(T_TWO val)
	{
		val_two = val;
	}
	T_ONE getValOne() const
	{
		return val_one;
	}
	T_TWO getValTwo() const
	{
		return val_two;
	}

	void display() const
	{
		cout << "( " << val_one << ", " << val_two << " )";
	}
	bool operator == (const Pair& pair)
	{
		return this->val_one == pair.val_one && this->val_two == pair.val_two;
	}

	bool operator !=(const Pair& pair)
	{
		return !(*this == pair);
	}

	friend ostream& operator <<(ostream& os, const Pair& pair)
	{
		return os << "( " << pair.getValOne() << ", " << pair.getValTwo() << " )";
	}


};


int main()
{
	SetConsoleOutputCP(1251);

	Pair<int, int> intPair(1, 2);
	intPair.display();
	cout << endl;
	Pair<int, int> intPair2(3, 4);
	intPair2.display();
	cout << endl;
	Pair<string, string> strPair("Hello", "World");
	strPair.display();
	cout << endl;
	Pair<Pair<string, string>, int> mark(strPair,8);
	mark.display();
	cout << endl;



	return 0;
}
