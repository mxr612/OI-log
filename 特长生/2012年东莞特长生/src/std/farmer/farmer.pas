program horses;
var
  i,j,k,n,x1,x2,min,x:longint;
  a,b,w,d:array[0..500] of longint;
  f:array[1..500,1..500] of longint;

begin
assign(input,'farmer.in');
reset(input);
assign(output,'farmer.out');
rewrite(output);
readln(n,k);
fillchar(b,sizeof(b),0);
fillchar(w,sizeof(w),0);
x1:= 0; x2:= 0;
for i:= 1 to n do
 begin
  readln(a[i]);
  if a[i] = 1 then
    inc(x1)
  else inc(x2);
  b[i]:= x1;
  w[i]:= x2;
 end;
for i:= 1 to n do
 f[1,i]:= w[i] * b[i];
for i:= 2 to k do
 for j:= i to n-k+i do
 begin
  min:= 10000000;
  for x:= i-1 to j-1 do
   begin
    f[i,j]:= f[i-1,x] + (w[j] - w[x]) * (b[j] - b[x]);
    if f[i,j] < min then min:= f[i,j];
   end;
  f[i,j]:= min;
  end;
write(f[k,n]);
close(input);
close(output);
end.
