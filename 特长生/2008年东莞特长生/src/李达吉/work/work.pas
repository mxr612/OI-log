program work(input,output);
var
  a:array[1..1000,1..3] of integer;
  b:array[1..1000] of boolean;
  i,n,min:integer;

procedure dfs(k,s:integer);
var
  j:integer;
  bb:boolean;
begin
  if k>n then begin
    if s<min then min:=s;
  end
  else begin
    bb:=false;
    for j:=1 to n do
      if (s>=a[j,2]) and (a[j,3]-s>a[j,1]) and not(b[j]) then begin
         b[j]:=true;
         dfs(k+1,s+a[j,1]);
         b[j]:=false;
         bb:=true;
      end;
    if not(bb) then dfs(k+1,s);
  end;
end;

begin
  assign(input,'work.in');
  assign(output,'work.out');
  reset(input); rewrite(output);
  readln(n);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do begin
    readln(a[i,1],a[i,2],a[i,3]);
    a[i,3]:=a[i,3]-a[i,2];
  end;
  min:=maxint;
  dfs(1,0);
  writeln(min);
  close(input); close(output);
end.