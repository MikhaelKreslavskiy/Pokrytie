#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int n;
	cin >> n;

	int** arr = new int* [n];
	int** arr_copy = new int* [n];

	for (int i = 0;i < n; i++)
	{
		 arr[i] = new int[2];
		 arr_copy[i] = new int[2];
	}
	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{

			
			cin >> arr[i][j];
			
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{


			///cin >> arr[i][j];
			if (arr[i][0] > arr[i][1])
			{
				t = arr[i][0];
				arr[i][0] = arr[i][1];
				arr[i][1] = t;
			}
		}
	}
	///cout << endl << endl;
	int min_i = 0;
	int tmp_x, tmp_y;
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << "  ";
		}

		cout << endl;
	}
	*/
	///cout << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = (n-1); j >= (i+1); j--)
		{
			if (arr[j][1] < arr[j-1][1])
			{
				

				tmp_x = arr[j][0];
				tmp_y = arr[j][1];

				arr[j][0] = arr[j-1][0];
				arr[j][1] = arr[j-1][1];

				arr[j-1][0] = tmp_x;
				arr[j-1][1] = tmp_y;

				///min_i = j;


			}
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << "  ";
		}

		cout << endl;
	}
	*/
	int i = 1;
	int f = 0;
	arr_copy[0][0] = arr[0][0];
	arr_copy[0][1] = arr[0][1];
	int size = n;
	while (i < n)
	{
		
		if (arr_copy[f][1] > arr[i][0])
		{
			i++;
			size--;
			continue;
		}
		else
		{
			f++;
			arr_copy[f][0] = arr[i][0];
			arr_copy[f][1] = arr[i][1];
			///f++;
			i++;


		}
		
	}

	///cout << endl;
	
	
	cout << size << endl;
	////cout << arr_copy[0][0] << "  " << arr_copy[0][1] << endl;
	for (int i = 0; i <size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << arr_copy[i][j] << " ";
		}
		cout << endl;
	}
}