#!/usr/bin/python3
"""
Script that prints the State object from the database hbtn_0e_6_usa
"""
import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import Base, State

if __name__ == "__main__":
    if len(sys.argv) != 5:
        print("Usage: {} <mysql_username> <mysql_password> <database_name>"
              .format(sys.argv[0]))
        exit(1)

    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost:3306/{}".format(
            sys.argv[1], sys.argv[2], sys.argv[3]
        ),
        pool_pre_ping=True,
    )

    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()

    states = session.query(State).filter(State.name == sys.argv[4])
    if states.count() != 0:
        for state in states:
            print(state.id)
    else:
        print("Not found")

    session.close()
