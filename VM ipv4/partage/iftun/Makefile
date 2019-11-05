run: compile
	./test_iftun /dev/net/tun | hexdump -C
compile:
	gcc tunalloc.c iftun.c -o test_iftun
