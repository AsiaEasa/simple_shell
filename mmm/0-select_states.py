#!/usr/bin/python3
"""Script that lists all states from mySQL database"""
import sys
import MySQLdb


def ListStates(USER, PASS, DB):
    """Lists all states from the database hbtn_0e_0_usa."""
    db = MySQLdb.connect(
        host="localhost",
        port=3306,
        user=USER,
        passwd=PASS,
        db=DB
    )
    cursor = db.cursor()

    cursor.execute("SELECT * FROM states ORDER BY states.id")

    rows = cursor.fetchall()

    for row in rows:
        print(row)

    cursor.close()
    db.close()


if __name__ == "__main__":
    USER = sys.argv[1]
    PASS = sys.argv[2]
    DB = sys.argv[3]

    ListStates(USER, PASS, DB)
