//https://leetcode.com/problems/design-tic-tac-toe/
/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

    A move is guaranteed to be valid and is placed on an empty block.
    Once a winning condition is reached, no more moves is allowed.
    A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Example:

Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

*/

//besides the obvious O(n^2) solution
class TicTacToe {
    vector<int> row_cnt;
    vector<int> col_cnt;
    int diag;
    int anti_diag;
    int len;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        row_cnt.resize(n,0);
        col_cnt.resize(n,0);
        diag =0;
        anti_diag = 0;
        len = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player==1){
            row_cnt[row]++;
            col_cnt[col]++;
            if(row==col){
                diag++;
            }
            if(row+col==len-1){
                anti_diag++;
            }
        }
        if(player==2){
            row_cnt[row]--;
            col_cnt[col]--;
            if(row==col){
                diag--;
            }
            if(row+col==len-1){
                anti_diag--;
            }
        }
        
        if(row_cnt[row]==len || col_cnt[col]==len || diag==len || anti_diag==len)
            return 1;
        
        if(row_cnt[row]==-len || col_cnt[col]==-len || diag==-len || anti_diag==-len)
            return 2;
            
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
