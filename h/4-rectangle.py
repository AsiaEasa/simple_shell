#!/usr/bin/python3
"""Module for Rectangle"""


class Rectangle:
    """Represent a rectangle."""

    def __init__(self, width=0, height=0):
        """Defines a new Rectangle.

        Args:
            width (int): The width of rectangle.
            height (int): The height of rectangle.
        """
        self.width = width
        self.height = height

    @property
    def width(self):
        """Get/set the width of the rectangle."""
        return self.__width

    @width.setter
    def width(self, value):
        if not isinstance(value, int):
            raise TypeError("width must be an integer")
        if value < 0:
            raise ValueError("width must be >= 0")
        self.__width = value

    @property
    def height(self):
        """Get/set the height of the rectangle."""
        return self.__height

    @height.setter
    def height(self, value):
        if not isinstance(value, int):
            raise TypeError("height must be an integer")
        if value < 0:
            raise ValueError("height must be >= 0")
        self.__height = value

    def area(self):
        """Return the"""
        return (self.__width * self.__height)

    def perimeter(self):
        """Return the perimeter"""
        if self.__width == 0 or self.__height == 0:
            return (0)
        return ((self.__width * 2) + (self.__height * 2))

    def __str__(self):
        """Method to create a string of a rectangle"""
        rectangle_str = ""
        if self.__width != 0 and self.__height != 0:
            rectangle_str += "\n".join(
                    "#" * self.__width for _ in range(self.__height))
        return rectangle_str

    def __repr__(self):
        """return a string representation of the rectangle"""
        return "Rectangle({:d}, {:d})".format(self.__width, self.__height)
