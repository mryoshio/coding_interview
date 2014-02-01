
STACK_SIZE = 10

class ArrayStack:
    """
    This class realize 3 stacks in 1 array.
    """

    def __init__(self):
        self.buffer = [0] * STACK_SIZE * 3
        self.stack_pointer = [-1, -1, -1]

    def push(self, stack_num, value):
        """
        push the value in the stack specified in arguments.
        """
        if self.stack_pointer[stack_num] + 1 >= STACK_SIZE:
            raise 'Out of Space'
        self.stack_pointer[stack_num] += 1
        self.buffer[self.abs_top_of_stack(stack_num)] = value

    def pop(self, stack_num):
        """
        pop value from stack_num specified in arguments.
        """
        if self.stack_pointer[stack_num] == -1:
            raise 'Trying to pop an empty stack.'
        value = self.buffer[self.abs_top_of_stack(stack_num)]
        self.buffer[self.abs_top_of_stack(stack_num)] = 0
        self.stack_pointer[stack_num] -= 1
        return value

    def peek(stack_num):
        index = self.abs_top_of_stack(stack_num)
        return self.buffer[index]

    def is_empty(stack_num):
        return self.stack_pointer[stack_nm] == -1
        
    def abs_top_of_stack(self, stack_num):
        return stack_num * STACK_SIZE + self.stack_pointer[stack_num]

    def debug(self):
        for stack_num in range(3):
            print "stack(%s)" % stack_num,
            for idx in range(STACK_SIZE):
                print self.buffer[stack_num * 10 + idx],
            print 

def main():
    from random import randint
    stack = ArrayStack()
    stack.debug()
    push_num = 10
    pop_num = 5
    for x in range(push_num):
        vs = [randint(0, 2), randint(0, 100)]
        print ('--- push %d in stack(%d)' % (vs[1], vs[0]))
        stack.push(vs[0], vs[1])
        stack.debug()
    for x in range(pop_num):    
        n = randint(0, 2)
        print ('---   pop stack(%d)' % n)
        stack.pop(n)
        stack.debug()

if __name__ == '__main__': main()
