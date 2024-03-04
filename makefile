psolids: main.o getword.o getjgraph.o degtorad.o get_tetrahedron.o \
         get_hexahedron.o get_octahedron.o get_dodecahedron.o \
         get_icosahedron.o rotate.o get_sums.o sort_face.o \
         center_shape.o print_shape.o
	cc main.o getword.o getjgraph.o degtorad.o get_tetrahedron.o \
	get_hexahedron.o get_octahedron.o get_dodecahedron.o \
	get_icosahedron.o rotate.o get_sums.o sort_faces.o center_shape.o \
	print_shape.o -o psolids -lm
        jgraph -P txt/ex1 >jgr.ps; ps2pdf jgr.ps img/ex1.pdf
        jgraph -P txt/ex2 >jgr.ps; ps2pdf jgr.ps img/ex2.pdf
        jgraph -P txt/ex3 >jgr.ps; ps2pdf jgr.ps img/ex3.pdf
        jgraph -P txt/ex4 >jgr.ps; ps2pdf jgr.ps img/ex3.pdf
        jgraph -P txt/ex5 >jgr.ps; ps2pdf jgr.ps img/ex3.pdf
main.o:
	cc -Iinclude -c src/main.c -o main.o
getword.o:
	cc -Iinclude -c src/getword.c -o getword.o
getjgraph.o:
	cc -Iinclude -c src/getjgraph.c -o getjgraph.o
degtorad.o:
	cc -c src/degtorad.c -o degtorad.o
get_tetrahedron.o:
	cc -Iinclude -c src/get_tetrahedron.c -o get_tetrahedron.o
get_hexahedron.o:
	cc -Iinclude -c src/get_hexahedron.c -o get_hexahedron.o
get_octahedron.o:
	cc -Iinclude -c src/get_octahedron.c -o get_octahedron.o
get_dodecahedron.o:
	cc -Iinclude -c src/get_dodecahedron.c -o get_dodecahedron.o
get_icosahedron.o:
	cc -Iinclude -c src/get_icosahedron.c -o get_icosahedron.o
rotate.o:
	cc -Iinclude -c src/rotate.c -o rotate.o
get_sums.o:
	cc -Iinclude -c src/get_sums.c -o get_sums.o
sort_face.o:
	cc -Iinclude -c src/sort_faces.c -o sort_faces.o
center_shape.o:
	cc -Iinclude -c src/center_shape.c -o center_shape.o
print_shape.o:
	cc -Iinclude -c src/print_shape.c -o print_shape.o
