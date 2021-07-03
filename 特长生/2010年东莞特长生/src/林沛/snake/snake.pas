program snake;
var
a:array[1..101,1..101] of longint;
i,j,k,l,n:integer;
begin
assign(input,'snake.in');reset(input);
assign(output,'snake.out');rewrite(output);
read(n);i:=n;j:=n; a[i,j]:=1;k:=1;
while (i<>1) and (j<>1) do
begin    dec(j);inc(k);  a[i,j]:=k;
if i=n then begin
repeat
dec(i);inc(j);inc(k);
a[i,j]:=k;

until j=n; end;  if (i=1) or (j=1) then break;
dec(i); inc(k);
a[i,j]:=k;
if j=n then begin
repeat
inc(i);dec(j); inc(k);
a[i,j]:=k;
until i=n; end; if (i=1) or (j=1) then break;
end;
while (i=1)and (j<>1) do
begin
dec(j);inc(k);a[i,j]:=k; if (i=1) and (j=1) then break;
repeat
inc(i);dec(j);inc(k);
a[i,j]:=k;
until j=1;
dec(i);inc(k);a[i,j]:=k;if (i=1) and (j=1) then break;
repeat
inc(j);dec(i);inc(k);
a[i,j]:=k;
until i=1;  end;

while (j=1)and (i<>1) do
begin

dec(i);inc(k);a[i,j]:=k; if (i=1) and (j=1) then break;
repeat
inc(j);dec(i);inc(k);
a[i,j]:=k;
until i=1;
dec(j);inc(k);a[i,j]:=k;
if (i=1)and  (j=1) then break;
repeat
inc(i);dec(j);inc(k);
a[i,j]:=k;
until j=1; end;
for j:=1 to n do   begin
writeln;

for i:=1 to n do    begin
write(a[i,j],' ');
    end;
    end;



close(input);
close(output);

end.








