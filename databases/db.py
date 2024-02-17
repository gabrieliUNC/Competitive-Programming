from datetime import datetime
from datetime import timedelta

class doc():
    def __init__(self):
        self.start = None
        self.end = None
        self.email = None
        self.pw = None

class database:

    def __init__(self):
        self.kvs = {}


    def post(self, time, user, email, pw):
        time = datetime.strptime(time)

        inp = doc()
        inp.start = time
        inp.end = time + timedelta(minutes = 10)
        inp.email = email
        inp.pw = pw

        self.kvs[user] = inp

    def get(self, user):
        inp = self.kvs[user]
        return inp
    

    def update(self, time, user, email, pw):
        self.post(time, user, email, pw)

    def rangeQuery(self, start, end):
        users = list()

        for user, inp in self.kvs.items():
            if inp.start >= start and inp.end <= end:
                users.append(user)

        return users