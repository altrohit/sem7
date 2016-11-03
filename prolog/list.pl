
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

/****************************************************
 *  Program 2
 *  A. Insert an item at nth position in every list at all levels
 *  B. Remove nth item from a list
 *  C. Remove nth item from every list at all levels
 *  D. Append two list
 *  Author: Gaurav Ujjwal
 ***************************************************/
insert(NUM,_,_,[],[NUM|[]]).
insert(_,_,_,X,Y):-            [_|_] = X  -> false  ;  Y = X.
insert(NUM,I,N,[H|T],[X|Y]):-  I =:= 0
		         -> (  insert(NUM,-1,N,[H|T],L),
			       [X|Y] = [NUM|L])
		         ;  (  insert(NUM,N,N,H,X),
			       J is I-1,
			       insert(NUM,J,N,T,Y) ).

insert_nth(NUM,N,[H|T],[X|Y]):-insert(NUM,N,N,[H|T],[X|Y]), !.


/***************************************************/
remove(_,[],X):-          X = [], !.
remove(N,[H|T],[X|Y]):-   N =:= 1               %Need to stop at parent
                     -> ( X = H,
			  [_|T1] = T,           %Extract Tail of T
			  Y=T1  )               %Set Y to extracted Tail
		     ;  ( N1 is N-1,
		          X = H,
			  remove(N1,T,Y)  ).

/***************************************************/
remove2(_,_,[],[]).
remove2(_,_,X,Y):-	 [_|_] = X  -> false  ;  Y = X.
remove2(N,I,[H|T],Z):-   I =:= 1
                    -> ( remove2(N,-1,T,L),
			 Z = L)
                    ;  ( remove2(N,N,H,X),
                         J is I-1,
		         remove2(N,J,T,Y),
	                 Z = [X|Y]).

remove_nth(N,[H|T],[X|Y]):- remove2(N,N,[H|T],[X|Y]), !.

%%Concatinate function
%%Concatinates two list
%%third argument is resultant list
conc([],B,B).
conc([H|T],B,[H|W]):-conc(T,B,W).
