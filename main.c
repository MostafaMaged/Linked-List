#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
}Node;


Node *head = NULL;

void InsertAtBeginning(int);
void InsertAtNthPosition(int data, int n);
void DeleteAtNthPosition(int n);
int getListLength();
void Print();
void ReverseList();
void PrintRecursively(Node*);
void ReverseListRecursively(Node *current, Node *prev);

int main()
{
    int choice = 0;
    int x = 0;
    int postition = 0;

    while(1){

        printf("Choose what u want to do :\n");
        printf("1.Insert number at beginning\n");
        printf("2.Insert number at nth position\n");
        printf("3.Delete number at nth position\n");
        printf("4.Print list numbers\n");
        printf("5.Reverse the list\n");
        printf("6.Print Reversely\n");
        printf("7.Reverse tne list recursively.\n");
        printf("9.Exit\n");
        printf("your choice: ");
        scanf("%d", &choice);

        if(choice != 9){
            switch(choice) {

                case 1:
                    printf("Enter your number : ");
                    scanf("%d", &x);
                    InsertAtBeginning(x);
                    break;

                case 2:
                    printf("Enter your number : ");
                    scanf("%d", &x);

                    do{
                    printf("Enter position > 1 : ");
                    scanf("%d", &postition);
                    }while(postition <= 0);
                    if(postition == 1 && head == NULL){
                        InsertAtBeginning(x);
                        break;
                    }
                    InsertAtNthPosition(x, postition);
                    break;

                case 3:
                    do{
                    printf("Enter position >= 1 : ");
                    scanf("%d", &postition);
                    }while(postition <= 0);
                    DeleteAtNthPosition(postition);
                    break;

                case 4:
                    PrintRecursively(head);
                    break;

                case 5:
                    ReverseList();
                    break;

                case 6:
                    PrintRecursivelyReversed();
                    break;

                case 7:
                    ReverseListRecursively(head, NULL);
                    break;

                default:
                    printf("You Entered invalid number.\n");
            }
        }
        else{
            break;
        }
    }
    return 0;
}

void InsertAtBeginning(int x){

    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    if(head == NULL){
        temp->next = NULL;
    }
    else{
        temp->next = head;
    }
    head = temp;
}

void InsertAtNthPosition(int dataNew, int n){

    if(n > getListLength() + 1){
        printf("This position doesn't exist as the list length is %d\n", getListLength());
        return;
    }
    Node *temp = head;
    int i = 1;
    for(i = 1; i < n - 1; i++){
        temp = temp->next;
    }
    Node *forward = temp->next;
    Node *newData = malloc(sizeof(Node));
    newData->data = dataNew;
    temp->next = newData;
    newData->next = forward;
}

void DeleteAtNthPosition(int n){

    if(n > getListLength() + 1){
        if(head == NULL){
            printf("List Is Already Empty.\n");
        }
        else{
        printf("This position doesn't exist as the list length is %d\n", getListLength());
        }
        return;
    }
    Node *temp = head;
    if(n == 1){
        head  = head->next;
        free(temp);
    }
    int i = 0;
    for(i = 1; i < n - 1; i++){
        temp = temp->next;
    }
    Node *forward = temp->next;
    temp->next = forward->next;
    free(forward);
}

void ReverseList(){

    if(head == NULL){
        printf("List Is Empty.");
    }
    else if(getListLength() == 1){
        return;
    }

    Node *prev, *current, *next;
    prev = NULL;
    current = head;
    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void ReverseListRecursively(Node *current, Node *prev){

    if(current == NULL){
        head = prev;
        return;
    }
    ReverseListRecursively(current->next, current);
    current->next = prev;
}

int getListLength(){

    if(head == NULL){
        return 0;
    }
    int counter = 0;
    Node *temp = head;
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    return counter;
}

void Print(){

    if(head == NULL){
        printf("List Is Empty.\n");
        return;
    }
    Node *temp = head;
    printf("List Items :\n");
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void PrintRecursively(Node* temp){
    if(temp == NULL){
        printf("\n");
        return;
    }
    printf("%d\t", temp->data);
    PrintRecursively(temp->next);

}

void PrintRecursivelyReversed(Node* temp){
    if(temp == NULL) return;
    PrintRecursively(temp->next);
    printf("%d\t", temp->data);
}

