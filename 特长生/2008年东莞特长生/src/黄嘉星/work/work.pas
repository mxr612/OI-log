var
  min,i,n:integer;
  t,a,b:array[1..1000] of integer;
  used:array[1..1000] of boolean;

procedure try(time,wt:integer);
var
  i:integer;
  f:boolean;
begin
  f:=false;
  for i:=1 to n do
   if (used[i]=false) and (time+t[i]<=b[i]) and (time>=a[i]) then
    begin
      f:=true;
      used[i]:=true;
      try(time+t[i],wt+t[i]);
      used[i]:=false;
    end;
  if not f then if wt<min then min:=wt;
end;

begin
  assign(input,'work.in');assign(output,'work.out');
  reset(input);rewrite(output);
  readln(n);min:=maxint;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do readln(t[i],a[i],b[i]);
  try(0,0);
  writeln(min);
  close(input);close(output);
end.

