all: Personnel.obj Student.obj TA.obj Teacher.obj Course.obj E3.obj
	g++ ex8-1.cpp Personnel.obj Student.obj TA.obj Teacher.obj Course.obj E3.obj -o ex8-1

Personnel.obj: Personnel.cpp
	g++ -c Personnel.cpp -o Personnel.obj

Student.obj: Student.cpp
	g++ -c Student.cpp -o Student.obj

TA.obj: TA.cpp
	g++ -c TA.cpp -o TA.obj

Teacher.obj: Teacher.cpp
	g++ -c Teacher.cpp -o Teacher.obj

Course.obj: Course.cpp
	g++ -c Course.cpp -o Course.obj

E3.obj: E3.cpp
	g++ -c E3.cpp -o E3.obj

clean:
	rm -f *.obj
	rm -f ex8-1

run: all
	./ex8-1 ./inputs/personals.csv ./inputs/courses.csv
