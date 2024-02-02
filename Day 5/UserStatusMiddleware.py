from User import User
from Status import Status
from StatusManagementSystem import StatusManagementSystem
from UserManagementSystem import UserManagementSystem
class UserStatusMiddleware:
    '''User and status middleware'''
    __upload_status_by_user = None

    def __init__(self, userManager : UserManagementSystem, statusManager: StatusManagementSystem) -> None:
        self.userManager = userManager
        self.statusManager = statusManager
        self.__upload_status_by_user = userManager.getAllUserIDs()

    def sendStatus(self, sender:User, status:Status):
        '''Upload the status'''
        if self.userManager.alreadyExist(sender):

            contacts = self.userManager.getAllContactsOfUser(sender)
            self.statusManager.addStatus(status)
            for contact in contacts:
                self.__upload_status_by_user[sender][contact.getID()].append(status) # send status to only those who are in the contacts of the sender
                

            
    
