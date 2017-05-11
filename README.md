# python-cpp-wrapper
Simple example for wrapping C/C++ for python.
This project is based on official python documentation:
https://docs.python.org/3.6/extending/extending.html

Build the wrapper
-----------------

The wrapper needs to be build with linked library before being importable into some python code

```shell
python setup.py build_ext --inplace
```


Run the test suite
------------------

Simply executes:

```shell
python test.py
```
