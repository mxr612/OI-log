program work(input,output);
var
  ti:array[0..1500]of boolean;
  ta:array[0..1500]of integer;
  num:array[1..1000]of boolean;
  a,b,t,go:array[1..1000]of integer;
  i,j,k,n,w,y:integer;

begin
  assign(input,'work.in');
  assign(output,'work.out');
  reset(input);
  rewrite(output);
  readln(input,n);
  fillchar(ta,sizeof(ta),0);
  for i:=1 to n do begin
    readln(input,t[i],a[i],b[i]);
    go[i]:=b[i]-t[i]+1;
    ta[go[i]]:=ta[go[i]]+1;
  end;
  for i:=1 to 1500 do ta[i]:=ta[i-1]+ta[i];
  fillchar(ti,sizeof(ti),false);
  fillchar(num,sizeof(num),false);
  i:=0;
  while i<=1500 do begin
    w:=-1;
    y:=0;
    for j:=1 to n do
      if (not(num[j])) and (i>=a[j]) and (i<=t[j]) and (ta[i+t[j]]>w) then begin
        w:=ta[j];
        y:=j;
      end;
    if y<>0 then begin
      num[y]:=true;
      for j:=i to i+t[y]-1 do ti[j]:=true;
      i:=i+t[y];
    end
    else i:=i+1;
  end;
  j:=0;
  for i:=0 to 1500 do
    if ti[i] then j:=j+1;
  writeln(output,j);
  close(input);
  close(output);
end.