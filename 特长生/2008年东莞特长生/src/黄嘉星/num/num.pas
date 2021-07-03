var
  n,i,p:integer;
  a,b:array[0..101] of integer;

procedure quicksort(s,t:integer);
var
  i,j,k,k1:integer;
begin
  if s<t then
   begin
     i:=s;j:=t;k:=a[i];k1:=b[i];
     repeat
       while (k>a[j]) and (i<j) do j:=j-1;
       if i<j then
        begin
          a[i]:=a[j];
          b[i]:=b[j];
          i:=i+1;
        end;
       while (k<a[i]) and (i<j) do i:=i+1;
       if i<j then
        begin
          a[j]:=a[i];
          b[j]:=b[i];
          j:=j-1;
        end;
     until i=j;
     a[i]:=k;b[i]:=k1;
     quicksort(s,i-1);
     quicksort(i+1,t);
   end;
end;

begin
  assign(input,'num.in');assign(output,'num.out');
  reset(input);rewrite(output);
  readln(n);
  for i:=1 to n do begin read(a[i]);b[i]:=i;end;
  readln(p);
  quicksort(1,n);
  writeln(a[p]);
  writeln(b[p]);
  close(input);close(output);
end.
