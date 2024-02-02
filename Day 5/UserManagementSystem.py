from User import User
class UserManagementSystem:
    '''User management system manages the users in the system'''
    __users = None

    def __init__(self) -> None:
        self.__users = {}


    def alreadyExist(self, user:User):
        '''Is the user already exist in the system'''
        for userID in self.__users:
            if userID == user.getID():
                return True
        return False

    def addUser(self, new_user: User):
        '''Add the user in the system'''
        if(self.alreadyExist(new_user)):
            return False
        self.__users[new_user.getID] = new_user
    
    def deleteUser(self, old_user:User):
        '''delete the user from the system'''
        # if(self.alreadyExist(old_user)):
        self.__users = self.__users.pop(old_user.getID())
    
    def getAllUserIDs(self):
        '''GEt all the id of the user from system'''
        ids = {}
        for userID in self.__users:
            ids[userID] = {}
        return ids        
    
    def getAllContactsOfUser(self, user:User):
        '''get all the contact of particular user'''
        return self.__users[user.getID()].getContacts()
    
    