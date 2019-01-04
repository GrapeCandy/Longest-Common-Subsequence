# Longest-Common-Subsequence
LCS's Algorithm and Theory


## Dynamic Programming
- 복잡한 문제를 간단한 여러 개의 문제로 나누어 푸는 방법
- 문제를 여러 개의 하위 문제(subproblem)로 나누어 푼 다음, 그것을 결합하여 최종 결과에 도달하는 것


## LCS(Longest-Common-Subsequence)란?
- 부분집합이 되는 수열들 중에 가장 긴 것을 찾는 알고리즘

<img src="https://i0.wp.com/algorithms.tutorialhorizon.com/files/2015/06/Longest-Common-Subsequence-example.jpg"></img>

[출처] https://algorithms.tutorialhorizon.com/dynamic-programming-longest-common-subsequence/


## LCS(length of LCS) pseudocode

  LCS_LENGTH(arr1[], arr2[])
  
    make 2D array 'c'
    
    for i <- 0 to n       
    {
      c[i][0] = 0;
    }
    for j <- 0 to m
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








 
