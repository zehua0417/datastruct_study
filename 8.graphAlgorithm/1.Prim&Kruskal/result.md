原图：
![graph](https://g.gravizo.com/g?
graph G {
  0;
  1;
  2;
  3;
  4;
  0 -- 1 [label="2"];
  0 -- 3 [label="6"];
  1 -- 2 [label="3"];
  1 -- 3 [label="8"];
  1 -- 4 [label="5"];
  2 -- 4 [label="7"];
  3 -- 4 [label="9"];
})
最小生成树：

---
### Prim算法
![graph](https://g.gravizo.com/g?
graph G {
  0;
  1;
  2;
  3;
  4;
  0 -- 1 [label="2"];
  0 -- 3 [label="6"];
  1 -- 2 [label="3"];
  1 -- 4 [label="5"];
})

---
### Kruskal算法
![graph](https://g.gravizo.com/g?
graph G {
  0;
  1;
  2;
  3;
  4;
  0 -- 1 [label="2"];
  0 -- 3 [label="6"];
  1 -- 2 [label="3"];
  1 -- 4 [label="5"];
})
