#! /bin/python

class Error(Exception):
    def __init__(self, expr, msg):
        self.expr = expr
        self.msg = msg
    def __str__(self):
        return self.expr + "-" + self.msg;

try :
    a=b; #raise NameError("toto", "tata");
except Exception as e:
    print("goto exception " + str(type(e)) + ": " + str(e));
