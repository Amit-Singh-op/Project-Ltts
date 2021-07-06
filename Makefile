target : ASCII_SPACE_INVADER.c Initialise_world.c Displayworld.c Color.c Loading.c control.c fun.h
	gcc ASCII_SPACE_INVADER.c Initialise_world.c Displayworld.c Color.c Loading.c control.c -o ASCII_SPACE_INVADER.exe

run: target
	./ASCII_SPACE_INVADER.exe