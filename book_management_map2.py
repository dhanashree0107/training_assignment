bookDict = {}


def insertBook(key1, bookName, authorName, cost):
    bookDict[key1] = [bookName, authorName, cost]


def displayBook():
    print("ID \t Book Name \t AuthorName \t Cost")
    for x, y in bookDict.items():
        print(x, "\t", end="")
        for i in y:
            print(i, "\t", end="")
        print("")


def deleteBook(key):
    if key in bookDict:
        del bookDict[key]
        print("Successfully Deleted the Book with ID: ", key)
    else:
        print("There is no such Book with this ID!!!")


def searchBook(key):
    if key in bookDict:
        print("ID \t Book Name \t AuthorName \t Cost")
        print(
            key, "\t", bookDict[key][0], "\t", bookDict[key][1], "\t", bookDict[key][2]
        )
    else:
        print("There is no such Book with this ID!!!")


print("Book Management System")
i = 0
while i != 5:
    print("1. Insert")
    print("2. Delete")
    print("3. Search")
    print("4. Display")
    print("5. Quit")

    i = int(input("Enter your Choice: "))
    print("")

    if i == 1:
        key1 = int(input("Enter ID: "))
        if key1 not in bookDict:
            bookName = input("Enter Book Name: ")
            authorName = input("Enter Author Name: ")
            cost = float(input("Enter Cost: "))
            insertBook(key1, bookName, authorName, cost)
        else:
            print("Book Already exist with the given ID: ",key1)

    elif i == 2:
        key2 = int(input("Enter ID to Delete: "))
        deleteBook(key2)

    elif i == 3:
        key3 = int(input("Enter ID to Search: "))
        searchBook(key3)

    elif i == 4:
        displayBook()

    elif i == 5:
        pass
    else:
        print("Wrong Input")
