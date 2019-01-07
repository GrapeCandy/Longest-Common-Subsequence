# Longest-Common-Subsequence
LCS's Algorithm and Theory


## Dynamic Programming
- 복잡한 문제를 간단한 여러 개의 문제로 나누어 푸는 방법
- 문제를 여러 개의 하위 문제(subproblem)로 나누어 푼 다음, 그것을 결합하여 최종 결과에 도달하는 것


## LCS(Longest-Common-Subsequence)란?
- 부분집합이 되는 수열들 중에 가장 긴 것을 찾는 알고리즘

<img src="https://i0.wp.com/algorithms.tutorialhorizon.com/files/2015/06/Longest-Common-Subsequence-example.jpg"></img>

[출처] https://algorithms.tutorialhorizon.com/dynamic-programming-longest-common-subsequence/


## LCS(length of LCS) pseudocode : just find LCS's length

  LCS_LENGTH(arr1[], arr2[])
  
    make 2D array 'c'
    
    for i <- 0 to n         (n : first array's length)      
    {
      c[i][0] = 0;
    }
    for j <- 0 to m         (m : second array's length)
    {
      c[0][j] = 0;
    }
    
    for i <- 1 to n
    {
      for j <- 1 to m
      {
        if find common character
        {
          c[i][j] <- c[i - 1][j - 1] + 1
        }
        else
        {
          if first array's character is bigger than second array,	c[i][j] <- c[i - 1][j];
          else c[i][j] <- c[i][j - 1];
        }
      }
    }
    return c array's last value
    
    
    
## LCS(print LCS) pseudocode : find string of LCS

[예시 : trace back]

<img src="https://i2.wp.com/www.techiedelight.com/wp-content/uploads/LCS-Backtrack-Wiki.png?zoom=2.625&resize=230%2C278&ssl=1"></img>

[출처] https://www.techiedelight.com/longest-common-subsequence-finding-lcs/


   print_LCS()
   
    stack<int>;

    while reach to 0 in the array
    {
      If current value of c is equal to previous column's value, count down i       (i : pointer that 2D array's column, initialized to end )
      else if current value of c is equal to previous row's value, count down j     (j : pointer that 2D array's row, initialized to     end)
      else if (current value of c) - 1 is equal to value of c on left diagonal
      {
        Put j index to stack
      }
    }

    While stack is not empty
    {
      Print common charactor
      Remove index from stack
    }
    
