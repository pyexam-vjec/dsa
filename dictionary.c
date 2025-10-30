#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;

#define SIZE 100

// Node structure
struct Node {
    char word[SIZE];
    char meaning[SIZE];
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char* word, char* meaning) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode-&gt;word, word);
    strcpy(newNode-&gt;meaning, meaning);
    newNode-&gt;left = newNode-&gt;right = NULL;
    return newNode;
}

// Function to insert a word-meaning pair
struct Node* insert(struct Node* root, char* word, char* meaning) {

    if (root == NULL) {
        return createNode(word, meaning);
    }

    if (strcmp(word, root-&gt;word) &lt; 0) {
        root-&gt;left = insert(root-&gt;left, word, meaning);
    } else if (strcmp(word, root-&gt;word) &gt; 0) {
        root-&gt;right = insert(root-&gt;right, word, meaning);
    } else {
        printf(&quot;Word already exists. Updating meaning.\n&quot;);
        strcpy(root-&gt;meaning, meaning);
    }

    return root;
}

// Function to search for a word
struct Node* search(struct Node* root, char* word) {
    if (root == NULL || strcmp(root-&gt;word, word) == 0) {
        return root;
    }

    if (strcmp(word, root-&gt;word) &lt; 0) {
        return search(root-&gt;left, word);
    } else {
        return search(root-&gt;right, word);
    }
}

// Inorder traversal to display dictionary
void inorder(struct Node* root) {
    if (root != NULL) {

        inorder(root-&gt;left);
        printf(&quot;%s: %s\n&quot;, root-&gt;word, root-&gt;meaning);
        inorder(root-&gt;right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice;
    char word[SIZE], meaning[SIZE];

    do {
        printf(&quot;\nDictionary Menu:\n&quot;);
        printf(&quot;1. Add word\n&quot;);
        printf(&quot;2. Search word\n&quot;);
        printf(&quot;3. Display dictionary\n&quot;);
        printf(&quot;4. Exit\n&quot;);
        printf(&quot;Enter your choice: &quot;);
        scanf(&quot;%d&quot;, &amp;choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf(&quot;Enter word: &quot;);
                fgets(word, SIZE, stdin);
                word[strcspn(word, &quot;\n&quot;)] = 0; // remove newline
                printf(&quot;Enter meaning: &quot;);
                fgets(meaning, SIZE, stdin);
                meaning[strcspn(meaning, &quot;\n&quot;)] = 0; // remove newline
                root = insert(root, word, meaning);
                break;

            case 2:
                printf(&quot;Enter word to search: &quot;);
                fgets(word, SIZE, stdin);
                word[strcspn(word, &quot;\n&quot;)] = 0;
                struct Node* found = search(root, word);
                if (found) {
                    printf(&quot;Meaning of \&quot;%s\&quot;: %s\n&quot;, word, found-&gt;meaning);
                } else {
                    printf(&quot;Word not found in dictionary.\n&quot;);
                }
                break;

            case 3:
                printf(&quot;\nDictionary Contents (In-order):\n&quot;);
                inorder(root);
                break;

            case 4:
                printf(&quot;Exiting program.\n&quot;);
                break;

            default:
                printf(&quot;Invalid choice! Try again.\n&quot;);
        }

    } while (choice != 4);

    return 0;
}
