program pp;
var a:array[1..1000] of integer;
    v:array[1..1000] of boolean;
    g:array[1..1000,1..1000] of integer;
    x,y,n,m,i,j,max:integer;
    s:longint;
    f:boolean;
procedure find(p,t:integer);
var q:integer;
begin
  if t>max then max:=t;
  for q:=1 to n do if g[p,q]=1 then
    if v[q] then begin f:=true;break; end else begin v[q]:=true;find(q,t+1);v[q]:=false;end;
end;
begin
  assign(input,'reward.in');
  assign(output,'reward.out');
  reset(input);rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  if n>1000 then writeln(-1) else
  begin
  for i:=1 to m do
  begin
    readln(x,y);
    g[x,y]:=1;
  end;
  f:=false;
  for i:=1 to n do
  begin
    fillchar(v,sizeof(v),false);
    max:=0;
    find(i,0);
    a[i]:=max;
  end;
  s:=0;
  if f then writeln('-1') else
  begin
    for i:=1 to n do s:=s+100+a[i];
    writeln(s);
  end;
  end;
  close(input);close(output)
end.
