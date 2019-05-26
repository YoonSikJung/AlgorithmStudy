

// BOGGLE

#include <iostream>

using namespace std;


char board[6][6];

int main(void)
{
    int T;

    scanf("%d", &T);

    for( int i = 1 ; i <= T; i++){
        for( int j = 0 ; j < 5; j++) 
        for( int k = 0 ; k < 5; k++)
        scanf("%c", &board[i][j]);
    }

     

    return 0;
}