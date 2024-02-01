class Book:
    __id = int
    __title = str
    __author = None
    __genre = None
    __publication_date = None
    __bar_code = None
    __copies = None
    __rack_no = None
    def __init__(self, id, title=None, author=None, genre=None, publication_date=None, bar_code=None, copies=0, rack_no=None ) -> None:
        self.__id = id
        self.__title = title
        self.__author = author
        self.__genre = genre
        self.__publication_date = publication_date
        self.__bar_code = bar_code
        self.__copies = copies
        self.__rack_no = rack_no
    def getId(self):
        '''Return id of the book'''
        return self.__id
    def getDetails(self):
        '''return all the details regarding the book'''
        return self.__id, self.__title, self.__author,self.__genre, self.__publication_date, self.__bar_code, self.__copies, self.__rack_no
    def getNumberOfCopies(self):
        '''Return the number of copies of the book exists'''
        return self.__copies
    def setNumberOfCopies(self, copies):
        '''Set the copies of the particular book'''
        self.__copies = copies
        return self.__copies
    def getAuthor(self):
        '''Return the author of the book particularly'''
        return self.__author
    def getTitle(self):
        return self.__title
    def getGenre(self):
        return self.__genre

