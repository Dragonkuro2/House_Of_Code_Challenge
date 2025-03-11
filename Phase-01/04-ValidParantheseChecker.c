#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the node structure
typedef struct Node {
	char pattern;
	struct Node *next;
} Node;

// define the stack structure
typedef struct {
	Node *top; // pointer to the top of the stack
} Stack;

/**
 * Initialize_stack - initialize the stack with null value.
 * @stack: stack we want to initialize.
 */
void Initialize_stack(Stack *stack){
	stack->top = NULL;
}

/**
 * IsEmpty - check if a stack is empty
 * @stack: stack to check if it's empty
 * Return: true if the stack is empty, otherwise false.
 */
bool IsEmpty(Stack *stack){
	return stack->top == NULL;
}

/**
 * push - push an element into the stack
 * @stack: pointer to the stack.
 * @value: value to push into the stack
 */
void push(Stack *stack, char value){
    // create a new node
    Node *new_node = malloc(sizeof(Node));
    if (!new_node){ // check if the memory was allocated
        printf("Error: Memory allocation failed\n");
        return;
    }

    // update the data of top pointer of the stack.
    new_node->pattern = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

/**
 * pop - Pop an element from the stack.
 * @stack: Pointer to the stack.
 */
void pop(Stack *stack){
    if (IsEmpty(stack)){
        printf("Stack Underflow, pop operation can't be done because stack is empty.\n");
        return;
    }

    // delete the top element of the stack
    Node *temp = stack->top;
    stack->top = temp->next;
    free(temp);
}

/**
 * isValid - Check if the brackets in the string are balanced.
 * @s: The input string.
 * Return: true if the brackets are balanced, false otherwise.
 */
bool isValid (const char *s)
{
    Stack stack;
    Initialize_stack(&stack); // initialize the stack with null value.

    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            push(&stack, s[i]); // push the opening bracket into the stack
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if (IsEmpty(&stack)) // if the stack is empty the pattern isn't valid.
                return false;

            char top = stack.top->pattern;

            // Check if the closing bracket matches the top of the stack
            if ((top != '(' && s[i] == ')') ||
                (top != '[' && s[i] == ']') ||
                (top != '{' && s[i] == '}')) {
                return false;
            }

            pop(&stack); // pop the matched opening bracket
        }
    }
    return IsEmpty(&stack);
}

int main (void)
{
    const char * test1 = "()";
    const char * test2 = "[{() }]";
    const char * test3 = "{[( a+b) * x}";
    const char * test4 = "{[ a+b ]*( x/y)}";
    printf ("Test 1: %s\n" , test1 );
    printf ("Is valid: %d\n" , isValid ( test1 ));
    printf ("Test 2: %s\n" , test2 );
    printf ("Is valid: %d\n" , isValid ( test2 ));
    printf ("Test 3: %s\n" , test3 );
    printf ("Is valid: %d\n" , isValid ( test3 ));
    printf ("Test 4: %s\n" , test4 );
    printf ("Is valid: %d\n" , isValid ( test4 ));
    return 0;
}