program reward(input,output);
var
  a:array[1..1000,1..1000]of boolean;
  b:array[0..1000]of integer;
  c:array[1..1000]of longint;
  i,j,k,m,n,t,sum:longint;

begin
  assign(input,'reward.in');
  assign(output,'reward.out');
  reset(input);
  rewrite(output);
  readln(input,n,m);
  fillchar(a,sizeof(a),false);
  fillchar(b,sizeof(b),0);
  b[0]:=maxint;
  for i:=1 to n do c[i]:=100;
  sum:=0;
  for i:=1 to m do begin
    readln(input,j,k);
    a[j,k]:=true;
    b[j]:=b[j]+1;
    sum:=sum+1;
  end;
  while sum>0 do begin
    t:=0;
    for i:=1 to n do
      if b[i]<b[t] then t:=i;
    if b[t]=0 then begin
      for i:=1 to n do
        if a[i,t] then begin
          b[i]:=b[i]-1;
          sum:=sum-1;
          if c[t]+1>c[i] then c[i]:=c[t]+1;          
        end;
      b[t]:=maxint;
    end
    else begin
      writeln(output,'-1');
      close(input);
      close(output);
      halt;
    end;
  end;
  k:=0;
  for i:=1 to n do k:=k+c[i];
  writeln(output,k);
  close(input);
  close(output);
end.