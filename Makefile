hola:
	echo holis
clean:
	find . -type f -name '*.o' -delete 
	find . -type f -executable -delete
	find . -type f -name '*.cpp:tests' -delete
	find . -type f -name '*.py:tests' -delete
