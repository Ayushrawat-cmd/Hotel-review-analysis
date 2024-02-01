from LibraryManagement import LibraryManagement
from Book import Book
from Member import Member
from Librarian import Librarian
library = LibraryManagement()
librarian = Librarian(1 ,"rames", "dladlk ")
book1 = Book(1,"harry", "jk", "fantasy", 2, "123", 1, 1)
# book2 = Book(1,"harry", "jk", "fantasy", 2, "12345", 3, 2)
book2 = Book(2,"harry potter", "jk", "fantasy", 2, "12345", 3, 2)
library.addBook(book1)
library.addBook(book1, 1)
library.displayAllBooks()
library.removeBook(book1)
library.displayAllBooks()

books = library.search("jk")
# print(books)
for book in books:
    print(book.getDetails())
