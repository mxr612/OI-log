var
  a:array[1..200,1..200]of longint;
  n,m:longint;
procedure print;
var
  i,j:longint;
begin
  for i:=1 to n do
    begin
    for j:=1 to n do
      write(a[i,j],' ');
    writeln;
  end;
end;

procedure dfs(x,y,r,ans:longint);
var
  i,j:longint;
begin
  if (x=1)and(y=1) then begin
                          a[1,1]:=n*n;
                          print;
                          exit;
                        end;
  if r=1 then
    begin
      while (x>=1)and(y<=n) do
        begin
          a[y,x]:=ans;
          dec(x);inc(y);
          inc(ans)
        end;
      inc(x);dec(y);
      if x=1 then dfs(x,y-1,0,ans)
      else dfs(x-1,y,0,ans);
    end
  else begin
         while (x<=n)and(y>=1)do
           begin
             a[y,x]:=ans;
             inc(x);dec(y);
             inc(ans);
           end;
         dec(x);inc(y);
         if y=1 then dfs(x-1,y,1,ans)
         else dfs(x,y-1,1,ans);
       end;
end;
begin
  assign(input,'snake.in');
  assign(output,'snake.out');
  reset(input);
  rewrite(output);
  read(n);
  dfs(n,n,0,1);
  close(input);
  close(output);
end.
