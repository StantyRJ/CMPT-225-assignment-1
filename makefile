all: fb td

fb: FriendsBook.o MyADT.o Profile.o
	g++ -Wall -o fb FriendsBook.o MyADT.o Profile.o

td: MyADTtest.o MyADT.o Profile.o
	g++ -Wall -o td MyADTtest.o MyADT.o Profile.o

FriendsBook.o: FriendsBook.cpp MyADT.h Profile.h
	g++ -Wall -c FriendsBook.cpp

MyADTtest.o: MyADTtest.cpp MyADT.h Profile.h
	g++ -Wall -c MyADTtest.cpp

MyADT.o: MyADT.h MyADT.cpp
	g++ -Wall -c MyADT.cpp

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp

clean:
	rm -f fb td *.o