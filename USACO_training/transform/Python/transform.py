"""
ID: yiru.li1
LANG: PYTHON3
TASK: transform
"""
from typing import List

# A square pattern of size N x N (1 <= N <= 10) black and white square tiles is transformed into another square pattern. Write a program that will recognize the minimum transformation that has been applied to the original pattern given the following list of possible transformations:
#   1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
#   2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
#   3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
#   4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
#   5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
#   6: No Change: The original pattern was not changed.
#   7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
# In the case that more than one transform could have been used, choose the one with the minimum number above.


def printTwoDimensionalArrayNicely(arrray):
    print('[')
    for i in arrray:
        print(i)
    print(']')

fin = open('transform.in', 'r')    # input file
fout = open('transform.out', 'w')  # output file

n = int(fin.readline())  # N, the size of the square (got from input file)

beforeSquare = []   # square before transformation (get from input file)
# Get beforeSquare from input file:
for i in range(n):  # for each row in beforeSquare:
    beforeSquare.append([])     # add new array to beforeSquare (because beforeSquare is a multidimensional array)
    for j in range(n):   # for each column in beforeSquare:
        readChar = fin.read(1)  # read a character from the input file
        if readChar == '\n':    # if the character is a newline:
            readChar = fin.read(1)  # read the next character instead
        beforeSquare[i].append(readChar)   # append the character to beforeSquare


afterSquare = []    # square after transformation (get from input file)
for i in range(n):  # for each row in afterSquare:
    afterSquare.append([])  # add new array to afterSquare (because afterSquare is a multidimensional array)
    for j in range(n):      # for each column in afterSquare:
        readChar = fin.read(1)  # read a character from the input file
        if readChar == '\n':    # if the character is a newline:
            readChar = fin.read(1)  # read the next character instead
        afterSquare[i].append(readChar)   # append the character to afterSquare


def rotate90(inputSquare, squareSize):  # function to rotate the square 90 degrees clockwise:
    outputSquare = []
    for i in range(squareSize):
        outputSquare.append([])
        for j in range(squareSize):
            outputSquare[i].append(inputSquare[squareSize-j-1][i])
    return outputSquare


def reflectHorizontally(inputSquare, squareSize): # function to reflect the square horizontally:
    outputSquare = []
    for i in range(squareSize):
        outputSquare.append([])
        for j in range(squareSize):
            outputSquare[i].append(inputSquare[i][squareSize-j-1])
    return outputSquare

testSquare = rotate90(beforeSquare, n) # square we'll use to test the different transformations with to see if they match afterSquare. We'll start by testing the "90 Degree Rotation" tranformation.
if testSquare == afterSquare:
    fout.write("1\n")
else:
    testSquare = rotate90(testSquare, n) # rotate testSquare another 90 degrees, meaning that now it has been rotated 180 degress.
    if testSquare == afterSquare:
        fout.write("2\n")
    else:
        testSquare = rotate90(testSquare, n) # rotate yet another 90 degrees, so now it has been rotated 270 degrees.
        if testSquare == afterSquare:
            fout.write("3\n")
        else:
            testSquare = reflectHorizontally(beforeSquare,n)
            if testSquare == afterSquare:
                fout.write("4\n")
            elif rotate90(testSquare, n) == afterSquare or rotate90(rotate90(testSquare, n), n) == afterSquare or rotate90(rotate90(rotate90(testSquare, n), n), n) == afterSquare:
                fout.write("5\n")
            else:
                if beforeSquare == afterSquare:  # check to see if beforeSquare was not changed in afterSquare
                    fout.write("6\n")
                else:
                    fout.write("7\n")



#fout.write (str(sum) + '\n')
fout.close()