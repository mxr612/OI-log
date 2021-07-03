var
  a,b:array[1..100] of integer;
  n,k:integer;
procedure duru;
 var
   f1:text;
   i,s:integer;
 begin
   assign(f1,'num.in');
   reset(f1);
   readln(f1,n);
   for i:=1 to n do
    begin
      read(f1,s);
      a[i]:=s;
    end;
   readln(f1);
   read(f1,k);
   close(f1);
 end;
procedure chuli;
 var
   i,j,t:integer;
 begin
   for i:=1 to n do b[i]:=a[i];
   for i:=1 to n-1 do
    for j:=i+1 to n do
     if b[i]<b[j] then
      begin
        t:=b[i];
        b[i]:=b[j];
        b[j]:=t;
      end;
 end;
procedure shuchu;
 var
   f2:text;
   i:integer;
 begin
   assign(f2,'num.out');
   rewrite(f2);
   for i:=1 to n do
    if b[k]=a[i] then
     begin
       writeln(f2,b[k]);
       writeln(f2,i);
     end;
   close(f2);
 end;
begin
  duru;
  chuli;
  shuchu;
end.