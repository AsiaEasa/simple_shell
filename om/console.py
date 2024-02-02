#!/usr/bin/python3
"""
Module Console
"""

import cmd
from models.base_model import BaseModel
import sys
import models
import shlex

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

    def do_show(self, argument):
        """string representation based on the class name and id"""
        token = shlex.split(argument)
        if len(token) == 0:
            print("** class name missing **")
        elif len(token) == 1:
            print("** instance id missing **")
        elif token[0] not in self.classes:
            print("** class doesn't exist **")
        else:
            dic = models.storage.all()
            # Key has format <className>.id
            keyU = token[0] + '.' + str(token[1])
            if keyU in dic:
                print(dic[keyU])
            else:
                print("** no instance found **")
        return

    def do_destroy(self, argument):
        """Deletes an instance based on the class name and id"""
        tokens = shlex.split(argument)
        if len(tokens) == 0:
            print("** class name missing **")
            return
        elif len(tokens) == 1:
            print("** instance id missing **")
            return
        elif tokens[0] not in self.classes:
            print("** class doesn't exist **")
            return
        else:
            dic = models.storage.all()
            # Key has format <className>.id
            key = tokens[0] + '.' + tokens[1]
            if key in dic:
                del dic[key]
                models.storage.save()
            else:
                print("** no instance found **")

    def do_all(self, line):
        '''Usage: 1. all | 2. all <class name> | 3. <class name>.all()
Function: Prints the string representation of all instances
        '''
        instance_obj = storage.all()
        instance_list = []

        if line == "" or line is None:
            for key, value in storage.all().items():
                instance_list.append(str(value))
            print(instance_list)

        else:
            if line not in storage.classes():
                print("** class doesn't exist **")
                return
            else:
                for key, value in storage.all().items():
                    class_name, instance_id = key.split(".")
                    if line == class_name:
                        instance_list.append(str(value))
                print(instance_list)

    def do_update(self, argument):
        """Updates an instance based on the class name and id """
        token1 = shlex.split(argument)
        if len(token1) == 0:
            print("** class name missing **")
            return
        elif len(token1) == 1:
            print("** instance id missing **")
            return
        elif len(token1) == 2:
            print("** attribute name missing **")
            return
        elif len(token1) == 3:
            print("** value missing **")
            return
        elif token1[0] not in self.classes:
            print("** class doesn't exist **")
            return
        keyI = token1[0] + "." + token1[1]
        dicI = models.storage.all()
        try:
            instanceU = dicI[keyI]
        except KeyError:
            print("** no instance found **")
            return
        try:
            typeA = type(getattr(instanceU, token1[2]))
            token1[3] = typeA(token1[3])
        except AttributeError:
            pass
        setattr(instanceU, token1[2], token1[3])
        models.storage.save()


if __name__ == '__main__':
    """infinite loop"""
    HBNBCommand().cmdloop()
