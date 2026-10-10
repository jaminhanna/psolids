bin/psolids: obj/main.o obj/getword.o obj/getjgraph.o obj/degtorad.o obj/get_tetrahedron.o obj/get_hexahedron.o obj/get_octahedron.o obj/get_dodecahedron.o obj/get_icosahedron.o obj/rotate.o obj/get_sums.o obj/sort_face.o obj/center_shape.o obj/print_shape.o
	cc obj/main.o obj/getword.o obj/getjgraph.o obj/degtorad.o obj/get_tetrahedron.o obj/get_hexahedron.o obj/get_octahedron.o obj/get_dodecahedron.o obj/get_icosahedron.o obj/rotate.o obj/get_sums.o obj/sort_faces.o obj/center_shape.o obj/print_shape.o -o bin/psolids -lm
obj/main.o:
	cc -Iinclude -c src/main.c -o obj/main.o
obj/getword.o:
	cc -Iinclude -c src/getword.c -o obj/getword.o
obj/getjgraph.o:
	cc -Iinclude -c src/getjgraph.c -o obj/getjgraph.o
obj/degtorad.o:
	cc -c src/degtorad.c -o obj/degtorad.o
obj/get_tetrahedron.o:
	cc -Iinclude -c src/get_tetrahedron.c -o obj/get_tetrahedron.o
obj/get_hexahedron.o:
	cc -Iinclude -c src/get_hexahedron.c -o obj/get_hexahedron.o
obj/get_octahedron.o:
	cc -Iinclude -c src/get_octahedron.c -o obj/get_octahedron.o
obj/get_dodecahedron.o:
	cc -Iinclude -c src/get_dodecahedron.c -o obj/get_dodecahedron.o
obj/get_icosahedron.o:
	cc -Iinclude -c src/get_icosahedron.c -o obj/get_icosahedron.o
obj/rotate.o:
	cc -Iinclude -c src/rotate.c -o obj/rotate.o
obj/get_sums.o:
	cc -Iinclude -c src/get_sums.c -o obj/get_sums.o
obj/sort_face.o:
	cc -Iinclude -c src/sort_faces.c -o obj/sort_faces.o
obj/center_shape.o:
	cc -Iinclude -c src/center_shape.c -o obj/center_shape.o
obj/print_shape.o:
	cc -Iinclude -c src/print_shape.c -o obj/print_shape.o
clean:
	rm -f bin/psolids obj/*.o
