from setuptools import setup
from mypyc.build import mypycify

setup(name='mypyc_output',
      ext_modules=mypycify(['mypyc_fib.py'], opt_level="3", debug_level="1"),
)
