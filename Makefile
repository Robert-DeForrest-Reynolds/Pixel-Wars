SourceFiles = 	Entry.c\
			  	SourceFileRead.c\

build:
	gcc $(SourceFiles) -o PixelWars -IInclude -LLibrary -lraylib -lgdi32 -lwinmm

run: build
	./PixelWars