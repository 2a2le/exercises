// Alex B

import java.util.HashSet;

class Node {
  Node next = null;
  int data;

  public Node(int d) {
    data = d;
  }

  static class Result {
    public Node node;
    public boolean result;
    
    public Result(Node node, boolean result) {
      this.node = node;
      this.result = result;
    }
  } 

  void appendToTail(int d) {
    Node end = new Node(d);
    Node n = this;
    while (n.next != null) {
      n = n.next;
    }
    n.next = end;
  }

  static Node deleteNode(Node head, int d) {
    Node n = head;
    
    if (n.data == d) {
      return n.next;    /* moved head */
    }

    while (n.next != null) {
      if (n.next.data == d) {
        n.next = n.next.next;
        return head;    /* head didn't change */
      }
      n = n.next;
    }
    return head;
  }


  // 1. Remove dups
  static void deleteDups2(Node n) {
    HashSet<Integer> set = new HashSet<Integer>();
    Node previous = null;
    while (n != null) {
      if (set.contains(n.data)) {
        previous.next = n.next;
      } else {
        set.add(n.data);
        previous = n;
      }
      n = n.next;
    }
  }

  // no buffer
  static void deleteDups(Node n) {
    Node current = n;
    while (current != null) {
      // delete all future nodes that match the current
      Node runner = current;
      while (runner.next != null) {
        if (runner.next.data == current.data) {
          runner.next = runner.next.next;
        } else {
          runner = runner.next;
        }
      }
      current = current.next;
    }
  }

  // 2. kth elem
  static Node kthToLast(Node n, int k) {
    Node current = n;
    Node runner = n;
    for (int i=0; i<k; i++) {
      if (runner == null) {
        return null;
      }
      runner = runner.next;
    }
    while (runner.next != null) {
      runner = runner.next;
      current = current.next;
    }
    return current;
  }

 
  // 3. is palindrome
  // recursive
  
  static int lengthOfList(Node n) {
    int length = 0;
    while (n != null) {
      length++;
      n = n.next;
    }
    return length;
  }

  static boolean isPalindrome(Node head) {
    int length = lengthOfList(head);
    Result res = isPalindromeRecurse(head, length);
    return res.result;
  }

  static Result isPalindromeRecurse(Node head, int length) {
    if (head == null || length <= 0) { // Even number of nodes
      return new Result(head, true);
    } else if (length == 1) { // Odd number of nodes
      return new Result(head.next, true);
    }

    /* Recurse through the sublist. */
    Result res = isPalindromeRecurse(head.next, length - 2);

    /* If child calls are not a palindrome pass back up a failure. */
    if (!res.result || head == null) {
      return res;
    }

    /* Check if the node data matches the corresponding one on the other side */
    res.result = (head.data == res.node.data);

    /* Return corresponding node */
    res.node = res.node.next;

    return res;
  }


  // find beginning of a loop
  static Node findBeginning(Node head) {
    Node slowRunner = head;
    Node fastRunner = head;

    while (fastRunner != null and fastRunner.next != null) {
      slowRunner = slowRunner.next;
      fastRunner = fastRunner.next.next;
      if (slowRunner == fastRunner) { // collision point, break
        break;
      }
    }

    if (fastRunner == null || fastRunner.next == null) {
      return null; // no collition point, therefore no cycle
    }

    slowRunner = head;
    while (slowRunner != fastRunner) {
      slowRunner = slowRunner.next;
      fastRunner = fastRunner.next.next;
    }

    return fastRunner;
  }

  static void printList(Node head) {
    Node n = head;
    while (n != null) {
      System.out.print(n.data + " ");
      n = n.next;
    }
    System.out.println();
  }

  public static void main(String[] args) {
    Node n = new Node(1);
    n.appendToTail(5);
    n.appendToTail(3);
    n.appendToTail(5);
    n.appendToTail(1);
    //n.appendToTail(3);
    printList(n);
    System.out.println(isPalindrome(n));
    System.out.println(kthToLast(n,2).data);
    System.out.println(kthToLast(n,0).data);
    //System.out.println(kthToLast(n,5).data);
    deleteDups(n);
    printList(n);
    
  }
}
