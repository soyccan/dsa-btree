.PHONY: all avl-demo hw6_2_1 hw6_2_2 hw6_2_3 clean upload

all: hw6_2_1

avl-demo hw6_2_1 hw6_2_2 hw6_2_3:
	[ -e build ] || mkdir build
	cd build && cmake .. && make

clean:
	rm -rf avl-demo hw6_2_1 hw6_2_2 hw6_2_3

upload:
	scp -P 9453 -r *.{c,h} CMakeLists.txt soyccan@bravo.nctu.me:/home/soyccan/Documents/dsa-hw6/
