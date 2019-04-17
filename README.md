## Introduction

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
**NOTE:** How to create shared libraries and link shared libraries using GNU compiler:  
+ How to create shared libraries:  
g++ -fPIC <source.cpp files> -I<header directories> -shared -o lib<name_of_libraries>.so  
+ How to link shared libraries: Note that if shared libraries being compiled with g++, we should use g++ to compile for all, if NOT we will meet error: undefined reference to functions ...  
g++ -L<shared libraries directories> <source.c or source.cpp files> -o <binary name> -l<shared_libraries_name>  
export LD_LIBRARY_PATH=<Directory to shared libraries>:$LD_LIBRARY_PATH  

## How to add Google Protocol Buffer into Bazel and usage generated source files  
+ Add Google Protocol Buffer into bazel WORKSPACE:  
```
http_archive(
   name = "com_google_protobuf", //exactly this name that the Google Protocol Buffer want us to add into this field.  
   strip_prefix = "<prefix_which_can_be_removed>", //example: protobuf-3.6.0 or protobuf-3.8.0, ...  
   url = "https://github.com/google/protobuf/releases/download/v3.6.0/protobuf-cpp-3.6.0.tar.gz",//whatever versions that you want to use in your project.  
)  
```  
**NOTE:** The Google Protocol Buffer is made by bazel already(it means the Google Protocol Buffer uses BUILD files inside to build protoc or proto libraries using bazel already), so we won't use new_http_archive in WORKSPACE file and DO NOT need to add build_file label as we did for other open source (that are made by Makefile/CMake, NOT bazel). It also means that we DO NOT need to specify which source files will be built or not, we don't care it, the Google Protocol Buffer will do it for us.  
+ How to use protoc and other protobuf libraries to generate .proto files or using their headers or linking to shared libraries:  
just simple like this in the .proto file, looks like:  
```
package(default_visibility = ["//visibility:public"])

cc_proto_library(
	name = "v2x_proto",
	deps = [":v2x_proto_lib"]
	)

proto_library(
	name = "v2x_proto_lib",
	srcs = ["v2x.proto"]
	)

```
*We can see that we don't identify protoc or any protobuf libraries to compile and link for this .proto files, the bazel and Google Protocol Buffer hand shake together and the bazel knows how to generate them and link them if needed, so we won't care it too. Just do the .proto like above example, it should be fine.*  
+ How to use generated source file from the .proto files: Example that we create an example folder name test_gg_buffer with BUILD and test_gg_buffer.cc inside.  
**Change in BUILD file:**  
```
cc_test(
	name = "test_gg_buffer",
	srcs = ["test_gg_buffer.cc"],
	copts = [
		"-Iexternal/com_google_protobuf/src"
	],
	deps = [
		"//proto:v2x_proto" //example that v2x.proto is under the proto folder  
	]
	)
```
**NOTE:** we take care 2 options: copts and deps. The copts will show where header files for the Google Protocol Buffer and the deps will show where is v2x.pb.h file, it will support us to avoid error type: No such files or directories.... when we compile test_gg_buffer.cc file.  

**Change in test_gg_buffer.cc file:**  
```
#include "proto/v2x.pb.h"
```
Just simple like that.  
