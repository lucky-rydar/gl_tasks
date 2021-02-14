# task1

ifndef GTEST_DIR
GTEST_DIR = ../googletest/googletest
endif

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

SOURCE_DIR = project
TEST_DIR = test

CXXFLAGS += -g -std=gnu++11 -Wall -Wextra -pthread
CPPFLAGS += -isystem $(GTEST_DIR)/include

stack.o : $(SOURCE_DIR)/stack.cpp $(SOURCE_DIR)/stack.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/stack.cpp

main.o : $(SOURCE_DIR)/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/main.cpp

main : stack.o main.o
	$(CXX) -o main stack.o main.o

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

stack_gTest.o : $(TEST_DIR)/stack_gTest.cpp $(GTEST_HEADERS) $(SOURCE_DIR)/stack.h
	$(CXX) $(CPPFLAGS) -I$(SOURCE_DIR) $(CXXFLAGS) -c $(TEST_DIR)/stack_gTest.cpp

stack_gTest : stack_gTest.o stack.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@ -L. -L$(SOURCE_DIR)

all: main stack_gTest
	./stack_gTest

clean: 
	rm *.o *.a main stack_gTest