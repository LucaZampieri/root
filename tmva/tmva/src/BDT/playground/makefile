CXX = g++ #mpicxx # clang #
CXXFLAGS =  -std=c++11 -fopenmp -g# -stdlib=libc++

ROOT_FLAGS = `root-config --cflags --glibs`

LD_FLAGS = -L -L.. -lpthread

CPPFLAGS = -I../include \
 -Wno-deprecated \
 -I$(XGBOOST_ROOT)/include -I$(XGBOOST_ROOT)/rabit/include

 XGBOOST_ROOT= /home/zampieri/Documents/CERN/xgboost
 INCLUDE_DIR= -I$(XGBOOST_ROOT)/include -I$(XGBOOST_ROOT)/dmlc-core/include -I$(XGBOOST_ROOT)/rabit/include
 LIB_DIR= -L$(XGBOOST_ROOT)/lib

OBJS = build/arrayBdtPreds.o build/uniqueBdtPreds.o \
			build/uniqueBdtBatch.o build/unique_bdt.o \
			 build/JitForestBdtPreds.o build/JitForestBdtAll.o\
			 build/JitForestBdtAll_Static.o build/xgboostBdt.o\
			 build/JitForestBranchless.o
EXE = arrayBdtPreds.exe uniqueBdtPreds.exe \
      uniqueBdtBatch.exe JitForestBdtPreds.exe \
			JitForestBdtAll.exe JitForestBdtAll_Static.exe \
			xgboostBdt.exe JitForestBranchless.exe

.PHONY : all clean distclean

all: $(EXE)

# linking
JitForestBranchless.exe: build/JitForestBranchless.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)

xgboostBdt.exe: build/xgboostBdt.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS) $(XGBOOST_ROOT)/lib/libxgboost.so

JitForestBdtAll_Static.exe: build/JitForestBdtAll_Static.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)

JitForestBdtAll.exe: build/JitForestBdtAll.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)

JitForestBdtPreds.exe: build/JitForestBdtPreds.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)

arrayBdtPreds.exe: build/arrayBdtPreds.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)

uniqueBdtPreds.exe: build/uniqueBdtPreds.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)

uniqueBdtBatch.exe: build/uniqueBdtBatch.o build/unique_bdt.o
	$(CXX) $(CXXFLAGS) -o $@  $^  $(LD_FLAGS) $(ROOT_FLAGS)


# compilation
build/JitForestBranchless.o: JitForestBranchless.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/xgboostBdt.o: xgboostBdt.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/JitForestBdtAll_Static.o: JitForestBdtAll_Static.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/JitForestBdtAll.o: JitForestBdtAll.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/JitForestBdtPreds.o: JitForestBdtPreds.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/uniqueBdtBatch.o: uniqueBdtBatch.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/uniqueBdtPreds.o: uniqueBdtPreds.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

build/arrayBdtPreds.o: arrayBdtPreds.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)


build/unique_bdt.o:  ../src/unique_bdt.cxx
		$(CXX) $(CXXFLAGS) $(ROOT_FLAGS) -c $< -o $@ $(CPPFLAGS)

clean :
	$(RM) build/*.o *.o

distclean : clean
	$(RM) $(EXE)
