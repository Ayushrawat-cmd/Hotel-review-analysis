from Text import Text
from Image import Image
class Status:
    __text = None
    __id = None
    __image = None

    def __init__(self,id, text:Text=None, image: Image = None) -> None:
        if text is not None:
            self.__text =text
        if image is not None:
            self.__image = image
        self.__id = id
    
    def getId(self):
        return self.__id
