import java.util.ArrayList;
import java.util.List;

public class grader {
  private static class treeHelper {
    static int N;
    static int logN = 0;
    static int[][] parent;
    static int[] depth;
    static int[] subtreeSize;

    static void dfs(final int[][] adjList, int currentNode, int parentNode) {
      parent[0][currentNode] = parentNode;
      subtreeSize[currentNode] = 1;
      for (int i = 0; i < adjList[currentNode].length; ++i) {
        final int nextNode = adjList[currentNode][i];
        if (nextNode != parentNode) {
          depth[nextNode] = depth[currentNode] + 1;
          dfs(adjList, nextNode, currentNode);
          subtreeSize[currentNode] += subtreeSize[nextNode];
        }
      }
    }

    static void initializeTree(final int[][] adjList) {
      N = adjList.length;

      depth = new int[N];
      subtreeSize = new int[N];
      for (logN = 0; (1 << logN) < N; ++logN) {}
      parent = new int[logN][N];

      dfs(adjList, 0, 0);
      for (int i = 1; i < logN; ++i) {
        for (int j = 0; j < N; ++j) {
          parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
      }
    }

    static int getLowestCommonAncestor(int X, int Y) {
      if (depth[X] < depth[Y]) {
        int Z = X;
        X = Y;
        Y = Z;
      }
      for (int i = logN - 1; i >= 0; --i) {
        if (depth[parent[i][X]] >= depth[Y]) {
          X = parent[i][X];
        }
      }
      if (X == Y) {
        return X;
      }
      for (int i = logN - 1; i >= 0; --i) {
        if (parent[i][X] != parent[i][Y]) {
          X = parent[i][X];
          Y = parent[i][Y];
        }
      }
      return parent[0][X];
    }

    static int getDistance(int X, int Y) {
      return depth[X] + depth[Y] - 2 * depth[getLowestCommonAncestor(X, Y)];
    }

    static int attractionsBehind(int X, int Y) {
      if (X == Y) {
        return N;
      }
      for (int i = logN - 1; i >= 0; --i) {
        if (depth[parent[i][X]] > depth[Y]) {
          X = parent[i][X];
        }
      }
      if (Y == parent[0][X]) {
        return N - subtreeSize[X];
      }
      return subtreeSize[Y];
    }

    static void checkFunTour(final int[] funTour) {
      if (funTour.length != N) {
        grader.wrongAnswer("Invalid size");
      }

      boolean[] visitedAttractions = new boolean[N];
      for (int i = 0; i < N; ++i) {
        if (funTour[i] < 0 || funTour[i] >= N) {
          grader.wrongAnswer("Invalid index");
        }
        if (visitedAttractions[funTour[i]]) {
          grader.wrongAnswer("Repeated index");
        }
        visitedAttractions[funTour[i]] = true;
      }

      int lastTravelTime = getDistance(funTour[0], funTour[1]);
      for (int i = 2; i < N; ++i) {
        int travelTime = getDistance(funTour[i - 1], funTour[i]);
        if (travelTime > lastTravelTime) {
          grader.wrongAnswer("Tour is not fun");
        }
        lastTravelTime = travelTime;
      }
    }
  }

  private static int N, Q;

  private static void wrongAnswer(String message) {
    System.out.printf("WA: %s\n", message);
    System.exit(0);
  }

  public static int hoursRequired(int X, int Y) {
    if (--Q < 0) {
      wrongAnswer("Too many queries");
    }
    if (X < 0 || X >= N || Y < 0 || Y >= N) {
      wrongAnswer("Invalid index");
    }
    return treeHelper.getDistance(X, Y);
  }

  public static int attractionsBehind(int X, int Y) {
    if (--Q < 0) {
      wrongAnswer("Too many queries");
    }
    if (X < 0 || X >= N || Y < 0 || Y >= N) {
      wrongAnswer("Invalid index");
    }
    return treeHelper.attractionsBehind(X, Y);
  }

  public static void main(String[] args) {
    InputReader inputReader = new InputReader(System.in);
    N = inputReader.readInt();
    Q = inputReader.readInt();

    List<List<Integer>> adjArrayList = new ArrayList<List<Integer>>();
    for (int i = 0; i < N; ++i) {
      adjArrayList.add(new ArrayList<Integer>());
    }
    for (int i = 0; i < N - 1; ++i) {
      int A = inputReader.readInt();
      int B = inputReader.readInt();
      adjArrayList.get(A).add(B);
      adjArrayList.get(B).add(A);
    }
    int[][] adjList = new int[N][];
    for (int i = 0; i < N; ++i) {
      adjList[i] = new int[adjArrayList.get(i).size()];
      for (int j = 0; j < adjList[i].length; ++j) {
        adjList[i][j] = adjArrayList.get(i).get(j);
      }
    }
    treeHelper.initializeTree(adjList);

    fun solver = new fun();
    int[] funTour = solver.createFunTour(N, Q);
    treeHelper.checkFunTour(funTour);

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < N; ++i) {
      sb.append(funTour[i]);
      sb.append(" \n".charAt(i == N - 1 ? 1 : 0));
    }
    System.out.print(sb.toString());
  }
}


class InputReader implements java.io.Closeable {
  private java.io.InputStream stream;
  private byte[] buf = new byte[1024];
  private int curChar;
  private int numChars;

  public InputReader(java.io.InputStream stream) {
    this.stream = stream;
  }
  
  @Override
  public void close() {
    try {
      this.stream.close();
    } catch (java.io.IOException e) {
    }
  }

  public int read() {
    if (numChars == -1) {
      throw new java.util.InputMismatchException();
    }
    if (curChar >= numChars) {
      curChar = 0;
      try {
        numChars = stream.read(buf);
      } catch (java.io.IOException e) {
        throw new java.util.InputMismatchException();
      }
      if (numChars <= 0) {
        return -1;
      }
    }
    return buf[curChar++];
  }

  public int readInt() {
    int c = eatWhite();
    int sgn = 1;
    if (c == '-') {
      sgn = -1;
      c = read();
    }
    int res = 0;
    do {
      if (c < '0' || c > '9') {
        throw new java.util.InputMismatchException();
      }
      res *= 10;
      res += c - '0';
      c = read();
    } while (!isSpaceChar(c));
    return res * sgn;
  }

  public String readString() {
    int c = eatWhite();
    StringBuilder res = new StringBuilder();
    do {
      if (Character.isValidCodePoint(c))
        res.appendCodePoint(c);
      c = read();
    } while (!isSpaceChar(c));
    return res.toString();
  }

  public String readLine() {
    StringBuilder res = new StringBuilder();
    while (true) {
      int c = read();
      if (c == '\n' || c == '\r' || c == -1)
        break;
      if (Character.isValidCodePoint(c))
        res.appendCodePoint(c);
    }
    return res.toString();
  }

  private int eatWhite() {
    int c = read();
    while (isSpaceChar(c)) {
      c = read();
    }
    return c;
  }

  public static boolean isSpaceChar(int c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
  }
}
