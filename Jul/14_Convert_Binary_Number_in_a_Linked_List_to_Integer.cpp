// 1290. Convert Binary Number in a Linked List to Integer

// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.

 

// Example 1:


// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10
// Example 2:

// Input: head = [0]
// Output: 0
 

// Constraints:

// The Linked List is not empty.
// Number of nodes will not exceed 30.
// Each node's value is either 0 or 1.


class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    int getDecimalValue(ListNode *head)
    {
        ListNode *newHead = reverse(head);

        ListNode *temp = newHead;
        int number = 0;
        int exponent = 0;
        while (temp != NULL)
        {
            if (temp->val == 1)
            {
                number += pow(2, exponent);
            }
            temp = temp->next;
            exponent++;
        }
        return number;
    }
};

/*
This code converts a binary number represented as a linked list to its decimal equivalent.

The solution uses two main functions:

1. reverse(): 
- Reverses the linked list using recursion
- Takes O(n) time where n is number of nodes
- Uses O(n) space for recursion stack

2. getDecimalValue():
- First reverses the list to process bits from least significant to most
- Iterates through reversed list, for each 1 bit adds 2^position to result
- Takes O(n) time for reversal and iteration
- Uses O(n) space for reversed list

Overall complexity:
Time: O(n) 
Space: O(n)

The approach:
1. Reverse list to process bits from right to left
2. Track position using exponent variable
3. For each 1 bit, add 2^exponent to result
4. Move to next node and increment exponent
5. Return final decimal value
*/