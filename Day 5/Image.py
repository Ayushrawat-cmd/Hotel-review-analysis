class Image:
    __content = None
    def __init__(self, content) -> None:
        self.__content = content
    
    def getContent(self):
        return self.__content