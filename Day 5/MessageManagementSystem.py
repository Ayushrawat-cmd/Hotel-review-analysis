from Message import Message
class MessageManagementSystem:
    '''Class to manage messages'''
    __message = None
    def __init__(self) -> None:
        self.__message = {}
    
    def saveMessage(self, message:Message):
        '''Save message in management system'''
        self.__message[message.getId()] = message

    def readMessage(self, message:Message):
        '''Read message from the management system'''
        return self.__message[message.getId()]