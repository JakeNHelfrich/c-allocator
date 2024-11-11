allocator.o: 	build_dir allocator.c
				gcc -o ./build/allocator allocator.c

build_dir:
		mkdir -p ./build

clean:
		rm -drf ./build