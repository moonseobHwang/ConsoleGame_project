#include <iostream>
#include <cstring>
using namespace std;
# define max_row = 26;
# define max_column = 19;

int main()
{
    
    int row, column;
    char char_row = '-', char_column = '|';

    // 입력 시작
    cout << "Enter Row and Column: ";
    cin >> row >> column;
    cout << "Display Row : ";
    cin >> char_row;
    cout << "Display Column : ";
    cin >> char_column;
    // 입력 끝

    // 행 생성
    char **map = new char *[row]; // Dynamic Allocation
    // 컬럼 생성
    for (int i = 0; i < row; i++)
        map[i] = new char[column];
    
    // 처음 맵의 값을 정해준다.
    
    // 첫 번째 행
    for (int j = 0; j < column; j++)
    {
        map[0][j] = char_row;
    }

    // 중간 행들
    for (int i = 1; i < row - 1 ; i++){ // output each array element's value
        for (int j = 0; j < column; j++)
        {
            if( j == 0)
                map[i][j] = char_column;
            else if( j == column - 1)
                map[i][j] = char_column;
            else
                map[i][j] = ' ';
        }
    } // end for

    // 새로운 행 추가하기
    for (int i = 0; i < 25; i++)
    {
        map[17][i] = char_row;
    }

    // 마지막 행
    for (int i = 0; i < column; i++)
    {
        map[row-1][i] = char_row;
    }

    
    // display
    for (int i = 0; i < row; i++){ // output each array element's value
        for (int j = 0; j < column; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    delete[] map;
    return 0;
}