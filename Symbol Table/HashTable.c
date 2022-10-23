#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int tableSize = 10;
char copyKey[100];


typedef struct _node
{
    char key[100];
    char value[100];
    struct _node *next;
} node;


typedef struct _carrierOfHeadLast
{
    node *head;
    node *last;
} carrierOfHeadLast;

carrierOfHeadLast *createNode()
{
    carrierOfHeadLast *newNode=(carrierOfHeadLast*)malloc(sizeof(carrierOfHeadLast));
    newNode->head=NULL;
    newNode->last=NULL;
    return newNode;
}
bool checkSimilarKey(carrierOfHeadLast *object)
{
    node *ptr=object->head;
    while(ptr != NULL)
    {
        if(strcmp(ptr->key, copyKey) == 0)
            return true;
        ptr=ptr->next;
    }
    if(ptr == NULL)
        return false;
}
void insert(carrierOfHeadLast *object, char key[], char value[])
{
    if(checkSimilarKey(object) == false)
    {
        node *newNode=(node*)malloc(sizeof(node));
        strcpy(newNode->key, key);
        strcpy(newNode->value, value);
        newNode->next=NULL;
        if(object->head==NULL)
        {
            object->head=newNode;
            object->last=newNode;
        }
        else
        {
            object->last->next=newNode;
            object->last=newNode;
        }
    }
    else
        printf("This key already exist! - %s\n\n", copyKey);
}
void show(carrierOfHeadLast **object)
{
    int i;
    for(i=0; i<tableSize; i++)
    {
        node *ptr=object[i]->head;
        printf("%d: ", i);
        while(ptr != NULL)
        {
            if(ptr->next == NULL)
                printf("(%s, %s)", ptr->key, ptr->value);
            else
                printf("(%s, %s) -> ", ptr->key, ptr->value);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("\n");
}
void showAllKeys(carrierOfHeadLast **object)
{
    int i;
    for(i=0; i<tableSize; i++)
    {
        node *ptr=object[i]->head;
        printf("%d: ", i);
        while(ptr != NULL)
        {
            if(ptr->next == NULL)
                printf("%s", ptr->key);
            else
                printf("%s, ", ptr->key);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("\n");
}
void showAllValues(carrierOfHeadLast **object)
{
    int i;
    for(i=0; i<tableSize; i++)
    {
        node *ptr=object[i]->head;
        printf("%d: ", i);
        while(ptr != NULL)
        {
            if(ptr->next == NULL)
                printf("%s", ptr->value);
            else
                printf("%s, ", ptr->value);
            ptr=ptr->next;
        }
        printf("\n");
    }
    printf("\n");
}
void delete_using_key(carrierOfHeadLast *object)
{
    node *pre = NULL;
    node *ptr=object->head;
    while(ptr != NULL)
    {
        if(strcmp(ptr->key, copyKey) == 0)
        {
            if(pre == NULL)
                object->head =ptr->next;
            else
                pre->next = ptr->next;
            break;
        }
        else
        {
            pre=ptr;
            ptr=ptr->next;
        }
    }
    if(ptr == NULL)
        printf("There is no value with this key - %s\n", copyKey);
}

void deleteAll(carrierOfHeadLast **object)
{
    int i;
    for(i=0; i<tableSize; i++)
    {
        object[i]->head = NULL;
        object[i]->last = NULL;
    }
}
void update_using_key(carrierOfHeadLast *object, char newValue[])
{
    node *ptr=object->head;
    while(ptr != NULL)
    {
        if(strcmp(ptr->key, copyKey) == 0)
        {
            strcpy(ptr->value, newValue);
            break;
        }
        else
            ptr=ptr->next;
    }
}

void search_by_key(carrierOfHeadLast *object)
{
    node *ptr=object->head;
    while(ptr != NULL)
    {
        if(strcmp(ptr->key, copyKey) == 0)
        {
            printf("%s -> %s\n", ptr->key, ptr->value);
            break;
        }
        else
            ptr=ptr->next;
    }
    if(ptr == NULL)
        printf("There is no value with this key - %s\n", copyKey);
}
int hashFunction(char key[])
{
    int i, add_ascii_value = 0, multiplier;
    strcpy(copyKey, key);
    for(i=0,multiplier = 2; i<strlen(key); i++, multiplier += 1)
        add_ascii_value = add_ascii_value + multiplier*key[i];
    return add_ascii_value%tableSize;
}
int main()
{
    int i, choice;
    char key[100], value[100], keyValue[100];

    carrierOfHeadLast *root[tableSize];
    for(i=0; i<10; i++)
        root[i]=createNode();

    while(true)
    {
        printf("1 - Insert\n");
        printf("2 - Show\n");
        printf("3 - Show All Keys\n");
        printf("4 - Show All Values\n");
        printf("5 - Delete Using Key\n");
        printf("6 - Delete All\n");
        printf("7 - Update Using Key\n");
        printf("8 - Search By Key\n");
        printf("9 - Get Hash Value of a Key\n");
        printf("10 - Exit\n");
        printf("\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");
        if(choice == 1)
        {
            printf("Enter Key: ");
            scanf("%s", key);
            printf("Enter Value: ");
            scanf("%s", value);
//            printf("Enter key, value: ");
//            gets(keyValue);
//
//
//
//            while (splitedValue != NULL)
//            {
//                printf("%s\n", token);
//                token = strtok(NULL, "-");
//            }

            printf("\n");
            insert(root[hashFunction(key)], key, value);
        }
        else if(choice == 2)
            show(root);
        else if(choice == 3)
            showAllKeys(root);
        else if(choice == 4)
            showAllValues(root);
        else if(choice == 5)
        {
            printf("Enter Key: ");
            scanf("%s", key);
            delete_using_key(root[hashFunction(key)]);
        }
        else if(choice == 6)
            deleteAll(root);
        else if(choice == 7)
        {
            printf("Enter Key: ");
            scanf("%s", key);
            printf("Enter Value: ");
            scanf("%s", value);
            update_using_key(root[hashFunction(key)], value);
        }
        else if(choice == 8)
        {
            printf("Enter Key: ");
            scanf("%s", key);
            search_by_key(root[hashFunction(key)]);
            printf("\n");
        }
        else if(choice == 9)
        {
            printf("Enter Key: ");
            scanf("%s", key);
            printf("Hash Value is: %d\n", hashFunction(key));
            printf("\n");
        }
        else if(choice == 10)
            break;
    }
    return 0;
}
