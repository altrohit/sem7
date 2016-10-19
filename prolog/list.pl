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
