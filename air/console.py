#!/usr/bin/python3
"""
Module Console interpreter
"""

import cmd
from models.base_model import BaseModel
from models.user import User
import models
import shlex
from models.state import State
from models.amenity import Amenity
from models.place import Place
from models.review import Review
from models.city import City


class HBNBCommand(cmd.Cmd):
    """Command interpreter class."""

    prompt = "(hbnb) "
    classes = {'BaseModel': BaseModel, 'User': User, 'State': State,
               'City': City, 'Amenity': Amenity,
               'Place': Place, 'Review': Review}

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

    def do_destroy(self, arg):
        """Deletes an instance based on the class name and id"""
        args = shlex.split(arg)
        if not args or len(args) < 1:
            print("** class name missing **")
            return
        else:
            if args[0] not in HBNBCommand.classes:
                print("** class doesn't exist **")
                return
            elif len(args) < 2:
                print("** instance id missing **")
                return
            else:
                instance_key = "{}.{}".format(args[0], args[1])
                if instance_key in models.storage.all():
                    del models.storage.all()[instance_key]
                    models.storage.save()
                else:
                    print("** no instance found **")

    def do_all(self, arg):
        """Prints string representation of all instances.
        """
        args = shlex.split(arg)
        if not args:
            all_instances = [str(V) for V in models.storage.all().values()]
            print(all_instances)
        elif args[0] not in HBNBCommand.classes:
            print("** class doesn't exist **")
        else:
            al_instances = [str(V) for K, V in models.storage.all().items()
                         if type(V).__name__ == args[0]]
            print(al_instances)

    def do_update(self, arg):
        """Updates an instance based on the class name and id.
        """
        args = shlex.split(arg)
        if not args:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.classes:
            print("** class doesn't exist **")
        elif len(args) < 2:
            print("** instance id missing **")
        else:
            instance_key = "{}.{}".format(args[0], args[1])
            if instance_key not in models.storage.all():
                print("** no instance found **")
            elif len(args) < 3:
                print("** attribute name missing **")
            elif len(args) < 4:
                print("** value missing **")
            else:
                obj = models.storage.all()[instance_key]
                try:
                    t = type(getattr(obj, args[2]))
                    args[3] = t(args[3])
                except AttributeError:
                    pass
                setattr(obj, args[2], args[3])
                models.storage.save()

if __name__ == '__main__':
    HBNBCommand().cmdloop()
