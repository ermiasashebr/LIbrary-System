#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
	char Title[100];
	char Author[100];
	int Pages;
	struct Book *next;
};

struct Book *start = NULL;

void addBook(void);
void displayBook(void);
void searchBook(void);


void addBook(){
	struct Book *book1;
	book1 = malloc(sizeof(struct Book));
	if(book1 == NULL){
		printf("Can't add more books.\n");
		return;
	}
	printf("\nEnter the title of the book: ");
	scanf("%s",book1->Title);

	printf("Enter the Author of the book: ");
	scanf("%s",book1->Author);

	printf("Enter the number of pages of the book: ");
	scanf("%d",&book1->Pages);

	book1->next = start;
	start = book1;

}


void displayBook(){
	struct Book *temp1;
	if(start == NULL){
		printf("\nThere is no book in the library.\n");
	}else{
		printf("\nTitle   Author   Page Number\n");
		for (temp1 = start; temp1 != NULL; temp1 = temp1->next){
			printf("%s    %s    %d\n",temp1->Title, temp1->Author, temp1->Pages);
		}
	}
}


void searchBook(){
	char title[100];
 	struct Book *cur,*prev;
	printf("\nEnter the title of the book you want: ");
	scanf("%s",title);
	for(cur = start;cur!=NULL;cur = cur->next){
		if(strcmp(cur->Title,title)==0){
		printf("\nTitle: %s\n",cur->Title);
		printf("Author: %s\n",cur->Author);
		printf("Number of pages: %d\n",cur->Pages);
		return;
		}



	}
	printf("\nBook not found.\n");
}

int main(){
	printf("What service would you like.\n");
	int choice;
	for(;;){
		printf("1. Add a book\n");
		printf("2. Display a book\n");
		
		printf("3. Search a book\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				addBook();
				break;
			
			case 2:
				displayBook();
				break;
			case 3:
				searchBook();
				break;
			case 4:
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid input! Enter a valid input\n");
		}
		printf("\n");

	}
	return 0;
}
