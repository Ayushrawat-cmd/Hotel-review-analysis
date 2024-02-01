from LibraryManagement import LibraryManagement
from Member import Member
class UserManagementSystem(LibraryManagement):
    def __init__(self) -> None:
        pass

    def addMember(self, new_member: Member):
        '''Add member in the system'''
        for member in super().members:
            if member.getId() == new_member.getId():
                return False
        
        super().members.append(new_member)
        return True
    
    def displayAllMember(self):
        '''Display all the members present in the system'''
        for member in super().members:
            print(member.showDetails())