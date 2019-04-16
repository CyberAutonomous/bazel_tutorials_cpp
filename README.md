This article shows how to use bazel for initializing C/C++ projects with features:  
+ Change default compiler from gcc into g++ by adding option: bazel build --action_env CC=/usr/bin/g++ <target>  
+ Compile and link source .c/.cpp directly at compile time  
+ How to link shared libraries that have been built outside bazel program.  
  **Note:**  
  - This step doesn't need options like: either -L or -l. Bydefault, the bazel understands which one is either shared libraries or static libraries.  
  - Add BUILD file inside folder that we need to use their libraries for other source code, the BUILD file looks like:  
  cc_library(  
  name = "example_lib_name",  
  srcs = ["lib_name.so"],  
  hdrs = ["where_are_header_files.h"],  
  visibility = ["//visibility:public"]  
  )  
  and as result, when we add the BUILD file looks like that, we can use their libraries at any where in our poject by using deps label in bazel like:  
  cc_binary(
  srcs = ...  
  hdrs = ...  
  deps = ["//where_is_folder_for_external_libraries:example_lib_name"]  
  )  
+ How to link shared libraries that are external libraries from internet, it means we build these libraries at the same time bazel program and link to them at the bazel time.  
NOTE: How to create shared libraries and link shared libraries using GNU compiler:  
+ How to create shared libraries:  
g++ -fPIC <source.cpp files> -I<header directories> -shared -o lib<name_of_libraries>.so  
+ How to link shared libraries: Note that if shared libraries being compiled with g++, we should use g++ to compile for all, if NOT we will meet error: undefined reference to functions ...  
g++ -L<shared libraries directories> <source.c or source.cpp files> -o <binary name> -l<shared_libraries_name>  
export LD_LIBRARY_PATH=<Directory to shared libraries>:$LD_LIBRARY_PATH  

