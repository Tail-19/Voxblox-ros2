from setuptools import find_packages
from setuptools import setup

setup(
    name='vpp_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('vpp_interfaces', 'vpp_interfaces.*')),
)
