
male(raja).
male(neel).
male(vij).
male(luv).
male(kush).

female(rani).
female(priya).
female(ruh).
female(rita).
female(mona).

father(neel,luv).
father(neel,rita).
father(vij,kush).
father(vij,mona).
father(raja,neel).
father(raja,vij).

mother(priya,luv).
mother(priya,rita).
mother(ruh,kush).
mother(ruh,mona).
mother(rani,neel).
mother(rani,vij).

sister_of(X,Y):-female(Y),mother(M,X),mother(M,Y).
brother_of(X,Y):-male(Y),mother(M,X),mother(M,Y).

parent_of(X,F,M):-father(F,X),mother(M,X).
