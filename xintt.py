#!/usr/bin/env python
'''
f/One DOS Extender internal tool for generating dispatch tables for extender
interrupt handlers. Instead of doing it by hand, especially for INT 21h DOS
functions, here is a simple tool that generates proper data based on user
input. Just redirect program output to file and you will have your table
and lables ready.

By default you can skip last parameter so your labels will have following
format: i[IntNumber]fx[FunctionNumber]h
'''
import os, sys


def help():
    print 'Usage: xintt [int_no] [start_number] [end_number] [<default_label>]'


def main():
    if len(sys.argv) != 4 and len(sys.argv) != 5:
        help()
    else:
        int_no = int(sys.argv[1],16)
        start_number = int(sys.argv[2], 16)
        end_number = int(sys.argv[3], 16)
        if len(sys.argv) == 5:
            default_label = '%s' % sys.argv[4]
        else:
            default_label = None

        if start_number >= end_number:
            print 'Wrong function numbers'
            sys.exit(1)

        print 'int%Xh_dispatch_table:' % int_no
        for i in range(start_number, end_number+1):
            if default_label:
                print '\tdw %s' % default_label
            else:
                print '\tdw i%Xfxn%02xh' % (int_no, i)

        print 'x_int%Xh:' % int_no
        if default_label:
                print '%s:' % default_label
        else:
            for i in range(start_number, end_number+1):
                print 'i%Xfxn%02xh:' % (int_no, i)
    sys.exit(0)

if __name__ == '__main__':
    main()
