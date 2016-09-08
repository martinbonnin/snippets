import java.io.*;
import java.util.*;


class Solution {
  static class Node {
    int value;
    Node left;
    Node right;
    public Node(int value) {
      this.value = value;
    }
  }

  static class SimpleNode {
    public int value;
    public SimpleNode next;
    public SimpleNode(int value) {
      this.value = value;
    }
  }
  public static void main(String[] args) {

    //traversal(); 
    //reverseWords();
    //uniqueChars();
    //stringPermutation();
    //replaceSpaces();
    //compression();
    //reverseList();
    //moveZeroes();
    //removeDups();
    //lastKthElement();
    //hanoiTowers();
    //twoStacksQueue();
    //sortStack();
    isBalanced();
  }
  
  static void isBalanced() {
    
  }
  
  static void sortStack() {
    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();
    
    stack1.push(1);
    stack1.push(8);
    stack1.push(2);
    stack1.push(3);
    stack1.push(3);
    stack1.push(9);
    stack1.push(10);
    stack1.push(3);
    
    while (!stack1.isEmpty()) {
      Integer a = stack1.pop();
      while (!stack2.isEmpty()) {
        Integer b = stack2.pop();
        if (b <= a) {
          stack2.push(b);
          break;
        } else {
          stack1.push(b);
        }
      }
      stack2.push(a);
    }
    
    while (!stack2.isEmpty()) {
      System.out.println(stack2.pop() + "");
    }
  }
  static class TwoStacksQueue {
    Stack<Object> stack1 = new Stack<>();
    Stack<Object> stack2 = new Stack<>();

    void queue(Object o) {
      stack1.push(o);
    }
    
    Object dequeue() {
      if (stack2.isEmpty()) {
        while (!stack1.isEmpty()) {
          stack2.push(stack1.pop());
        }
      }
      
      if (stack2.isEmpty()) {
        return null;
      }
      
      return stack2.pop();
    }
    
    boolean isEmpty() {
      return stack1.isEmpty() && stack2.isEmpty();
    }
  }
  
  static void twoStacksQueue() {
    TwoStacksQueue queue = new TwoStacksQueue();
    
    queue.queue(1);
    queue.queue(2);
    queue.dequeue();
    queue.queue(3);
    queue.queue(4);
    queue.queue(5);
    queue.dequeue();
    queue.queue(6);
    
    while (!queue.isEmpty()) {
      System.out.print(queue.dequeue() + "");
    }
  }
  
  static void hanoiTowers() {
    ArrayList<Stack<Integer>> towers = new ArrayList<>();
    towers.add(new Stack<Integer>());
    towers.add(new Stack<Integer>());
    towers.add(new Stack<Integer>());
    
    towers.get(0).push(3);
    towers.get(0).push(2);
    towers.get(0).push(1);
    towers.get(0).push(0);
    
    
    moveTopElements(towers, 4, 0, 2);

    for (int i = 0; i < 3; i++) {
      System.out.print("tower " + i + ": ");
      while (!towers.get(i).isEmpty()) {
        Integer value = towers.get(i).pop();
        System.out.print(value + " ");
      }
      System.out.print("\n");
    }
}

  static void moveTopElements(ArrayList<Stack<Integer>> towers, int n, int from, int to) {
    if (n == 1) {
      towers.get(to).push(towers.get(from).pop());
      return;
    }
    
    int i = 0;
    for (; i < 3; i++) {
      if (i != from && i != to) {
        break;
      }
    }
    moveTopElements(towers, n - 1, from, i);
    Integer disk = towers.get(from).pop();
    if (!towers.get(to).isEmpty()) {
      if (disk > towers.get(to).peek()) {
        System.out.println("Error pushing disk " + disk + " from " + from + " to " + to);
        return;
      }
    }
    towers.get(to).push(disk);
    moveTopElements(towers, n - 1, i, to);    
  }
  
  static void lastKthElement() {
    SimpleNode head = new SimpleNode(1);
    head.next = new SimpleNode(2);
    head.next.next = new SimpleNode(3);
    head.next.next.next = new SimpleNode(4);
    head.next.next.next.next = new SimpleNode(2);
    head.next.next.next.next.next = new SimpleNode(2);

    SimpleNode node2, node1;
    node2 = head;

    int k = 4;
    
    for (int i = 0; i < k + 1; i++) {
      node2 = node2.next;
    }
    
    node1 = head;
    while (node2 != null) {
      node2 = node2.next;
      node1 = node1.next;
    }
    
    System.out.println(node1.value);
  }
  
  static void removeDups() {
    SimpleNode head = new SimpleNode(1);
    head.next = new SimpleNode(2);
    head.next.next = new SimpleNode(3);
    head.next.next.next = new SimpleNode(4);
    head.next.next.next.next = new SimpleNode(2);
    head.next.next.next.next.next = new SimpleNode(2);
    
    SimpleNode current = head;
    
    /*while (current != null) {
      SimpleNode runner = current.next;
      SimpleNode prev = current;
      while (runner != null) {
        if (runner.value == current.value) {
          prev.next = runner.next;
        } else {
          prev = runner;
        }
        runner = runner.next;
      }
      current = current.next;
    }*/
    Set<Integer> seen = new HashSet<>();
    
    current = head.next;
    SimpleNode prev = head;
    while (current != null) {
      if (seen.contains(current.value)) {
        prev.next = current.next;
      } else {
        seen.add(current.value);
        prev = current;
      }
      current = current.next;
    }
    
    current = head;
    while (current != null) {
      System.out.println(current.value);
      current = current.next;
    }
    
  }
  
