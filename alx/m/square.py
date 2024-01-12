#!/usr/bin/python3
'''Square class.'''
from models.rectangle import Rectangle


class Square(Rectangle):
    ''' Inside Square class.'''

    def __init__(self, size, x=0, y=0, id=None):
        '''The constructor.'''
        super().__init__(size, size, x, y, id)

    @property
    def size(self):
        '''Size of this square.'''
        return (self.width)

    @size.setter
    def size(self, value):
        self.width = value
        self.height = value

    def __str__(self):
        '''Returns string info.'''
        return '[Square] ({}) {}/{} - {}'.\
            format(self.id, self.x, self.y, self.width)

    def __update(self, id=None, size=None, x=None, y=None):
        '''Updates instance attributes via */**args.'''
        if id is not None:
            self.id = id
        if size is not None:
            self.size = size
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
        return ({"id": self.id, "size": self.width,
                "x": self.x, "y": self.y})
