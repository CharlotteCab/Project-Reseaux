run: compile
	./test_iftun tun0 | hexdump -C
compile:
	gcc tunalloc.c iftun.c -o test_iftun
