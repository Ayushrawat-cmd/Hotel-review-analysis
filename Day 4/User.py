class User():
    __id = None
    __name = None
    __address = None

    def __init__(self,  name, address, id) -> None:
        self.__name = name
        self.__address = address
        self.__id = id

    def showDetails(self):
        '''Return all the details having about the user'''
        return self.__name, self.__address
    
    def getId(self):
        return self.__id