#!/usr/bin/python3
"""Script that lists all cities from
the database hbtn_0e_4_usa
"""
import MySQLdb
import sys

if __name__ == "__main__":
    USER = sys.argv[1]
    PASS = sys.argv[2]
    DB = sys.argv[3]

    db = MySQLdb.connect(
        host="localhost",
        port=3306,
        user=USER,
        passwd=PASS,
        db=DB
    )

    cursor = db.cursor()
    cursor.execute(
        "SELECT C.id, C.name, S.name \
                    FROM cities C, states S \
                    WHERE C.state_id = S.id \
                    ORDER BY C.id"
    )
    rows = cursor.fetchall()
    for row in rows:
        print(row)

    cursor.close()
    db.close()
