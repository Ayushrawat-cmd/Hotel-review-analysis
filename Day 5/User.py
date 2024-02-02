from Person import Person
from Contact import Contact
from Status import Status
class User(Person):
    '''User is a person'''
    __contacts = None # User have contacts
    __id = None
    def __init__(self, id, name, age, gender, phone_number) -> None:
        super().__init__( name, age,gender,phone_number)
        self.__contacts = {}
        self.__id = id
    
    def addContact(self, contact: Contact):
        '''Add contact is user's contact list'''
        self.__contacts[contact.getID()] = contact
    
    def getContacts(self):
        '''Get all the contacts'''
        return self.__contacts
    
    def getID(self):
        return self.__id
    # def getDetails(self):
