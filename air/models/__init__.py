#!/usr/bin/python3
"""To storage the instances"""

from models.engine.file_storage import FileStorage

classes = {'BaseModel': 'BaseModel', 'User': 'User'}
storage = FileStorage()
storage.reload()
