#include <iostream>
#include <string>

using namespace std;

int lcs_length(string arr1, string arr2);

void main(void)
{
	string arr1, arr2;											//String variables that store two array's value

	/*Input two array's value*/
	cout << "please input array1's value(without space): ";		//Input arr1's value
	cin >> arr1;

	cout << "please input array2's value(without space): ";		//Input arr2's value
	cin >> arr2;

	arr1 = "0" + arr1;											//Add 0 to front of arr1(Becasue of making c array)		
	arr2 = "0" + arr2;											//Add 0 to front of arr2(Becasue of making c array)

	cout << lcs_length(arr1, arr2) << endl;						//Call lcs_length function and print longest common subsequence
}


//////////////////////////////////////////
//	<lcs_length>						//
// : calculate lcs and	return lcs		//
//////////////////////////////////////////
int lcs_length(string arr1, string arr2)
{
	int m = arr1.length();							//Length of column
	int n = arr2.length();							//Length of row

	/*Make 2d array*/
	int **c = new int*[n];							//Allocate double pointer array
	for (int i = 0; i < n; ++i)
	{
		c[i] = new int[m];							//Make length m array to each c array
	}

	/*Initialize first line(column, row) to 0*/
	for (int i = 0; i < n; i++)
	{
		c[i][0] = 0;								//Make i'th first row to 0
	}
	for (int j = 0; j < m; j++)
	{
		c[0][j] = 0;								//Make j'th first column to 0
	}

	for (int i = 1; i < n; i++)						//Point to each row until reach to end of array
	{
		for (int j = 1; j < m; j++)					//Point to each column until reach to end of array
		{
			if (arr2[i] == arr1[j])					//If arr2's i'th value is equal to arr1's j'th value
			{
				c[i][j] = c[i - 1][j - 1] + 1;		//current location's value of c array is (c value on the diagonal) + 1
			}
			else                                    //If arr2's i'th value is not equal to arr1's j'th value
			{
				if (c[i - 1][j] > c[i][j - 1])	c[i][j] = c[i - 1][j];				//if Previous column value of current c value is biggert than the previous row value
				else c[i][j] = c[i][j - 1];											//Current c value is previous column's c value
			}
		}
	}
	return c[n-1][m-1];								//Return Longest common subsequence
}
