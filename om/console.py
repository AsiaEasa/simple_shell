#!/usr/bin/python3
"""
Module Console
"""

import cmd
from models.base_model import BaseModel
import sys
import models

class HBNBCommand(cmd.Cmd):
    """HBNB Class """
    prompt = '(hbnb) '
    classes = {'BaseModel': BaseModel}

    def do_quit(self, argument):
        """Defines quit option"""
        return True

    def do_EOF(self, argument):
        """ Defines EOF option"""
        print()
        return True

    def emptyline(self):
        """ Defines Empty option"""
        pass

    def do_create(self, argument):
        """Creates an instance of BaseModel"""
        if argument:
            if argument in self.classes:
                get_class = getattr(sys.modules[__name__], argument)
                instance = get_class()
                print(instance.id)
                models.storage.save()
            else:
                print("** class doesn't exist **")
        else:
            print("** class name missing **")
        return

if __name__ == '__main__':
    """infinite loop"""
    HBNBCommand().cmdloop()
