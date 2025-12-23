#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// Linked List Implementation
typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node;

// implementation functions
Node *createNode(int val);
Node *addToList(Node *head, int val);
Node *readList();
void printList(Node *head);
void freeList(Node *head);

// solution functions
int findMedian(Node *head);
Node *mergeLists(Node *head1, Node *head2);
Node *getMedianNode(Node *head);
Node *sortList(Node *head);
Node *reverseList(Node *head);
int isPalindrome(Node *head);
Node *rearrangeList(Node *head);
Node *removeRepeatedNodes(Node *head); // did not free memory
Node *removeSlide(Node *head, int k);

// struct for problem I

typedef struct Student_t
{
    char email[1000];
    char branch[1000];
    char id[1000];
} Student;

void generateId(Student *s);
bool compareStrings(char *one, char *two, int n);

// struct for problem J

typedef struct Country_t
{
    char name[1000];
    int gold;
    int silver;
    int bronze;
} Country;

bool compareCountries(Country *c1, Country *c2);
void sortCountriesArray(Country *countries, int n);
void swapCountries(Country *c1, Country *c2);

int main()
{
    // Student s;
    // scanf(" %[^\n]", s.email);
    // scanf(" %[^\n]", s.branch);
    // generateId(&s);
    // printf("%s\n", s.id);
    int n;
    scanf("%d", &n);
    Country countries[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", countries[i].name, &countries[i].gold, &countries[i].silver, &countries[i].bronze);
    }
    sortCountriesArray(countries, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", countries[i].name);
    }
    return 0;
}

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return newNode;
}

Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (head == NULL)
        {
            head = addToList(head, temp);
        }
        else
        {
            addToList(head, temp);
        }
    }
    return head;
}

void printList(Node *head)
{
    Node *cpy = head;
    while (cpy != NULL)
    {
        printf("%d ", cpy->data);
        cpy = cpy->next;
    }
    printf("\n");
    return;
}

void freeList(Node *head)
{
    Node *curr, *nxt;
    curr = head;
    while (curr != NULL)
    {
        nxt = curr->next;
        free(curr);
        curr = nxt;
    }
}

int findMedian(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (true)
    {
        if (fast->next == NULL)
        {
            return slow->data;
        }
        if (fast->next->next == NULL)
        {
            return (((slow->data) + (slow->next->data)) / 2);
        }
        slow = slow->next;
        fast = fast->next->next;
    }
}

Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data)
    {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
    return NULL;
}

Node *getMedianNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; // important if we use head we get seg fault
    while (true)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return NULL;
}

Node *sortList(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    Node *left = head;
    Node *mid = getMedianNode(head);
    Node *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return mergeLists(left, right);
}

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int isPalindrome(Node *head)
{
    Node *mid = getMedianNode(head);
    mid->next = reverseList(mid->next);
    Node *l = head;
    Node *r = mid->next;
    while (r)
    {
        if (l->data != r->data)
            return 0;
        l = l->next;
        r = r->next;
    }
    return 1;
}

Node *rearrangeList(Node *head)
{
    Node *E = head;
    Node *C = head->next;
    Node *Cst = C;
    while (C && C->next)
    {
        E->next = C->next;
        E = E->next;
        C->next = E->next;
        C = C->next;
    }
    E->next = Cst;
    return head;
}

Node *removeRepeatedNodes(Node *head) // did not free memory
{
    Node *prev = head, *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
            break;
        if (curr->data != curr->next->data)
        {
            prev = curr;
            curr = curr->next;
            continue;
        }
        bool isHead = (curr == head);
        int currData = curr->data;
        while (curr != NULL && curr->data == currData)
        {
            curr = curr->next;
        }
        if (isHead)
        {
            head = curr;
        }
        else
        {
            prev->next = curr;
        }
    }
    return head;
}

Node *removeSlide(Node *head, int k)
{
    int count = 1;
    Node *slow = head, *fast = head;
    while (count < k)
    {
        fast = fast->next;
        count++;
    }
    Node *prev = slow;
    while (fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (slow == head)
        return head->next; // important
    prev->next = slow->next;
    slow->next = NULL;
    free(slow);
    return head;
}

void generateId(Student *s)
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        s->id[i] = s->email[i + 1];
    }
    s->id[i] = 'A';
    i++;
    if (compareStrings("CS", s->branch, 2))
    {
        s->id[i] = '7';
    }
    else if (compareStrings("ECE", s->branch, 3))
    {
        s->id[i] = 'A';
    }
    else
    {
        s->id[i] = '3';
    }
    i++;
    s->id[i] = 'P';
    i++;
    s->id[i] = 'S';
    i++;
    for (int j = i; j < i + 4; j++)
    {
        s->id[j] = s->email[5 + (j - i)];
    }
    i += 4;
    s->id[i] = 'H';
    i++;
    s->id[i] = '\0';
    return;
}

bool compareStrings(char *one, char *two, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (one[i] != two[i])
            return false;
    }
    return true;
}

bool compareCountries(Country *c1, Country *c2)
{
    // this func returns true if c1 < c2
    if (c1->gold < c2->gold)
        return true;
    if (c1->gold > c2->gold)
        return false;
    if (c1->silver < c2->silver)
        return true;
    if (c1->silver > c2->silver)
        return false;
    if (c1->bronze < c2->bronze)
        return true;
    if (c1->bronze > c2->bronze)
        return false;
    return true; // will never hit this
}

void sortCountriesArray(Country *countries, int n)
{
    // basic bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compareCountries(&countries[j], &countries[j + 1]) == true)
            {
                swapCountries(&countries[j], &countries[j + 1]);
            }
        }
    }
    return;
}
void swapCountries(Country *c1, Country *c2)
{
    Country temp = *c1;
    *c1 = *c2;
    *c2 = temp;
    return;
}