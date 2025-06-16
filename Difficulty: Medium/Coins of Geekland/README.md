<h2><a href="https://www.geeksforgeeks.org/problems/coins-of-geekland--141631/1">Coins of Geekland</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">In Geekland there is a grid&nbsp;of coins of size <strong>N x</strong> <strong>N</strong>. You have to find the maximum sum of coins in any&nbsp;sub-grid&nbsp;of size<strong> K x K</strong>.<br><strong>Note:</strong> Coins of the negative denomination are&nbsp;also possible at Geekland.</span><br><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 5, K = 3 
mat[[]] = {1, 1, 1, 1, 1}&nbsp;
          {2, 2, 2, 2, 2}&nbsp;
          {3, 8, 6, 7, 3}&nbsp;
          {4, 4, 4, 4, 4}&nbsp;
          {5, 5, 5, 5, 5}</span>
<span style="font-size: 18px;"><strong>Output:</strong> 48</span>
<span style="font-size: 18px;"><strong>Explanation:</strong> {8, 6, 7}
             {4, 4, 4}
             {5, 5, 5}
has the maximum sum</span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 1, K = 1
mat[[]] = {{4}} </span>
<span style="font-size: 18px;"><strong>Output:</strong> 4</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task: </strong>&nbsp;<br>You don't need to read input or print anything. Complete the function <strong>Maximum_Sum()</strong> which takes the matrix mat[], size of Matrix N, and value K as input parameters and returns the maximum sum.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N<sup>2</sup>)<br><strong>Expected Auxiliary Space:</strong> O(N<sup>2</sup>)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ K&nbsp;≤ N ≤ 10<sup>3</sup><br>-5*10<sup>5</sup> ≤ mat[i][j] ≤ 5*10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;