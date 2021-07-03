const
  maxn=103;
var
  a:array[1..maxn,1..maxn]of longint;
  d:array[1..maxn]of longint;
  n:longint;

procedure main;
var
  i,j,x,y,p,p1,c,t:longint;
begin
  readln(n);
  p:=-1;x:=n;y:=n;c:=1;p1:=1;t:=1;
  for i:=1 to n*n do
    begin
      a[x,y]:=i;
      d[c]:=d[c]+1;
      if d[c]=c then
        begin
          c:=c+t;
          if c>n then
             begin
               fillchar(d,sizeof(d),0);
               p1:=p1*(-1);
               t:=-1;c:=n-1;
             end;
          if p1=1 then x:=x-1 else y:=y-1;
          p1:=p1*(-1);
          p:=p*(-1);
        end
      else begin
             if p=1 then begin x:=x+1;y:=y-1 end
                    else begin x:=x-1;y:=y+1 end;
           end;
    end;
    for i:=1 to n do
      begin
        for j:=1 to n-1 do
          write(a[i,j],' ');
        writeln(a[i,n]);
      end;
end;

begin
  assign(input,'snake.in');
  assign(output,'snake.out');
  reset(input);
  rewrite(output);
  main;
  close(input);
  close(output);
end.
