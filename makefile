all:
	gcc -pg CharLinkList.c -o Linklist.exe	
	gprof Linklist.exe gmon.out > profile.txt