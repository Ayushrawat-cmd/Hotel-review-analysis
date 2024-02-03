
class User:
    '''User is the base class for admin , hotel agent, normaluser/guest which having name ,age, phone,email, address, properties'''
    __id = None
    __name = None
    __age = None
    __email = None
    __phone = None
    __address = None
    def __init__(self, id:int , name:str, age:int, email: str,phone:int, address:str) -> None:
        self.__id = id
        self.__name = name
        self.__age = age
        self.__email = email
        self.__phone = phone
        self.__address = address
    
    def getDetails(self):
        return self.__id, self.__name, self.__age,self.__email, self.__phone, self.__address

    def getId(self):
        return self.__id
    
    def modifyDetails(self, name=None, age=None, email =None, phone=None, address=None):
        '''modify the details of the user'''
        if name is not None:
            self.__name = name
        if age is not None :
            self.__age = age
        if email is not None:
            self.__email = email
        if phone is not None:
            self.__phone = phone
        if address is not None:
            self.__address = address