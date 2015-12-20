# Time-stamp: <2015-12-20 17:48:14 daniel>

# Variables
cc := /usr/bin/g++
ccflags := -std=c++11 -g
target := sample

# Main target
$(target):	main.o stone.o
	$(cc) $(ccflags) -o $@ $^

# objects
main.o:	main.cc stone.hh
	$(cc) $(ccflags) -c -o $@ $<

# log object
stone.o:	stone.cc stone.hh
	$(cc) $(ccflags) -c -o $@ $<

# standard clean function
.PHONY:	clean
clean:
	rm -f *.o $(target) *.log
