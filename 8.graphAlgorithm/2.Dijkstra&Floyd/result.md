### 原图：
![graph](https://g.gravizo.com/g?
graph G {
  0;
  1;
  2;
  3;
  4;
  5;
  0 -- 1 [label="5"];
  0 -- 2 [label="1"];
  1 -- 2 [label="2"];
  1 -- 3 [label="1"];
  2 -- 3 [label="4"];
  2 -- 4 [label="8"];
  3 -- 4 [label="3"];
  3 -- 5 [label="6"];
})

---
### Dijkstra算法：
![graph](https://g.gravizo.com/g?
graph G {
  0;
  1;
  2;
  3;
  4;
  5;
  0 -- 2 [label="1"];
  0 -- 1 [label="3"];
  0 -- 3 [label="4"];
  0 -- 4 [label="7"];
  0 -- 5 [label="10"];
})

---
原图:
![WeightedDirectedGraph](https://g.gravizo.com/g?
digraph G {
  0;
  1;
  2;
  3;
0 -> 2 [label = "3"];
1 -> 0 [label = "1"];
1 -> 2 [label = "5"];
2 -> 1 [label = "4"];
2 -> 3 [label = "6"];
3 -> 0 [label = "4"];
3 -> 1 [label = "2"];
3 -> 2 [label = "8"];
})

---
### Floyd算法: 
![WeightedDirectedGraph](https://g.gravizo.com/g?
digraph G {
  0;
  1;
  2;
  3;
0 -> 0 [label = "0"];
0 -> 1 [label = "7"];
0 -> 2 [label = "3"];
0 -> 3 [label = "9"];
1 -> 0 [label = "1"];
1 -> 1 [label = "0"];
1 -> 2 [label = "4"];
1 -> 3 [label = "10"];
2 -> 0 [label = "5"];
2 -> 1 [label = "4"];
2 -> 2 [label = "0"];
2 -> 3 [label = "6"];
3 -> 0 [label = "3"];
3 -> 1 [label = "2"];
3 -> 2 [label = "6"];
3 -> 3 [label = "0"];
})

