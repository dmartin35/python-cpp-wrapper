import os
from setuptools import setup, Extension


demo_ext = Extension('demo',
   include_dirs=[os.path.join('lib', 'include')],
   libraries=['demo'],
   library_dirs=[os.path.join('lib', 'lib64')],
   sources=['_demo.c']
)


setup(
    name='demo-wrapper',
    description='Simple example of wrapping C/C++ for Python',
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Libraries',
        'Programming Language :: C',
        'Programming Language :: C++',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'License :: OSI Approved :: MIT License',
        ],
    platforms='unix',
    ext_package='',
    ext_modules=[demo_ext],
)

