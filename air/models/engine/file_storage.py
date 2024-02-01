#!/usr/bin/python3
"""Module for FileStorage class"""


import json
from models.base_model import BaseModel
import models
from models.user import User


class FileStorage():
    """A class to serializes instances to a JSON file and
    deserializes JSON file to instances"""

    #Private class attributes:
    __file_path = "file.json"
    __objects = {}

    def all(self):
        """returns the dictionary __objects"""
        return self.__objects

    def new(self, obj):
        """ sets in __objects the obj with key <obj class name>.id"""
        K = obj.__class__.__name__
        ID = obj.id
        self.__objects["{}.{}".format(K, ID)] = obj

    def save(self):
        """ serializes __objects to the JSON file (path: __file_path)"""
        New = {K: V.to_dict() for K, V in self.__objects.items()}

        with open(self.__file_path, 'w')as fi_1:
            json.dump(New, fi_1)

    def reload(self):
        """ deserializes the JSON file to __objects (only if the JSON file
        (__file_path) exists ; otherwise, do nothing. If the file doesn’t
        exist, no exception should be raised)"""
        try:
            with open(self.__file_path, 'r', encoding="UTF8") as fi_2:
                LOAD = json.load(fi_2)
                for K, V in LOAD.items():
                    classname = eval(V["__class__"])(**V)
                    self.__objects[K] = classname
        except FileNotFoundError:
            pass
