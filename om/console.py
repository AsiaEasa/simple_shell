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

    def do_all(self, argument):
        """all string representation of all instances"""
        token_set = shlex.split(argument)
        lists = []
        dic = models.storage.all()
        # show all if no class is passed
        if len(token_set) == 0:
            for key in dic:
                rep_Class = str(dic[key])
                lists.append(rep_Class)
            print(lists)
            return

        if token_set[0] not in self.classes:
            print("** class doesn't exist **")
            return
        else:
            # Representation for a specific class
            rep_Class = ""
            for key in dic:
                className = key.split('.')
                if className[0] == token_set[0]:
                    rep_Class = str(dic[key])
                    lists.append(rep_Class)
            print(lists)

if __name__ == '__main__':
    """infinite loop"""
    HBNBCommand().cmdloop()
