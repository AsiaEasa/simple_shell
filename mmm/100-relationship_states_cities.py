#!/usr/bin/python3
"""
Script that adds the State object “Louisiana” to the database hbtn_0e_6_usa
"""
import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import Base, State
from relationship_city import City

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: {} <mysql_username> <mysql_password> <database_name>"
              .format(argv[0]))
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

    N_state = State(name="California")
    N_city = City(name='San Francisco')
    N_state.cities.append(N_city)

    session.add(N_state)
    session.add(N_city)
    session.commit()

    session.close()
