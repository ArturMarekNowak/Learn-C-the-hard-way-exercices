#Usuall CFLAGS - OPTFLAGS allows to augment the build options 
CLFAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)


#Options for linking library - OPTLIBS allows to augment the linking options
LIBS=-ldl $(OPTLIBS)


#Sets PREFIX to this unless users sets other
PREFIX?=/usr/local


#Searches for all .c files in src and subcatalogs
SOURCES=$(wildcard src/**/*.c src/*.c)


#Changes all found .c in SOURCES to .o in OBCJECTS
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))


#We use 'wildcard' again to find all tests sources
TEST_SRC=$(wildcard tests/*_tests/c)


#Stripping away .c to achieve full program with same name as .c file
TESTS=$(patsubst %.c,%,$(TEST_SRC))


#We say that the ultimate target is build/libYOUR_LIBRARY.a
#Must be changed accordingly to used library
TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))





#The Target Build
#The first target is what make runs by default when no target is given
#In this case: '$(TARGET)' <--library and 'tests'
#All will build a library 
#Further conducted will be unit tests
all: $(TARGET) $(SO_TARGET) tests


#'true dev build!'
#-Wextra - contains additional debug options
dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all


#Compilation of library Target, whatever that is
#We expand CFLAGS by -fPIC with += operator
$(TARGET): CFLAGS += -fPIC

#Real target - make the build directory and then compile all of the OBJECTS
$(TARGET): build $(OBCJECTS)
	ar rcs $@ $(OBJECTS)    #ar - creation of TARGET, $@ $(OBJECTS) <==> put the target for this Makefile source here and all the OBJECTS after that
	ranlib $@		#ranlibe on TARGET ==> it's built!

#Makes build/ or bin/ directories if they don't exist yet
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin



#The Unit Tests
#If you have the target that's not real but there is a directory or file with that name
#then you need to tag the target with .PHONY: so make will ignore the file and always run
.PHONY: tests
tests: CFLAGS += $(TARGET)         #Add build/libYOUR_LIBRARY.a to the linking
tests: $(TESTS)			   #Make, use what you know about building programs and the current CFLAGS settings to build each program in TESTS
	sh ./tests/runtests.sh     #When all TESTS are built, run this shell script 

#The Cleaner
#Target starts things off when we need to clean up the project
clean:
	rm -rf build $(OBJECTS) $(TESTS)              #This cleans out most of the junk
	rm -f tests/tests.log			      #that various compilers and tools leave behind
	find . -name "*.gc*" -exec rm {} \;	      #Also gets rid of build/ directory and uses trick to delete
	rm -rf `find . -name "*.dSYM" -print`	      #*.dSYM directory that Apple's XCODE leaves behind

#The Install
#Now we need a way to install the project and for Makefile to build 
#Install depending on 'all' target, so that when we 'make install' we build everything
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/		#Creation of 'lib' directory if it doesn't exist
							#DESTDIR - doing build in secure or odd location, 
							#PREFIX - doing build other than in /usr/local
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/	#Actuall install

#The Checker
#Bonus - created to detect bad functions
#Allows to run check whenever needed
#Display message
#Sets regex (Regular Expression) which will be looking for bad functions like 'strcpy'
#Running 'egrep' to look for any bad patterns. The '|| true' makes sure that there won't
#be an error if 'egrep' doesn't find anything

BADFUNCTIONS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' 
check:				
	@echo Files with potentially dangerous functions.				
	@egrep $(BADFUNCTIONS) $(SOURCES) || true
