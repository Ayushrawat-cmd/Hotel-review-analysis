class Message:
    '''Message is the class having get message method and set'''
    __id = None
    __content = None
    
    def __init__(self, id , content) -> None:
        self.__id = id
        self.__content =content

    def getMessage(self):
        return self.__content
    
    def setMessage(self):
        self.__content

    def getId(self):
        return self.__id