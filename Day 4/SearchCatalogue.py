# from LibraryManagement import LibraryManagement
# from Book import Book
class SearchCatalogue():
    # book = None
    def __init__(self) -> None:
        pass
    def searchByAuthor(self, author, library):
        books = []
        # print(author)
        for book in library.all_books:
            # print(book.getAuthor())
            if book.getAuthor() == author:
                books.append(book.getId())
        # print(books)
        return books
    def searchByGenre(self, genre, library):
        books = []
        for book in library.all_books:
            if book.getGenre() == genre:
                books.append(book.getId())
        return books
    def searchByTitle(self,title, library) :
        books = []
        for book in library.all_books:
            if book.getTitle() == title:
                books.append(book.getId())
        return books
    
        
        