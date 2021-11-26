# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ssw3-team2/Term-Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ssw3-team2/Term-Project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ssw3-team2/Term-Project/CMakeFiles /home/ssw3-team2/Term-Project/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ssw3-team2/Term-Project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Term-Project

# Build rule for target.
Term-Project: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Term-Project
.PHONY : Term-Project

# fast build rule for target.
Term-Project/fast:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/build
.PHONY : Term-Project/fast

Ensemble/Ensemble.o: Ensemble/Ensemble.cc.o

.PHONY : Ensemble/Ensemble.o

# target to build an object file
Ensemble/Ensemble.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/Ensemble/Ensemble.cc.o
.PHONY : Ensemble/Ensemble.cc.o

Ensemble/Ensemble.i: Ensemble/Ensemble.cc.i

.PHONY : Ensemble/Ensemble.i

# target to preprocess a source file
Ensemble/Ensemble.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/Ensemble/Ensemble.cc.i
.PHONY : Ensemble/Ensemble.cc.i

Ensemble/Ensemble.s: Ensemble/Ensemble.cc.s

.PHONY : Ensemble/Ensemble.s

# target to generate assembly for a file
Ensemble/Ensemble.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/Ensemble/Ensemble.cc.s
.PHONY : Ensemble/Ensemble.cc.s

ImageRec/ImageRec.o: ImageRec/ImageRec.cc.o

.PHONY : ImageRec/ImageRec.o

# target to build an object file
ImageRec/ImageRec.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/ImageRec.cc.o
.PHONY : ImageRec/ImageRec.cc.o

ImageRec/ImageRec.i: ImageRec/ImageRec.cc.i

.PHONY : ImageRec/ImageRec.i

# target to preprocess a source file
ImageRec/ImageRec.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/ImageRec.cc.i
.PHONY : ImageRec/ImageRec.cc.i

ImageRec/ImageRec.s: ImageRec/ImageRec.cc.s

.PHONY : ImageRec/ImageRec.s

# target to generate assembly for a file
ImageRec/ImageRec.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/ImageRec.cc.s
.PHONY : ImageRec/ImageRec.cc.s

ImageRec/histogram.o: ImageRec/histogram.cc.o

.PHONY : ImageRec/histogram.o

# target to build an object file
ImageRec/histogram.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/histogram.cc.o
.PHONY : ImageRec/histogram.cc.o

ImageRec/histogram.i: ImageRec/histogram.cc.i

.PHONY : ImageRec/histogram.i

# target to preprocess a source file
ImageRec/histogram.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/histogram.cc.i
.PHONY : ImageRec/histogram.cc.i

ImageRec/histogram.s: ImageRec/histogram.cc.s

.PHONY : ImageRec/histogram.s

# target to generate assembly for a file
ImageRec/histogram.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/histogram.cc.s
.PHONY : ImageRec/histogram.cc.s

ImageRec/image2vec.o: ImageRec/image2vec.cc.o

.PHONY : ImageRec/image2vec.o

# target to build an object file
ImageRec/image2vec.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/image2vec.cc.o
.PHONY : ImageRec/image2vec.cc.o

ImageRec/image2vec.i: ImageRec/image2vec.cc.i

.PHONY : ImageRec/image2vec.i

# target to preprocess a source file
ImageRec/image2vec.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/image2vec.cc.i
.PHONY : ImageRec/image2vec.cc.i

ImageRec/image2vec.s: ImageRec/image2vec.cc.s

.PHONY : ImageRec/image2vec.s

# target to generate assembly for a file
ImageRec/image2vec.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/image2vec.cc.s
.PHONY : ImageRec/image2vec.cc.s

ImageRec/kmeans.o: ImageRec/kmeans.cc.o

.PHONY : ImageRec/kmeans.o

# target to build an object file
ImageRec/kmeans.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/kmeans.cc.o
.PHONY : ImageRec/kmeans.cc.o

ImageRec/kmeans.i: ImageRec/kmeans.cc.i

.PHONY : ImageRec/kmeans.i

# target to preprocess a source file
ImageRec/kmeans.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/kmeans.cc.i
.PHONY : ImageRec/kmeans.cc.i

ImageRec/kmeans.s: ImageRec/kmeans.cc.s

.PHONY : ImageRec/kmeans.s

# target to generate assembly for a file
ImageRec/kmeans.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ImageRec/kmeans.cc.s
.PHONY : ImageRec/kmeans.cc.s

ItemRec.o: ItemRec.cc.o

.PHONY : ItemRec.o

# target to build an object file
ItemRec.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ItemRec.cc.o
.PHONY : ItemRec.cc.o

ItemRec.i: ItemRec.cc.i

