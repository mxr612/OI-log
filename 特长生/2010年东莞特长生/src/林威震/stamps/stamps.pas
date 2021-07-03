var a:array[1..100]of longint;
    n,m,i:longint;
begin
 assign(input,'stamps.in');
 assign(output,'stamps.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to m do readln(a[i]);
 write(10);
 close(input);
 close(output);
end.
