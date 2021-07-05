all: hello.exe

hello.exe: ASCII_SPACE_INVADER.c Initialise_world.c Displayworld.c Color.c Loading.c
	 gcc -c ASCII_SPACE_INVADER.c Initialise_world.c Displayworld.c Color.c Loading.c
     
clean:
	 rm hello.exe