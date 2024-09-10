import minesweeper
import random 

random.seed(42)   # do this for repeatability

board = minesweeper.make_board(10,15,20)
print(minesweeper.board_height(board))
print(minesweeper.board_width(board))
print(minesweeper.count_mines(board,1,0))
# print(minesweeper.reveal_mines(board))
print(minesweeper.check_win(board))
# add additional checks ...