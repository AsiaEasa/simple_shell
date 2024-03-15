#!/usr/bin/python3
"""
Script that deletes all State objects
"""
import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import Base, State

if __name__ == "__main__":
    engine = create_engine(
        "mysql+mysqldb://{}:{}@localhost:3306/{}".format(
            sys.argv[1], sys.argv[2], sys.argv[3]
        ),
        pool_pre_ping=True,
    )

    Base.metadata.create_all(engine)
    Session = sessionmaker(bind=engine)
    session = Session()
    states_a = session.query(State).filter(State.name.like("%a%"))
    if states_a.count():
        for state in states_a:
            session.delete(state)
        session.commit()
    session.close()
