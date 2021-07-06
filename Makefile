target : ASCII_SPACE_INVADER.c Initialise_world.c Displayworld.c Color.c Loading.c fun.h
	gcc ASCII_SPACE_INVADER.c Initialise_world.c Displayworld.c Color.c Loading.c -o ASCII_SPACE_INVADER.exe

run: target
	./ASCII_SPACE_INVADER.exe