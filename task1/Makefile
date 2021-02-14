# task1

ifndef GTEST_DIR
GTEST_DIR = ../googletest/googletest
endif

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

SOURCE_DIR = project
TEST_DIR = test 

CXXFLAGS += -g -std=gnu++17 -Wall -Wextra -pthread

stack.o : $(SOURCE_DIR)/stack.cpp $(SOURCE_DIR)/stack.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/stack.cpp

main.o : $(SOURCE_DIR)/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/main.cpp

main : stack.o main.o
	$(CXX) -o main stack.o main.o

stack_gTest : $(TEST_DIR)/stack_gTest.cpp

all: main

clean: 
	rm *.o main