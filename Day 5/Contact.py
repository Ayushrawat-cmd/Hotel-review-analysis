from Person import Person
class Contact(Person):
    '''Contact is the person'''
    __id= None
    def __init__(self, id) -> None:
        self.__id = id
    def getID(self):
        return self.__id