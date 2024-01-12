#!/usr/bin/python3
'''Rectangle class.'''
from models.base import Base


class Rectangle(Base):
    '''Inside Rectangle class.'''

    def __init__(self, width, height, x=0, y=0, id=None):
        '''The Constructor.'''
        super().__init__(id)
        self.width = width
        self.height = height
        self.x = x
        self.y = y

    @property
    def width(self):
        '''Rectangle width.'''
        return (self.__width)

    @width.setter
    def width(self, value):
        self.val_int("width", value, False)
        self.__width = value

    @property
    def height(self):
        '''Rectangle height.'''
        return (self.__height)

    @height.setter
    def height(self, value):
        self.val_int("height", value, False)
        self.__height = value

    @property
    def x(self):
        '''x in rectangle.'''
        return (self.__x)

    @x.setter
    def x(self, value):
        self.val_int("x", value)
        self.__x = value

    @property
    def y(self):
        '''y in rectangle.'''
        return (self.__y)

    @y.setter
    def y(self, value):
        self.val_int("y", value)
        self.__y = value

    def val_int(self, name, value, check=True):
        '''Validating value in rectangle.'''
        if not isinstance(value, int):
            raise TypeError("{} must be an integer".format(name))
        if check and value < 0:
            raise ValueError("{} must be >= 0".format(name))
        elif not check and value <= 0:
            raise ValueError("{} must be > 0".format(name))

    def area(self):
        '''Area of this rectangle.'''
        return (self.width * self.height)

    def display(self):
        '''Prints string representation.'''
        m = '\n' * self.y + \
            (' ' * self.x + '#' * self.width + '\n') * self.height
        print(m, end='')

    def __str__(self):
        '''Returns string info.'''
        return '[Rectangle] ({}) {}/{} - {}/{}'.\
            format(self.id, self.x, self.y, self.width,
                   self.height)

    def __update(self, id=None, width=None, height=None, x=None, y=None):
        '''Updates instance attributes via */**args.'''
        if id is not None:
            self.id = id
        if width is not None:
            self.width = width
        if height is not None:
            self.height = height
        if x is not None:
            self.x = x
        if y is not None:
            self.y = y

    def update(self, *args, **kwargs):
        '''Updates instance attributes no-keyword & keyword args.'''
        if args:
            self.__update(*args)
        elif kwargs:
            self.__update(**kwargs)

    def to_dictionary(self):
        '''Returns dictionary.'''
        return ({"id": self.id, "width": self.__width, "height": self.__height,
                "x": self.__x, "y": self.__y})
