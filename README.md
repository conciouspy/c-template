# A simple C project template using CMake and Litmus unit test framework.
This template can be used to create a simple C project with the following features:
- CMake build system
- Litmus unit test framework
- Basic folder structure for source code, headers, and tests
- Example source and test files
- Configurable project name
- Easy to extend with additional source and test files

## Usage
1. Copy the entire template folder to a new location.
2. Rename the folder to your desired project name.
3. Edit the `CMakeLists.txt` file to change the project name.
4. Edit the `base.h`, `main.c`, `lib.c`, and `dummy_tests.c` files to include your project name in the appropriate places.
5. Add your source code and test files to the `src` and `tests` folders, respectively.
6. In the project folder, create a `build` directory, and cd into it.
6. Run `cmake ..` to generate the build files.
7. Build the project using your preferred build system (e.g., Make, Ninja).
8. Run the tests using the generated test executable.

## Folder structure
```
<Project>
	.gitignore (file)
	CMakeLists.txt (file)
	Config.cmake.in (file)
	sourcelist.cmake (file)
	include (folder)
		<Project> (folder)
			base.h (file) # template file requires project name edit.
	src (folder)
		lib.c (file) # template file requires project name edit.
		main.c (file) # template file requires project name edit.
	tests (folder)
		litmus (folder)
			tests.h (file) # no edit required. Just include.
		src
			dummy_tests.c (file) # template file. Requires include edit.
			tests.c (file) # no edit required. Just include.
		CMakeLists.txt (file)
```

##  Project/CMakeLists.txt file
```
# change of project name
project(<Project name> C)

# all else seems fine.
```

## Files to be edited.
### base.h
- create `Project/include/Project` folder.
- copy `base.h` template file to it. 
- edit the `#infndef` and `#define` names in the `Project/include/Project/base.h`

### main.c and lib.c
- create `Project/src` folder.
- copy `main.c` and `lib.c` template files to it.
- edit the `#include "<Project>/base.h"` entries in both the files.

### Project/tests/src/dummy_tests.c
- copy `<Project\tests\litmus\tests.h>` file. **No Edits required in this one.**
- copy `<Project\tests\src\tests.c>` file.  **No Edits required in this one.**
- copy `<Project\tests\src\dummy_tests.c>` file.  **No Edits required in this one.**
- edit `<Project\tests\src\dummy_tests.c>` for `#include "<Project>\base.h"`

