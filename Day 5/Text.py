class Text:
    __content = None
    def __init__(self, content ) -> None:
        self.__content = content
    def getContent(self):
        '''Get the content'''
        return self.__content