/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/
class Solution {
	//Time : O(M*N), Space:O(1)
public:
    enum direction
    {
        right,
        down,
        left,
        up,
        invalid
    };
    
    int invalidNumber = -200;

    bool isInValid(vector<vector<int>>& matrix, int& coordX, int& coordY)
    {
        return matrix[coordX][coordY] == invalidNumber;
    }

    void updateMovingParemeters(vector<vector<int>>& matrix, int& coordX, int& coordY, direction& dir)
    {
        //move coord based on directions
        switch(dir)
        {
            case direction::down:
                {
                    ++coordX;
                    if(coordX >= matrix.size() || isInValid(matrix, coordX,coordY))
                    {
                        --coordX;
                        --coordY;
                        dir = direction::left;
                    }
                    break;
                }
            case direction::right:
                {
                    ++coordY;
                    if(coordY >= matrix[coordX].size()|| isInValid(matrix, coordX,coordY))
                    {
                        --coordY;
                        ++coordX;
                        dir = direction::down;
                    }
                    break;
                }
            case direction::up:
                {
                    --coordX;
                    if(coordX < 0|| isInValid(matrix, coordX,coordY))
                    {
                        ++coordX;
                        ++coordY;
                        dir = direction::right;
                    }
                    break;
                }
            case direction::left:
                {
                    --coordY;
                    if(coordY < 0|| isInValid(matrix, coordX,coordY))
                    {
                        ++coordY;
                        --coordX;
                        dir = direction::up;
                    }
                    break;
                }
            default:
                break;
        }
    }


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        //starting on the left
        direction dir = direction::right;
        int totalElement = matrix.size() * matrix[0].size();
        vector<int> result(totalElement); // init for the result
  
        int coordX = 0;
        int coordY = 0;

        for(int i = 0; i < matrix.size(); ++i)
        {
            matrix[i].resize(matrix[0].size(), false);
        }

        for(int i = 0; i < totalElement; ++i)
        {
            result[i] = matrix[coordX][coordY];
            cout << result[i] <<endl;
            matrix[coordX][coordY] = invalidNumber;//mark this element as visited
            updateMovingParemeters(matrix, coordX, coordY,dir);
        }


        return result;
    }
};