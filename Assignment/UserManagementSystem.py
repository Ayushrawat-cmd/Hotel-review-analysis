from User import User
class UserManagementSystem:
    '''user management system basically do the operation related the user like adding the user in the system etc.'''
    __users = None

    def __init__(self) -> None:
        self.__users = {}
    
    def addUser(self, new_user:User):
        '''add the user in the system'''
        if self.__users.get(new_user.getId()):
            return False
        self.__users[new_user.getId()] = new_user
        return True
    
    def displayDetailsOfAllUsers(self):
        '''display the details of all users'''
        details = []
        for user in self.__users:
            details.append(self.__users[user].getDetails())
        return details
    
    def deleteUser(self, old_user:User):
        '''delete the user from the system'''
        if self.__users.get(old_user.getId()):
            self.__users.pop(old_user.getId())
            return True
        return False
    
    def checkedIn(self, user:User):
        '''User has occupy the room'''
        self.__users[user.getId()].occupyRoom()
    
    def isUserAvailaible(self, user:User):
        return user.getId() in self.__users

        