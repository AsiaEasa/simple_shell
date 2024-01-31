#!/usr/bin/python3
"""This script is the base"""

import uuid
from datetime import datetime


class BaseModel:
	"""Class BaseModel"""
		def __init__(self, *args, **kwargs):
			"""Constructor"""
				IOS = "%Y-%m-%dT%H:%M:%S.%f"
				if kwargs and kwargs != {}:
				for key in kwargs:
				if key == "created_at":
				self.__dict__["created_at"] = datetime.strptime(
						kwargs["created_at"], "%Y-%m-%dT%H:%M:%S.%f")
				elif key == "updated_at":
				self.__dict__["updated_at"] = datetime.strptime(
						kwargs["updated_at"], "%Y-%m-%dT%H:%M:%S.%f")
				else:
				self.__dict__[key] = kwargs[key]
				else:
	self.id = str(uuid.uuid4())
	self.created_at = datetime.now()
self.updated_at = datetime.now()

	def save(self):
	"""updates the public instance attribute updated_at with the current datetime"""
		self.updated_at = datetime.now()

		def to_dict(self):
	"""Returns a dictionary containing all keys/values of __dict__ of the instance"""
		dict_C = self.__dict__.copy()
		dict_C["created_at"] = self.created_at.isoformat()
		dict_C["updated_at"] = self.updated_at.isoformat()
		dict_C['__class__'] = self.__class__.__name__
		return dict_C

		def __str__(self):
			"""print() by use __str__ method"""
				Name = type(self).__name__
				return "[{}] ({}) {}".format(Name, self.id, self.__dict__)
