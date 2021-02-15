# task2

ifndef GTEST_DIR
GTEST_DIR = ../googletest/googletest
endif

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

SOURCE_DIR = project
TEST_DIR = test

CXXFLAGS += -g -std=gnu++17 -Wall -Wextra -pthread
CPPFLAGS += -isystem $(GTEST_DIR)/include

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

fibonacci_gTest.o : $(TEST_DIR)/fibonacci_gTest.cpp $(GTEST_HEADERS) $(SOURCE_DIR)/fibonacci.h
	$(CXX) $(CPPFLAGS) -I$(SOURCE_DIR) $(CXXFLAGS) -c $(TEST_DIR)/fibonacci_gTest.cpp

fibonacci_gTest : fibonacci_gTest.o fibonacci.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@ -L. -L$(SOURCE_DIR)
	
fibonacci.o : $(SOURCE_DIR)/fibonacci.cpp  $(SOURCE_DIR)/fibonacci.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/fibonacci.cpp
	
main.o : $(SOURCE_DIR)/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/main.cpp
	
main : main.o fibonacci.o
	$(CXX) -o main main.o fibonacci.o
	
all : fibonacci_gTest main
	./fibonacci_gTest

clean:
	rm *.o *.a main fibonacci_gTest