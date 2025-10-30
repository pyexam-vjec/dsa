#include &lt;stdio.h&gt;
#define R 5
#define C 5
#define INF 9999

int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

int isValid(int x, int y) {
    return (x &gt;= 0 &amp;&amp; x &lt; R &amp;&amp; y &gt;= 0 &amp;&amp; y &lt; C);
}

void findShortestDistance(int maze[R][C]) {
    int dist[R][C];
    int queue[R * C][2], front = 0, rear = 0;

    // Initialize all distances as INF
    for (int i = 0; i &lt; R; i++)
        for (int j = 0; j &lt; C; j++)
            dist[i][j] = INF;

    // Enqueue all landmine cells
    for (int i = 0; i &lt; R; i++) {
        for (int j = 0; j &lt; C; j++) {

            if (maze[i][j] == 0) {
                dist[i][j] = 0;
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
        }
    }

    // BFS
    while (front &lt; rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        for (int k = 0; k &lt; 4; k++) {
            int nx = x + row[k];
            int ny = y + col[k];

            if (isValid(nx, ny) &amp;&amp; dist[nx][ny] &gt; dist[x][y] + 1 &amp;&amp; maze[nx][ny] == 1) {
                dist[nx][ny] = dist[x][y] + 1;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
            }
        }
    }

    // Print the result
    printf(&quot;Shortest distances from landmine:\n&quot;);
    for (int i = 0; i &lt; R; i++) {
        for (int j = 0; j &lt; C; j++) {

            if (dist[i][j] == INF)
                printf(&quot;-1 &quot;);
            else
                printf(&quot;%2d &quot;, dist[i][j]);
        }
        printf(&quot;\n&quot;);
    }
}
int main() {
    int maze[R][C] = {
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}
    };

    findShortestDistance(maze);

    return 0;
}
