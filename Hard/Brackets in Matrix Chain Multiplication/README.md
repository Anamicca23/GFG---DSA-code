<h2><a href="https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1">Brackets in Matrix Chain Multiplication</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array&nbsp;<strong>p[]</strong>&nbsp;of length <strong>n </strong>used to denote the dimensions of a series of matrices such that&nbsp;dimension of <strong>i'th</strong> matrix is <strong>p[i] * p[i+1]</strong>. There are a total of&nbsp;<strong>n-1</strong> matrices.&nbsp;Find the most efficient way to multiply these matrices together.&nbsp;<br>The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same. Please see examples for more clarifications.</span></p>
<p><strong>NOTE : As there can be multiple possible answers, the console would print "True" for correct string and "False" for incorrect string. You need to only return a string which performs minimum number of multiplications.</strong></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> 
n = 5
p[] = {1, 2, 3, 4, 5}
<strong>Output:</strong> <br>(((AB)C)D)
<strong>Explaination:</strong> <br>The total number of multiplications are (1*2*3) + (1*3*4) + (1*4*5) = 6 + 12 + 20 = 38.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> 
n = 3
p = {3, 3, 3}
<strong>Output:</strong> <br>(AB)
<strong>Explaination:</strong> <br>The total number of multiplications are (3*3*3) = 27.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>matrixChainOrder()</strong> which takes n and p[] as input parameters and returns the string with the proper order of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n<sup>3</sup>)<br><strong>Expected Auxiliary Space:</strong> O(n<sup>2</sup>)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>2 ≤ n ≤ 26&nbsp;<br>1 ≤ p[i] ≤ 500&nbsp;</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;