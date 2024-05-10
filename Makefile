OUTPUT_DIRECTORY := target

output: $(OUTPUT_DIRECTORY)/main.o $(OUTPUT_DIRECTORY)/static.o
	g++ $(OUTPUT_DIRECTORY)/main.o $(OUTPUT_DIRECTORY)/static.o -o output



$(OUTPUT_DIRECTORY)/main.o: main.cpp | $(OUTPUT_DIRECTORY)
	g++ -c main.cpp -o $(OUTPUT_DIRECTORY)/main.o

$(OUTPUT_DIRECTORY)/static.o: src/static_func/static.cpp src/static_func/static.hpp | $(OUTPUT_DIRECTORY)
	g++ -c src/static_func/static.cpp -o $(OUTPUT_DIRECTORY)/static.o

$(OUTPUT_DIRECTORY):
	mkdir $(OUTPUT_DIRECTORY)

clean:
	del /Q $(OUTPUT_DIRECTORY)\*.o
	rmdir /s /q $(OUTPUT_DIRECTORY)
	del /Q output.exe