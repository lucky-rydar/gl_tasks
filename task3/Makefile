# task3

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

file_counter_gTest.o : $(TEST_DIR)/file_counter_gTest.cpp $(GTEST_HEADERS) $(SOURCE_DIR)/file_counter.h
	$(CXX) $(CPPFLAGS) -I$(SOURCE_DIR) $(CXXFLAGS) -c $(TEST_DIR)/file_counter_gTest.cpp

file_counter_gTest : file_counter_gTest.o file_counter.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@ -L. -L$(SOURCE_DIR)
	
file_counter.o : $(SOURCE_DIR)/file_counter.h $(SOURCE_DIR)/file_counter.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/file_counter.cpp
	
main.o : $(SOURCE_DIR)/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SOURCE_DIR)/main.cpp
	
main : main.o file_counter.o
	$(CXX) -o main main.o file_counter.o -lpthread
	
all : file_counter_gTest main
	./file_counter_gTest

clean:
	rm *.o *.a main file_counter_gTest