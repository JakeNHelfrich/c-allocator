allocator.o: 	build_dir allocator.c
				gcc -o ./build/allocator allocator.c

build_dir:
		mkdir ./build

clean:
		rm -drf ./build