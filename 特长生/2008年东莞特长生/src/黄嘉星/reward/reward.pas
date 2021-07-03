var
  i,j:longint;
  min,a,b,n,m,c,s:int64;
  n1,f:array[0..1001] of int64;
  aa:array[0..1001,0..1001] of int64;

procedure try(k,p:longint);
var
  i:longint;
begin
  if p=a then begin writeln(-1);close(input);close(output);halt;end;
  for i:=1 to n1[p] do f[aa[p,n1[i]]]:=k-1;
  for i:=1 to n1[p] do try(k-1,aa[p,n1[i]]);
end;

begin
  assign(input,'reward.in');assign(output,'reward.out');
  reset(input);rewrite(output);
  readln(n,m);
  fillchar(n1,sizeof(n1),0);
  for i:=1 to n do f[i]:=-32767;
  fillchar(aa,sizeof(aa),0);
  for i:=1 to m do
   begin
     readln(a,b);
     n1[a]:=n1[a]+1;
     aa[a,n1[a]]:=b;
     if f[a]=-32767 then
      begin
        f[a]:=1;
        f[b]:=f[a]-1;
        try(0,b);
      end
     else
      begin
        f[b]:=f[a]-1;
        try(f[b],b);
      end;
   end;
  min:=maxint;
  for i:=1 to n do if f[i]<min then min:=f[i];
  s:=0;
  for i:=1 to n do s:=s+100-min+f[i];
  writeln(s);
  close(input);close(output);
end.




