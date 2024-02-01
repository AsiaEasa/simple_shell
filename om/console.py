#!/usr/bin/python3
"""
Module Console
"""

import cmd

class HBNBCommand(cmd.Cmd):
    """HBNB Class """
    prompt = '(hbnb) '
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
if __name__ == '__main__':
    """infinite loop"""
    HBNBCommand().cmdloop()
