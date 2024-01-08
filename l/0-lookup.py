#!/usr/bin/python3
'''Module for lookup method.'''


def lookup(obj):
    '''Looks up object attributes and methods.
    Returns:
        list: the attributes.
    '''
    return dir(obj)
