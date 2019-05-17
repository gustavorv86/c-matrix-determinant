#!/usr/bin/env python3

import argparse
import random
import sys


def main():
    parser = argparse.ArgumentParser(description="Matrix generator") 
    parser.add_argument("-r", "--rows", type=int, required=True, help="number of rows")
    parser.add_argument("-c", "--cols", type=int, required=True, help="number of columns")
    parser.add_argument("-o", "--output", type=str, required=True, help="output file")
    
    args = parser.parse_args()

    if args.rows <= 0 or args.cols <= 0:
        print("ERROR: invalid arguments", file=sys.stderr)
        exit(1)

    try:
        fd = open(args.output, "w")
        
        fd.write(str(args.rows) + "\n")
        fd.write(str(args.cols) + "\n")

        for i in range(args.rows):
            for j in range(args.cols):
                ri = random.randint(-9, 9)
                fd.write(" " + str(ri) + " ")

            fd.write("\n")

    except Exception as ex:
        print("ERROR: cannot open \"{}\": {}".format(args.output, ex))


if __name__ == "__main__":
    main()

