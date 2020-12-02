									Automobile Inventory Management System

	This inventory management system, is used to maintain an automobile store. The management system has a record of all the raw materials present. The management system makes necessary changes when a raw material is bought or sold or lost.

To open the management system use the command --- “make all” and to execute this use ./main command.

	That welcomes you to the automobile inventory management system.
Select the desired number from the main menu to perform the respective action on the automobile database.
Contents of the folder
    • view.c , search.c , sorting_price.c ,warranty.c , quantity.c , add.c , delete.c , modify.c and contains a main function (main.c) in which the above mentioned functions are called. 
    • Each (.c) file have respective (.h)files which contains respective prototypes of the functions.
Contents of the files
    1. view.c – Contains a function to view all the raw materials in the database.
    2. search.c – Contains a function to search a particular raw material in the database.
    3. sorting_price.c - Contains a function to view the items with prices of the specified product in sorted order or in a given range.
    4. warranty.c – Contains a function to display the products with warranty less than or greater than or equal to given value or in a given range.
    5. quantity.c – Contains a function to view the raw materials which are less than the given quantity.
    6. add.c – Contains a function to add a new raw material to the existing database.
    7. delete.c – Contains a function to remove a raw material or raw materials with particular warranty from the given database.
    8. modify.c – Contains a function to modify the details of a particular raw material in the database.


    • Real life situations which actually happen :-
	A manager might want to see all the raw materials so he uses view (1) to do so. If the owner wants to sell a raw material, he first checks the amount of raw material left with him, he fixes the price to make profit etc. So, he has to get all information about a particular product, so he uses search (2). Sometimes some buyers wants to buy products by seeing their price and sometimes warranty. So   buyer wants to compare the products by their prices and warranty. Seller can give this information to buyers by using sorting_price method(3) and warranty method(4). Once he sells the whole raw material to someone, he doesn’t have it anymore. So, to remove it from the database he uses the delete (7). The owner checks which all raw materials are on the verge of completion and places a new order for those raw materials. To do so he uses the function quantity(5). Along with these raw materials the owner has purchased a new material which was recently launched in the market. To add a new raw material to the database he uses add (6). If the owner finds that few raw materials with particular warranty have expired he has to remove them from the database. To do that he uses delete (7). If the owner has bought a raw material which already exists in the database its quantity should be increased in the database or according to it the price should be modified. This can be done using modify (8). It is also useful when a product is sold , so its quantity decreases , it should be modified.




TEAM MEMBERS:

    • G Sri Harsha 
	IMT2019030

    • Anumolu Tarun Kumar
	IMT2019011

    • D V N P S M Manohar Suggula
	IMT2019025

    • Samhitha Perala
	IMT2019521

    • Channamsetty Sivani
	IMT2019020

    • Chinthakunta Amitha Reddy
	IMT2019023



												THANK YOU



