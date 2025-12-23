#include <stdio.h>
#include <stdlib.h>

// this is not a complete implementation of dblyLL only required functions are implemented

typedef struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
} Node;

Node *createNode(int val);
Node *addAtEnd(Node *listHead, Node *newNode);
Node *gotoNext(Node *listHead);
Node *gotoPrev(Node *listHead);
Node *readList();
void printList(Node *listHead);
void problemA();
Node *findInList(Node *listHead, int val);
Node *addNext(Node *listHead, Node *nextNode);
void removeNode(Node *node);
void problemB();
void problemC();
Node *getHead(Node *listHead);
Node *getTail(Node *listHead);
void problemD();
Node *readListOfSizen(int n);
void problemE();
void problemF();
int UpperBound(int *arr, int st, int end, int tgt);
void problemG();
void problemH();
void problemI();
void problemJ();
int isValid(int *arr, int n, int k, int sz);

int main()
{
    problemJ();
    return 0;
}

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *addAtEnd(Node *listHead, Node *newNode)
{
    if (listHead == NULL)
    {
        return newNode;
    }
    Node *curr = listHead;
    while (curr->next)
    {
        curr = curr->next;
    }
    newNode->prev = curr;
    curr->next = newNode;
    return listHead;
}

Node *gotoNext(Node *listHead)
{
    if (listHead->next != NULL)
        return listHead->next;
    return listHead;
}

Node *gotoPrev(Node *listHead)
{
    if (listHead->prev != NULL)
        return listHead->prev;
    return listHead;
}

Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *listHead = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        Node *newNode = createNode(temp);
        listHead = addAtEnd(listHead, newNode);
    }
    return listHead;
}

void printList(Node *listHead)
{
    Node *curr = listHead;
    while (curr->prev != NULL)
        curr = curr->prev;
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return;
}

void problemA()
{
    Node *curr = readList();
    int operation = 0;
    while (operation != 5)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            int new;
            scanf("%d", &new);
            curr = addAtEnd(curr, createNode(new));
            break;
        case 2:
            printf("%d\n", curr->data);
            break;
        case 3:
            curr = gotoNext(curr);
            break;
        case 4:
            curr = gotoPrev(curr);
            break;
        }
    }
}

Node *findInList(Node *listHead, int val)
{
    Node *temp1 = listHead;
    Node *temp2 = listHead;
    while (temp1)
    {
        if (temp1->data == val)
        {
            return temp1;
        }
        temp1 = temp1->next;
    }
    while (temp2)
    {
        if (temp2->data == val)
        {
            return temp2;
        }
        temp2 = temp2->prev;
    }
    return NULL; // if not found
}

Node *addNext(Node *curr, Node *node)
{
    node->next = curr->next;
    node->prev = curr;
    if (curr->next)
        curr->next->prev = node;
    curr->next = node;
    return curr;
}

void removeNode(Node *node)
{
    if (!node)
        return;

    if (node->prev)
        node->prev->next = node->next;

    if (node->next)
        node->next->prev = node->prev;

    free(node);
}

void problemB()
{
    Node *curr = readList();
    int operation = 0;
    int new;
    while (operation != 5)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf("%d", &new);
            curr = addAtEnd(curr, createNode(new));
            break;
        case 2:
            printf("%d\n", curr->data);
            break;
        case 3:
            curr = gotoNext(curr);
            break;
        case 4:
            curr = gotoPrev(curr);
            break;
        case 6:
            scanf("%d", &new);
            Node *node = findInList(curr, new);
            removeNode(node);
            node = createNode(new);
            curr = addNext(curr, node);
            break;
        }
    }
}

void problemC()
{
    int k;
    scanf("%d", &k);
    Node *list = readList();
    Node *left = getHead(list);
    Node *right = getTail(list);
    int found = 0;
    while (left->data != right->data)
    {
        if (left->data + right->data == k)
        {
            found = 1;
            break;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    printf("%d\n", found);
}

Node *getHead(Node *listHead)
{
    Node *curr = listHead;
    while (curr->prev)
    {
        curr = curr->prev;
    }
    return curr;
}

Node *getTail(Node *listHead)
{
    Node *curr = listHead;
    while (curr->next)
    {
        curr = curr->next;
    }
    return curr;
}

void problemD()
{
    Node *left = readList();
    Node *right = getTail(left);
    long long leftSum = left->data;
    long long rightSum = right->data;
    int A = 1, B = 1;
    int ansA = 0, ansB = 0;
    while (left != right)
    {
        if (leftSum == rightSum)
        {
            ansA = A;
            ansB = B;
            left = left->next;
            leftSum += left->data;
            A++;
        }
        else if (leftSum < rightSum)
        {
            left = left->next;
            leftSum += left->data;
            A++;
        }
        else
        {
            right = right->prev;
            rightSum += right->data;
            B++;
        }
    }
    printf("%d %d\n", ansA, ansB);
}

Node *readListOfSizen(int n)
{
    Node *listHead = NULL;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        Node *newNode = createNode(temp);
        listHead = addAtEnd(listHead, newNode);
    }
    return listHead;
}

void problemE()
{
    int n, k;
    scanf("%d %d", &n, &k);
    Node *listHead = readListOfSizen(n);
    Node *listTail = getTail(listHead);
    Node *curr = listTail;
    k = k % n;
    if (k == 0)
    {
        printList(listHead);
        return;
    }

    for (int i = 1; i < k; i++)
    {
        curr = curr->prev;
    }
    curr->prev->next = NULL;
    curr->prev = NULL;
    listHead->prev = listTail;
    listTail->next = listHead;
    printList(curr);
}

void problemF()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k = 0;
    int i = 0;
    while (i < n)
    {
        k++;
        int tgt = arr[i];
        i = UpperBound(arr, i, n - 1, tgt);
    }
    printf("%d\n", k);
}

int UpperBound(int *arr, int st, int end, int tgt)
{
    int l = st, r = end;
    int ans = end + 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > tgt)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

void problemG()
{
    int n, limit;
    scanf("%d %d", &n, &limit);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int l = 0, r = n - 1;
    int ans = arr[0];
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] <= limit)
        {
            ans = arr[m];
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
}

void problemH()
{
    long long n;
    scanf("%lld", &n);
    long long l = 1, r = n;
    long long ans = 0;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (m <= n / m)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    printf("%lld\n", ans);
}

void problemI()
{
    long long n;
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("0\n");
        return;
    }
    long long l = 1, r = n - 1;
    long long ans = 0;
    long long T = n * (n - 1);
    T /= 4;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (m * (2 * n - m - 1) >= 2 * T)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%lld\n", ans);
}

void problemJ()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int lo = 1, hi = max;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isValid(arr, n, k, mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    printf("%d\n", ans);
}
int isValid(int *arr, int n, int k, int sz)
{
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (arr[i] / sz);
    }
    return count >= k;
}