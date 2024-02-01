from Book import Book
from SearchCatalogue import SearchCatalogue
from Member import Member

class LibraryManagement:
    '''
    Library managment class will have all the methods to do certain operations in our management system
    It will have the search catalogue, members and all the books in system
    '''

    all_books = None 
    __search_catalogue = None
    members  = None

    def __init__(self) -> None:
        self.all_books =[] # it will hold all the Books 
        self.__search_catalogue = SearchCatalogue() 
        self.members = [Member]
    

    def addBook(self, new_book:Book, num_of_copies=0):
        '''
        Add book in the system whenever new book's object is created
        '''
        found = 0
        
        for book in range(len(self.all_books)):
            if self.all_books[book].getId() == new_book.getId():

                found = 1
                self.all_books[book].setNumberOfCopies(self.all_books[book].getNumberOfCopies()+ num_of_copies+new_book.getNumberOfCopies())
        if found == 0:
            new_book.setNumberOfCopies(num_of_copies+new_book.getNumberOfCopies())
            self.all_books.append(new_book)
        return True
    
    def removeBook(self, delete_book:Book):
        '''
        Remove the book from the system
        '''
        found = 0
        for book in range(len(self.all_books)):
            if self.all_books[book].getId() == delete_book.getId():
                found = 1
                print(self.all_books[book].getId(), delete_book.getId(), self.all_books[book].getNumberOfCopies())
                self.all_books[book].setNumberOfCopies(self.all_books[book].getNumberOfCopies()-1)
                print(self.all_books[book].getId(), delete_book.getId(), self.all_books[book].getNumberOfCopies())
        if found == 0:
            return False
        return True
    
    def search(self, author=None, title=None, genre=None):
        '''Search the book in the catalogue class that wehther the book of particular filter is present or not in the system'''
        books = []
        if author is not None:
            books += self.__search_catalogue.searchByAuthor(author=author,library=self)
        if title is not None:
            books += self.__search_catalogue.searchByTitle(title=title, library=self)
        if genre is not None:
            books += self.__search_catalogue.searchByGenre(genre=genre, library=self)
        # Taking the union of all the books present in the system
        book_objects = []
        for book in range(len(self.all_books)):
            if self.all_books[book].getId() in books:
                book_objects.append(self.all_books[book])
        return book_objects
    
    def isBookAvailaible(self, find_book: Book):
        '''Is the particular book availaible in the system or not'''
        for book in range(len(self.all_books)):
            if self.all_books[book].getId() == find_book.getId() and self.all_books[book].getNumberOfCopies() >=1 :
                return True
        return False

    def issueBook(self, book:Book, member_for_issue: Member, date):
        '''Issue the book for the particular member in the system'''
        if self.isBookAvailaible(Book): # is the book availaible or not
            if self.removeBook(book): #remove the book from the system
                for member in range(len(self.members)):
                    if self.members[member].getId() == member_for_issue:
                        self.members[member].checkOutBook(book, date)
                        return True
            
        return False
    
    def reserveBooks(self, book_to_reserve: Book, member_for_reserve:Member): 
        '''Reserve the book for particular member if the book is not availaible'''
        for book in range(len(self.all_books)):
            if self.all_books[book].getId() == book_to_reserve.getId() and self.all_books[book].getNumberOfCopies() == 0:
                for member in range(len(self.members)):
                    if self.members[member].getId() == member_for_reserve.getId():
                        self.members[member].reserveBook(book_to_reserve)
                        return True
        return False
    
    def returnBooks(self, book_to_return :Book, member_for_return:Member):
        '''Return the book by the member to the system'''
        for member in range(len(self.members)):
            if self.members[member].getId() == member_for_return.getId():
                for book in range(len(self.all_books)):
                    if self.all_books[book].getId() == book_to_return.getId():
                        if member_for_return.returnBook(book_to_return):
                            self.all_books[book].setNumberOfCopies(book, 1)
                            return True
        return False
    
    def reIssueBook(self, book_to_reissue:Book, member_for_reissue:Member, date):
        '''Re issue the book to extend the time period by which person can hold the book'''
        for member in range(len(self.member_for_reissue)):
            if member_for_reissue.getId() == self.members[member].getId():
                for book in range(len(self.all_books)):
                    if self.all_books[book].getId() == book_to_reissue.getId():
                        return self.members[member].checkOutBook(book_to_reissue, date)
        return False
    
    def displayAllBooks(self):
        '''Display all the books'''
        for book in self.all_books:
            print(Book.getDetails(book))

    def notifyBookAvailaible(self, reserveBook:Book, message ):
        '''Notify all the users who reserve the book when the book is availaible in the system'''
        for book in range(len(self.all_books)):
            if self.all_books[book].getId() == reserveBook.getId() and self.all_books[book].getNumberOfCopies() == 0:
                return False
        for member in self.members:
            for book in member.getReserveBooks():
                if reserveBook.getId() == book.getId() and self.all_books:
                    member.recieved_message.append(message)
    
    
    

    
                