.PHONY : ItemRec.i

# target to preprocess a source file
ItemRec.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ItemRec.cc.i
.PHONY : ItemRec.cc.i

ItemRec.s: ItemRec.cc.s

.PHONY : ItemRec.s

# target to generate assembly for a file
ItemRec.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/ItemRec.cc.s
.PHONY : ItemRec.cc.s

Knn/Knn.o: Knn/Knn.cc.o

.PHONY : Knn/Knn.o

# target to build an object file
Knn/Knn.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/Knn/Knn.cc.o
.PHONY : Knn/Knn.cc.o

Knn/Knn.i: Knn/Knn.cc.i

.PHONY : Knn/Knn.i

# target to preprocess a source file
Knn/Knn.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/Knn/Knn.cc.i
.PHONY : Knn/Knn.cc.i

Knn/Knn.s: Knn/Knn.cc.s

.PHONY : Knn/Knn.s

# target to generate assembly for a file
Knn/Knn.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/Knn/Knn.cc.s
.PHONY : Knn/Knn.cc.s

TagRec/TagRec.o: TagRec/TagRec.cc.o

.PHONY : TagRec/TagRec.o

# target to build an object file
TagRec/TagRec.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/TagRec/TagRec.cc.o
.PHONY : TagRec/TagRec.cc.o

TagRec/TagRec.i: TagRec/TagRec.cc.i

.PHONY : TagRec/TagRec.i

# target to preprocess a source file
TagRec/TagRec.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/TagRec/TagRec.cc.i
.PHONY : TagRec/TagRec.cc.i

TagRec/TagRec.s: TagRec/TagRec.cc.s

.PHONY : TagRec/TagRec.s

# target to generate assembly for a file
TagRec/TagRec.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/TagRec/TagRec.cc.s
.PHONY : TagRec/TagRec.cc.s

TextRec/TextRec.o: TextRec/TextRec.cc.o

.PHONY : TextRec/TextRec.o

# target to build an object file
TextRec/TextRec.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/TextRec/TextRec.cc.o
.PHONY : TextRec/TextRec.cc.o

TextRec/TextRec.i: TextRec/TextRec.cc.i

.PHONY : TextRec/TextRec.i

# target to preprocess a source file
TextRec/TextRec.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/TextRec/TextRec.cc.i
.PHONY : TextRec/TextRec.cc.i

TextRec/TextRec.s: TextRec/TextRec.cc.s

.PHONY : TextRec/TextRec.s

# target to generate assembly for a file
TextRec/TextRec.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/TextRec/TextRec.cc.s
.PHONY : TextRec/TextRec.cc.s

booktest.o: booktest.cc.o

.PHONY : booktest.o

# target to build an object file
booktest.cc.o:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/booktest.cc.o
.PHONY : booktest.cc.o

booktest.i: booktest.cc.i

.PHONY : booktest.i

# target to preprocess a source file
booktest.cc.i:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/booktest.cc.i
.PHONY : booktest.cc.i

booktest.s: booktest.cc.s

.PHONY : booktest.s

# target to generate assembly for a file
booktest.cc.s:
	$(MAKE) -f CMakeFiles/Term-Project.dir/build.make CMakeFiles/Term-Project.dir/booktest.cc.s
.PHONY : booktest.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Term-Project"
	@echo "... Ensemble/Ensemble.o"
	@echo "... Ensemble/Ensemble.i"
	@echo "... Ensemble/Ensemble.s"
	@echo "... ImageRec/ImageRec.o"
	@echo "... ImageRec/ImageRec.i"
	@echo "... ImageRec/ImageRec.s"
	@echo "... ImageRec/histogram.o"
	@echo "... ImageRec/histogram.i"
	@echo "... ImageRec/histogram.s"
	@echo "... ImageRec/image2vec.o"
	@echo "... ImageRec/image2vec.i"
	@echo "... ImageRec/image2vec.s"
	@echo "... ImageRec/kmeans.o"
	@echo "... ImageRec/kmeans.i"
	@echo "... ImageRec/kmeans.s"
	@echo "... ItemRec.o"
	@echo "... ItemRec.i"
	@echo "... ItemRec.s"
	@echo "... Knn/Knn.o"
	@echo "... Knn/Knn.i"
	@echo "... Knn/Knn.s"
	@echo "... TagRec/TagRec.o"
	@echo "... TagRec/TagRec.i"
	@echo "... TagRec/TagRec.s"
	@echo "... TextRec/TextRec.o"
	@echo "... TextRec/TextRec.i"
	@echo "... TextRec/TextRec.s"
	@echo "... booktest.o"
	@echo "... booktest.i"
	@echo "... booktest.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
