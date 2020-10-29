#CFLAGS - Makefile variable which can be set to specify additional switches in process of building the project
#g - enables use of extra debugging information that only GDB can use
#O2 - optimization level
#Wall - all warning options enable
#Isrc - append directory src to the list of directories searched for include files
#rdynamic - 
#DNDEBUG - "-D" is a way to define macro, "NDEBUG" is the macro to be defined to turn off asserts as mandated by the C standard
#OPTFLAGS - allows to augment the build options
##########################################################################
#LIBS - Makefile variable which can be used to augment the linking options
#Wl,--no-as-needed - pass '--no-as-needed' as option to the linker
#no-as-need - 
#ldl - use 'dl' as library when linking
#OPTLIBS - allows to augment the linking options
##########################################################################
#PREFIX - Sets PREFIX to this unless users sets other

CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LDLIBS=-Wl,--no-as-needed -ldl $(OPTLIBS)
PREFIX?=/usr/local




#SOURCES - searches for all .c files in src and subcatalogs
#OBJECTS - changes all found .c in SOURCES to .o in OBCJECTS

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))





#TEST_SRC - find all tests sources
#TEST - stripping away .c to achieve full program with same name as .c file

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))





#TARGET - We say that the ultimate target is build/libYOUR_LIBRARY.a, must be changed accordingly to used library
#TEST - stripping away .a to achieve .so with same name as .a library

TARGET=build/libex29.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))





#The Target Build
#The first target is what make runs by default when no target is given
#In this case: '$(TARGET)' <--library and 'tests'
#All will build a library 
#Further conducted will be unit tests

all: $(TARGET) $(SO_TARGET) tests





#'true dev build!'

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all




#Compilation of library Target, whatever that is
#We expand CFLAGS by -fPIC with += operator

$(TARGET): CFLAGS += -fPIC




#Real target - make the build directory and then compile all of the OBJECTS
#ar - archive OBJECTS into here, rcs - replace the files/create archive if doesnt exist/write an object-file index into the archive
#ranlib - this command in Linux is used to generate index to archive. ranlib generates an index to the contents of an archive and it will be stored in the archive

$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@




#shared - produce a shared object which can then be linked with other objects to form an executable

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)




#Makes build/ or bin/ directories if they don't exist yet

build:
	@mkdir -p build
	@mkdir -p bin




#PHONY - There is a chance that they might be a file calles tests, so we put the .PHONY so the makefile knows what to do
#tests: CFLAGS += $(TARGET) - Adds build/libYOUR_LIBRARY.a to the linking
#tests: $(TESTS) - deak make, use what you know about building programs and the current CFLAGS settings to build each program in TESTS
#run script shell

.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh




# The Cleaner
#Target starts things off when we need to clean up the project

clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log 
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`




#The Install
#Now we need a way to install the project and for Makefile to build
#Install depending on 'all' target, so that when we 'make install' we build everything

install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	




#The Checker
#Bonus - created to detect bad functions
#Allows to run check whenever needed
#Display message
#Sets regex (Regular Expression) which will be looking for bad functions like 'strcpy'
#Running 'egrep' to look for any bad patterns. The '|| true' makes sure that there won't
#be an error if 'egrep' doesn't find anything
check:
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
		|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true

