from distutils.core import setup, Extension
import numpy

def main():

    setup(name="kitsune",
          version="1.0.0",
          description="DSP in C",
          author="Clayton Seitz",
          author_email="cwseitz@uchicago.edu",
          ext_modules=[Extension("kitsune", ["kitsune.c"],
                       include_dirs = [numpy.get_include()],
                       library_dirs = ['/usr/lib/x86_64-linux-gnu'],
                       libraries=[])])


if __name__ == "__main__":
    main()
