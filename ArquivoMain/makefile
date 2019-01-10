encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c
checksum.o: checksum.c checksum.h
	gcc -c checksum.c
libhfsecurity.a:encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o 
test_code:teste.c libhfsecurity.a
	gcc teste.c -lhfsecurity -o test_code










