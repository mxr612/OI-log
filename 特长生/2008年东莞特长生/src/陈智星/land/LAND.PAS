var
  n,sum:longint;
procedure rr;
  var
    f1:text;
  begin
    assign(f1,'land.in');
    reset(f1);
    readln(f1,n);
    close(f1);
  end;
function main(n:longint):longint;
  var
    i,j:longint;
  begin
    j:=1;
    for i:=1 to n do
      j:=j*2;
    sum:=sum+j;
    if n>1 then main:=main(n-1)
           else if n=1 then sum:=sum+1;
  end;
procedure ww;
  var
    f2:text;
  begin
    assign(f2,'land.out');
    rewrite(f2);
    writeln(f2,sum);
    close(f2);
  end;
begin
  rr;
  main(n*n-1);
  ww;
end.