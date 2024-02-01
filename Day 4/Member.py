from User import User
from Book import Book
class Member(User):
    __reserve_books = None
    __issued_books = None
    __issued_books_date = None
    __max_checkout_books = int
    recieved_message = None
    def __init__(self, name,address, id  ):
        super().__init__(name, address, id)
        self.__issued_books = [Book]
        self.__reserve_books = [Book]
        self.__issued_books_date = []
        self.__max_checkout_books = 5
        self.recieved_message = []

    def checkOutBook(self, book : Book, date) -> bool:
        '''Checkout functionality for the user by adding certain validation in it'''
        for issued_book in range(len(self.__issued_books)):
            if self.__issued_books[issued_book].getId() == book.getId():
                self.__issued_books_date[issued_book] = date
                return True
        if(len(self.__issued_books) == self.__max_checkout_books ): #maximum books got issued
            return False
        self.__issued_books.append(book)
        self.__issued_books_date.append(date)
        return True

    def reserveBook(self, book : Book) -> None:
        '''Reserve the book by the user'''
        self.__reserve_books.append(book)
    
    def returnBook(self, book :Book)->bool:
        '''Return book to the system'''
        for issued_book in range(len(self.__issued_books)):
            if self.__issued_books[issued_book].getId() == book.getId():
                self.__issued_books.pop(issued_book)
                self.__issued_books_date.pop(issued_book)
                return True
        return False

    def getReserveBooks(self):
        return self.__reserve_books

    def displayeMessages(self):
        print(self.recieved_message)

        
    


