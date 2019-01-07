#include <iostream>
#include <string>
#include <stack>

using namespace std;

int m;							//The length of arr2
int n;							//The length of arr1

int** c = new int*[n];			//Double pointer array

string arr1;					//first array
string arr2;					//second array

void LCS_lenghth();				//function that makes the length of LCS
void print_LCS();				//function that prints LCS's path

void main(void)
{
	cout << "Please input arr1's value(without space): ";
	cin >> arr1;													//Input arr1

	cout << "Please input arr2's value(without space): ";
	cin >> arr2;													//Input arr2

	arr1 = "0" + arr1;												//Add 0 to front of arr1
	arr2 = "0" + arr2;												//Add 0 to front of arr2

	LCS_lenghth();													//Call LCS_length function
}

void LCS_lenghth()
{
	m = arr1.length();												//length of arr1
	n = arr2.length();												//length of arr2

	/*Make 2D array c*/
	for (int i = 0; i < n; i++)	
	{	
		c[i] = new int[m];											//Make m length array to c[i]										
	}

	/*The first lines (row, column) of array make 0*/
	for (int i = 0; i < n; i++)
	{
		c[i][0] = 0;												//Make c array's i'th row to 0 
	}
	for (int i = 0; i < m; i++)
	{	
		c[0][i] = 0;												//Make c array's i'th column to 0
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (arr2[i] == arr1[j])											//if arr2's value is equal to arr1's value
			{
				c[i][j] = c[i - 1][j - 1] + 1;								//current c array's value is previous value on diagonal 
			}
			else															//If arr2's value is not equal to arr1's value
			{
				if (c[i - 1][j] > c[i][j - 1])	c[i][j] = c[i - 1][j];		//if previous row's c value is bigger than previous column's value, biggest value is current c's value
				else c[i][j] = c[i][j - 1];									//Else oposite value is current c's value
			}
		}
	}

	cout << endl << "LCS: " << c[n - 1][m - 1] << endl;

	print_LCS();													//Call print_LCS function

	return;															//return
}

void print_LCS()
{
	int i = n - 1;													//i is the end of row
	int j = m - 1;													//j is the end of column
	stack<int> s;

	while (c[i][j] != 0)											//while reach to 0 in the c array
	{
		if (c[i][j] == c[i - 1][j])	i--;							//If current value of c is equal to previous column's value, count down i
		else if (c[i][j] == c[i][j - 1])	j--;					//If current value of c is equal to previous row's value, count down j
		else if (c[i][j] == (c[i - 1][j - 1] + 1))					//If current value of c - 1 is equal to value of c on diagonal
		{
			s.push(j);												//Put j index to s
			i--;													//Count down i
			j--;													//Count down j
		}
	}

	cout << "Common subsquence: ";
	while (!s.empty())												//While stack is not empty
	{
		cout << arr1[s.top()] << " ";								//Print common charactor
		s.pop();													//Remove index from stack
	}
	cout << endl << endl;											//New line
}

