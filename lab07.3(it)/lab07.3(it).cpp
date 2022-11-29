#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

bool IsElementLocalMinimum(int** arr, int row_count, int col_count, int pos_row, int pos_col);
void NumberLocalMinimum(int** arr, int row_count, int col_count, int& numberLocalMin);

int ABS(int numb);
int FindSumAbsUnderDiagonal(int** arr, int row_count, int col_count);

int main()
{
    srand(time(NULL));
    int rowCount, colCount, n;
    cout << "Enter n in Matrix "; cin >> n;

    rowCount = n;
    colCount = n;

    int** matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        matrix[i] = new int[colCount];
    }

    cout << "Created matrix:\n";
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            matrix[i][j] = (rand() % 100) - 49;

            if (!(matrix[i][j] < 0)) cout << " ";   //add "space" if number positive    
            cout << matrix[i][j];

            if (j != colCount - 1)
            {
                cout << "\t ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
    cout << endl;

    int numberLocalMin = 0;
    NumberLocalMinimum(matrix, rowCount, colCount, numberLocalMin);

    cout << "Number Local Minimum: " << numberLocalMin << endl;
    cout << "\nSum absolut value upper diagonal matrix " << FindSumAbsUnderDiagonal(matrix, rowCount, colCount) << endl;

}

void Create(int** arr, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            arr[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** arr, const int rowCount, const int colCount)
{
        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < colCount; j++)
            {
                cout << "a[" << i << "][" << j << "] = ";
                cin >> arr[i][j];
            }
            cout << endl;
        }
}
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool IsElementLocalMinimum(int** arr, int row_count, int col_count, int pos_row, int pos_col)
{
    int localMin = arr[pos_row][pos_col];

    if (pos_row > 0 && localMin > arr[pos_row - 1][pos_col]) return false;
    if (pos_col > 0 && localMin > arr[pos_row][pos_col - 1]) return false;

    if (pos_row<row_count - 1 && localMin > arr[pos_row + 1][pos_col]) return false;
    if (pos_col<col_count - 1 && localMin > arr[pos_row][pos_col + 1]) return false;

    return true;
}

void NumberLocalMinimum(int** arr, int row_count, int col_count, int& numberLocalMin)
{
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < col_count; j++)
        {
            if (IsElementLocalMinimum(arr, row_count, col_count, i, j))
            {
                numberLocalMin++;
            }
        }
    }
}

int FindSumAbsUnderDiagonal(int** arr, int row_count, int col_count)
{
    int sum = 0;
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < col_count; j++)
        {
            if (i < j) sum += ABS(arr[i][j]);
        }
    }
    return sum;
}

int ABS(int numb)
{
    if (numb < 0)
        return numb * (-1);
    return numb;
}
