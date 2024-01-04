#!/usr/bin/python3
"""Module for Rectangle"""


class Rectangle:
    """Represent a rectangle."""

    number_of_instances = 0
    print_symbol = "#"

    def __init__(self, width=0, height=0):
        """Defines a new Rectangle.

        Args:
            width (int): The width of rectangle.
            height (int): The height of rectangle.
        """
        Rectangle.number_of_instances += 1
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
        return self.__width * self.__height

    def perimeter(self):
        """Return the perimeter"""
        if self.__width == 0 or self.__height == 0:
            return 0
        return (self.__width * 2) + (self.__height * 2)

    @staticmethod
    def bigger_or_equal(rect_1, rect_2):
        """Return the Rectangle with the greater area.
        TypeError: If either of rect_1 or rect_2 is not a Rectangle.
        """
        if not isinstance(rect_1, Rectangle):
            raise TypeError("rect_1 must be an instance of Rectangle")
        if not isinstance(rect_2, Rectangle):
            raise TypeError("rect_2 must be an instance of Rectangle")
        if rect_1.area() >= rect_2.area():
            return rect_1
        return rect_2

    def __str__(self):
        """Method to create a string of a rectangle"""
        if self.__height == 0 or self.__width == 0:
            return ""
        symbol = str(self.print_symbol)
        rectangle = ""
        for i in range(self.__height - 1):
            rectangle += symbol * self.__width + "\n"
        rectangle += symbol * self.__width
        return rectangle

    def __repr__(self):
        """return a string representation of the rectangle"""
        return "Rectangle({:d}, {:d})".format(self.__width, self.__height)

    def __del__(self):
        """Print a message for deletion"""
        print("Bye rectangle...")
        Rectangle.number_of_instances -= 1
