#!/usr/bin/python3
"""Reads from standard input and computes metrics.
"""


def p_stats(size, status_codes):
    """"to print stats"""
    print("File size: {}".format(size))
    for k in sorted(status_codes):
        print("{}: {}".format(k, status_codes[k]))


def p_log():
    """print matrics"""
    import sys

    s = 0
    s_codes = {}
    v_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    c_t = 0

    try:
        for line in sys.stdin:
            if c_t != 10:
                c_t += 1
            else:
                p_stats(s, s_codes)
                c_t = 1

            line = line.split()

            try:
                s += int(line[-1])
            except (IndexError, ValueError):
                pass

            try:
                if line[-2] in v_codes:
                    if s_codes.get(line[-2], -1) != -1:
                        s_codes[line[-2]] += 1
                    else:
                        s_codes[line[-2]] = 1
            except IndexError:
                pass

        p_stats(s, s_codes)

    except KeyboardInterrupt:
        p_stats(s, s_codes)
        raise


if __name__ == "__main__":
    p_log()
