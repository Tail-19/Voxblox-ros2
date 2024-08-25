# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vpp_interfaces:srv/PredictDepth.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PredictDepth_Request(type):
    """Metaclass of message 'PredictDepth_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vpp_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vpp_interfaces.srv.PredictDepth_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__predict_depth__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__predict_depth__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__predict_depth__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__predict_depth__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__predict_depth__request

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

            from vpp_interfaces.msg import Result
            if Result.__class__._TYPE_SUPPORT is None:
                Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PredictDepth_Request(metaclass=Metaclass_PredictDepth_Request):
    """Message class 'PredictDepth_Request'."""

    __slots__ = [
        '_image',
        '_result',
    ]

    _fields_and_field_types = {
        'image': 'sensor_msgs/Image',
        'result': 'vpp_interfaces/Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vpp_interfaces', 'msg'], 'Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.image = kwargs.get('image', Image())
        from vpp_interfaces.msg import Result
        self.result = kwargs.get('result', Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.image != other.image:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def image(self):
        """Message field 'image'."""
        return self._image

    @image.setter
    def image(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'image' field must be a sub message of type 'Image'"
        self._image = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from vpp_interfaces.msg import Result
            assert \
                isinstance(value, Result), \
                "The 'result' field must be a sub message of type 'Result'"
        self._result = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PredictDepth_Response(type):
    """Metaclass of message 'PredictDepth_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vpp_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vpp_interfaces.srv.PredictDepth_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__predict_depth__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__predict_depth__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__predict_depth__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__predict_depth__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__predict_depth__response

            from sensor_msgs.msg import PointCloud2
            if PointCloud2.__class__._TYPE_SUPPORT is None:
                PointCloud2.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PredictDepth_Response(metaclass=Metaclass_PredictDepth_Response):
    """Message class 'PredictDepth_Response'."""

    __slots__ = [
        '_object_segment',
    ]

    _fields_and_field_types = {
        'object_segment': 'sensor_msgs/PointCloud2',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'PointCloud2'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import PointCloud2
        self.object_segment = kwargs.get('object_segment', PointCloud2())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.object_segment != other.object_segment:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def object_segment(self):
        """Message field 'object_segment'."""
        return self._object_segment

    @object_segment.setter
    def object_segment(self, value):
        if __debug__:
            from sensor_msgs.msg import PointCloud2
            assert \
                isinstance(value, PointCloud2), \
                "The 'object_segment' field must be a sub message of type 'PointCloud2'"
        self._object_segment = value


class Metaclass_PredictDepth(type):
    """Metaclass of service 'PredictDepth'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vpp_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vpp_interfaces.srv.PredictDepth')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__predict_depth

            from vpp_interfaces.srv import _predict_depth
            if _predict_depth.Metaclass_PredictDepth_Request._TYPE_SUPPORT is None:
                _predict_depth.Metaclass_PredictDepth_Request.__import_type_support__()
            if _predict_depth.Metaclass_PredictDepth_Response._TYPE_SUPPORT is None:
                _predict_depth.Metaclass_PredictDepth_Response.__import_type_support__()


class PredictDepth(metaclass=Metaclass_PredictDepth):
    from vpp_interfaces.srv._predict_depth import PredictDepth_Request as Request
    from vpp_interfaces.srv._predict_depth import PredictDepth_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