  static void moveZeroes() {
    int array[] = {6, 4, 0, 5, 0, 0, 0, 1, 0};
    
    int j = 0;
    for (int i=0; i < array.length; i++) {
      if (array[i] != 0) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        j++;
      }
    }
    
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + " ");
    }
    System.out.print("\n");
  }
  
  static void reverseWords() {
    String s = "Man bites dog";
    String a[] = s.split(" ");
    for (int i = 0; i < a.length/2; i++) {
      String tmp = a[i];
      a[i] = a[a.length - 1 -i];
      a[a.length - 1 - i] = tmp;
    }
    System.out.println(String.join(" ", a));
  }
  
  static void traversal() {
    Node root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(5);
    root.left.left = new Node(3);
    root.left.right = new Node(4);
    
    System.out.print("breadth-first: ");
    LinkedList<Node> queue = new LinkedList<>();
    queue.offer(root);
    while (!queue.isEmpty()) {
      Node node = queue.poll();
      System.out.print(node.value);
      if (node.left != null) {
        queue.offer(node.left);
      }
      if (node.right != null) {
        queue.offer(node.right);
      }
    }      
    System.out.print("\n");

    System.out.print("depth-first in-order non-recursive: ");
    queue = new LinkedList<>();
    queue.offerLast(root);
    while (!queue.isEmpty()) {
      Node node = queue.pollLast();
      System.out.print(node.value);
      if (node.right != null) {
        queue.offerLast(node.right);
      }
      if (node.left != null) {
        queue.offerLast(node.left);
      }
    }   
    System.out.print("\n");
    
    System.out.print("depth-first in-order recursive: ");
    printNodeInOrder(root);
    System.out.print("\n");
  }
  
  static void printNodeInOrder(Node node) {
      System.out.print(node.value);
      if (node.left != null) {  
        printNodeInOrder(node.left);
      }
      if (node.right != null) {
        printNodeInOrder(node.right);
      }
  }
    
  static void uniqueChars() {
    String s = "abcdefgg";
    char c[] = new char[256];
    for (int i = 0; i < s.length(); i++) {
      c[s.charAt(i)]++;
      if (c[s.charAt(i)] >= 2) {
        System.out.println("char " + s.charAt(i) + " is duplicate");
        return;
      }
    }
    System.out.println("no duplicate");
  }
  
  static void stringPermutation() {
    String s1 = "abcdef";
    String s2 = "fedcba";
    
    byte bytes[] = s1.getBytes();
    Arrays.sort(bytes);
    s1 = new String(bytes);
    bytes = s2.getBytes();
    Arrays.sort(bytes);
    s2 = new String(bytes);
    
    if (s2.equals(s1)) {
      System.out.println("permutation!");
    } else {
      System.out.println("not a permutation! ");
    }
  }
  
  static void replaceSpaces() {
    String s = "a b c d e f ";
    //System.out.println(s.replaceAll(" ", "%20"));
    char d[] = s.toCharArray();
    int len = d.length;
    int spaceCount = 0;
    for (int i = 0; i < len; i++) {
      if (d[i] == ' ') {
        spaceCount++;
      }
    }
    
    int finalLen = len + spaceCount * 2;
    char c[] = new char[finalLen];
    System.arraycopy(d, 0, c, 0, len);
    int j = finalLen - 1;
    
    for (int i = len - 1; i >= 0; i--) {
      if (c[i] == ' ') {
        c[j - 2] = '%';
        c[j - 1] = '2';
        c[j] = '0';
        j -= 3;
      } else {
        c[j] = c[i];
        j --;
      }        
    }
    
    System.out.println(new String(c));
  }
  
  static void compression() {
    String s = "aabcccccaaa";
    
    char currentChar = s.charAt(0);
    int currentCount = 1;
    String d = "";
    for (int i = 1; i < s.length(); i++) {
      char c = s.charAt(i);
      if (c != currentChar) {
        d += ("" + currentChar) + currentCount;
        currentChar = c;
        currentCount = 1;
      } else {
        currentCount++;
      }        
    }
    
    d += ("" + currentChar) + currentCount;
    System.out.println(d);
  }
  
  static void reverseList() {
    SimpleNode head = new SimpleNode(1);
    head.next = new SimpleNode(2);
    head.next.next = new SimpleNode(3);
    head.next.next.next = new SimpleNode(4);
    
    SimpleNode current = head;
    SimpleNode prev = null;
    while (current != null) {
      SimpleNode next = current.next;
      
      current.next = prev;
      prev = current;
      current = next;
    }
    
    current = prev;
    while (prev != null) {
      System.out.println(prev.value);
      prev = prev.next;
    }
  }
}
