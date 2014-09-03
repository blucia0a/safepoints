SPPASS := ../SafePoints/SafePoints.dylib

CC := clang
ifeq ($(shell uname -s),Darwin)
	LIBEXT := dylib
else
	LIBEXT := so
endif

LOADPASS := -Xclang -load -Xclang $(SPPASS)

test: test.o sp.o

sp.o: sp.c
	clang -c -O1 -o $@ $^

sp.bc: sp.c
	clang -c -O1 -o $@ $^

%.o: %.c
	clang -c -O1 -o $@ $(LOADPASS) $^

%.bc: %.c
	clang -c -O1 -emit-llvm -o $@ $(LOADPASS) $^
clean:
	-rm *.o test *.bc *.ll
