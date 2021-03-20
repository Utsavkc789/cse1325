CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: smart

original: CXXFLAGS += -D__ORIGINAL
original: smart

debug:	CXXFLAGS += -g
debug:	smart


smart: main.o person.o student.o parent.o mainwin.o EntryDialog.o *.h
	$(CXX) $(CXXFLAGS) main.o person.o student.o parent.o mainwin.o EntryDialog.o $(GTKFLAGS) -o smart
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

person.o: person.cpp *.h
	-$(CXX) $(CXXFLAGS) -c person.cpp -o person.o
    
student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o
	
parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
	
EntryDialog.o: EntryDialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c EntryDialog.cpp $(GTKFLAGS) -o EntryDialog.o
	
	
clean:
	rm -f *.o *.gch *~ a.out smart
