FileCopy: main.o copyfile.o searchfile.o fileCpyMenu.o
	g++ main.o copyfile.o searchfile.o fileCpyMenu.o -o a.exe

main.o: main.cpp
	g++ -c main.cpp

copyfile.o: copyfile.cpp
	g++ -c  copyfile.cpp

searchfile.o: searchfile.cpp
	g++ -c searchfile.cpp

fileCpyMenu.o: fileCpyMenu.cpp
	g++ -c fileCpyMenu.cpppp