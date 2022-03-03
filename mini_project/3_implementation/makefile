PROJ_NAME = ContactManagement
SRC = cm.c new.c

TEST_SRC= test_contact.c unity.c new.c

ifdef os
	Rm = del /q
	FixPath = $(subst /,\,$1)
	EXEC = exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -rf
		FixPath = $1
		EXEC = out
	endif
endif

Build:
	gcc $(SRC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))
run:Build
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

Build_test:
	gcc $(TEST_SRC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))
run_test:Build_test
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

staticcheck:
	cppcheck --enable=all -iunity .
dynamiccheck:
	valgrind ./$(call FixPath,$(PROJ_NAME).$(EXEC))
coverage:
	gcc -fprofile-arcs -ftest-coverage $(SRC) -o $(call FixPath,$(PROJ_NAME).$(EXEC))
	gcov -a ./$(call FixPath,$(PROJ_NAME).$(EXEC))