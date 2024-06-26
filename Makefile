OUTPUT_DIRECTORY := target

output: $(OUTPUT_DIRECTORY)/main.o $(OUTPUT_DIRECTORY)/static.o $(OUTPUT_DIRECTORY)/file_reader.o $(OUTPUT_DIRECTORY)/alg.o
	g++ $(OUTPUT_DIRECTORY)/main.o $(OUTPUT_DIRECTORY)/static.o $(OUTPUT_DIRECTORY)/file_reader.o $(OUTPUT_DIRECTORY)/alg.o -o output

$(OUTPUT_DIRECTORY)/file_reader.o: src/filer_reader/file_reader.cpp src/filer_reader/file_reader.hpp | $(OUTPUT_DIRECTORY)
	g++ -c src/filer_reader/file_reader.cpp -o $(OUTPUT_DIRECTORY)/file_reader.o

$(OUTPUT_DIRECTORY)/alg.o: src/alg/alg.cpp src/alg/alg.hpp | $(OUTPUT_DIRECTORY)
	g++ -c src/alg/alg.cpp -o $(OUTPUT_DIRECTORY)/alg.o

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