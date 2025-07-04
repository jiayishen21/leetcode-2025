class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            rowFound = set()
            colFound = set()

            for j in range(9):
                # Check row
                if board[i][j] != '.':
                    rowNum = int(board[i][j])
                    if rowNum in rowFound:
                        return False
                    rowFound.add(rowNum)

                # Check col
                if board[j][i] != '.':
                    colNum = int(board[j][i])
                    if colNum in colFound:
                        return False
                    colFound.add(colNum)

        # Check squares
        for i in range(3):
            for j in range(3):
                squareFound = set()

                for x in range(3 * i, 3 * i + 3):
                    for y in range(3 * j, 3 * j + 3):
                        if board[x][y] == '.':
                            continue
                        num = int(board[x][y])
                        if num in squareFound:
                            return False
                        squareFound.add(num)

        return True
