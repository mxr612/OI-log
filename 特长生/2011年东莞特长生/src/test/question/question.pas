program question;
var
  a,p:array[1..100,1..100]of longint;
  d:array[1..100,1..100]of boolean;
  b,num,l:array[1..100]of longint;
  m,n,i,j,k,min,now:longint;
  bb:boolean;
  t:array[1..100]of boolean;
procedure dfs(k,now:longint);
  var i,j,w:longint;
  begin
    if k>m then
      begin
        if now<min then min:=now;
        exit
      end;
    if now>=min-1 then exit;
    for i:=1 to num[k]do
      begin
        w:=p[k,i];
        for j:=1 to l[w]do inc(b[a[w,j]]);
        j:=k+1;
        while b[j]>0 do inc(j);
        dfs(j,now+1);
        for j:=1 to l[w]do dec(b[a[w,j]])
      end
  end;
begin
  assign(input,'question.in');
  assign(output,'question.out');
  reset(input);
  rewrite(output);
  readln(m,n);
  for i:=1 to n do
    begin
      read(l[i]);
      for j:=1 to l[i] do
        begin
          read(a[i,j]);
          d[i,a[i,j]]:=true;
        end
    end;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)and(not t[i])and(not t[j]) then
        begin
          bb:=true;
          for k:=1 to m do if d[i,k] and not d[j,k] then
            begin
              bb:=false;
              break
            end;
          if bb then
            t[i]:=true
        end;
  for i:=1 to n do if not t[i]then
    begin
      for j:=1 to l[i] do
        begin
          inc(num[a[i,j]]);
          p[a[i,j],num[a[i,j]]]:=i
        end
    end;
  min:=1000000000;
  for i:=1 to m do if (num[i]=1)and(not t[p[i,1]]) then
    begin
      for j:=1 to l[p[i,1]]do inc(b[a[p[i,1],j]]);
      t[p[i,1]]:=true;
      inc(now)
    end;
  k:=1;
  while b[k]>0 do inc(k);
  dfs(k,now);
  writeln(min);
  close(input);
  close(output)
end.