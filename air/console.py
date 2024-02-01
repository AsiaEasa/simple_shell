#!/usr/bin/python3
"""
Module Console interpreter
"""

import cmd
from models.base_model import BaseModel
import models
import shlex

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

    def do_show(self, arg):
        """Prints the string representation of an instance."""
        args = shlex.split(arg)
        if not args or len(args) < 1:
            print("** class name missing **")
        else:
            if args[0] not in HBNBCommand.classes:
                print("** class doesn't exist **")
            elif len(args) < 2:
                print("** instance id missing **")
            else:
                instance_key = "{}.{}".format(args[0], args[1])
                if instance_key in models.storage.all():
                    print(models.storage.all()[instance_key])
                else:
                    print("** no instance found **")
        return

if __name__ == '__main__':
    HBNBCommand().cmdloop()
