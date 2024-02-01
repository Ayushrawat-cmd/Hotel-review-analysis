from LibraryManagement import LibraryManagement
from User import User
from Member import Member

class Librarian(User):
    '''Inherits the properties and methods of the user and also have the system to do certain operations on it'''
    library = None
    def __init__(self,id, name, address) -> None:
        super().__init__(id, name, address)
        self.library = LibraryManagement()

    def addMember(self, new_member: Member):
        '''Add member in the system'''
        for member in self.library.members:
            if member.getId() == new_member.getId():
                return False
        
        self.library.members.append(new_member)
        return True
    
    def displayAllMember(self):
        '''Display all the members present in the system'''
        for member in self.library.members:
            print(member.showDetails())
