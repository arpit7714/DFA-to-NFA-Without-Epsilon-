# DFA-to-NFA-Without-Epsilon-

This program is taking input from the file nfa.txt and pritinf the output into the file dfa.txt <br/>
Input Format <br/>
N M // N- number of states , M- Number of Symbol Used<br/>
C 1--C //C - Numbe of final states ,1--c - to declare which states are the final states<br/>
K //Number of transition function <br/>
a s b 1---b // a is the previous state , s is the input symbol (Symbol starts from 1 --- n and states always starts from 0--n), b is the number of states is goes to after taking that particular symbol , 1--b is the states that which it goes. <br/> 
-----------<br/>
-----------<br/>
-----------<br/>
<br/>
<br/>
----------k times<br/>
# Input
<br/>
5 2<br/>
1 4<br/>
9<br/>
0 1 2 0 1<br/> 
0 2 1 3<br/>
1 1 1 2<br/>
1 2 1 2<br/>
2 1 1 4<br/>
3 1 1 3<br/>
3 2 1 2 <br/>
4 1 1 4<br/>
4 2 1 3 <br/>
<br/>
<br/>
<br/>

# Output

DFA for the corresponding NFA<br/>
0  0,1  3  <br/>
0,1  0,1,2  2,3 <br/> 
3  3  2  <br/>
0,1,2  0,1,2,4f  2,3<br/>  
2,3  3,4f  2  <br/>
2  4f  -1  <br/>
0,1,2,4f  0,1,2,4f  2,3<br/>  
3,4f  3,4f  2,3  <br/>
4f  4f  3  <br/>
-1  -1  -1  <br/>

<br/><br/> where f means the final states and -1 means phi

