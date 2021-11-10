all: fig.pdf

borrador.x: borrador.cpp
	g++ borrador.cpp -o borrador.x

datos.txt: borrador.x
	./borrador.x > datos.txt

fig.pdf: plot.gp datos.txt
	gnuplot plot.gp

clean:
	rm -f a.out *.x *.txt *.pdf 
