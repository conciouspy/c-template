# core library souce set
# TEMPLATE: src/lib.c is a initial file. This will be created with a simple function defined in it.
set(main_lib_sources src/lib.c)

# core executable source set
# TEMPLATE: src/main.c is a initial file. This will be created with a simple main function defined in it.
set(main_exe_sources ${main_lib_sources} src/main.c)

# include files specifically
# TEMPLATE: include/cli-tools/base.h is a initial file. This will be created with a simple macro defined in it.
# TODO: Fix the project name to be programatically adjusted/ Driven out of a Variable name.
set(header_files 
	include/${PROJECT_NAME}/base.h
        )
