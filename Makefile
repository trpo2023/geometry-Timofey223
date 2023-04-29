CFLAGS = -Isrc -Wall -Wextra -Werror

EXE = ./bin/

DIR_OBJ = ./obj/src/

DIR_SRC = ./src/

DIR_SRC_GEOM = $(DIR_SRC)geometry/

DIR_OBJ_GEOM = $(DIR_OBJ)geometry/

DIR_SRC_LIB = $(DIR_SRC)libgeometry/

DIR_OBJ_LIB = $(DIR_OBJ)libgeometry/



$(EXE)main : $(DIR_OBJ_GEOM)main.o $(DIR_OBJ_LIB)libmain.a
	gcc $(CFLAGS) $(DIR_OBJ_LIB)geometry.o $(DIR_OBJ_GEOM)main.o -lm -o $(EXE)main

$(DIR_OBJ_GEOM)main.o : $(DIR_SRC_GEOM)main.c
	gcc  $(CFLAGS) -MMD -c $(DIR_SRC_GEOM)main.c -o $@

$(DIR_OBJ_LIB)libmain.a : $(DIR_OBJ_LIB)geometry.o
	ar rcs $@ $^

$(DIR_OBJ_LIB)geometry.o : $(DIR_SRC_LIB)geometry.c
	gcc $(CFLAGS) -MMD -c $(DIR_SRC_LIB)geometry.c -o $@

-include obj/src/geometry/main.d obj/src/libgeometry/geometry.d



