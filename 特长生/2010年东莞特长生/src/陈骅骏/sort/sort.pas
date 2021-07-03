const
   maxn=200;
var
   a,b:array[0..maxn]of longint;
   i,j,n:longint;
procedure swap(var x,y:longint);
var
   t:longint;
begin
   t:=x;x:=y;y:=t
end;
begin
   assign(input,'sort.in');reset(input);
   assign(output,'sort.out');rewrite(output);

   readln(n);
   for i:=1 to n do readln(a[i],b[i]);

   for i:=1 to n do
    for j:=i+1 to n do
     if (b[i]<b[j]) or ((b[i]=b[j]) and (a[i]>a[j])) then
     begin
        swap(a[i],a[j]);
        swap(b[i],b[j])
     end;

   b[0]:=-1;
   for i:=1 to n do
   begin
      if b[i]<>b[i-1] then j:=i;
      writeln(a[i],' ',b[i],' ',j)
   end;

   close(input);close(output)
end.
