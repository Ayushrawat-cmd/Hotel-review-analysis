from UserManagementSystem import UserManagementSystem
from MessageManagementSystem import MessageManagementSystem
from User import User
from Message import Message
class UserMessageMiddleware:
    '''User Message middleware basically helps in interaction with the User management system and Message management system'''
    __sent_messages_by_user = None
    __recieved_messages_by_user = None
    def __init__(self, userManager: UserManagementSystem, messageManager: MessageManagementSystem) -> None:
        self.userManager = userManager
        self.messageManager = messageManager
        self.__sent_messages_by_user = userManager.getAllUserIDs()
        self.__recieved_messages_by_user = userManager.getAllUserIDs()
    
    def sendMessage(self, sender:User, reciever:User,  message: Message):
        '''Send message to reciever by the sender'''
        if self.userManager.alreadyExist(sender) and self.userManager.alreadyExist(reciever):
            self.__sent_messages_by_user[sender.getID()][reciever.getID()].append(message.getId())
            self.__recieved_messages_by_user[reciever.getID()][sender.getID()].append(message.getId())
            self.messageManager.saveMessage(message)
            return True
        return False
    
    def readMessages(self, owner: User):
        '''Read all the messages which is sent by the user to someone else and which is sent to the user'''
        recieved_messages = {}
        sent_messages = {}
        if self.userManager.alreadyExist(owner):
            for user in self.__recieved_messages_by_user:
                if user == owner.getID():
                    for recievers in self.__recieved_messages_by_user[user]:
                        recieved_messages[recievers] = self.__recieved_messages_by_user[user][recievers]

            for user in self.__sent_messages_by_user:
                if user == owner.getID():
                    for senders in self.__sent_messages_by_user[user]:
                        sent_messages[senders] = self.__sent_messages_by_user[user][senders]
        return recieved_messages, senders



