from abc import abstractmethod, ABC
class Person(ABC):
    '''Base class for the User and person'''
    __name = None
    __age = None
    __gender = None
    # __id = None
    
    def __init__(self, name, age, gender) -> None:
        self.__name = name
        self.__age = age
        self.__gender = gender
        # self.__id = id

    # @abstractmethod
    def displayProfile(self):
        return self.__name, self.__age, self.__gender
    
    @abstractmethod
    def getID(self):
        pass