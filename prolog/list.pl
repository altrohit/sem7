
%%member function:
%%finds if X is in list Y.
member(X,[X|_]).
member(X,[_|Y]):-member(X,Y).

%%Sum function
%%calculate the sum total of list elements
sum([],S):- S is 0.
sum([H|T],S):-sum(T,S1),
	S is H+S1.


%%Utility function for max function
%%returns M with maximum value among X & Y
max2(X,Y,M):-
	(   X >= Y
	->  M = X
	;   M = Y ).

%%Max function
%%finds maxximum element of list
max([],M):- M is 0.
max([H|T],M):-
    max(T,M1),
    max2(H,M1,M).

%%Concatinate function
%%Concatinates two list
%%third argument is resultant list
conc([],B,B).
conc([H|T],B,[H|W]):-conc(T,B,W).


%%Reverse List
%%Base case:- reverse of empty list is empty list
rev([],[]).
rev([H|T],RL):-rev(T,RT),
	       conc(RT,[H],RL).

%%Palindrome
%%Base case:- an element is palindrome
same(X,X).
palind(X):-rev(X,RX),
	   same(X,RX).
%%GCD
gcd(0,Y,Y):-!.
gcd(X,0,X):-!.
gcd(X,Y,G):-X1 is X mod Y,
	gcd(Y,X1,G).

%%Length of list
len([],0).
len([_|T],L):-len(T,L1),
	L is L1 + 1.


%%Odd length
odd(X):-len(X,L),
	L1 is L mod 2,
	L1 \== 0.

%%Even length
even(X):-len(X,L),
	L1 is L mod 2,
	L1 == 0.


