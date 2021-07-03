program reward(input,output);
var
  a:array[1..1000,1..1000] of boolean;
  b:array[1..1000] of integer;
  n,m,i,j,a1,b1:longint; bo,max:boolean;

procedure dfs(k,s:integer;bb:boolean);
var
  ii:integer;
begin
  if not(bb) then begin
    if s>b[k] then b[k]:=s;
  end
  else begin
    for ii:=1 to n do
      if a[ii,k] then begin
        dfs(ii,s+1,true);
      end;
    dfs(k,s,false)
  end;
end;

begin
  assign(input,'reward.in');
  assign(output,'reward.out');
  reset(input); rewrite(output);
  readln(n,m);
  max:=false;
  fillchar(a,sizeof(a),false);
  fillchar(b,sizeof(b),0);
  for i:=1 to m do begin
    readln(a1,b1);
    a[a1,b1]:=true;
  end;
  for i:=1 to n do begin
    bo:=true;
    for j:=1 to n do
      if a[i,j]=true then begin bo:=false; break; end;
    if bo=true then begin
      dfs(i,0,true);
      max:=true;
    end;
  end;
  j:=0;
  if max then begin
    for i:=1 to n do j:=j+b[i];
    writeln(100*n+j);
  end else writeln(-1);
  close(input); close(output);
end.
