all:
	python setup.py build_ext --inplace
	python ./graphs.py
	make clean

build:
	python setup.py build_ext --inplace

graph:
	python ./graphs.py

clean:
	rm -f wrapper.c
	rm -rf build/

