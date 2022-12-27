#include <iostream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
 
using namespace std; 
 
int main()
{
	//initilize an array of size 6 with the values of n given
	int n[6] = {16, 64, 256, 1024, 4096, 16384};
	for(int i = 0; i<6; i++)
	{
		//variables used
		int x, y, z;
		//initialize M value we will use (m1,m2)
		int **M = new int *[n[i]];

		for(int j = 0; j<n[i]; j++)
		{
			M[i] = new int[i];
		}

		for(int k = 0; k<n[i]; k++)
		{
			for(int l = 0; l<n[i]; l++)
			{
				//setting every value in matrix to '0'
				M[k][l] = 0; 
			}
		}

		//choose values of M
		size_t m = 1677721600;
		//size_t m = 13421772800;
		time_t timer;
		timer = clock();

		//as instructions say: perform calculation by adding 
		//random numbers from 1-100
		for(int f = 0; f<m; f++)
		{
			x = rand() % 100 + 1;
			y = rand() % n[i];
			z = rand() % n[i];
			M[z][y] = M[z][y] + x;
		}

		//stop timer
		timer = clock() - timer;

		printf("Clock time for n size %d: %.2f seconds", 
		n[i], ((float)timer) / CLOCKS_PER_SEC);
        cout << endl;

		//iterate to next value in array
        i++;

	}


 	return 0; 
} 


