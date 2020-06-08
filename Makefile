EXE := hw6_2_1 hw6_2_2 hw6_2_3
.PHONY: all clean upload $(EXE)

all: $(EXE)

build: CMakeLists.txt
	mkdir -pv build
	cd build && cmake ..

$(EXE): build
	cmake --build build --target $@

clean:
	# use negated condition so that make won't stop
	[ ! -e build ] || cmake --build build --target clean
	rm -rf build

upload:
	scp -P 9453 -r *.{c,h} Makefile CMakeLists.txt soyccan@bravo.nctu.me:/home/soyccan/Documents/dsa-hw6/
