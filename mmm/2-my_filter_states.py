#!/usr/bin/python3
"""Script that displays all values in the states table"""
import sys
import MySQLdb


def ListStates(USER, PASS, DB, SN):
    """Lists all states from the database hbtn_0e_0_usa."""
    db = MySQLdb.connect(
        host="localhost",
        port=3306,
        user=USER,
        passwd=PASS,
        db=DB
    )
    cursor = db.cursor()
    cursor.execute("SELECT * FROM states WHERE name = BINARY '{}' \
    ORDER BY states.id".format(SN))

    rows = cursor.fetchall()

    for row in rows:
        print(row)

    db.close()


if __name__ == "__main__":
    USER = sys.argv[1]
    PASS = sys.argv[2]
    DB = sys.argv[3]
    SN = sys.argv[4]

    ListStates(USER, PASS, DB, SN)
