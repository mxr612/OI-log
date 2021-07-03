program num(input,output);
var a:array[1..100] of integer;
    nu:array[1..100] of integer;
    i,j,n,k:integer;

procedure swap(var a,b:integer);
var c:integer;
begin
  c:=a;a:=b;b:=c;
end;

begin
   assign(input,'num.in');
   assign(output,'num.out');
   reset(input);rewrite(output);
   readln(n);
   for i:=1 to n do begin
       read(a[i]);
       nu[i]:=i;
   end;
   readln(k);
   for i:=1 to n-1 do
   for j:=i+1 to n do
     if a[i]<a[j] then begin
        swap(a[i],a[j]);
        swap(nu[i],nu[j]);
     end;
   writeln(a[k]);
   writeln(nu[k]);
   close(input);close(output);
end.