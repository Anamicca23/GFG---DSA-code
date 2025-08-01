<h2><a href="https://www.geeksforgeeks.org/problems/word-boggle4143/1">Word Boggle</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a dictionary of distinct <strong>words</strong> and an <strong>M x N</strong> board where every cell has one character. Find all possible words from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong>&nbsp;While forming a word we can move to&nbsp;any of the 8 adjacent cells. A&nbsp;cell can be used&nbsp;only once in one word.</span></p>
<p><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: 
</strong>N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
<strong>Output:</strong>
CAT
<strong>Explanation</strong>: 
<span style="color: #800080;">C</span> A P
<span style="color: #800080;">A</span> N D
<span style="color: #800080;">T</span> I E
Words we got is denoted using same color.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 4
dictionary = {"GEEKS","FOR","QUIZ","GO"}
R = 3, C = 3 
board = {{G,I,Z},{U,E,K},{Q,S,E}}
<strong>Output:</strong>
GEEKS QUIZ
<strong>Explanation</strong>: 
<span style="color: #ff8c00;">G</span> <span style="color: #0000cd;">I</span> <span style="color: #0000cd;">Z</span>
<span style="color: #0000cd;">U</span> <span style="color: #ff8c00;">E</span> <span style="color: #ff8c00;">K</span>
<span style="color: #0000cd;">Q</span> <span style="color: #ff8c00;">S</span> <span style="color: #ff8c00;">E</span> 
Words we got is denoted using same color.</span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Your task:</strong><br>You dont need to read input or print anything. Your task is to complete the function&nbsp;<strong>wordBoggle()</strong>&nbsp;which takes the dictionary contaning N&nbsp;space-separated strings and R*C board </span><span style="font-size: 18px;">as input parameters and returns a list of&nbsp;words that exist on the board in <strong>lexicographical order</strong>.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(N*W + R*C^2)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(N*W + R*C)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N&nbsp;≤ 15<br>1 ≤ R, C&nbsp;≤ 50<br>1 ≤ length of Word&nbsp;≤ 60<br>Each word can consist of both lowercase and uppercase letters.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<code>Directi</code>&nbsp;<code>Google</code>&nbsp;<code>Facebook</code>&nbsp;<code>Yahoo</code>&nbsp;<code>Nvidia</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>Backtracking</code>&nbsp;<code>Trie</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;