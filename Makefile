SourceFiles = 	Entry.c\
			  	SourceFileRead.c\
				Creeps.c\

build:
	gcc $(SourceFiles) -o PixelWars -IInclude -LLibrary -lraylib -lgdi32 -lwinmm

run: build
	./PixelWars