<h2><a href="https://www.geeksforgeeks.org/problems/implement-queue-using-array/1?page=1&difficulty=Basic&sortBy=difficulty">Queue Using Array</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Implement a Queue using an Array. Queries in the Queue are of the following type:<br><strong>(i)</strong>&nbsp;1 x&nbsp; &nbsp;(a query of this type means&nbsp;&nbsp;pushing&nbsp;<strong>'x'</strong>&nbsp;into the queue)<br><strong>(ii)</strong> 2 &nbsp; &nbsp; (a query of this type means to pop an element from the queue and print the popped element)</span></p>
<p><span style="font-size: 18px;">We just have to implement the functions <strong>push </strong>and <strong>pop </strong>and the driver code will handle the output. </span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>Q = 5, Queries = 1 2 1 3 2 1 4 2
<strong>Output: </strong>2&nbsp;3<strong>
Explanation:
</strong>In the first test case for query&nbsp;
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2 &nbsp; poped element will be 2 the 
    queue will be {3}
1 4 the queue will be {3 4}
2 &nbsp; poped element will be 3&nbsp;</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>Q = 4, Queries = 1 3 2 2 1 4 &nbsp; 
<strong>Output: </strong>3 -1<strong>
Explanation:
</strong>In the second testcase for query&nbsp;
1 3 the queue will be {3}
2&nbsp; &nbsp;poped element will be 3 the
&nbsp;   queue will be empty
2&nbsp; &nbsp;there is no element in the
&nbsp;   queue and hence -1
1 4 the queue will be {4}.&nbsp;</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ Q ≤ 10<sup>5</sup><br>0 ≤ x<strong> </strong>≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Queue</code>&nbsp;<code>Data Structures</code>&nbsp;