#!/usr/bin/python3
"""
Module Console interpreter
"""

import cmd
from models.base_model import BaseModel
import models

class HBNBCommand(cmd.Cmd):
    """Command interpreter class."""

    prompt = "(hbnb) "
    classes = {'BaseModel': BaseModel}

    def do_quit(self, arg):
        """Quit command to exit the program."""
        return True

    def do_EOF(self, arg):
        """Exit the program on EOF."""
        print()
        return True

    def emptyline(self):
        """Do nothing on empty line."""
        pass

    def do_create(self, arg):
        """Create a new instance of classes, save it, and print the id."""
        if not arg:
            print("** class name missing **")
        else:
            if arg not in HBNBCommand.classes:
                print("** class doesn't exist **")
            else:
                _class = self.classes.get(arg)
                New_instance = _class()
                models.storage.save()
                print(New_instance.id)

if __name__ == '__main__':
    HBNBCommand().cmdloop()
