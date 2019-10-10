# output binary
BIN := KWIC

# source files
SRCS := \
    $(shell find . -name '*.cpp' ! -path '*/Unit_Tests/*' ! -name 'main_gtest.cpp')

# intermediate directory for generated object files
OBJDIR := .o
# intermediate directory for generated dependency files
DEPDIR := .d

# object files, auto generated from source files
OBJS := $(patsubst %,$(OBJDIR)/%.o,$(basename $(SRCS)))
# dependency files, auto generated from source files
DEPS := $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS)))

# compilers (at least gcc and clang) don't create the subdirectories automatically
$(shell mkdir -p $(dir $(OBJS)) >/dev/null)
$(shell mkdir -p $(dir $(DEPS)) >/dev/null)

# C compiler
CC := g++
# C++ compiler
CXX := g++
# linker
LD := g++

# C++ flags
CXXFLAGS := -std=c++17
# C/C++ flags
CPPFLAGS := -g -Wall #-Wextra -pedantic
# linker flags
LDFLAGS := -lcurl
LDLIBS +=
# flags required for dependency generation; passed to compilers
DEPFLAGS = -MT $@ -MD -MP -MF $(DEPDIR)/$*.Td

# compile C++ source files
COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -c -o $@
# link object files to binary
LINK.o = $(LD) -o $@ $(LDFLAGS) $(LDLIBS)
# precompile step
PRECOMPILE =
# postcompile step
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d

all: $(BIN)

.PHONY: clean
clean:
	$(RM) -r $(OBJDIR) $(DEPDIR) $(BIN) Test

$(BIN): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS) $(LDLIBS)


$(OBJDIR)/%.o: %.cpp
$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d
	$(PRECOMPILE)
	$(COMPILE.cc) $<
	$(POSTCOMPILE)

.PRECIOUS: $(DEPDIR)/%.d
$(DEPDIR)/%.d: ;

######################TEST######################


#Tests
#Defines test source files (all but main)
TESTSRCS := $(shell find . -name '*.cpp' ! -name 'main.cpp')

TESTLDFLAGS := -lcurl -lgtest -lpthread
# object files, auto generated from source files
TESTOBJS := $(patsubst %,$(OBJDIR)/%.o,$(basename $(TESTSRCS)))
# dependency files, auto generated from source files
TESTDEPS := $(patsubst %,$(DEPDIR)/%.d,$(basename $(TESTSRCS)))

# compilers (at least gcc and clang) don't create the subdirectories automatically
$(shell mkdir -p $(dir $(TESTOBJS)) >/dev/null)
$(shell mkdir -p $(dir $(TESTDEPS)) >/dev/null)

Test : $(TESTOBJS)
	$(CXX) -o $@ $^ $(TESTLDFLAGS) $(LDLIBS)


################################################


print-% :
	@echo $* = $($*)

-include $(DEPS)
-include $(TESTDEPS)
