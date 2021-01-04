all: generate transform solve

generate: gen.o generate.o
	g++ -o generate generate.o gen.o

gen.o: gen.cpp sudoku.h
	g++ -c gen.cpp

generate.o: generate.cpp sudoku.h
	g++ -c generate.cpp

transform: transform.o trans.o
	g++ -o transform transform.o trans.o

trans.o: trans.cpp sudoku.h
	g++ -c trans.cpp

transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp

solve: sol.o solve.o
	g++ -o solve solve.o sol.o

sol.o: sol.cpp sudoku.h
	g++ -c sol.cpp

solve.o: solve.cpp sudoku.h
	g++ -c solve.cpp
