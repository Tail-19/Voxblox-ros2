from setuptools import find_packages, setup

package_name = 'mask_rcnn_ros2'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='alpha',
    maintainer_email='alpha@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    # tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "mask_rcnn = mask_rcnn_ros2.mask_rcnn_ros2_node:main",
            "predictor = mask_rcnn_ros2.predictor",
        ],
    },
)
