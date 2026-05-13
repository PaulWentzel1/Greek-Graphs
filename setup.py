from setuptools import setup, Extension
from Cython.Build import cythonize

extension = Extension(
    name="wrapper",
    sources=["wrapper.pyx", "lib.c"],
    extra_compile_args=["-O3", "-march=native", "-ffast-math"]
)

setup(ext_modules=cythonize(extension))
