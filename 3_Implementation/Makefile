PROJ_NAME = ASCII_SPACE_INVADER
TEST_PROJ_NAME = Test_$(PROJ_NAME)

SRC =src/Initialise_world.c \
src/Displayworld.c \
src/Color.c \
src/Loading.c \
src/Control.c \
src/End_.c \
src/laserenemy.c \
src/Enemydisapper.c \
src/Enemy_direction.c \
src/update_board.c \

INC_H = inc

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
.PHONY: run clean test doc all

all:
	gcc -I $(INC_H) $(SRC) ASCII_SPACE_INVADER.c -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm
	./$(call FixPath,$(PROJ_NAME).$(EXEC))
	
run:
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

