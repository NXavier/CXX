all:
	gcc -w -pg -fopenmp Main.c -o Eindopdracht.exe
	gprof Eindopdracht.exe gmon.out > profiler.txt

profile: 
	gcc -w -pg Main.c -o Eindopdracht.exe
	gprof Eindopdracht.exe gmon.out > profiler.txt

openmp:
	gcc -fopenmp Main.c -o Eindopdracht.exe