# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        if k == 0 or head == None or head.next == None:
            return head
        
        # Retrieve size of list
        size = 1
        iterator = head
        while iterator.next != None:
            iterator = iterator.next
            size += 1
            
        # Save the tail node
        tail = iterator
        
        # Iterate to the pivot
        k = k % size
        iterator = head
        for i in range(size - k - 1):
            iterator = iterator.next
            
        # Rotate the list at pivot
        tail.next = head
        head = iterator.next
        iterator.next = None
        return head
    
    # [1,2,3] k=4