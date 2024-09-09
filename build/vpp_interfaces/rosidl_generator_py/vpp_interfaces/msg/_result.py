# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vpp_interfaces:msg/Result.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'class_ids'
# Member 'scores'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Result(type):
    """Metaclass of message 'Result'."""

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
                'vpp_interfaces.msg.Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__result

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

            from sensor_msgs.msg import RegionOfInterest
            if RegionOfInterest.__class__._TYPE_SUPPORT is None:
                RegionOfInterest.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Result(metaclass=Metaclass_Result):
    """Message class 'Result'."""

    __slots__ = [
        '_header',
        '_class_ids',
        '_class_names',
        '_scores',
        '_boxes',
        '_masks',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'class_ids': 'sequence<int64>',
        'class_names': 'sequence<string>',
        'scores': 'sequence<float>',
        'boxes': 'sequence<sensor_msgs/RegionOfInterest>',
        'masks': 'sequence<sensor_msgs/Image>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int64')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'RegionOfInterest')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.class_ids = array.array('q', kwargs.get('class_ids', []))
        self.class_names = kwargs.get('class_names', [])
        self.scores = array.array('f', kwargs.get('scores', []))
        self.boxes = kwargs.get('boxes', [])
        self.masks = kwargs.get('masks', [])

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
        if self.header != other.header:
            return False
        if self.class_ids != other.class_ids:
            return False
        if self.class_names != other.class_names:
            return False
        if self.scores != other.scores:
            return False
        if self.boxes != other.boxes:
            return False
        if self.masks != other.masks:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def class_ids(self):
        """Message field 'class_ids'."""
        return self._class_ids

    @class_ids.setter
    def class_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'q', \
                "The 'class_ids' array.array() must have the type code of 'q'"
            self._class_ids = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -9223372036854775808 and val < 9223372036854775808 for val in value)), \
                "The 'class_ids' field must be a set or sequence and each value of type 'int' and each integer in [-9223372036854775808, 9223372036854775807]"
        self._class_ids = array.array('q', value)

    @builtins.property
    def class_names(self):
        """Message field 'class_names'."""
        return self._class_names

    @class_names.setter
    def class_names(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'class_names' field must be a set or sequence and each value of type 'str'"
        self._class_names = value

    @builtins.property
    def scores(self):
        """Message field 'scores'."""
        return self._scores

    @scores.setter
    def scores(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'scores' array.array() must have the type code of 'f'"
            self._scores = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'scores' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._scores = array.array('f', value)

    @builtins.property
    def boxes(self):
        """Message field 'boxes'."""
        return self._boxes

    @boxes.setter
    def boxes(self, value):
        if __debug__:
            from sensor_msgs.msg import RegionOfInterest
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, RegionOfInterest) for v in value) and
                 True), \
                "The 'boxes' field must be a set or sequence and each value of type 'RegionOfInterest'"
        self._boxes = value

    @builtins.property
    def masks(self):
        """Message field 'masks'."""
        return self._masks

    @masks.setter
    def masks(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Image) for v in value) and
                 True), \
                "The 'masks' field must be a set or sequence and each value of type 'Image'"
        self._masks = value
