# Time-stamp: <2015-12-20 18:27:21 daniel>

# Copyright (c) 2015 by Daniel Mendyke
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


# Variables
cc := /usr/bin/g++
ccflags := -std=c++11 -g
target := sample

# Main target
$(target):	main.o stone.o
	$(cc) $(ccflags) -o $@ $^

# test object
main.o:	main.cc stone.hh
	$(cc) $(ccflags) -c -o $@ $<

# log object
stone.o:	stone.cc stone.hh
	$(cc) $(ccflags) -c -o $@ $<

# standard clean function
.PHONY:	clean
clean:
	rm -f *.o $(target) *.log
