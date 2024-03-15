#!/usr/bin/python3
"""Module that lists all State objects"""
import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from relationship_state import State
from relationship_city import City

if __name__ == "__main__":
    username, password, database = sys.argv[1], sys.argv[2], sys.argv[3]

    engine = create_engine(
        f"mysql+mysqldb://{username}:{password}@localhost/{database}",
        pool_pre_ping=True,
    )
    Session = sessionmaker(bind=engine)
    session = Session()

    states = session.query(State).order_by(State.id).all()
    state_index = 0
    while state_index < len(states):
        state = states[state_index]
        print(f"{state.id}: {state.name}")
        city_index = 0
        while city_index < len(state.cities):
            city = state.cities[city_index]
            print(f"    {city.id}: {city.name}")
            city_index += 1
        state_index += 1
