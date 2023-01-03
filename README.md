# OthelloSearch

Shortest paths to reach specific configuration in the game of Othello/Reversi/黑白棋, including:
+ **Eatup**: (if both players cooperate) all pieces on the board could be turned into one color (and hence game over) in 9 moves. All such 9~12-move sequences were found.
+ **Pass**: one player could be forced to pass after 8 moves. No 9-move sequence exists, and 10~12-move sequences were enumerated.
+ **PassEdge**: pass without reaching an edge can happen after 9 moves. 9~12-move sequences were enumerated.
+ **PassEatupEdge**: pass without reaching an edge or all pieces in one color can happen after 12 moves. 12~13-move sequences were enumerated.
+ **Corner**: corner can be reached in 17 moves. 17~18-move sequences were enumerated.

Please forgive the horrible C code from 2007 when I first learned programming.\
I believe the code accounts for symmetry but I've forgotten the details.
