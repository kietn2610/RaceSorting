
#include <iostream>
#include <fstream>
using namespace std;

void quickSort(int *arr, int low, int high)
{

    int l = low;
    int h = high;
    int pivot = arr[(l + h) / 2];
    int temp;

    while (l <= h)
    {
        while (arr[l] < pivot)
            l++;
        while (arr[h] > pivot)
            h--;
        if (l <= h)
        {
            temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
            l++;
            h--;
        }
    }
    if (h > low)
        quickSort(arr, low, h);
    if (l < high)
        quickSort(arr, l, high);


}

void qsort (int arr[], int n)
{
    cout<< "Starting Array Quick Sort with "<<n<< " items\n";
    quickSort(arr,0, n-1);
    cout << "Ending Quick Sort\n";
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Please include input filename and output filename in param list.\n";
		cout << "Example:\n";
		cout << "     % mySort numbers.txt mySorted.txt\n";
		exit(EXIT_SUCCESS);
	}


	const int MAX = 1000000;
  	ofstream fout;
	ifstream fin;
	int n;

	int v[MAX];
	int count = 0;

	fin.open(argv[1]);
	while (fin >> n )
	{
		v[count++] = n;	// insert a number into the arary and increase the index
	}

	qsort(v,count);	// call the qsort function

        fout.open(argv[2], ios::out | ios::trunc);
        for (int i = 0; i < count; i++)
		fout << v[i]<<endl;


        fout.close();
	fin.close();
        return 0;
}
