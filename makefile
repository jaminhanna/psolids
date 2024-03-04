psolids: main.o getword.o getjgraph.o degtorad.o get_tetrahedron.o \
         get_hexahedron.o get_octahedron.o get_dodecahedron.o \
         get_icosahedron.o rotate.o get_sums.o sort_face.o \
         center_shape.o print_shape.o
	cc obj/* -o psolids -lm
main.o:
	cc -Iinclude -c src/main.c -o obj/main.o
getword.o:
	cc -Iinclude -c src/getword.c -o obj/getword.o
getjgraph.o:
	cc -Iinclude -c src/getjgraph.c -o obj/getjgraph.o
degtorad.o:
	cc -c src/degtorad.c -o obj/degtorad.o
get_tetrahedron.o:
	cc -Iinclude -c src/get_tetrahedron.c -o obj/get_tetrahedron.o
get_hexahedron.o:
	cc -Iinclude -c src/get_hexahedron.c -o obj/get_hexahedron.o
get_octahedron.o:
	cc -Iinclude -c src/get_octahedron.c -o obj/get_octahedron.o
get_dodecahedron.o:
	cc -Iinclude -c src/get_dodecahedron.c -o obj/get_dodecahedron.o
get_icosahedron.o:
	cc -Iinclude -c src/get_icosahedron.c -o obj/get_icosahedron.o
rotate.o:
	cc -Iinclude -c src/rotate.c -o obj/rotate.o
get_sums.o:
	cc -Iinclude -c src/get_sums.c -o obj/get_sums.o
sort_face.o:
	cc -Iinclude -c src/sort_faces.c -o obj/sort_faces.o
center_shape.o:
	cc -Iinclude -c src/center_shape.c -o obj/center_shape.o
print_shape.o:
	cc -Iinclude -c src/print_shape.c -o obj/print_shape.o
