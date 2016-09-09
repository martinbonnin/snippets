import java.io.*;
import java.util.*;

Node {
val, 
next, 
random }

A {
val: ’a’
next: D
random: G}

D {
val: ’d’
next: G
random: A}

G {
val: ’g’
next: null
random: D}


A -> D -> G -> null
  
A' -> D' -> G' -> null
  

  
class Node {
  public int value;
  public Node copy;
  public Node next;
  public Node random;
}

/*Node deepCopy (Node root) {
  Node current = root;
  while (current != null) {
    Node n = new Node();
    n.value = current.value;
    
    current = current.next;
  }
}*/

Node deepCopy (Node root) {
  if (root == null) {
    return null;
  } else if (root.copy != null) {
    return root.copy;
  }
    
  Node n = new Node();
  n.value = root.value;
  root.copy = n;

  n.next = deepCopy(root.next);
  n.random = deepCopy(root.random);
  
  return n;
}




Given a map represented by an int[][] where the 0’s are water and the 1’s are land, find the number of islands in this map.
{ {0, 0, 1}, 
  {1, 0, 0}, 
  {1, 0, 0}} => 2


int numberOfIslands(int[][] map)  {
  int columns = map.length;
  int lines = map[0].length;
  int map1 = new int[lines* columns];
  int map2 = new int[liness * column];
  
  for (int x = 0; x < columns; x++) {
    for (int y = 0; y < lines; y++) {
      map1[x + y * columns] = map[x][y];
      map2[x + y * columns] = 0;
    }
  }
  
  int count = 0;
  for (int x = 0; x < columns; x++) {
    for (int y = 0; y < lines; y++) {
      if (map1[x + y * columns] == 1) {
        int island

        for (k = x - 1; k <= x +1; k++) {
          for (l = y - 1; l <= y +1; l++) {
            if (l == y && k == x) {
              continue:
            }
            
            if (l < 0 || k < 0 || l > lines || k > columns) {
              continue:
            }
            
            if (map2[k + l * lines] != 0) {
              // this is adjacent to an island
              island = map2[k + l * lines];
            }
          }
        }
        
        if (island == 0) {
          // new island
          count++;
          island = count;
        }
        
        map2[x + y * lines] = island;
      }
    }
  }
  
  return count;
  
}




















