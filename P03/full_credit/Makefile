CXXFLAGS = --std=c++17

fractions: main.o fraction.o *.h
	$(CXX) $(CXXFLAGS) main.o fraction.o -o fractions

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

fraction.o: fraction.cpp *.h
	-$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o

test.o: test.cpp *.h
	-$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
    
test: test.o  fraction.o
	$(CXX) $(CXXFLAGS) test.o fraction.o -o test

clean:
	rm -f *.o *.gch *~ a.out fractions

