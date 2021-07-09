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
src/welcome.c \
src/ShowConsole.c \
src/check.c \

# All test source files
TEST_SRC = test/test.c\
unity/unity.c


COV_SRC = test.c

INC_H = inc
INC_T = unity

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

test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC)) -lm
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

coverage:
	
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) unity/unity.c  test/test.c $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC)) -lm
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	


cppcheck:
	cppcheck --enable=all $(SRC) ASCII_SPACE_INVADER.c

debug:
	gcc -I $(INC_H) $(SRC) main.c -g -o $(PROJ_NAME).$(EXEC) -lm
	gdb $(PROJ_NAME).$(EXEC)

valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)

clean:
	$(RM) *.DAT
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov