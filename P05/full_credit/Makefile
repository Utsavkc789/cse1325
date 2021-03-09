CXXFLAGS = --std=c++17

smart: main.o person.o student.o parent.o *.h
	$(CXX) $(CXXFLAGS) main.o person.o student.o parent.o -o smart

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

person.o: person.cpp *.h
	-$(CXX) $(CXXFLAGS) -c person.cpp -o person.o
    
student: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o
	
parent: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

clean:
	rm -f *.o *.gch *~ a.out smart
