#include <iostream>

int main()
{
	using namespace std;

	int line, n;

	// get user input
	cout << "Enter a positive number: ";
	cin >> n;
	line = 0;

	// type first chunk
	while (line < n) // for each line
	{
		for (int c = 0; c < line; c++) // for each char
			cout << ' ';
		for (int c = 0; c < ((n - line) * 2 - 1); c++)
			cout << '*';
		for (int c = 0; c < line; c++)
			cout << ' ';
		cout << endl;
		line += 1;
	}

	line--;

	// type second chunk
	while (line >= 0)
	{
		for (int c = 0; c < line; c++)
			cout << ' ';
		for (int c = 0; c < ((n - line) * 2 - 1); c++)
			cout << '*';
		for (int c = 0; c < line; c++)
			cout << ' ';
		cout << endl;
		--line;
	}
	return 0;
}