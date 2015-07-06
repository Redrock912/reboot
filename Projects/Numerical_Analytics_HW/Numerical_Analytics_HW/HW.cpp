#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int choose;
	cout << "Choose which method you want to perform ( 1 : LU , 2 : Gauss-seidel)" << endl;
	cin >> choose;
	
	
	float a[10][10], l[10][10], u[10][10];
	if (choose == 1)
	{
		void lu(float[][10], float[][10], float[][10], int n);
		void output(float[][10], int);
		int n = 0, i = 0, j = 0;
		cout << "Enter size of 2d array(Square matrix) : ";

		cin >> n;

		for (i = 0; i < n; i++)

		{

			for (j = 0; j < n; j++)

			{

				cout << "Enter values no:" << i << ", " << j << ": ";

				cin >> a[i][j];

			}

		}
		lu(a, l, u, n);
		cout << "\nL Decomposition\n\n";
		output(l, n);
		cout << "\nU Decomposition\n\n";
		output(u, n);
	}
	else if (choose == 2)
	{

		for (int i = 0; i < 3; i++)

		{

			for (int j = 0; j < 3; j++)

			{

				cout << "Enter values no:" << i << ", " << j << ": ";

				cin >> a[i][j];

			}

		}
		float x, y, z;
		x = 1; y = 1; z = 2; // initial guess 

		int iter;
		cout << "Type in the iterations you want for gauss-seidel" << endl;
		cin >> iter;
		// 
		for (int i = 0; i < iter; i++)
		{
			x = a[0][0] + a[0][2] * y + a[0][3] * z;
			y = a[1][0] + a[1][1] * x + a[1][3] * z;
			z = a[2][0] + a[2][1] * x + a[2][2] * y;
		}

		cout << "These are the results : " << x << " " << y << " " << z << endl;
	}

    return 0;

}

void lu(float a[][10], float l[][10], float u[][10], int n)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++)
		{
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++)
                {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }
}

void output(float x[][10], int n)
{
	    int i = 0, j = 0;
	    for (i = 0; i < n; i++)
		    {
		       for (j = 0; j < n; j++)
			       {
			            printf("%f ", x[i][j]);
			       }
		        cout << "\n";
		    }
	}

