M = csvRead("data/bfs.csv");
M2 = csvRead("data/dfs.csv");
M3 = csvRead("data/astar.csv");

ps = M(:,1);

t = M(:,3);
t2 = M2(:,3);
t3 = M3(:,3);

plot(ps, t, 'mo-');
plot(ps, t2, 'ko-');
plot(ps, t3, 'go-');

xlabel("rozmiar problemu");
ylabel("czas wyszukiwania");
legend("BFS", "DFS", "A*", "in_lower_right");
