%%returns sum of two numbers
sum(X,Y,S):- S is X+Y.

%%returns maximum of two numbers
max(X,Y,M):-
	(   X >= Y
	->  M = X
	;   M = Y ).

%%returns factorial of a number
fact(0,1).
fact(A,X):-
	A > 0,
	A1 is A - 1,
	fact(A1,Y),
	X is A * Y.

%%returns nth fibonacci number
fib(0,0).
fib(1,1).
fib(N,X):-
	N > 1,
	N1 is N-1,
	N2 is N-2,
	fib(N1,X1),
	fib(N2,X2),
	X is X1+X2.
