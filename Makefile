SourceFiles = 	Source/Entry.c\
			  	Source/SourceFileRead.c\
				Source/Creeps.c\

build:
	gcc $(SourceFiles) -o PixelWars -IInclude -LLibrary -lraylib -lgdi32 -lwinmm

run: build
	./PixelWars