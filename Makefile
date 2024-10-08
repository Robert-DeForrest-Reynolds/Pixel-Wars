run:
	gcc Entry.c -o PixelWars -IInclude -LLibrary -lraylib -lgdi32 -lwinmm
	./PixelWars