C Matrix Determinant
====================

Program to calculate the matrix determinant.

What you need
-------------

Install the next software.

`sudo apt-get install git gcc make cmake`

Prepare build environment
-------------------------

Clone this repository.

`git clone https://github.com/gustavorv86/c-matrix-determinant`

Go to repository folder and type next commands:

```
cd c-matrix-determinant
mkdir build
cd build
```

Debug build
-----------

Type the next commands:

```
cmake ..
make
```

Release build
-------------

Type the next commands:

```
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

Run examples
------------

Into the **build** directory, run the next command:

`./dist/Debug/bin/matrix_determinant ../tests/matrix_01.txt`

For **Release** compilation, run the next command:

`./dist/Release/bin/matrix_determinant ../tests/matrix_01.txt`


Matrix random generator
-----------------------

Use the next command to generate random matrices:

`./matrix_rand.py -r 5 -c 5 -o tests/matrix_random.txt`

