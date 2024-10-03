#include <stdio.h>
#include <stdlib.h>

struct Haffman{
    char data;
    int freq;
    struct Haffman* left_child;
    struct Haffman* right_child;
    struct Haffman* array[6];
};

int main() {
    struct Haffman array[6];
    for (int i = 0; i < 6; ++i) {
        struct Haffman* newNode = malloc(sizeof (struct Haffman));
        newNode->left_child = NULL;
        newNode->right_child = NULL;
        printf("Enter the character: ");
        newNode->data = getchar();
        printf("Enter the frequency: ");
        scanf("%d", &newNode->freq);
        getchar();
       array[i]= *newNode;
    }
    printf("\nHaffman coding elements is:-- \n");
        for (int i = 0; i < 6; ++i) {
            printf("Data:- %c, Frequency:- %d\n", array[i].data, array[i].freq);
        }
    return 0;
}
